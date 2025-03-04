#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DependencyInjectorComponent.generated.h"

/**
 * Компонент для внедрения зависимостей между системами
 * Обеспечивает слабую связность компонентов и уменьшает необходимость в Cast
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TRONRPG_API UDependencyInjectorComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UDependencyInjectorComponent();

    /**
     * Зарегистрировать компонент в реестре
     * @param ComponentClass Класс компонента 
     * @param Component Экземпляр компонента
     */
    UFUNCTION(BlueprintCallable, Category = "Dependencies")
    void RegisterComponent(TSubclassOf<UActorComponent> ComponentClass, UActorComponent* Component);
    
    /**
     * Зарегистрировать объект в реестре
     * @param ObjectClass Класс объекта
     * @param Object Экземпляр объекта
     */
    UFUNCTION(BlueprintCallable, Category = "Dependencies")
    void RegisterObject(TSubclassOf<UObject> ObjectClass, UObject* Object);
    
    /**
     * Зарегистрировать интерфейс в реестре
     * @param InterfaceClass Класс интерфейса
     * @param InterfaceInstance Экземпляр, реализующий интерфейс
     */
    UFUNCTION(BlueprintCallable, Category = "Dependencies")
    void RegisterInterface(TSubclassOf<UInterface> InterfaceClass, UObject* InterfaceInstance);
    
    /**
     * Получить компонент по классу
     * @param ComponentClass Класс компонента
     * @return Экземпляр компонента или nullptr
     */
    UFUNCTION(BlueprintCallable, Category = "Dependencies")
    UActorComponent* GetComponent(TSubclassOf<UActorComponent> ComponentClass) const;
    
    /**
     * Получить объект по классу
     * @param ObjectClass Класс объекта
     * @return Экземпляр объекта или nullptr
     */
    UFUNCTION(BlueprintCallable, Category = "Dependencies")
    UObject* GetObject(TSubclassOf<UObject> ObjectClass) const;
    
    /**
     * Получить объект, реализующий интерфейс
     * @param InterfaceClass Класс интерфейса
     * @return Объект, реализующий интерфейс, или nullptr
     */
    UFUNCTION(BlueprintCallable, Category = "Dependencies")
    UObject* GetInterfaceObject(TSubclassOf<UInterface> InterfaceClass) const;
    
    /**
     * Получить типизированный компонент
     * @tparam T Тип компонента
     * @return Компонент указанного типа или nullptr
     */
    template<typename T>
    T* GetTypedComponent() const
    {
        return Cast<T>(GetComponent(T::StaticClass()));
    }
    
    /**
     * Получить типизированный объект
     * @tparam T Тип объекта
     * @return Объект указанного типа или nullptr
     */
    template<typename T>
    T* GetTypedObject() const
    {
        return Cast<T>(GetObject(T::StaticClass()));
    }
    
    /**
     * Получить объект, реализующий указанный интерфейс
     * @tparam T Тип интерфейса
     * @return Объект, реализующий интерфейс, или nullptr
     */
    template<typename T>
    UObject* GetInterfaceImplementation() const
    {
        static_assert(TIsDerivedFrom<T, UInterface>::Value, "T must be derived from UInterface");
        return GetInterfaceObject(T::StaticClass());
    }

private:
    // Реестр зарегистрированных компонентов
    UPROPERTY()
    TMap<UClass*, UActorComponent*> ComponentRegistry;
    
    // Реестр зарегистрированных объектов
    UPROPERTY()
    TMap<UClass*, UObject*> ObjectRegistry;
    
    // Реестр зарегистрированных интерфейсов
    UPROPERTY()
    TMap<UClass*, UObject*> InterfaceRegistry;
};