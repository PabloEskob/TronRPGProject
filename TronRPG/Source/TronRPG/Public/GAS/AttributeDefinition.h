#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "AttributeDefinition.generated.h"

/**
 * Определение атрибута персонажа
 * Содержит настройки для инициализации и ограничений атрибута
 */
UCLASS(BlueprintType)
class TRONRPG_API UAttributeDefinition : public UPrimaryDataAsset
{
    GENERATED_BODY()
    
public:
    // Название атрибута
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute")
    FText AttributeName;
    
    // Имя атрибута для идентификации
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute")
    FName AttributeId;
    
    // Описание атрибута
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute", meta = (MultiLine = true))
    FText Description;
    
    // Теги атрибута для категоризации
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute")
    FGameplayTagContainer AttributeTags;
    
    // Значение по умолчанию
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute")
    float BaseValue = 0.0f;
    
    // Минимальное значение атрибута
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute")
    float MinValue = 0.0f;
    
    // Максимальное значение атрибута
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute")
    float MaxValue = 100.0f;
    
    // Ограничивать ли значение атрибута
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute")
    bool bClampValue = true;
    
    // Является ли атрибут процентным (0-1)
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute")
    bool bIsPercentage = false;
    
    // Является ли атрибут "текущим значением" с соответствующим "максимальным значением"
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute")
    bool bIsCurrentValue = false;
    
    // Связанный атрибут максимального значения (если bIsCurrentValue = true)
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attribute", meta = (EditCondition = "bIsCurrentValue"))
    FName MaxValueAttributeId;
    
    // Получить FPrimaryAssetId для этого ассета
    virtual FPrimaryAssetId GetPrimaryAssetId() const override
    {
        return FPrimaryAssetId("AttributeDefinition", AttributeId);
    }
};