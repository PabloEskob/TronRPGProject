// Tron

#include "Component/Weapon/WeaponComponent.h"

#include "Component/Weapon/WeaponLogicComponent.h"
#include "Component/Weapon/WeaponVisualComponent.h"
#include "Data/Weapon/WeaponDataAsset.h"
#include "TronRPG/TronRPG.h"

UWeaponComponent::UWeaponComponent()
{
	// Настройки компонента
	PrimaryComponentTick.bCanEverTick = false;
	SetIsReplicatedByDefault(true);

	// Создаем дочерние компоненты
	LogicComponent = CreateDefaultSubobject<UWeaponLogicComponent>(TEXT("WeaponLogicComponent"));
	VisualComponent = CreateDefaultSubobject<UWeaponVisualComponent>(TEXT("WeaponVisualComponent"));
}

void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	// Инициализируем компоненты и настраиваем связи между ними
	InitializeComponents();
}

void UWeaponComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// Отписываемся от делегатов
	if (LogicComponent)
	{
		LogicComponent->OnWeaponChanged.RemoveDynamic(this, &UWeaponComponent::OnWeaponChanged);
	}

	Super::EndPlay(EndPlayReason);
}

void UWeaponComponent::InitializeComponents()
{
	// Настройка связей между компонентами
	if (LogicComponent && VisualComponent)
	{
		// Настраиваем взаимодействие между компонентами
		LogicComponent->SetVisualComponent(VisualComponent);

		// Подписываемся на события изменения оружия
		LogicComponent->OnWeaponChanged.AddDynamic(this, &UWeaponComponent::OnWeaponChanged);

		// Устанавливаем компоненты меша для визуального компонента
		VisualComponent->MainHandMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MainHandMesh"));
		VisualComponent->MainHandMeshComponent->SetupAttachment(GetOwner()->GetRootComponent(), TEXT("WeaponSocket_MainHand"));
		VisualComponent->MainHandMeshComponent->SetVisibility(false);
		VisualComponent->MainHandMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		VisualComponent->MainHandMeshComponent->SetCanEverAffectNavigation(false);
		VisualComponent->MainHandMeshComponent->SetIsReplicated(true);

		VisualComponent->OffHandMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OffHandMesh"));
		VisualComponent->OffHandMeshComponent->SetupAttachment(GetOwner()->GetRootComponent(), TEXT("WeaponSocket_OffHand"));
		VisualComponent->OffHandMeshComponent->SetVisibility(false);
		VisualComponent->OffHandMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		VisualComponent->OffHandMeshComponent->SetCanEverAffectNavigation(false);
		VisualComponent->OffHandMeshComponent->SetIsReplicated(true);

		UE_LOG(LogWeaponSystem, Log, TEXT("WeaponComponent: Components initialized"));
	}
	else
	{
		UE_LOG(LogWeaponSystem, Error, TEXT("WeaponComponent: Failed to initialize components"));
	}
}

bool UWeaponComponent::EquipWeapon(UWeaponDataAsset* WeaponAsset)
{
	if (!LogicComponent)
	{
		UE_LOG(LogWeaponSystem, Warning, TEXT("WeaponComponent: LogicComponent is not valid"));
		return false;
	}

	// Делегируем логику экипировки LogicComponent
	return LogicComponent->EquipWeapon(WeaponAsset);
}

bool UWeaponComponent::UnequipWeapon()
{
	if (!LogicComponent)
	{
		UE_LOG(LogWeaponSystem, Warning, TEXT("WeaponComponent: LogicComponent is not valid"));
		return false;
	}

	// Делегируем логику снятия оружия LogicComponent
	return LogicComponent->UnequipWeapon();
}

bool UWeaponComponent::EquipWeaponByTag(FGameplayTag WeaponTag)
{
	if (!LogicComponent)
	{
		UE_LOG(LogWeaponSystem, Warning, TEXT("WeaponComponent: LogicComponent is not valid"));
		return false;
	}

	// Делегируем логику экипировки по тегу LogicComponent
	return LogicComponent->EquipWeaponByTag(WeaponTag);
}

void UWeaponComponent::UpdateWeaponVisuals(bool bIsVisible)
{
	if (!VisualComponent || !LogicComponent)
	{
		UE_LOG(LogWeaponSystem, Warning, TEXT("WeaponComponent: VisualComponent or LogicComponent is not valid"));
		return;
	}

	// Делегируем обновление визуализации VisualComponent
	VisualComponent->UpdateWeaponVisuals(LogicComponent->CurrentWeapon, bIsVisible);
}

FGameplayTagContainer UWeaponComponent::GetCurrentWeaponTags() const
{
	if (!LogicComponent)
	{
		return FGameplayTagContainer();
	}

	// Делегируем получение тегов оружия LogicComponent
	return LogicComponent->GetCurrentWeaponTags();
}

bool UWeaponComponent::IsWeaponEquipped() const
{
	if (!LogicComponent)
	{
		return false;
	}

	// Делегируем проверку наличия оружия LogicComponent
	return LogicComponent->IsWeaponEquipped();
}

bool UWeaponComponent::HasWeaponWithTag(FGameplayTag Tag) const
{
	if (!LogicComponent)
	{
		return false;
	}

	// Делегируем проверку наличия тега LogicComponent
	return LogicComponent->HasWeaponWithTag(Tag);
}

UWeaponDataAsset* UWeaponComponent::GetCurrentWeapon() const
{
	if (!LogicComponent)
	{
		return nullptr;
	}

	// Возвращаем текущее оружие из LogicComponent
	return LogicComponent->CurrentWeapon;
}

void UWeaponComponent::OnWeaponChanged(UWeaponDataAsset* NewWeapon)
{
	// Обработчик изменения оружия
	// Вызывается из LogicComponent при изменении оружия

	// Обновляем визуальное представление оружия
	if (VisualComponent)
	{
		VisualComponent->UpdateWeaponVisuals(NewWeapon, NewWeapon != nullptr);
		UE_LOG(LogWeaponSystem, Log, TEXT("WeaponComponent: Weapon changed and visuals updated"));
	}

	// Здесь можно добавить дополнительную логику при смене оружия
}

void UWeaponComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Добавлять здесь репликацию свойств, если необходимо
}
