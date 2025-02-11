#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameplayTagsLibrary.generated.h"

/**
 * Библиотека статических тегов для проекта TronRPG.
 * Здесь можно определить все нужные Gameplay Tags, чтобы использовать их по всему проекту.
 */
UCLASS()
class UGameplayTagsLibrary : public UObject
{
	GENERATED_BODY()

public:
	// Пример тега для melee-атаки
	static const FGameplayTag Attack_Melee;

	// Здесь можно добавить и другие теги, например:
	// static const FGameplayTag Spell_MagicOrb;
	// static const FGameplayTag State_Stunned;
	// static const FGameplayTag State_Attacking;
};
