#include "Object/ServiceLocator.h"

UServiceLocator* UServiceLocator::Instance = nullptr;

UServiceLocator& UServiceLocator::Get()
{
	if (!Instance)
	{
		Instance = NewObject<UServiceLocator>();
		Instance->AddToRoot(); // Предотвращаем сборку мусора
		UE_LOG(LogTemp, Log, TEXT("ServiceLocator initialized"));
	}
	return *Instance;
}

void UServiceLocator::ClearServices()
{
	UE_LOG(LogTemp, Log, TEXT("Clearing ServiceLocator registry"));
	ServiceRegistry.Empty();

	// Если нужно полностью освободить синглтон, можно добавить:
	// if (Instance)
	// {
	//     Instance->RemoveFromRoot();
	//     Instance = nullptr;
	// }
}
