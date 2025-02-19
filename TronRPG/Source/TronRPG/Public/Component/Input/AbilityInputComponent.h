// Tron

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbilityInputComponent.generated.h"

class UInputComponent;
class UTronRpgAbilitySystemComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TRONRPG_API UAbilityInputComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAbilityInputComponent();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetupPlayerInput(UInputComponent* PlayerInputComponent);

protected:
	UPROPERTY(Transient)
	UTronRpgAbilitySystemComponent* AbilitySystemComponent;
};
