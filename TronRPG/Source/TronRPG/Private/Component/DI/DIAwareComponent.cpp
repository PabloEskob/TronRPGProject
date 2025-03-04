#include "Component/DI/DIAwareComponent.h"
#include "Component/DI/DependencyInjectorComponent.h"

UDIAwareComponent::UDIAwareComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UDIAwareComponent::BeginPlay()
{
	Super::BeginPlay();
    
	// Получаем DependencyInjector от владельца
	AActor* Owner = GetOwner();
	if (Owner)
	{
		DependencyInjector = Owner->FindComponentByClass<UDependencyInjectorComponent>();
        
		// Если нашли инжектор, инициализируем зависимости
		if (DependencyInjector)
		{
			// Регистрируем себя в инжекторе
			DependencyInjector->RegisterComponent(GetClass(), this);
            
			// Инициализируем зависимости
			InitializeDependencies();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("%s: DependencyInjector not found on owner %s"), 
				   *GetName(), *Owner->GetName());
		}
	}
}

void UDIAwareComponent::InitializeDependencies()
{
	// Пустая реализация для переопределения в дочерних классах
}