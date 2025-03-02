#include "GameInstanceSubsystem/GameMessageBus/GameMessageBus.h"
#include "Kismet/GameplayStatics.h"

void UGameMessageBus::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    
    // Инициализация карты слушателей
    for (int32 i = 0; i < static_cast<int32>(EGameMessageType::Game) + 1; ++i)
    {
        EGameMessageType Type = static_cast<EGameMessageType>(i);
        MessageListeners.Add(Type, FOnGameMessageReceived());
        MessageHandlers.Add(Type, TArray<TWeakObjectPtr<UObject>>());
    }
    
    UE_LOG(LogTemp, Log, TEXT("GameMessageBus initialized"));
}

void UGameMessageBus::Deinitialize()
{
    // Очищаем все делегаты
    for (auto& Pair : MessageListeners)
    {
        Pair.Value.Clear();
    }
    
    MessageListeners.Empty();
    MessageHandlers.Empty();
    
    Super::Deinitialize();
    
    UE_LOG(LogTemp, Log, TEXT("GameMessageBus deinitialized"));
}

void UGameMessageBus::SendMessage(const FGameMessage& Message)
{
    // Получаем делегат для данного типа сообщения
    FOnGameMessageReceived* Listeners = MessageListeners.Find(Message.MessageType);
    
    if (Listeners && Listeners->IsBound())
    {
        // Вызываем делегат, передавая сообщение
        Listeners->Broadcast(Message);
        
        UE_LOG(LogTemp, Verbose, TEXT("GameMessageBus: Message sent - Type: %d, ID: %s"), 
               static_cast<int32>(Message.MessageType), *Message.MessageID.ToString());
    }
    
    // Получаем обработчики Blueprint для данного типа сообщения
    TArray<TWeakObjectPtr<UObject>>* Handlers = MessageHandlers.Find(Message.MessageType);
    
    if (Handlers)
    {
        // Проходим по всем обработчикам
        for (auto It = Handlers->CreateIterator(); It; ++It)
        {
            TWeakObjectPtr<UObject> HandlerPtr = *It;
            
            if (HandlerPtr.IsValid())
            {
                UObject* Handler = HandlerPtr.Get();
                
                // Проверяем, реализует ли объект интерфейс IGameMessageHandlerInterface
                if (Handler->GetClass()->ImplementsInterface(UGameMessageHandlerInterface::StaticClass()))
                {
                    // Вызываем метод обработки сообщения
                    IGameMessageHandlerInterface::Execute_HandleGameMessage(Handler, Message);
                }
                else
                {
                    // Удаляем невалидные обработчики
                    It.RemoveCurrent();
                }
            }
            else
            {
                // Удаляем невалидные обработчики
                It.RemoveCurrent();
            }
        }
    }
}

void UGameMessageBus::SendSimpleMessage(EGameMessageType MessageType, FName MessageID, UObject* Sender, UObject* MessageData)
{
    // Создаем сообщение и отправляем его
    FGameMessage Message(MessageType, MessageID, Sender, MessageData);
    SendMessage(Message);
}

void UGameMessageBus::SubscribeToMessages(EGameMessageType MessageType, UObject* Handler)
{
    if (!Handler)
    {
        UE_LOG(LogTemp, Warning, TEXT("GameMessageBus: Cannot subscribe null handler"));
        return;
    }
    
    // Проверяем, реализует ли объект интерфейс IGameMessageHandlerInterface
    if (!Handler->GetClass()->ImplementsInterface(UGameMessageHandlerInterface::StaticClass()))
    {
        UE_LOG(LogTemp, Warning, TEXT("GameMessageBus: Handler does not implement IGameMessageHandlerInterface"));
        return;
    }
    
    // Получаем список обработчиков для данного типа сообщения
    TArray<TWeakObjectPtr<UObject>>* Handlers = MessageHandlers.Find(MessageType);
    
    if (Handlers)
    {
        // Добавляем обработчик, если он еще не добавлен
        TWeakObjectPtr<UObject> HandlerPtr(Handler);
        
        if (!Handlers->Contains(HandlerPtr))
        {
            Handlers->Add(HandlerPtr);
            
            UE_LOG(LogTemp, Log, TEXT("GameMessageBus: Subscribed handler %s to messages of type %d, total handlers: %d"), 
                   *Handler->GetName(), static_cast<int32>(MessageType), Handlers->Num());
        }
    }
}

void UGameMessageBus::UnsubscribeFromMessages(EGameMessageType MessageType, UObject* Handler)
{
    if (!Handler)
    {
        return;
    }
    
    // Получаем список обработчиков для данного типа сообщения
    TArray<TWeakObjectPtr<UObject>>* Handlers = MessageHandlers.Find(MessageType);
    
    if (Handlers)
    {
        // Удаляем обработчик
        TWeakObjectPtr<UObject> HandlerPtr(Handler);
        
        if (Handlers->Remove(HandlerPtr) > 0)
        {
            UE_LOG(LogTemp, Log, TEXT("GameMessageBus: Unsubscribed handler %s from messages of type %d, remaining handlers: %d"), 
                   *Handler->GetName(), static_cast<int32>(MessageType), Handlers->Num());
        }
    }
}

UGameMessageBus* UGameMessageBus::GetGameMessageBus(const UObject* WorldContextObject)
{
    if (!WorldContextObject)
    {
        return nullptr;
    }
    
    UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(WorldContextObject);
    if (!GameInstance)
    {
        return nullptr;
    }
    
    return GameInstance->GetSubsystem<UGameMessageBus>();
}