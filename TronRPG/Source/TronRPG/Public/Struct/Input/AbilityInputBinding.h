// Tron

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "AbilityInputBinding.generated.h"


class UInputAction;

/**
 * Универсальная структура для связывания InputAction с тегом способности
 * Используется как в конфигурации, так и в компоненте
 */
USTRUCT(BlueprintType)
struct TRONRPG_API FAbilityInputBinding
{
	GENERATED_BODY()

public:
	/** Название привязки для удобства настройки */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	FString BindingName;

	/** Действие ввода (Enhanced Input) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> InputAction = nullptr;

	/** Тег, который идентифицирует способность */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	FGameplayTag AbilityTag;

	/** Отменять ли способность при отпускании кнопки */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	bool bCancelOnRelease = false;

	/** Приоритет привязки (более высокий приоритет перезаписывает более низкий) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input", meta = (ClampMin = "0"))
	int32 Priority = 0;

	/** Описание привязки для удобства использования */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	FText Description;
};
