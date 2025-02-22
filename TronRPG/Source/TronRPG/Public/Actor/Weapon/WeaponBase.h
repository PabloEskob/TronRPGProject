// Tron
#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Data/Weapon/WeaponDataAsset.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

class UWeaponStateComponent;
class UGameplayEffect;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWeaponStateChanged, AWeaponBase*, Weapon, const FGameplayTagContainer&, StateTags);

UCLASS()
class TRONRPG_API AWeaponBase : public AActor
{
    GENERATED_BODY()

public:
    AWeaponBase();

    // Меш оружия
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
    USkeletalMeshComponent* WeaponMesh;

    // Данные оружия (ассет)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon", Replicated)
    TSoftObjectPtr<UWeaponDataAsset> WeaponData;

    // Компонент состояния оружия
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UWeaponStateComponent* StateComponent;

    // Событие изменения состояния оружия
    UPROPERTY(BlueprintAssignable, Category = "Weapon")
    FOnWeaponStateChanged OnWeaponStateChanged;

    // Экипировка оружия
    UFUNCTION(BlueprintCallable, Category = "Weapon")
    virtual void Equip(ACharacter* OwnerCharacter);

    // Снятие оружия
    UFUNCTION(BlueprintCallable, Category = "Weapon")
    virtual void Unequip();

protected:
    virtual void BeginPlay() override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    // Обработка изменения состояния оружия
    UFUNCTION()
    void HandleWeaponStateChanged(AWeaponBase* Weapon, const FGameplayTagContainer& StateTags);

    // Серверные RPC для экипировки, снятия, атаки и применения эффектов
    UFUNCTION(Server, Reliable, WithValidation)
    void Server_Equip(ACharacter* OwnerCharacter);
    bool Server_Equip_Validate(ACharacter* OwnerCharacter);

    UFUNCTION(Server, Reliable, WithValidation)
    void Server_Unequip();
    bool Server_Unequip_Validate();

private:
    // Асинхронная загрузка WeaponData, если ассет не загружен
    void LoadWeaponDataAsync();
};
