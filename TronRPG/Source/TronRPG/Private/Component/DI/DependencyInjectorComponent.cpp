// Tron

#include "Component/DI/DependencyInjectorComponent.h"

UDependencyInjectorComponent::UDependencyInjectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UDependencyInjectorComponent::InjectDependencies(UGameManager* InGameManager, UUIManager* InUIManager)
{
	GameManager = InGameManager;
	UIManager = InUIManager;

	// Проверка на валидность зависимостей
	ensureMsgf(GameManager, TEXT("GameManager is null in DependencyInjectorComponent"));
	ensureMsgf(UIManager, TEXT("UIManager is null in DependencyInjectorComponent"));
}
