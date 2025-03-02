#include "Character/TronRpgBaseCharacter.h"

#include "Animation/Character/CharacterAnimInstance.h"
#include "GAS/TronRpgAbilitySystemComponent.h"
#include "GAS/TronRpgAttributeSet.h"
#include "Component/TronRpgComboComponent.h"
#include "Component/Animation/AnimationComponent.h"
#include "Component/DI/DependencyInjectorComponent.h"
#include "Component/Weapon/WeaponComponent.h"
#include "Data/Weapon/WeaponDataAsset.h"
#include "Net/UnrealNetwork.h"
#include "AbilitySystemGlobals.h"
#include "GameplayEffect.h"
#include "GameplayAbilitySpec.h"
#include "Input/TronRpgEnhancedInputComponent.h"
#include "Object/GameplayTagsLibrary.h"
#include "TronRPG/TronRPG.h"

ATronRpgBaseCharacter::ATronRpgBaseCharacter()
{
	// Системные настройки
	bReplicates = true;
	SetNetUpdateFrequency(60.f); // Оптимизация для быстрого обновления в сети

	// Создание компонентов
	AbilitySystemComponent = CreateDefaultSubobject<UTronRpgAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UTronRpgAttributeSet>(TEXT("AttributeSet"));
	ComboComponent = CreateDefaultSubobject<UTronRpgComboComponent>(TEXT("ComboComponent"));
	AnimationComponent = CreateDefaultSubobject<UAnimationComponent>(TEXT("AnimationComponent"));
	DependencyInjector = CreateDefaultSubobject<UDependencyInjectorComponent>(TEXT("DependencyInjector"));
	AbilityInputComponent = CreateDefaultSubobject<UTronRpgEnhancedInputComponent>(TEXT("AbilityInputComponent"));
	WeaponComponent = CreateDefaultSubobject<UWeaponComponent>(TEXT("WeaponComponent"));

	// Привязка делегата для обработки видимости оружия
	OnWeaponVisibilityChanged.AddDynamic(this, &ATronRpgBaseCharacter::UpdateWeaponVisibility);

	// Инициализация переменных состояния
	bAbilitiesInitialized = false;
}

void ATronRpgBaseCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	SetupComponents();
}

void ATronRpgBaseCharacter::SetupComponents()
{
	// Проверка валидности и настройка дополнительных параметров компонентов
	if (AbilitySystemComponent)
	{
		// Настройка обработки тегов для ASC

		AbilitySystemComponent->SetTagMapCount((TAG_State_Running), 0);
		AbilitySystemComponent->SetTagMapCount((TAG_State_Sprinting), 0);
	}

	// Настройка отладочных сообщений для компонентов
	UE_LOG(LogTemp, Log, TEXT("Components for %s have been set up"), *GetName());
}

void ATronRpgBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

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
			DefaultWeaponAsset->WalkForwardBlendSpace.LoadSynchronous();
			DefaultWeaponAsset->WalkBackwardBlendSpace.LoadSynchronous();
		}
		// Установка начальных blend space для анимации движения
		AnimationComponent->SetMovementBlendSpace(
			DefaultWeaponAsset->WalkForwardBlendSpace.Get(),
			DefaultWeaponAsset->WalkBackwardBlendSpace.Get()
		);

		// Автоматическая экипировка оружия по умолчанию, если нужно
		// Раскомментировать при необходимости:
		// EquipWeapon(DefaultWeaponAsset, 0.0f);
	}
}

void ATronRpgBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Инициализация способностей при взятии персонажа под контроль
	if (HasAuthority() && AbilitySystemComponent)
	{
		InitializeAbilities();
		ApplyBaseEffects();
	}
}

void ATronRpgBaseCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// На клиенте тоже инициализируем способности после получения PlayerState
	InitializeAbilities();
}

void ATronRpgBaseCharacter::InitializeAbilities()
{
	// Предотвращаем повторную инициализацию
	if (bAbilitiesInitialized || !AbilitySystemComponent)
		return;

	// Выдаем базовые способности
	for (TSubclassOf<UGameplayAbility>& AbilityClass : BaseAbilities)
	{
		if (AbilityClass)
		{
			FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
			AbilitySystemComponent->GiveAbility(AbilitySpec);
		}
	}

	bAbilitiesInitialized = true;
}

