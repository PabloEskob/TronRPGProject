#include "Component/DI/DependencyInjectorComponent.h"

UDependencyInjectorComponent::UDependencyInjectorComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UDependencyInjectorComponent::RegisterComponent(TSubclassOf<UActorComponent> ComponentClass, UActorComponent* Component)
{
    if (ComponentClass && Component)
    {
        ComponentRegistry.Add(ComponentClass, Component);
        UE_LOG(LogTemp, Verbose, TEXT("Registered component of class %s"), *ComponentClass->GetName());
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to register component: %s"), 
               Component ? TEXT("Invalid class") : TEXT("Invalid component"));
    }
}

void UDependencyInjectorComponent::RegisterObject(TSubclassOf<UObject> ObjectClass, UObject* Object)
{
    if (ObjectClass && Object)
    {
        ObjectRegistry.Add(ObjectClass, Object);
        UE_LOG(LogTemp, Verbose, TEXT("Registered object of class %s"), *ObjectClass->GetName());
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to register object: %s"), 
               Object ? TEXT("Invalid class") : TEXT("Invalid object"));
    }
}

void UDependencyInjectorComponent::RegisterInterface(TSubclassOf<UInterface> InterfaceClass, UObject* InterfaceInstance)
{
    if (InterfaceClass && InterfaceInstance)
    {
        // Проверяем, реализует ли объект указанный интерфейс
        if (InterfaceInstance->GetClass()->ImplementsInterface(InterfaceClass))
        {
            InterfaceRegistry.Add(InterfaceClass, InterfaceInstance);
            UE_LOG(LogTemp, Verbose, TEXT("Registered interface implementation %s for %s"), 
                   *InterfaceInstance->GetClass()->GetName(), *InterfaceClass->GetName());
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Object %s does not implement interface %s"), 
                   *InterfaceInstance->GetClass()->GetName(), *InterfaceClass->GetName());
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to register interface: %s"), 
               InterfaceInstance ? TEXT("Invalid interface class") : TEXT("Invalid instance"));
    }
}

UActorComponent* UDependencyInjectorComponent::GetComponent(TSubclassOf<UActorComponent> ComponentClass) const
{
    if (ComponentClass)
    {
        UActorComponent* const* FoundComponent = ComponentRegistry.Find(ComponentClass);
        if (FoundComponent)
        {
            return *FoundComponent;
        }
    }
    return nullptr;
}

UObject* UDependencyInjectorComponent::GetObject(TSubclassOf<UObject> ObjectClass) const
{
    if (ObjectClass)
    {
        UObject* const* FoundObject = ObjectRegistry.Find(ObjectClass);
        if (FoundObject)
        {
            return *FoundObject;
        }
    }
    return nullptr;
}

UObject* UDependencyInjectorComponent::GetInterfaceObject(TSubclassOf<UInterface> InterfaceClass) const
{
    if (InterfaceClass)
    {
        UObject* const* FoundObject = InterfaceRegistry.Find(InterfaceClass);
        if (FoundObject)
        {
            return *FoundObject;
        }
    }
    return nullptr;
}