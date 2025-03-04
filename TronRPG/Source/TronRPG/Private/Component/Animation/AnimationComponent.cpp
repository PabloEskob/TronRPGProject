// Tron

#include "Component/Animation/AnimationComponent.h"

#include "Animation/Character/CharacterAnimInstance.h"
#include "Animation/AnimMontage.h"
#include "Animation/AnimInstance.h"

UAnimationComponent::UAnimationComponent()
{
    // Настройки компонента
    PrimaryComponentTick.bCanEverTick = false;
    SetIsReplicatedByDefault(true);
    
    // Инициализация указателей
    SkeletalMeshComponent = nullptr;
    AnimInstance = nullptr;
    CurrentMontage = nullptr;
}

void UAnimationComponent::BeginPlay()
{
    Super::BeginPlay();
    
    // Get SkeletalMeshComponent from owner
    SkeletalMeshComponent = GetOwner()->FindComponentByClass<USkeletalMeshComponent>();
    
    // Get AnimInstance and set up delegates
    if (SkeletalMeshComponent)
    {
        UAnimInstance* BaseAnimInstance = SkeletalMeshComponent->GetAnimInstance();
        if (BaseAnimInstance)
        {
            // Register montage end handler
            BaseAnimInstance->OnMontageEnded.AddDynamic(this, &UAnimationComponent::OnMontageEnded_Native);
            
            // Try to cast to our AnimInstance type
            AnimInstance = Cast<UCharacterAnimInstance>(BaseAnimInstance);
            if (AnimInstance)
            {
                // ADD THIS LINE - Subscribe to OnAnimNotifyBegin from CharacterAnimInstance
                AnimInstance->OnAnimNotifyBegin.AddDynamic(this, &UAnimationComponent::OnMontageNotifyBegin_Native);
                UE_LOG(LogTemp, Log, TEXT("AnimationComponent: Successfully subscribed to CharacterAnimInstance's OnAnimNotifyBegin"));
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("AnimInstance is not UCharacterAnimInstance in %s"), *GetOwner()->GetName());
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("AnimInstance not found in %s"), *GetOwner()->GetName());
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("SkeletalMeshComponent not found in %s"), *GetOwner()->GetName());
    }
}

void UAnimationComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    // Отвязываем делегаты для предотвращения утечек памяти
    if (SkeletalMeshComponent)
    {
        UAnimInstance* BaseAnimInstance = SkeletalMeshComponent->GetAnimInstance();
        if (BaseAnimInstance)
        {
            BaseAnimInstance->OnMontageEnded.RemoveDynamic(this, &UAnimationComponent::OnMontageEnded_Native);
        }
    }
    
    Super::EndPlay(EndPlayReason);
}

void UAnimationComponent::SetMovementBlendSpace(UBlendSpace* Forward, UBlendSpace* Backward)
{
    if (AnimInstance)
    {
        AnimInstance->SetMovementBlendSpace(Forward, Backward);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Cannot set blend space: AnimInstance is invalid"));
    }
}

void UAnimationComponent::TransitionToNewBlendSpace(UBlendSpace* Forward, UBlendSpace* Backward, float Duration)
{
    if (AnimInstance)
    {
        AnimInstance->TransitionToNewBlendSpace(Forward, Backward, Duration);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Cannot transition blend space: AnimInstance is invalid"));
    }
}

float UAnimationComponent::PlayMontage(UAnimMontage* Montage, float PlayRate, FName StartSectionName)
{
    if (!SkeletalMeshComponent || !Montage)
    {
        UE_LOG(LogTemp, Warning, TEXT("Cannot play montage: Invalid parameters"));
        return 0.0f;
    }

    float Duration = 0.0f;
    UAnimInstance* BaseAnimInstance = SkeletalMeshComponent->GetAnimInstance();
    
    if (BaseAnimInstance)
    {
        // Сохраняем указатель на текущий монтаж
        CurrentMontage = Montage;
        
        // Воспроизводим монтаж
        Duration = BaseAnimInstance->Montage_Play(Montage, PlayRate);
        
        // Если указана начальная секция, переходим к ней
        if (StartSectionName != NAME_None)
        {
            BaseAnimInstance->Montage_JumpToSection(StartSectionName, Montage);
        }
        
        UE_LOG(LogTemp, Log, TEXT("Playing montage %s with duration %.2f"), *Montage->GetName(), Duration);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Cannot play montage: AnimInstance is invalid"));
    }
    
    return Duration;
}

