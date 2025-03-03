#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "GameplayTagContainer.h"
#include "TronRpgEnhancedInputComponent.generated.h"

class UAbilityInputComponent;
class ATronRpgBaseCharacter;
class UTronRpgComboComponent;

/**
 * Расширенный компонент ввода для TronRPG
 * Добавляет функциональность для обработки комбо-атак и взаимодействия с AbilityInputComponent
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
    
	/** Обновить кэшированные ссылки */
	void UpdateCachedReferences();
};