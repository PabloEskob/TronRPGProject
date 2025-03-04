#include "Input/TronRpgEnhancedInputComponent.h"
#include "Component/Input/AbilityInputComponent.h"
#include "Character/TronRpgBaseCharacter.h"
#include "Component/TronRpgComboComponent.h"
#include "GAS/TronRpgAbilitySystemComponent.h"
#include "Object/GameplayTagsLibrary.h"
#include "GameplayAbility/MeleeAttackAbility.h"

UTronRpgEnhancedInputComponent::UTronRpgEnhancedInputComponent()
{
    // Инициализация по умолчанию
    AbilityInputComponent = nullptr;
    OwningCharacter = nullptr;
}

void UTronRpgEnhancedInputComponent::SetAbilityInputComponent(UAbilityInputComponent* InAbilityInputComponent)
{
    AbilityInputComponent = InAbilityInputComponent;
    UpdateCachedReferences();
}

void UTronRpgEnhancedInputComponent::ProcessComboInput(const FInputActionValue& InputActionValue)
{
    // Обновляем кэшированные ссылки, если необходимо
    if (!OwningCharacter)
    {
        UpdateCachedReferences();
        if (!OwningCharacter)
        {
            UE_LOG(LogTemp, Warning, TEXT("TronRpgEnhancedInputComponent: Failed to find owning character for combo input"));
            return;
        }
    }
    
    // Получаем компонент комбо
    UTronRpgComboComponent* ComboComp = OwningCharacter->GetComboComponent();
    if (!ComboComp || !ComboComp->IsComboWindowOpen())
    {
        return;
    }
    
    // Получаем AbilitySystemComponent
    UAbilitySystemComponent* ASC = OwningCharacter->GetAbilitySystemComponent();
    if (!ASC)
    {
        return;
    }
    
    // Ищем активную способность атаки
    TArray<FGameplayAbilitySpec*> ActiveAbilities;
    ASC->GetActivatableGameplayAbilitySpecsByAllMatchingTags(
        FGameplayTagContainer(TAG_Ability_Combat_Melee), 
        ActiveAbilities
    );
    
    // Если нашли активную способность, продолжаем комбо
    for (FGameplayAbilitySpec* AbilitySpec : ActiveAbilities)
    {
        if (AbilitySpec && AbilitySpec->IsActive())
        {
            UMeleeAttackAbility* MeleeAbility = Cast<UMeleeAttackAbility>(AbilitySpec->GetPrimaryInstance());
            if (MeleeAbility)
            {
                // Обрабатываем ввод комбо в компоненте
                ComboComp->ProcessComboInput();
                
                // Продолжаем комбо в способности
                MeleeAbility->ContinueComboAttack();
                
                UE_LOG(LogTemp, Log, TEXT("Combo continued, new count: %d"), 
                       ComboComp->GetCurrentComboCount());
                return;
            }
        }
    }
    
    // Если активной атаки не нашли, пытаемся активировать новую
    UE_LOG(LogTemp, Log, TEXT("No active melee ability found, trying to activate new one"));
    TryActivateAbilityByTag(TAG_Ability_Combat_Melee);
}

bool UTronRpgEnhancedInputComponent::TryActivateAbilityByTag(const FGameplayTag& AbilityTag)
{
    // Обновляем кэшированные ссылки, если необходимо
    if (!OwningCharacter)
    {
        UpdateCachedReferences();
        if (!OwningCharacter)
        {
            return false;
        }
    }
    
    // Получаем AbilitySystemComponent напрямую
    UAbilitySystemComponent* ASC = OwningCharacter->GetAbilitySystemComponent();
    if (!ASC)
    {
        return false;
    }
    
    // Создаем контейнер тегов для активации
    FGameplayTagContainer AbilityTags;
    AbilityTags.AddTag(AbilityTag);
    
    // Пытаемся активировать способность
    bool bActivated = ASC->TryActivateAbilitiesByTag(AbilityTags);
    
    if (bActivated)
    {
        UE_LOG(LogTemp, Log, TEXT("TronRpgEnhancedInputComponent: Successfully activated ability with tag %s"),
               *AbilityTag.ToString());
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("TronRpgEnhancedInputComponent: Failed to activate ability with tag %s"),
               *AbilityTag.ToString());
    }
    
    return bActivated;
}

ATronRpgBaseCharacter* UTronRpgEnhancedInputComponent::GetOwningCharacter() const
{
    return OwningCharacter;
}

UTronRpgComboComponent* UTronRpgEnhancedInputComponent::GetOwnerComboComponent() const
{
    return OwningCharacter ? OwningCharacter->GetComboComponent() : nullptr;
}

void UTronRpgEnhancedInputComponent::UpdateCachedReferences()
{
    // Получаем владельца компонента
    AActor* Owner = GetOwner();
    if (Owner)
    {
        OwningCharacter = Cast<ATronRpgBaseCharacter>(Owner);
        
        if (!OwningCharacter)
        {
            // Проверяем, не является ли владелец контроллером
            if (AController* Controller = Cast<AController>(Owner))
            {
                OwningCharacter = Cast<ATronRpgBaseCharacter>(Controller->GetPawn());
            }
        }
    }
    
    if (!OwningCharacter)
    {
        UE_LOG(LogTemp, Warning, TEXT("TronRpgEnhancedInputComponent: Failed to cache character reference"));
    }
}