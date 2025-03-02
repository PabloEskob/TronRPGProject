#include "Component/Weapon/WeaponLogicComponent.h"
#include "Component/Weapon/WeaponVisualComponent.h"
#include "GAS/TronRpgAbilitySystemComponent.h"
#include "GameInstanceSubsystem/WeaponAsset/TronRpgWeaponAssetManager.h"
#include "Data/Weapon/WeaponDataAsset.h"
#include "Net/UnrealNetwork.h"
#include "Object/GameplayTagsLibrary.h"
#include "TronRPG/TronRPG.h"

UWeaponLogicComponent::UWeaponLogicComponent()
{
   PrimaryComponentTick.bCanEverTick = false;
   SetIsReplicatedByDefault(true);
   
   CurrentWeapon = nullptr;
   AbilitySystemComponent = nullptr;
   VisualComponent = nullptr;
}

void UWeaponLogicComponent::BeginPlay()
{
   Super::BeginPlay();
   
   // Получаем AbilitySystemComponent из владельца
   AbilitySystemComponent = GetOwner()->FindComponentByClass<UTronRpgAbilitySystemComponent>();
   
   // Получаем компонент визуализации, если еще не установлен
   if (!VisualComponent)
   {
       VisualComponent = GetOwner()->FindComponentByClass<UWeaponVisualComponent>();
   }
   
   // Инициализация истории оружия
   WeaponHistory.Empty(MaxWeaponHistorySize);
}

bool UWeaponLogicComponent::EquipWeapon(UWeaponDataAsset* WeaponAsset)
{
   // Проверка валидности параметров
   if (!WeaponAsset || CurrentWeapon == WeaponAsset)
   {
       UE_LOG(LogWeaponSystem, Warning, TEXT("Invalid weapon asset or already equipped: %s"),
              WeaponAsset ? *WeaponAsset->GetName() : TEXT("nullptr"));
       return false;
   }
   
   // Скрываем текущее оружие
   if (VisualComponent)
   {
       VisualComponent->UpdateWeaponVisuals(WeaponAsset, false);
   }
   
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
   
   // Уведомляем о смене оружия
   OnWeaponChanged.Broadcast(CurrentWeapon);
   
   UE_LOG(LogWeaponSystem, Log, TEXT("Weapon equipped: %s"), *WeaponAsset->GetName());
   
   return true;
}

bool UWeaponLogicComponent::UnequipWeapon()
{
   if (!CurrentWeapon)
   {
       UE_LOG(LogWeaponSystem, Warning, TEXT("Attempted to unequip weapon when none is equipped"));
       return false;
   }
   
   // Удаляем теги текущего оружия
   UpdateGameplayTags(CurrentWeapon, false);
   
   // Скрываем оружие
   if (VisualComponent)
   {
       VisualComponent->UpdateWeaponVisuals(nullptr, false);
   }
   
   UE_LOG(LogWeaponSystem, Log, TEXT("Weapon unequipped: %s"), *CurrentWeapon->GetName());
   
   // Сохраняем ссылку на оружие для уведомления
   UWeaponDataAsset* PreviousWeapon = CurrentWeapon;
   
   // Сбрасываем указатель текущего оружия
   CurrentWeapon = nullptr;
   
   // Уведомляем о смене оружия
   OnWeaponChanged.Broadcast(nullptr);
   
   return true;
}

bool UWeaponLogicComponent::EquipWeaponByTag(FGameplayTag WeaponTag)
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

FGameplayTagContainer UWeaponLogicComponent::GetCurrentWeaponTags() const
{
   return CurrentWeapon ? CurrentWeapon->WeaponTags : FGameplayTagContainer();
}

bool UWeaponLogicComponent::HasWeaponWithTag(FGameplayTag Tag) const
{
   return CurrentWeapon && CurrentWeapon->WeaponTags.HasTag(Tag);
}

void UWeaponLogicComponent::AddToWeaponHistory(UWeaponDataAsset* WeaponAsset)
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

void UWeaponLogicComponent::UpdateGameplayTags(UWeaponDataAsset* WeaponAsset, bool bAdd)
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

void UWeaponLogicComponent::OnRep_CurrentWeapon()
{
   // Обновляем визуализацию при репликации
   if (VisualComponent)
   {
       VisualComponent->UpdateWeaponVisuals(CurrentWeapon, CurrentWeapon != nullptr);
   }
   
   // Обновляем теги
   if (AbilitySystemComponent)
   {
       // Сначала очищаем все теги оружия
       AbilitySystemComponent->RemoveLooseGameplayTag(TAG_State_Equipment_Equipped);
       
       // Затем обновляем теги для текущего оружия
       if (CurrentWeapon)
       {
           UpdateGameplayTags(CurrentWeapon, true);
       }
   }
   
   // Уведомляем о смене оружия
   OnWeaponChanged.Broadcast(CurrentWeapon);
}

UTronRpgWeaponAssetManager* UWeaponLogicComponent::GetWeaponAssetManager() const
{
   return GetOwner()->GetGameInstance() ? GetOwner()->GetGameInstance()->GetSubsystem<UTronRpgWeaponAssetManager>() : nullptr;
}

void UWeaponLogicComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
   Super::GetLifetimeReplicatedProps(OutLifetimeProps);
   
   // Репликация текущего оружия
   DOREPLIFETIME(UWeaponLogicComponent, CurrentWeapon);
}