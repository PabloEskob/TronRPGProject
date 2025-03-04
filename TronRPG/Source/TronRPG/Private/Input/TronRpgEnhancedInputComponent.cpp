#include "Input/TronRpgEnhancedInputComponent.h"
#include "Component/Input/AbilityInputComponent.h"
#include "Character/TronRpgBaseCharacter.h"
#include "Component/TronRpgComboComponent.h"
#include "GAS/TronRpgAbilitySystemComponent.h"
#include "Object/GameplayTagsLibrary.h"
#include "GameplayAbility/MeleeAttackAbility.h"
#include "Task/AbilityTask_WaitForComboInput.h"

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
    
    // Получаем AbilitySystemComponent
    UAbilitySystemComponent* ASC = OwningCharacter->GetAbilitySystemComponent();
    if (!ASC)
    {
        return;
    }
    
    // ШАГИ ИСПРАВЛЕНИЯ:
    // 1. Сначала проверяем, есть ли активная способность атаки, независимо от тега окна комбо
    TArray<FGameplayAbilitySpec*> ActiveAbilities;
    ASC->GetActivatableGameplayAbilitySpecsByAllMatchingTags(
        FGameplayTagContainer(TAG_Ability_Combat_Melee), 
        ActiveAbilities
    );
    
    bool bFoundActiveAttackAbility = false;

    UTronRpgComboComponent* ComboComp = OwningCharacter->GetComboComponent();
    
    // Проверяем все активные способности
    for (FGameplayAbilitySpec* AbilitySpec : ActiveAbilities)
    {
        if (AbilitySpec && AbilitySpec->IsActive())
        {
            bFoundActiveAttackAbility = true;
            UMeleeAttackAbility* MeleeAbility = Cast<UMeleeAttackAbility>(AbilitySpec->GetPrimaryInstance());
            
            // 2. Если это способность ближнего боя и есть открытое окно комбо (через ComboInputTask)
            if (MeleeAbility && ComboComp->ComboInputTask)
            {
                // Вызываем обработку комбо-ввода
                ComboComp->ComboInputTask->ProcessComboInput();
                UE_LOG(LogTemp, Log, TEXT("TronRpgEnhancedInputComponent: Processed combo input for ability %s"), 
                       *MeleeAbility->GetName());
                return;
            }
            else if (MeleeAbility)
            {
                // 3. Если есть активная способность атаки, но нет ComboInputTask,
                // логируем это как информацию для отладки
                UE_LOG(LogTemp, Verbose, TEXT("TronRpgEnhancedInputComponent: Found active MeleeAbility but no ComboInputTask"));
                
                // Не активируем новую способность, так как уже есть активная
                return;
            }
        }
    }
    
    // 4. Если нет активной способности атаки, только тогда активируем новую
    if (!bFoundActiveAttackAbility)
    {
        UE_LOG(LogTemp, Log, TEXT("TronRpgEnhancedInputComponent: No active attack ability, activating new one"));
        TryActivateAbilityByTag(TAG_Ability_Combat_Melee);
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("TronRpgEnhancedInputComponent: Found active attack ability but couldn't process combo input"));
    }
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
    
    // НОВЫЙ КОД: Проверяем, нет ли уже активной способности с этим тегом
    bool bHasActiveAbilityWithTag = false;
    TArray<FGameplayAbilitySpec*> MatchingAbilities;
    ASC->GetActivatableGameplayAbilitySpecsByAllMatchingTags(FGameplayTagContainer(AbilityTag), MatchingAbilities);
    
    for (FGameplayAbilitySpec* AbilitySpec : MatchingAbilities)
    {
        if (AbilitySpec && AbilitySpec->IsActive())
        {
            bHasActiveAbilityWithTag = true;
            UE_LOG(LogTemp, Verbose, TEXT("TronRpgEnhancedInputComponent: Ability with tag %s is already active"),
                   *AbilityTag.ToString());
            break;
        }
    }
    
    // Если способность уже активна, не пытаемся активировать её снова
    if (bHasActiveAbilityWithTag)
    {
        return true; // Возвращаем true, так как с точки зрения вызывающего кода, всё в порядке
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