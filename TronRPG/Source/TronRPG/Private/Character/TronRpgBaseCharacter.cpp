#include "Character/TronRpgBaseCharacter.h"

#include "Animation/Character/CharacterAnimInstance.h"
#include "GAS/TronRpgAbilitySystemComponent.h"
#include "GAS/TronRpgAttributeSet.h"
#include "Component/Animation/AnimationComponent.h"
#include "Component/Input/AbilityInputComponent.h"
#include "Component/Weapon/WeaponComponent.h"
#include "Data/Weapon/WeaponDataAsset.h"
#include "Net/UnrealNetwork.h"

ATronRpgBaseCharacter::ATronRpgBaseCharacter()
{
	// Системные настройки
	bReplicates = true;
	SetNetUpdateFrequency(60.f);

	// Создание компонентов - все вызовы CreateDefaultSubobject должны быть здесь
	AbilitySystemComponent = CreateDefaultSubobject<UTronRpgAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AttributeSet = CreateDefaultSubobject<UTronRpgAttributeSet>(TEXT("AttributeSet"));
	AnimationComponent = CreateDefaultSubobject<UAnimationComponent>(TEXT("AnimationComponent"));
	AbilityInputComponent = CreateDefaultSubobject<UAbilityInputComponent>(TEXT("AbilityInputComponent"));
	WeaponComponent = CreateDefaultSubobject<UWeaponComponent>(TEXT("WeaponComponent"));

	// Создание компонентов оружия
	WeaponComponent->MainHandMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MainHandMesh"));
	WeaponComponent->OffHandMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OffHandMesh"));

	// Конфигурация уже созданных компонентов может быть вынесена в отдельные методы
	ConfigureAbilityComponents();
	ConfigureWeaponComponents();

	// Привязка делегата
	OnWeaponVisibilityChanged.AddDynamic(this, &ATronRpgBaseCharacter::UpdateWeaponVisibility);

	// Инициализация переменных состояния
	bAbilitiesInitialized = false;
}

void ATronRpgBaseCharacter::ConfigureAbilityComponents()
{
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

void ATronRpgBaseCharacter::ConfigureWeaponComponents()
{
	// Настройка компонентов оружия
	ConfigureWeaponMesh(WeaponComponent->MainHandMeshComponent, TEXT("WeaponSocket_MainHand"));
	ConfigureWeaponMesh(WeaponComponent->OffHandMeshComponent, TEXT("WeaponSocket_OffHand"));
}

void ATronRpgBaseCharacter::ConfigureWeaponMesh(UStaticMeshComponent* MeshComponent, const FName& SocketName)
{
	MeshComponent->SetupAttachment(GetMesh(), SocketName);
	MeshComponent->SetVisibility(false);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComponent->SetCanEverAffectNavigation(false);
	MeshComponent->SetIsReplicated(true);
}

void ATronRpgBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	AbilityInputComponent->SetupPlayerInput(GetController()->InputComponent);

	// Инициализация базового оружия, если указано
	InitializeDefaultWeapon();

	// Логирование начала игры
	UE_LOG(LogTemp, Log, TEXT("Character %s has begun play"), *GetName());
}

void ATronRpgBaseCharacter::InitializeDefaultWeapon()
{
	if (DefaultWeaponAsset && AnimationComponent)
	{
		if (!DefaultWeaponAsset->WalkForwardBlendSpace.IsValid())
		{
			UBlendSpace* LoadSynchronous = DefaultWeaponAsset->WalkForwardBlendSpace.LoadSynchronous();
			UBlendSpace* BlendSpace = DefaultWeaponAsset->WalkBackwardBlendSpace.LoadSynchronous();
		}
		// Установка начальных blend space для анимации движения
		AnimationComponent->SetMovementBlendSpace(
			DefaultWeaponAsset->WalkForwardBlendSpace.Get(),
			DefaultWeaponAsset->WalkBackwardBlendSpace.Get()
		);
	}
}


