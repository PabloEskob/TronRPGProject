// Tron

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CharacterComponentProvider.generated.h"

class UTronRpgAbilitySystemComponent;
class UAnimationComponent;
class UWeaponComponent;

UINTERFACE(MinimalAPI, BlueprintType)
class UCharacterComponentProvider : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TRONRPG_API ICharacterComponentProvider
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// Получить компонент оружия
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Components")
	UWeaponComponent* GetWeaponComponent() ;

	// Получить компонент анимации
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Components")
	UAnimationComponent* GetAnimationComponent() ;

	// Получить компонент системы способностей
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Components")
	UTronRpgAbilitySystemComponent* GetAbilitySystemComponent() ;
};
