#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "GameplayTagContainer.h"
#include "InputActionValue.h"
#include "TronRpgEnhancedInputComponent.generated.h"

class UAbilityInputComponent;
class ATronRpgBaseCharacter;
class UTronRpgComboComponent;
class UGameplayAbility;

/**
 * Расширенный компонент ввода для TronRPG
 * Добавляет функциональность для обработки комбо-атак и взаимодействия с системой способностей (GAS)
 */
UCLASS()
class TRONRPG_API UTronRpgEnhancedInputComponent : public UEnhancedInputComponent
{
    GENERATED_BODY()
    
public:
    UTronRpgEnhancedInputComponent();
    
    /**
     * Установить ссылку на компонент обработки ввода способностей
     * @param InAbilityInputComponent Указатель на AbilityInputComponent
     */
    void SetAbilityInputComponent(UAbilityInputComponent* InAbilityInputComponent);
    
    /**
     * Обработать ввод для комбо-атаки
     * Находит активную способность атаки и вызывает в ней метод продолжения комбо
     * @param InputActionValue Значение действия ввода
     */
    void ProcessComboInput(const FInputActionValue& InputActionValue);
    
    /**
     * Активировать способность с указанным тегом
     * @param AbilityTag Тег активируемой способности
     * @return true, если активация прошла успешно
     */
    bool TryActivateAbilityByTag(const FGameplayTag& AbilityTag);
    
    /**
     * Получить текущего владельца (персонажа)
     * @return Указатель на базового персонажа
     */
    ATronRpgBaseCharacter* GetOwningCharacter() const;
    
    /**
     * Получить компонент комбо у владельца
     * @return Указатель на компонент комбо
     */
    UTronRpgComboComponent* GetOwnerComboComponent() const;
    
private:
    /** Компонент обработки ввода способностей */
    UPROPERTY()
    UAbilityInputComponent* AbilityInputComponent;
    
    /** Кэшированная ссылка на владельца */
    UPROPERTY()
    ATronRpgBaseCharacter* OwningCharacter;
    
    /** 
     * Обновить кэшированные ссылки на компоненты и владельца
     * Ищет владельца компонента и сохраняет ссылку на него для более эффективного доступа
     */
    void UpdateCachedReferences();
};