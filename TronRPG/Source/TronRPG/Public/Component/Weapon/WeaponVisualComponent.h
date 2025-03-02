// Tron

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponVisualComponent.generated.h"

class UWeaponDataAsset;

/**
 * Компонент для визуального представления оружия
 * Отвечает только за обновление мешей и визуальных эффектов оружия
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TRONRPG_API UWeaponVisualComponent : public UActorComponent
{
	GENERATED_BODY()
    
public:
	UWeaponVisualComponent();
    
	virtual void BeginPlay() override;
    
	/**
	 * Обновить визуальное представление оружия
	 * @param WeaponAsset Ассет оружия для отображения
	 * @param bIsVisible Должно ли оружие быть видимым
	 */
	UFUNCTION(BlueprintCallable, Category = "Weapon|Visual")
	void UpdateWeaponVisuals(UWeaponDataAsset* WeaponAsset, bool bIsVisible);
    
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
};