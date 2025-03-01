// Tron

#include "Component/Weapon/WeaponComponent.h"

#include "GameInstanceSubsystem/WeaponAsset/TronRpgWeaponAssetManager.h"
#include "GAS/TronRpgAbilitySystemComponent.h"
#include "Data/Weapon/WeaponDataAsset.h"
#include "Net/UnrealNetwork.h"
#include "Object/GameplayTagsLibrary.h"
#include "TronRPG/TronRPG.h"

UWeaponComponent::UWeaponComponent()
{
	// Настройки компонента
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickInterval = 0.1f; // Оптимизация производительности, тик каждые 100мс
	SetIsReplicatedByDefault(true);

	// Инициализация указателей
	CurrentWeapon = nullptr;
	AbilitySystemComponent = nullptr;
}

void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	// Получаем AbilitySystemComponent из владельца
	AbilitySystemComponent = GetOwner()->FindComponentByClass<UTronRpgAbilitySystemComponent>();

	// Проверяем, что компоненты оружия правильно настроены
	if (MainHandMeshComponent)
	{
		MainHandMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		MainHandMeshComponent->SetVisibility(false);
	}

	if (OffHandMeshComponent)
	{
		OffHandMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		OffHandMeshComponent->SetVisibility(false);
	}

	// Инициализация истории оружия
	WeaponHistory.Empty(MaxWeaponHistorySize);
}

void UWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Регулярные проверки или обновления состояния оружия можно реализовать здесь
	// Например, проверка условий повреждения оружия, износа и т.д.
}

bool UWeaponComponent::EquipWeapon(UWeaponDataAsset* WeaponAsset)
{
	// Проверка валидности параметров
	if (!WeaponAsset || CurrentWeapon == WeaponAsset)
	{
		UE_LOG(LogWeaponSystem, Warning, TEXT("Invalid weapon asset or already equipped: %s"),
		       WeaponAsset ? *WeaponAsset->GetName() : TEXT("nullptr"));
		return false;
	}

	UpdateWeaponVisuals(false);

	// Сохраняем предыдущее оружие
	UWeaponDataAsset* PreviousWeapon = CurrentWeapon;

	// Обновляем текущее оружие
	CurrentWeapon = WeaponAsset;

	// Добавляем в историю
	AddToWeaponHistory(WeaponAsset);

	// Обрабатываем предыдущее оружие
	if (PreviousWeapon)
	{
		UpdateGameplayTags(PreviousWeapon, false);
	}

	// Применяем теги нового оружия
	UpdateGameplayTags(CurrentWeapon, true);

	/*// Обновляем визуализацию
	UpdateWeaponVisuals(true);*/

	UE_LOG(LogWeaponSystem, Log, TEXT("Weapon equipped: %s"), *WeaponAsset->GetName());

	return true;
}

bool UWeaponComponent::UnequipWeapon()
{
	if (!CurrentWeapon)
	{
		UE_LOG(LogWeaponSystem, Warning, TEXT("Attempted to unequip weapon when none is equipped"));
		return false;
	}

	// Удаляем теги текущего оружия
	UpdateGameplayTags(CurrentWeapon, false);

	/*// Скрываем оружие
	UpdateWeaponVisuals(false);*/

	UE_LOG(LogWeaponSystem, Log, TEXT("Weapon unequipped: %s"), *CurrentWeapon->GetName());

	// Сбрасываем указатель текущего оружия
	CurrentWeapon = nullptr;

	return true;
}

bool UWeaponComponent::EquipWeaponByTag(FGameplayTag WeaponTag)
{
	if (!WeaponTag.IsValid())
	{
		UE_LOG(LogWeaponSystem, Warning, TEXT("Attempted to equip weapon with invalid tag"));
		return false;
	}

	// Получаем менеджер ассетов оружия
	UTronRpgWeaponAssetManager* WeaponManager = GetWeaponAssetManager();
	if (!WeaponManager)
	{
		UE_LOG(LogWeaponSystem, Error, TEXT("Weapon asset manager not found"));
		return false;
	}

	// Получаем список оружий с указанным тегом
	TArray<UWeaponDataAsset*> Weapons = WeaponManager->GetWeaponsByTag(WeaponTag);
	if (Weapons.Num() == 0)
	{
		UE_LOG(LogWeaponSystem, Warning, TEXT("No weapons found with tag: %s"), *WeaponTag.ToString());
		return false;
	}

	// Выбираем первое оружие из списка
	UWeaponDataAsset* TargetWeapon = Weapons[0];

	// Если у нас уже экипировано оружие с этим тегом, снимаем его
	if (CurrentWeapon && CurrentWeapon->WeaponTags.HasTagExact(WeaponTag))
	{
		return UnequipWeapon();
	}

	// Иначе экипируем новое оружие
	return EquipWeapon(TargetWeapon);
}