void UAnimationComponent::StopMontage(UAnimMontage* Montage, float BlendOutTime)
{
    if (!SkeletalMeshComponent)
    {
        return;
    }

    UAnimInstance* BaseAnimInstance = SkeletalMeshComponent->GetAnimInstance();
    if (!BaseAnimInstance)
    {
        return;
    }

    // Если Montage не указан, используем CurrentMontage
    if (!Montage)
    {
        Montage = CurrentMontage;
    }

    // Останавливаем указанный монтаж
    if (Montage)
    {
        BaseAnimInstance->Montage_Stop(BlendOutTime, Montage);
        
        // Если это был текущий монтаж, сбрасываем указатель
        if (Montage == CurrentMontage)
        {
            CurrentMontage = nullptr;
        }
    }
    else
    {
        // Если Montage все еще не определен, останавливаем все монтажи
        BaseAnimInstance->StopAllMontages(BlendOutTime);
        CurrentMontage = nullptr;
    }
}

bool UAnimationComponent::JumpToMontageSection(FName SectionName)
{
    if (!SkeletalMeshComponent || !CurrentMontage)
    {
        return false;
    }

    UAnimInstance* BaseAnimInstance = SkeletalMeshComponent->GetAnimInstance();
    if (!BaseAnimInstance)
    {
        return false;
    }

    // Проверяем наличие секции в монтаже
    if (CurrentMontage->GetSectionIndex(SectionName) != INDEX_NONE)
    {
        // Переходим к указанной секции
        BaseAnimInstance->Montage_JumpToSection(SectionName, CurrentMontage);
        return true;
    }
    
    return false;
}

bool UAnimationComponent::JumpToNextMontageSection()
{
    if (!SkeletalMeshComponent || !CurrentMontage)
    {
        return false;
    }

    UAnimInstance* BaseAnimInstance = SkeletalMeshComponent->GetAnimInstance();
    if (!BaseAnimInstance)
    {
        return false;
    }

    // Получаем текущую секцию
    FName CurrentSection = BaseAnimInstance->Montage_GetCurrentSection(CurrentMontage);
    
    // Получаем индекс секции
    int32 CurrentSectionIndex = CurrentMontage->GetSectionIndex(CurrentSection);
    
    // Получаем следующую секцию (с проверкой на выход за границы массива)
    if (CurrentSectionIndex != INDEX_NONE && CurrentSectionIndex < CurrentMontage->CompositeSections.Num() - 1)
    {
        // Есть следующая секция, переходим к ней
        FName NextSection = CurrentMontage->CompositeSections[CurrentSectionIndex + 1].SectionName;
        BaseAnimInstance->Montage_JumpToSection(NextSection, CurrentMontage);
        return true;
    }
    else if (CurrentMontage->CompositeSections.Num() > 0)
    {
        // Если мы находимся в последней секции или не в составной секции,
        // то переходим к первой секции для зацикливания
        FName FirstSection = CurrentMontage->CompositeSections[0].SectionName;
        if (FirstSection != CurrentSection)
        {
            BaseAnimInstance->Montage_JumpToSection(FirstSection, CurrentMontage);
            return true;
        }
    }
    
    return false;
}


bool UAnimationComponent::IsPlayingMontage(UAnimMontage* Montage) const
{
    if (!SkeletalMeshComponent)
    {
        return false;
    }

    UAnimInstance* BaseAnimInstance = SkeletalMeshComponent->GetAnimInstance();
    if (!BaseAnimInstance)
    {
        return false;
    }

    // Если Montage не указан, проверяем любой монтаж
    if (!Montage)
    {
        return BaseAnimInstance->IsAnyMontagePlaying();
    }
    
    // Проверяем указанный монтаж
    return BaseAnimInstance->Montage_IsPlaying(Montage);
}

float UAnimationComponent::GetMontageRemainingTime(UAnimMontage* Montage) const
{
    if (!SkeletalMeshComponent)
    {
        return 0.0f;
    }

    UAnimInstance* BaseAnimInstance = SkeletalMeshComponent->GetAnimInstance();
    if (!BaseAnimInstance)
    {
        return 0.0f;
    }

    // Если Montage не указан, используем текущий
    if (!Montage)
    {
        Montage = CurrentMontage;
    }

    // Проверяем, воспроизводится ли монтаж
    if (Montage && BaseAnimInstance->IsPlayingSlotAnimation(Montage, Montage->GetFName()))
    {
        // Получаем полную длительность монтажа
        float SequenceLength = Montage->GetPlayLength();
        
        // Получаем текущую позицию воспроизведения
        float CurrentPosition = BaseAnimInstance->Montage_GetPosition(Montage);
        
        // Вычисляем оставшееся время
        return SequenceLength - CurrentPosition;
    }
    
    return 0.0f;
}

void UAnimationComponent::OnMontageEnded_Native(UAnimMontage* Montage, bool bInterrupted)
{
    // Если закончился текущий монтаж, сбрасываем указатель
    if (Montage == CurrentMontage)
    {
        CurrentMontage = nullptr;
    }
    
    // Транслируем событие через делегат
    OnMontageEnded.Broadcast(Montage, bInterrupted);
}

void UAnimationComponent::OnMontageNotifyBegin_Native(FName NotifyName)
{
    // Транслируем событие через делегат
    OnMontageNotifyBegin.Broadcast(NotifyName);
}