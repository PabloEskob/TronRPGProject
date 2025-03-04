#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"
#include "AnimatableCharacter.generated.h"

class UCharacterMovementComponent;
class UAbilitySystemComponent;

UINTERFACE(MinimalAPI, Blueprintable)
class UAnimatableCharacter : public UInterface
{
	GENERATED_BODY()
};

/**
 * Интерфейс для персонажей с поддержкой анимации
 * Предоставляет доступ к компонентам движения и системы способностей
 */
class TRONRPG_API IAnimatableCharacter
{
	GENERATED_BODY()

public:
	/**
	 * Получить компонент движения персонажа
	 * @return Указатель на компонент движения
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Animation")
	UCharacterMovementComponent* GetCharacterMovement() const;
    
	/**
	 * Получить компонент системы способностей
	 * @return Указатель на AbilitySystemComponent
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Animation")
	UAbilitySystemComponent* GetAbilitySystemComponent() const;
    
	/**
	 * Получить теги состояния персонажа
	 * @return Контейнер с тегами
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Animation")
	FGameplayTagContainer GetCurrentGameplayTags() const;
};