#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameMessageBus.generated.h"

/**
 * Типы сообщений в игре
 */
UENUM(BlueprintType)
enum class EGameMessageType : uint8
{
    Combat,        // Сообщения о боевых действиях
    Inventory,     // Сообщения об инвентаре
    Character,     // Сообщения о персонаже
    Animation,     // Сообщения об анимации
    Weapon,        // Сообщения об оружии
    Ability,       // Сообщения о способностях
    UI,            // Сообщения для пользовательского интерфейса
    Game           // Общие игровые сообщения
};

/**
 * Структура игрового сообщения
 */
USTRUCT(BlueprintType)
struct FGameMessage
{
    GENERATED_BODY()
    
    // Тип сообщения
    UPROPERTY(BlueprintReadWrite, Category = "Message")
    EGameMessageType MessageType = EGameMessageType::Game;
    
    // Идентификатор сообщения
    UPROPERTY(BlueprintReadWrite, Category = "Message")
    FName MessageID;
    
    // Отправитель сообщения
    UPROPERTY(BlueprintReadWrite, Category = "Message")
    UObject* Sender = nullptr;
    
    // Данные сообщения (опционально)
    UPROPERTY(BlueprintReadWrite, Category = "Message")
    UObject* MessageData = nullptr;
    
    // Дополнительные теги сообщения
    UPROPERTY(BlueprintReadWrite, Category = "Message")
    FGameplayTagContainer MessageTags;
    
    // Конструктор для удобства
    FGameMessage() {}
    
    FGameMessage(EGameMessageType InType, FName InID, UObject* InSender = nullptr, UObject* InData = nullptr)
        : MessageType(InType), MessageID(InID), Sender(InSender), MessageData(InData) {}
};

/**
 * Делегат для получения сообщений
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameMessageReceived, const FGameMessage&, Message);

/**
 * Интерфейс для обработчиков сообщений
 */
UINTERFACE(MinimalAPI, BlueprintType)
class UGameMessageHandlerInterface : public UInterface
{
    GENERATED_BODY()
};

class IGameMessageHandlerInterface
{
    GENERATED_BODY()
    
public:
    // Метод обработки сообщения
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Messaging")
    void HandleGameMessage(const FGameMessage& Message);
};

/**
 * Система для отправки и получения сообщений между компонентами
 * Обеспечивает слабое связывание между системами
 */
UCLASS()
class TRONRPG_API UGameMessageBus : public UGameInstanceSubsystem
{
    GENERATED_BODY()
    
public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;
    
    /**
     * Отправить сообщение
     * @param Message Сообщение для отправки
     */
    UFUNCTION(BlueprintCallable, Category = "Messaging")
    void SendMessage(const FGameMessage& Message);
    
    /**
     * Отправить сообщение (упрощенная версия)
     * @param MessageType Тип сообщения
     * @param MessageID Идентификатор сообщения
     * @param Sender Отправитель сообщения
     * @param MessageData Данные сообщения
     */
    UFUNCTION(BlueprintCallable, Category = "Messaging")
    void SendSimpleMessage(EGameMessageType MessageType, FName MessageID, UObject* Sender = nullptr, UObject* MessageData = nullptr);
    
    /**
     * Регистрация для получения сообщений определенного типа
     * @param MessageType Тип сообщения для подписки
     * @param Handler Объект, реализующий интерфейс IGameMessageHandlerInterface
     */
    UFUNCTION(BlueprintCallable, Category = "Messaging")
    void SubscribeToMessages(EGameMessageType MessageType, UObject* Handler);
    
    /**
     * Отписка от получения сообщений определенного типа
     * @param MessageType Тип сообщения для отписки
     * @param Handler Объект, ранее подписанный на сообщения
     */
    UFUNCTION(BlueprintCallable, Category = "Messaging")
    void UnsubscribeFromMessages(EGameMessageType MessageType, UObject* Handler);
    
    /**
     * Получить экземпляр UGameMessageBus из контекста
     * @param WorldContextObject Объект с контекстом мира
     * @return Экземпляр UGameMessageBus или nullptr, если не найден
     */
    UFUNCTION(BlueprintPure, Category = "Messaging", meta = (WorldContext = "WorldContextObject"))
    static UGameMessageBus* GetGameMessageBus(const UObject* WorldContextObject);
    
protected:
    // Карта типов сообщений на соответствующие делегаты для нативного кода
    TMap<EGameMessageType, FOnGameMessageReceived> MessageListeners;
    
    // Карта типов сообщений на списки обработчиков для Blueprint
    TMap<EGameMessageType, TArray<TWeakObjectPtr<UObject>>> MessageHandlers;
};