// Tron
#include "GameInstanceSubsystem/GameplayTags/GameplayTagsSubsystem.h"
#include "Object/GameplayTagsLibrary.h"

void UGameplayTagsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	GameplayTags::InitializeTags();
	UE_LOG(LogTemp, Log, TEXT("Gameplay Tags Subsystem initialized."));
}

void UGameplayTagsSubsystem::Deinitialize()
{
	Super::Deinitialize();
	UE_LOG(LogTemp, Log, TEXT("Gameplay Tags Subsystem deinitialized."));
}

bool UGameplayTagsSubsystem::AreTagsInitialized() const
{
	return GameplayTags::AreTagsInitialized();
}
