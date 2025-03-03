#include "Input/TronRpgEnhancedInputComponent.h"
#include "Component/Input/AbilityInputComponent.h"
#include "Character/TronRpgBaseCharacter.h"
#include "Component/TronRpgComboComponent.h"
#include "GAS/TronRpgAbilitySystemComponent.h"
#include "Object/GameplayTagsLibrary.h"

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
    if (!ComboComp)
    {
        UE_LOG(LogTemp, Warning, TEXT("TronRpgEnhancedInputComponent: Failed to find combo component"));
        return;
    }
    
    // Если окно комбо открыто, обрабатываем ввод
    if (ComboComp->IsComboWindowOpen())
    {
        // Обрабатываем ввод комбо
        ComboComp->ProcessComboInput();
        
        // Активируем способность атаки через AbilitySystemComponent
        TryActivateAbilityByTag(TAG_Ability_Combat_Melee);
        
        UE_LOG(LogTemp, Log, TEXT("TronRpgEnhancedInputComponent: Processed combo input, current combo: %d"), 
               ComboComp->GetCurrentComboCount());
    }
    else
    {
        UE_LOG(LogTemp, Verbose, TEXT("TronRpgEnhancedInputComponent: Combo window not open, ignoring input"));
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