void ATronRpgBaseCharacter::ApplyBaseEffects()
{
	if (!AbilitySystemComponent) return;

	// Применяем постоянные эффекты
	for (TSubclassOf<UGameplayEffect>& EffectClass : PersistentEffects)
	{
		if (EffectClass)
		{
			FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
			EffectContext.AddSourceObject(this);

			FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(
				EffectClass, 1.0f, EffectContext);

			if (SpecHandle.IsValid())
			{
				FActiveGameplayEffectHandle EffectHandle =
					AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());

				if (!EffectHandle.IsValid())
				{
					UE_LOG(LogTemp, Warning, TEXT("Failed to apply persistent effect %s to %s"),
					       *EffectClass->GetName(), *GetName());
				}
			}
		}
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

	// Логика экипировки на сервере
	if (WeaponComponent && AnimationComponent)
	{
		WeaponComponent->EquipWeapon(WeaponAsset);
		AnimationComponent->PlayMontage(WeaponAsset->EquipMontage.Get());
		AnimationComponent->TransitionToNewBlendSpace(
			WeaponAsset->WalkForwardBlendSpace.Get(),
			WeaponAsset->WalkBackwardBlendSpace.Get(),
			BlendSpaceTransitionDuration
		);
		return true;
	}
	return false;
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

	// Логика снятия оружия на сервере
	if (AnimationComponent && DefaultWeaponAsset)
	{
		AnimationComponent->PlayMontage(WeaponComponent->CurrentWeapon->UnequipMontage.Get());
		AnimationComponent->TransitionToNewBlendSpace(
			DefaultWeaponAsset->WalkForwardBlendSpace.Get(),
			DefaultWeaponAsset->WalkBackwardBlendSpace.Get(),
			1.0f
		);
		WeaponComponent->UnequipWeapon();
		return true;
	}
	return false;
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

	// Репликация компонента AbilitySystem
	DOREPLIFETIME(ATronRpgBaseCharacter, AbilitySystemComponent);

	// Можно добавить другие переменные для репликации при необходимости
}

bool ATronRpgBaseCharacter::EquipWeapon_Implementation(UWeaponDataAsset* WeaponAsset, float BlendSpaceTransitionDuration)
{
	return EquipWeapon(WeaponAsset, BlendSpaceTransitionDuration);
}

bool ATronRpgBaseCharacter::UnequipWeapon_Implementation()
{
	return UnequipWeapon();
}

bool ATronRpgBaseCharacter::ExecuteAttack_Implementation(const FGameplayTag& AttackTag)
{
	// Проверяем наличие способности с указанным тегом
	return ActivateAbilityByTag(AttackTag);
}

float ATronRpgBaseCharacter::ApplyDamageToTarget_Implementation(AActor* Target, float DamageAmount, bool bIsCritical)
{
	if (!Target || DamageAmount <= 0.0f)
	{
		return 0.0f;
	}

	// Получаем компонент AbilitySystem цели
	UAbilitySystemComponent* TargetASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Target);
	if (!TargetASC)
	{
		return 0.0f;
	}

	// Увеличиваем урон, если он критический
	float FinalDamage = DamageAmount;
	if (bIsCritical)
	{
		FinalDamage *= 2.0f;
	}

	// Создаем контекст эффекта
	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	// Ищем эффект урона
	TSubclassOf<UGameplayEffect> DamageEffect = nullptr;
	for (TSubclassOf<UGameplayEffect> Effect : PersistentEffects)
	{
		if (Effect->GetDefaultObject<UGameplayEffect>()->GameplayTags.HasTag(TAG_Damage))
		{
			DamageEffect = Effect;
			break;
		}
	}

	if (DamageEffect)
	{
		// Создаем спецификацию эффекта
		FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(
			DamageEffect, 1.0f, EffectContext);

		if (SpecHandle.IsValid())
		{
			// Устанавливаем значение урона
			SpecHandle.Data->SetSetByCallerMagnitude(TAG_Damage, FinalDamage);

			// Если удар критический, добавляем соответствующий тег
			if (bIsCritical)
			{
				SpecHandle.Data->AddDynamicAssetTag(TAG_Damage_Critical);
			}

			// Применяем эффект к цели
			FActiveGameplayEffectHandle ActiveHandle = TargetASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());

			if (ActiveHandle.IsValid())
			{
				UE_LOG(LogWeaponSystem, Log, TEXT("Applied %.1f damage to %s (Critical: %s)"),
				       FinalDamage, *Target->GetName(), bIsCritical ? TEXT("Yes") : TEXT("No"));

				return FinalDamage;
			}
		}
	}

	return 0.0f;
}

bool ATronRpgBaseCharacter::HasWeaponEquipped_Implementation() const
{
	return WeaponComponent && WeaponComponent->IsWeaponEquipped();
}

bool ATronRpgBaseCharacter::ActivateAbilityByTag(const FGameplayTag& AbilityTag)
{
	if (!AbilitySystemComponent || !AbilityTag.IsValid())
	{
		return false;
	}

	return AbilitySystemComponent->TryActivateAbilityByTag(AbilityTag);
}

bool ATronRpgBaseCharacter::IsAbilityActive(const FGameplayTag& AbilityTag) const
{
	if (!AbilitySystemComponent || !AbilityTag.IsValid())
	{
		return false;
	}

	return AbilitySystemComponent->HasActiveAbilityWithTag(AbilityTag);
}

UGameplayAbility* ATronRpgBaseCharacter::GetAbilityByTag(const FGameplayTag& AbilityTag) const
{
	if (!AbilitySystemComponent || !AbilityTag.IsValid())
	{
		return nullptr;
	}

	// Находим ручку спецификации способности
	FGameplayAbilitySpecHandle Handle = AbilitySystemComponent->FindAbilitySpecHandleByTag(AbilityTag);

	if (Handle.IsValid())
	{
		// Получаем спецификацию по ручке
		FGameplayAbilitySpec* AbilitySpec = AbilitySystemComponent->FindAbilitySpecFromHandle(Handle);

		if (AbilitySpec && AbilitySpec->Ability)
		{
			return AbilitySpec->Ability;
		}
	}

	return nullptr;
}
