#pragma once

#include "CoreMinimal.h"
#include "ServiceLocator.generated.h"

/**
 * Центральный реестр сервисов для приложения
 * Реализует паттерн "Сервис локатор" для глобального доступа к сервисам
 */
UCLASS()
class TRONRPG_API UServiceLocator : public UObject
{
	GENERATED_BODY()

public:
	/**
	 * Получить единственный экземпляр локатора
	 * @return Ссылка на экземпляр
	 */
	static UServiceLocator& Get();
    
	/**
	 * Зарегистрировать сервис
	 * @param Service Экземпляр сервиса
	 */
	template<typename T>
	void RegisterService(T* Service)
	{
		if (Service)
		{
			ServiceRegistry.Add(T::StaticClass(), Service);
			UE_LOG(LogTemp, Log, TEXT("Registered service: %s"), *T::StaticClass()->GetName());
		}
	}
    
	/**
	 * Получить сервис по типу
	 * @return Экземпляр сервиса или nullptr
	 */
	template<typename T>
	T* GetService() const
	{
		UObject* const* FoundService = ServiceRegistry.Find(T::StaticClass());
		if (FoundService)
		{
			return Cast<T>(*FoundService);
		}
		return nullptr;
	}
    
	/**
	 * Очистить реестр сервисов
	 * Используется при завершении работы
	 */
	void ClearServices();

private:
	// Синглтон-экземпляр
	static UServiceLocator* Instance;
    
	// Реестр сервисов
	UPROPERTY()
	TMap<UClass*, UObject*> ServiceRegistry;
};