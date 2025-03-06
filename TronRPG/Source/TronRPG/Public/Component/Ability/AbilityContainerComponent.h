// Tron

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbilityContainerComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TRONRPG_API UAbilityContainerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAbilityContainerComponent();

	virtual void BeginPlay() override;
};
