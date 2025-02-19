// Tron

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameplayTagsSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class TRONRPG_API UGameplayTagsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	bool AreTagsInitialized() const;
};