void UWeaponComponent::UpdateWeaponVisuals(bool bIsVisible)
{
	// Обновляем визуализацию оружия
	if (CurrentWeapon)
	{
		// Устанавливаем меш для основной руки
		if (MainHandMeshComponent)
		{
			bool bHasMainHandWeapon = CurrentWeapon->WeaponSlot.HasTag(TAG_Equipment_Slot_MainHand);
			MainHandMeshComponent->SetStaticMesh(bHasMainHandWeapon ? CurrentWeapon->WeaponMesh.Get() : nullptr);
			MainHandMeshComponent->SetVisibility(bIsVisible && bHasMainHandWeapon);
		}

		// Устанавливаем меш для дополнительной руки
		if (OffHandMeshComponent)
		{
			bool bHasOffHandWeapon = CurrentWeapon->WeaponSlot.HasTag(TAG_Equipment_Slot_OffHand);
			OffHandMeshComponent->SetStaticMesh(bHasOffHandWeapon ? CurrentWeapon->AdditionalWeaponMesh.Get() : nullptr);
			OffHandMeshComponent->SetVisibility(bIsVisible && bHasOffHandWeapon);
		}
	}
	else
	{
		// Если нет текущего оружия, скрываем оба меша
		if (MainHandMeshComponent)
		{
			MainHandMeshComponent->SetVisibility(false);
		}

		if (OffHandMeshComponent)
		{
			OffHandMeshComponent->SetVisibility(false);
		}
	}
}

FGameplayTagContainer UWeaponComponent::GetCurrentWeaponTags() const
{
	return CurrentWeapon ? CurrentWeapon->WeaponTags : FGameplayTagContainer();
}

bool UWeaponComponent::HasWeaponWithTag(FGameplayTag Tag) const
{
	return CurrentWeapon && CurrentWeapon->WeaponTags.HasTag(Tag);
}

void UWeaponComponent::AddToWeaponHistory(UWeaponDataAsset* WeaponAsset)
{
	if (!WeaponAsset) return;

	// Удаляем существующее вхождение этого оружия из истории
	WeaponHistory.Remove(WeaponAsset);

	// Добавляем оружие в начало истории
	WeaponHistory.Insert(WeaponAsset, 0);

	// Ограничиваем размер истории
	if (WeaponHistory.Num() > MaxWeaponHistorySize)
	{
		WeaponHistory.RemoveAt(MaxWeaponHistorySize, WeaponHistory.Num() - MaxWeaponHistorySize);
	}
}

void UWeaponComponent::UpdateGameplayTags(UWeaponDataAsset* WeaponAsset, bool bAdd)
{
	if (!AbilitySystemComponent || !WeaponAsset) return;
    
	if (bAdd)
	{
		// Добавляем теги оружия
		AbilitySystemComponent->AddLooseGameplayTags(WeaponAsset->WeaponTags);
        
		// Добавляем тег состояния "оружие экипировано"
		AbilitySystemComponent->AddLooseGameplayTag(TAG_Weapon_Equipped);
		AbilitySystemComponent->AddLooseGameplayTag(TAG_State_Equipment_Equipped);
	}
	else
	{
		// Удаляем теги оружия
		AbilitySystemComponent->RemoveLooseGameplayTags(WeaponAsset->WeaponTags);
        
		// Удаляем тег состояния "оружие экипировано", если это было последнее оружие
		if (!CurrentWeapon)
		{
			AbilitySystemComponent->RemoveLooseGameplayTag(TAG_Weapon_Equipped);
			AbilitySystemComponent->RemoveLooseGameplayTag(TAG_State_Equipment_Equipped);
		}
	}
}

void UWeaponComponent::OnRep_CurrentWeapon()
{
	// Обновляем визуализацию при репликации
	UpdateWeaponVisuals(CurrentWeapon != nullptr);

	// Обновляем теги
	if (AbilitySystemComponent)
	{
		// Сначала очищаем все теги оружия
		AbilitySystemComponent->RemoveLooseGameplayTag(FGameplayTag::RequestGameplayTag(TEXT("State.Equipment.Equipped")));

		// Затем обновляем теги для текущего оружия
		if (CurrentWeapon)
		{
			UpdateGameplayTags(CurrentWeapon, true);
		}
	}
}

UTronRpgWeaponAssetManager* UWeaponComponent::GetWeaponAssetManager() const
{
	return GetOwner()->GetGameInstance() ? GetOwner()->GetGameInstance()->GetSubsystem<UTronRpgWeaponAssetManager>() : nullptr;
}

void UWeaponComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Репликация текущего оружия
	DOREPLIFETIME(UWeaponComponent, CurrentWeapon);
}
