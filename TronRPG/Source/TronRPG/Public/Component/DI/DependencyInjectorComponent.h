// Tron

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DependencyInjectorComponent.generated.h"

class UGameManager;
class UUIManager;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TRONRPG_API UDependencyInjectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UDependencyInjectorComponent();

	UFUNCTION(BlueprintCallable, Category = "Dependencies")
	void InjectDependencies(UGameManager* InGameManager, UUIManager* InUIManager);

	UFUNCTION(BlueprintCallable, Category = "Dependencies")
	UGameManager* GetGameManager() const { return GameManager; }

	UFUNCTION(BlueprintCallable, Category = "Dependencies")
	UUIManager* GetUIManager() const { return UIManager; }

protected:
	UPROPERTY(Transient, BlueprintReadOnly, Category = "Managers")
	UGameManager* GameManager;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Managers")
	UUIManager* UIManager;
};
