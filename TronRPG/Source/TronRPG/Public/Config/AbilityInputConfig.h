// Tron

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "InputAction.h"
#include "Engine/DataAsset.h"
#include "Struct/Input/AbilityInputBinding.h"
#include "AbilityInputConfig.generated.h"


/**
 * Конфигурационный ассет для определения привязок ввода к способностям
 * Позволяет настраивать, какие геймплей-теги активируются при нажатии каких кнопок
 */
UCLASS(BlueprintType)
class TRONRPG_API UAbilityInputConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	/** Массив привязок действий ввода к тегам способностей */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta=(TitleProperty="BindingName"))
	TArray<FAbilityInputBinding> AbilityBindings;

	/** Найти привязку по тегу способности */
	UFUNCTION(BlueprintCallable, Category = "Input Configuration")
	FAbilityInputBinding FindBindingByTag(FGameplayTag AbilityTag) const;

	/** Найти привязку по действию ввода */
	UFUNCTION(BlueprintCallable, Category = "Input Configuration")
	FAbilityInputBinding FindBindingByInputAction(const UInputAction* InputAction) const;
    
	/** Получить все привязки */
	UFUNCTION(BlueprintCallable, Category = "Input Configuration")
	const TArray<FAbilityInputBinding>& GetAllBindings() const { return AbilityBindings; }
};
