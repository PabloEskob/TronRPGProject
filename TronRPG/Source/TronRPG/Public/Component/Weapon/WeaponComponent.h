#pragma once

#include "CoreMinimal.h"
#include "Component/DI/DIAwareComponent.h"
#include "GameplayTagContainer.h"
#include "WeaponComponent.generated.h"

class UWeaponDataAsset;
class UTronRpgAbilitySystemComponent;
class UAnimationComponent;

// Перечисление состояний экипировки оружия
UENUM(BlueprintType)
enum class EWeaponEquipState : uint8
{
    None,
    Equipping,
    Equipped,
    Unequipping
};

// Делегаты для событий оружия
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponEquipStateChanged, EWeaponEquipState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponChanged, UWeaponDataAsset*, NewWeapon);

/**
 * Компонент для управления оружием персонажа
 * Отвечает за экипировку, снятие и управление визуализацией оружия
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TRONRPG_API UWeaponComponent : public UDIAwareComponent
{
    GENERATED_BODY()

public:
    UWeaponComponent();

    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    /**
     * Текущее экипированное оружие
     */
    UPROPERTY(ReplicatedUsing=OnRep_CurrentWeapon, BlueprintReadOnly, Category = "Weapon")
    UWeaponDataAsset* CurrentWeapon;

    /**
     * Меш-компонент для оружия в основной руке
     */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    UStaticMeshComponent* MainHandMeshComponent;

    /**
     * Меш-компонент для оружия в дополнительной руке
     */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
    UStaticMeshComponent* OffHandMeshComponent;

    /**
     * Текущее состояние экипировки оружия
     */
    UPROPERTY(BlueprintReadOnly, Category = "Weapon")
    EWeaponEquipState EquipState = EWeaponEquipState::None;

    /**
     * Экипировать указанное оружие
     */
    UFUNCTION(BlueprintCallable, Category = "Weapon")
    bool EquipWeapon(UWeaponDataAsset* WeaponAsset);

    /**
     * Снять текущее оружие
     */
    UFUNCTION(BlueprintCallable, Category = "Weapon")
    bool UnequipWeapon();

    /**
     * Экипировать оружие по тегу
     */
    UFUNCTION(BlueprintCallable, Category = "Weapon")
    bool EquipWeaponByTag(FGameplayTag WeaponTag);

    /**
     * Обновить визуальное представление оружия
     */
    UFUNCTION(BlueprintCallable, Category = "Weapon")
    void UpdateWeaponVisuals(bool bIsVisible);

    /**
     * Получить теги текущего оружия
     */
    UFUNCTION(BlueprintPure, Category = "Weapon")
    FGameplayTagContainer GetCurrentWeaponTags() const;

    /**
     * Проверить, экипировано ли оружие
     */
    UFUNCTION(BlueprintPure, Category = "Weapon")
    bool IsWeaponEquipped() const { return CurrentWeapon != nullptr && EquipState == EWeaponEquipState::Equipped; }

    /**
     * Проверить, соответствует ли текущее оружие указанному тегу
     */
    UFUNCTION(BlueprintPure, Category = "Weapon")
    bool HasWeaponWithTag(FGameplayTag Tag) const;

    // Делегаты событий
    UPROPERTY(BlueprintAssignable, Category = "Weapon|Events")
    FOnWeaponEquipStateChanged OnWeaponEquipStateChanged;

    UPROPERTY(BlueprintAssignable, Category = "Weapon|Events")
    FOnWeaponChanged OnWeaponChanged;

protected:
    // Инициализация зависимостей через DI
    virtual void InitializeDependencies() override;
    
    // Кэшированные зависимости
    UPROPERTY()
    UTronRpgAbilitySystemComponent* AbilitySystemComponent;
    
    UPROPERTY()
    UAnimationComponent* AnimationComponent;

    /**
     * История последних экипированных оружий
     */
    UPROPERTY()
    TArray<UWeaponDataAsset*> WeaponHistory;

    /**
     * Максимальный размер истории оружия
     */
    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    int32 MaxWeaponHistorySize = 5;

    /**
     * Добавить оружие в историю
     */
    void AddToWeaponHistory(UWeaponDataAsset* WeaponAsset);

    /**
     * Обновить теги геймплея, связанные с оружием
     */
    void UpdateGameplayTags(UWeaponDataAsset* WeaponAsset, bool bAdd);

    /**
     * Обработчик изменения текущего оружия (для репликации)
     */
    UFUNCTION()
    void OnRep_CurrentWeapon();

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    /**
     * Получить Asset Manager для оружия
     */
    class UTronRpgWeaponAssetManager* GetWeaponAssetManager() const;

    // Изменить состояние экипировки
    void SetEquipState(EWeaponEquipState NewState);

    // Обработчики событий анимации
    UFUNCTION()
    void OnEquipAnimationEnded(UAnimMontage* Montage, bool bInterrupted);

    UFUNCTION()
    void OnUnequipAnimationEnded(UAnimMontage* Montage, bool bInterrupted);

    // Завершение процессов экипировки/снятия
    UFUNCTION()
    void FinishEquipping();

    UFUNCTION()
    void FinishUnequipping();
};