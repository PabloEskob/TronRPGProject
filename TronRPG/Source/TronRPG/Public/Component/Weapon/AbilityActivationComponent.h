// Tron

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbilityActivationComponent.generated.h"


struct FInputActionValue;
struct FGameplayTag;
class UAbilitySystemComponent;

UCLASS()
class TRONRPG_API UAbilityActivationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	void Initialize(UAbilitySystemComponent* InASC);
	bool ActivateAbilityByTag(const FGameplayTag& AbilityTag);
	void HandleInput(const FInputActionValue& Value, FName ActionName);

	UPROPERTY()
	TMap<FName, FGameplayTag> InputNameToAbilityTagMap;
};
