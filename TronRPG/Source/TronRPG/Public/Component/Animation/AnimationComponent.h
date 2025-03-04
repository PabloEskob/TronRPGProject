// Tron

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AnimationComponent.generated.h"

class UBlendSpace;
class UAnimMontage;
class UCharacterAnimInstance;

/**
 * Делегат, вызываемый при завершении проигрывания Montage
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAnimMontageEnded, UAnimMontage*, Montage, bool, bInterrupted);

/**
 * Делегат, вызываемый при достижении определенной точки в Montage
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAnimMontageNotifyBegin, FName, NotifyName);

/**
 * Компонент для управления анимацией персонажа
 * Инкапсулирует взаимодействие с AnimInstance и предоставляет высокоуровневый API
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TRONRPG_API UAnimationComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UAnimationComponent();
    
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

    /**
     * Установить blend space для движения без плавного перехода
     * @param Forward Blend space для движения вперед
     * @param Backward Blend space для движения назад
     */
    UFUNCTION(BlueprintCallable, Category = "Animation")
    void SetMovementBlendSpace(UBlendSpace* Forward, UBlendSpace* Backward);

    /**
     * Плавный переход к новому blend space
     * @param Forward Blend space для движения вперед
     * @param Backward Blend space для движения назад
     * @param Duration Длительность перехода в секундах
     */
    UFUNCTION(BlueprintCallable, Category = "Animation")
    void TransitionToNewBlendSpace(UBlendSpace* Forward, UBlendSpace* Backward, float Duration);

    /**
     * Воспроизвести анимационный монтаж
     * @param Montage Монтаж для воспроизведения
     * @param PlayRate Скорость воспроизведения
     * @param StartSectionName Название начальной секции
     * @return Длительность монтажа с учетом скорости воспроизведения
     */
    UFUNCTION(BlueprintCallable, Category = "Animation")
    float PlayMontage(UAnimMontage* Montage, float PlayRate = 1.0f, FName StartSectionName = NAME_None);

    /**
     * Остановить воспроизведение указанного монтажа
     * @param Montage Монтаж для остановки (если nullptr, будет остановлен текущий монтаж)
     * @param BlendOutTime Время смешивания при остановке
     */
    UFUNCTION(BlueprintCallable, Category = "Animation")
    void StopMontage(UAnimMontage* Montage = nullptr, float BlendOutTime = 0.25f);

    /**
     * Перейти к указанной секции монтажа
     * @param SectionName Название секции
     * @return true, если переход выполнен успешно
     */
    UFUNCTION(BlueprintCallable, Category = "Animation")
    bool JumpToMontageSection(FName SectionName);

    /**
     * Перейти к следующей секции монтажа
     * @return true, если переход выполнен успешно
     */
    UFUNCTION(BlueprintCallable, Category = "Animation")
    bool JumpToNextMontageSection();

    /**
     * Проверить, воспроизводится ли указанный монтаж
     * @param Montage Монтаж для проверки (если nullptr, проверяется любой монтаж)
     * @return true, если монтаж воспроизводится
     */
    UFUNCTION(BlueprintPure, Category = "Animation")
    bool IsPlayingMontage(UAnimMontage* Montage = nullptr) const;

    /**
     * Получить оставшееся время воспроизведения монтажа
     * @param Montage Монтаж для проверки (если nullptr, используется текущий монтаж)
     * @return Оставшееся время в секундах
     */
    UFUNCTION(BlueprintPure, Category = "Animation")
    float GetMontageRemainingTime(UAnimMontage* Montage = nullptr) const;
 
    /**
     * Получить AnimInstance
     * @return Указатель на CharacterAnimInstance
     */
    UFUNCTION(BlueprintPure, Category = "Animation")
    UCharacterAnimInstance* GetAnimInstance() const { return AnimInstance; }

    /**
     * Событие окончания воспроизведения Montage
     */
    UPROPERTY(BlueprintAssignable, Category = "Animation|Delegates")
    FOnAnimMontageEnded OnMontageEnded;

    /**
     * Событие достижения Notify в Montage
     */
    UPROPERTY(BlueprintAssignable, Category = "Animation|Delegates")
    FOnAnimMontageNotifyBegin OnMontageNotifyBegin;

protected:
    /** Компонент скелетного меша персонажа */
    UPROPERTY()
    USkeletalMeshComponent* SkeletalMeshComponent;

    /** Анимационный инстанс персонажа */
    UPROPERTY()
    UCharacterAnimInstance* AnimInstance;

    /** Текущий воспроизводимый монтаж */
    UPROPERTY()
    UAnimMontage* CurrentMontage;

    /**
     * Обработчик завершения монтажа
     * @param Montage Завершившийся монтаж
     * @param bInterrupted Флаг прерывания монтажа
     */
    UFUNCTION()
    void OnMontageEnded_Native(UAnimMontage* Montage, bool bInterrupted);

    /**
     * Обработчик Notify в монтаже
     * @param NotifyName Имя Notify
     */
    UFUNCTION()
    void OnMontageNotifyBegin_Native(FName NotifyName);
};