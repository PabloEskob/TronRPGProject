#include "Component/Weapon/WeaponComponent.h"

#include "Component/Animation/AnimationComponent.h"
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
    EquipState = EWeaponEquipState::None;
}

void UWeaponComponent::BeginPlay()
{
    Super::BeginPlay();
    
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

void UWeaponComponent::InitializeDependencies()
{
    // Получаем зависимости через DI
    AbilitySystemComponent = GetDependency<UTronRpgAbilitySystemComponent>();
    AnimationComponent = GetDependency<UAnimationComponent>();
    
    // Проверяем, что получили все необходимые зависимости
    if (!AbilitySystemComponent)
    {
        UE_LOG(LogWeaponSystem, Warning, TEXT("%s: Failed to get AbilitySystemComponent dependency"), *GetName());
    }
    
    if (!AnimationComponent)
    {
        UE_LOG(LogWeaponSystem, Warning, TEXT("%s: Failed to get AnimationComponent dependency"), *GetName());
    }
}

void UWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // Регулярные проверки или обновления состояния оружия можно реализовать здесь
    // Например, проверка условий повреждения оружия, износа и т.д.
}

void UWeaponComponent::SetEquipState(EWeaponEquipState NewState)
{
    if (EquipState != NewState)
    {
        EWeaponEquipState OldState = EquipState;
        EquipState = NewState;

        // Обработка изменения состояния
        switch (NewState)
        {
        case EWeaponEquipState::Equipping:
            // Добавляем тег состояния экипировки для блокировки атак
            if (AbilitySystemComponent)
            {
                AbilitySystemComponent->AddLooseGameplayTag(TAG_State_Equipment_Changing);
            }
            break;

        case EWeaponEquipState::Equipped:
            // Завершаем процесс экипировки
            if (CurrentWeapon && AbilitySystemComponent)
            {
                // Добавляем теги оружия
                UpdateGameplayTags(CurrentWeapon, true);
            }
            break;

        case EWeaponEquipState::Unequipping:
            // Добавляем тег состояния экипировки для блокировки атак
            if (AbilitySystemComponent)
            {
                AbilitySystemComponent->AddLooseGameplayTag(TAG_State_Equipment_Changing);
            }
            break;

        case EWeaponEquipState::None:
            // Завершаем процесс снятия
            if (OldState == EWeaponEquipState::Unequipping && AbilitySystemComponent)
            {
                // Удаляем теги текущего оружия
                if (CurrentWeapon)
                {
                    UpdateGameplayTags(CurrentWeapon, false);
                }
                CurrentWeapon = nullptr;
            }

            // Удаляем тег состояния экипировки
            if (AbilitySystemComponent)
            {
                AbilitySystemComponent->RemoveLooseGameplayTag(TAG_State_Equipment_Changing);
            }
            break;
        }

        // Вызываем делегат
        OnWeaponEquipStateChanged.Broadcast(NewState);
    }
}

bool UWeaponComponent::EquipWeapon(UWeaponDataAsset* WeaponAsset)
{
    // Проверка валидности параметров и состояния
    if (!WeaponAsset || CurrentWeapon == WeaponAsset || 
        EquipState == EWeaponEquipState::Equipping || 
        EquipState == EWeaponEquipState::Unequipping)
    {
        UE_LOG(LogWeaponSystem, Warning, TEXT("Invalid weapon asset, already equipped, or equipment change in progress"));
        return false;
    }

    // Скрываем старое оружие
    UpdateWeaponVisuals(false);

    // Сохраняем предыдущее оружие и уведомляем об изменении
    UWeaponDataAsset* PreviousWeapon = CurrentWeapon;
    CurrentWeapon = WeaponAsset;
    OnWeaponChanged.Broadcast(CurrentWeapon);

    // Добавляем в историю
    AddToWeaponHistory(WeaponAsset);

    // Переходим в состояние экипировки
    SetEquipState(EWeaponEquipState::Equipping);

    // Воспроизведение анимации экипировки
    if (AnimationComponent && WeaponAsset->EquipMontage.Get())
    {
        // Подписываемся на завершение анимации
        AnimationComponent->OnMontageEnded.AddDynamic(this, &UWeaponComponent::OnEquipAnimationEnded);
        AnimationComponent->PlayMontage(WeaponAsset->EquipMontage.Get());
    }
    else
    {
        // Если нет анимации, сразу завершаем экипировку
        FinishEquipping();
    }

    UE_LOG(LogWeaponSystem, Log, TEXT("Weapon equip started: %s"), *WeaponAsset->GetName());
    return true;
}

bool UWeaponComponent::UnequipWeapon()
{
    if (!CurrentWeapon || EquipState == EWeaponEquipState::Unequipping || EquipState == EWeaponEquipState::Equipping)
    {
        UE_LOG(LogWeaponSystem, Warning, TEXT("No weapon equipped or equipment change in progress"));
        return false;
    }
    
    // Переходим в состояние снятия оружия
    SetEquipState(EWeaponEquipState::Unequipping);
    
    // Воспроизводим анимацию снятия оружия
    if (AnimationComponent && CurrentWeapon->UnequipMontage.Get())
    {
        // Подписываемся на завершение анимации
        AnimationComponent->OnMontageEnded.AddDynamic(this, &UWeaponComponent::OnUnequipAnimationEnded);
        AnimationComponent->PlayMontage(CurrentWeapon->UnequipMontage.Get());
    }
    else
    {
        // Если нет анимации, сразу завершаем процесс
        UpdateWeaponVisuals(false);
        FinishUnequipping();
    }
    
    UE_LOG(LogWeaponSystem, Log, TEXT("Weapon unequip started: %s"), *CurrentWeapon->GetName());
    
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
    UpdateWeaponVisuals(EquipState == EWeaponEquipState::Equipped);

    // Обновляем теги
    if (AbilitySystemComponent)
    {
        // Сначала очищаем все теги оружия
        AbilitySystemComponent->RemoveLooseGameplayTag(TAG_State_Equipment_Changing);

        // Затем обновляем теги для текущего оружия
        if (CurrentWeapon && EquipState == EWeaponEquipState::Equipped)
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

void UWeaponComponent::OnEquipAnimationEnded(UAnimMontage* Montage, bool bInterrupted)
{
    if (AnimationComponent)
    {
        AnimationComponent->OnMontageEnded.RemoveDynamic(this, &UWeaponComponent::OnEquipAnimationEnded);
    }
    
    // Завершаем процесс экипировки
    FinishEquipping();
}

void UWeaponComponent::OnUnequipAnimationEnded(UAnimMontage* Montage, bool bInterrupted)
{
    if (AnimationComponent)
    {
        AnimationComponent->OnMontageEnded.RemoveDynamic(this, &UWeaponComponent::OnUnequipAnimationEnded);
    }
    
    // Завершаем процесс снятия оружия
    FinishUnequipping();
}

void UWeaponComponent::FinishEquipping()
{
    // Переходим в состояние "оружие экипировано"
    SetEquipState(EWeaponEquipState::Equipped);
    
    UE_LOG(LogWeaponSystem, Log, TEXT("Weapon equip process completed for: %s"), 
           CurrentWeapon ? *CurrentWeapon->GetName() : TEXT("nullptr"));
}

void UWeaponComponent::FinishUnequipping()
{
    // Переходим в состояние "без оружия"
    SetEquipState(EWeaponEquipState::None);
    
    UE_LOG(LogWeaponSystem, Log, TEXT("Weapon unequip process completed"));
}