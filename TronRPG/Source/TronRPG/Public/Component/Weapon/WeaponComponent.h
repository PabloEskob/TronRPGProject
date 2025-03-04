// Tron

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Component/Animation/AnimationComponent.h"
#include "WeaponComponent.generated.h"

class UWeaponDataAsset;
class UTronRpgAbilitySystemComponent;

/**
 * Компонент для управления оружием персонажа
 * Отвечает за экипировку, снятие и управление визуализацией оружия
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TRONRPG_API UWeaponComponent : public UActorComponent
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
	 * Экипировать указанное оружие
	 * @param WeaponAsset Ассет оружия для экипировки
	 * @return true если экипировка прошла успешно
	 */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	bool EquipWeapon(UWeaponDataAsset* WeaponAsset);

	/**
	 * Снять текущее оружие
	 * @return true если оружие было снято успешно
	 */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	bool UnequipWeapon();

	/**
	 * Экипировать оружие по тегу
	 * @param WeaponTag Геймплей-тег оружия
	 * @return true если оружие было найдено и экипировано
	 */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	bool EquipWeaponByTag(FGameplayTag WeaponTag);

	/**
	 * Обновить визуальное представление оружия
	 * @param bIsVisible Флаг видимости оружия
	 */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void UpdateWeaponVisuals(bool bIsVisible);

	/**
	 * Получить теги текущего оружия
	 * @return FGameplayTagContainer с тегами оружия
	 */
	UFUNCTION(BlueprintPure, Category = "Weapon")
	FGameplayTagContainer GetCurrentWeaponTags() const;

	/**
	 * Проверить, экипировано ли оружие
	 * @return true если оружие экипировано
	 */
	UFUNCTION(BlueprintPure, Category = "Weapon")
	bool IsWeaponEquipped() const { return CurrentWeapon != nullptr; }

	/**
	 * Проверить, соответствует ли текущее оружие указанному тегу
	 * @param Tag Тег для проверки
	 * @return true если текущее оружие имеет указанный тег
	 */
	UFUNCTION(BlueprintPure, Category = "Weapon")
	bool HasWeaponWithTag(FGameplayTag Tag) const;

	UPROPERTY(BlueprintReadOnly, Category = "Weapon")
	bool bIsChangingEquipment = false;

protected:
	/**
	 * Компонент системы способностей для управления тегами
	 */
	UPROPERTY()
	UTronRpgAbilitySystemComponent* AbilitySystemComponent;

	/**
	 * История последних экипированных оружий
	 * Используется для быстрого переключения между оружием
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
	 * @param WeaponAsset Оружие для добавления
	 */
	void AddToWeaponHistory(UWeaponDataAsset* WeaponAsset);

	/**
	 * Обновить теги геймплея, связанные с оружием
	 * @param WeaponAsset Оружие для обновления тегов
	 * @param bAdd Добавить или удалить теги
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
	 * @return Указатель на Asset Manager
	 */
	class UTronRpgWeaponAssetManager* GetWeaponAssetManager() const;

	UPROPERTY()
	UAnimationComponent* AnimationComponent;

	// Добавить в публичный раздел:
	UFUNCTION()
	void OnEquipAnimationEnded(UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION()
	void OnUnequipAnimationEnded(UAnimMontage* Montage, bool bInterrupted);

	// Добавить в публичный раздел:
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void FinishEquipping();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void FinishUnequipping();
};
