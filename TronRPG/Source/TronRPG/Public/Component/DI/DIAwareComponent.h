#pragma once

#include "CoreMinimal.h"
#include "DependencyInjectorComponent.h"
#include "Components/ActorComponent.h"
#include "DIAwareComponent.generated.h"

class UDependencyInjectorComponent;

/**
 * Базовый класс для компонентов, поддерживающих внедрение зависимостей
 * Автоматически получает ссылку на DependencyInjector владельца
 */
UCLASS(Abstract)
class TRONRPG_API UDIAwareComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UDIAwareComponent();

	virtual void BeginPlay() override;

protected:
	// Инжектор зависимостей
	UPROPERTY()
	UDependencyInjectorComponent* DependencyInjector;

	/**
	 * Получить зависимость через инжектор
	 * @tparam T Тип зависимости 
	 * @return Зависимость или nullptr
	 */
	template <typename T>
	T* GetDependency() const
	{
		return DependencyInjector ? DependencyInjector->GetTypedComponent<T>() : nullptr;
	}

	/**
	 * Получить сервис
	 * @tparam T Тип сервиса
	 * @return Сервис или nullptr
	 */
	template <typename T>
	T* GetService() const
	{
		return DependencyInjector ? DependencyInjector->GetTypedObject<T>(): nullptr;
	}

	/**
	 * Получить объект, реализующий интерфейс
	 * @tparam T Тип интерфейса
	 * @return Объект, реализующий интерфейс, или nullptr
	 */
	template <typename T>
	UObject* GetInterfaceImplementation() const
	{
		return DependencyInjector ? DependencyInjector->GetInterfaceImplementation<T>() : nullptr;
	}

	/**
	 * Хук для инициализации зависимостей
	 * Вызывается после получения DependencyInjector
	 */
	virtual void InitializeDependencies();
};