void ATronRpgBaseCharacter::UpdateWeaponVisibility(bool bIsVisible)
{
	if (WeaponComponent)
	{
		WeaponComponent->UpdateWeaponVisuals(bIsVisible);
	}
}

UAbilitySystemComponent* ATronRpgBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

bool ATronRpgBaseCharacter::EquipWeapon(UWeaponDataAsset* WeaponAsset, float BlendSpaceTransitionDuration)
{
	if (!WeaponAsset)
	{
		UE_LOG(LogTemp, Warning, TEXT("Attempted to equip null weapon asset"));
		return false;
	}

	// Для сетевой игры: на клиенте вызываем серверную функцию
	if (GetLocalRole() < ROLE_Authority)
	{
		Server_EquipWeapon(WeaponAsset, BlendSpaceTransitionDuration);
		return true; // Предполагаем успех на клиенте, сервер проверит
	}

	// Проверка, не находится ли персонаж в анимации атаки
	if (AbilitySystemComponent && AbilitySystemComponent->HasMatchingGameplayTag(FGameplayTag::RequestGameplayTag("State.Attacking")))
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannot equip weapon: character is attacking"));
		return false;
	}

	// Вызов экипировки через компонент оружия
	if (!WeaponComponent)
	{
		return false;
	}

	bool success = WeaponComponent->EquipWeapon(WeaponAsset);

	// Если экипировка прошла успешно, настраиваем BlendSpace
	if (success && AnimationComponent && WeaponAsset)
	{
		AnimationComponent->TransitionToNewBlendSpace(
			WeaponAsset->WalkForwardBlendSpace.Get(),
			WeaponAsset->WalkBackwardBlendSpace.Get(),
			BlendSpaceTransitionDuration
		);
	}

	return success;
}

void ATronRpgBaseCharacter::Server_EquipWeapon_Implementation(UWeaponDataAsset* WeaponAsset, float BlendSpaceTransitionDuration)
{
	EquipWeapon(WeaponAsset, BlendSpaceTransitionDuration);
}

bool ATronRpgBaseCharacter::UnequipWeapon()
{
	if (!WeaponComponent || !WeaponComponent->CurrentWeapon)
	{
		return false;
	}

	// Для сетевой игры: на клиенте вызываем серверную функцию
	if (GetLocalRole() < ROLE_Authority)
	{
		Server_UnequipWeapon();
		return true; // Предполагаем успех на клиенте, сервер проверит
	}

	// Проверка, не находится ли персонаж в анимации атаки
	if (AbilitySystemComponent && AbilitySystemComponent->HasMatchingGameplayTag(FGameplayTag::RequestGameplayTag("State.Attacking")))
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannot unequip weapon: character is attacking"));
		return false;
	}

	// Вызов снятия оружия через компонент
	bool success = WeaponComponent->UnequipWeapon();

	// Если снятие прошло успешно, настраиваем BlendSpace
	if (success && AnimationComponent && DefaultWeaponAsset)
	{
		AnimationComponent->TransitionToNewBlendSpace(
			DefaultWeaponAsset->WalkForwardBlendSpace.Get(),
			DefaultWeaponAsset->WalkBackwardBlendSpace.Get(),
			1.0f
		);
	}

	return success;
}

void ATronRpgBaseCharacter::Server_UnequipWeapon_Implementation()
{
	UnequipWeapon();
}

bool ATronRpgBaseCharacter::EquipWeaponByTag(FGameplayTag WeaponTag)
{
	if (!WeaponComponent) return false;

	// Делегируем логику компоненту оружия
	return WeaponComponent->EquipWeaponByTag(WeaponTag);
}

void ATronRpgBaseCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Добавляем репликацию флага
	DOREPLIFETIME(ATronRpgBaseCharacter, bIsPlayingEquipAnimation);

	// Существующие репликации
	DOREPLIFETIME(ATronRpgBaseCharacter, AbilitySystemComponent);
}