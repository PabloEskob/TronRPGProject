// Tron

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Engine/DataAsset.h"
#include "TronAbilitySet.generated.h"

USTRUCT(BlueprintType)
struct FTronAbilityInfo
{
	GENERATED_BODY()

	/** Тег, используемый для идентификации способности */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
	FGameplayTag AbilityTag;

	/** Класс способности */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
	TSubclassOf<UGameplayAbility> AbilityClass;

	/** Уровень способности */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability", meta = (ClampMin = "1"))
	int32 AbilityLevel = 1;

	/** Имя способности для удобства редактирования */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
	FString TagName;
};

/**
 * 
 */
UCLASS()
class TRONRPG_API UTronAbilitySet : public UPrimaryDataAsset
{
	GENERATED_BODY()

protected:
	/** Массив с информацией о способностях */
	UPROPERTY(EditAnywhere, meta = (TitleProperty = "TagName"), BlueprintReadWrite, Category = "Tron | Abilities")
	TArray<FTronAbilityInfo> Abilities;

public:
	/**
	 * Добавляет или изменяет способность в наборе
	 */
	void AddOrModifyAbility(const FGameplayTag& AbilityTag, TSubclassOf<UGameplayAbility> AbilityClass, int32 Level = 1,
	                        const FString& Name = TEXT(""));

	/**
	 * Получает информацию о способности по тегу
	 * @return true если способность найдена
	 */
	bool GetAbilityByTag(const FGameplayTag& AbilityTag, FTronAbilityInfo& OutAbilityInfo) const;

	/**
	 * Получает все способности в наборе
	 */
	void GetAllAbilities(TArray<FTronAbilityInfo>& OutAbilities) const
	{
		OutAbilities = Abilities;
	}
};
