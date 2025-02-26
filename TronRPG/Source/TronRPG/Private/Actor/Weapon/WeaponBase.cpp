#include "Actor/Weapon/WeaponBase.h"
#include "AbilitySystemComponent.h"
#include "Component/Weapon/WeaponStateComponent.h"
#include "Engine/AssetManager.h"
#include "Engine/StreamableManager.h"
#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"
#include "Object/GameplayTagsLibrary.h"
#include "TronRPG/TronRPG.h"

AWeaponBase::AWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;
	SetReplicates(true);

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	RootComponent = WeaponMesh;

	StateComponent = CreateDefaultSubobject<UWeaponStateComponent>(TEXT("StateComponent"));
}

void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();

	// Проверяем, загружен ли WeaponData, иначе загружаем асинхронно
	if (!WeaponData.IsValid())
	{
		/*LoadWeaponDataAsync();*/
		return;
	}
}

void AWeaponBase::LoadWeaponDataAsync()
{
	FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
	Streamable.RequestAsyncLoad(WeaponData.ToSoftObjectPath(), FStreamableDelegate::CreateLambda([this]()
	{
	}));
}

void AWeaponBase::Equip(ACharacter* OwnerCharacter)
{
	if (!HasAuthority())
	{
		Server_Equip(OwnerCharacter);
		return;
	}

	if (!OwnerCharacter || !StateComponent || !WeaponData.IsValid() || !WeaponMesh)
	{
		UE_LOG(LogWeaponSystem, Error, TEXT("Cannot equip weapon: Invalid OwnerCharacter, StateComponent, WeaponData, or WeaponMesh"));
		return;
	}

	StateComponent->bIsEquipped = true;
	SetOwner(OwnerCharacter);
	StateComponent->SetWeaponState(TAG_Weapon_Equipped, true);
}

void AWeaponBase::Unequip()
{
	if (!HasAuthority())
	{
		Server_Unequip();
		return;
	}

	if (!StateComponent || !WeaponMesh)
	{
		UE_LOG(LogWeaponSystem, Error, TEXT("Cannot unequip weapon: Invalid StateComponent or WeaponMesh"));
		return;
	}

	StateComponent->bIsEquipped = false;
	StateComponent->SetWeaponState(TAG_Weapon_Equipped, false);
	SetOwner(nullptr);
}

void AWeaponBase::HandleWeaponStateChanged(AWeaponBase* Weapon, const FGameplayTagContainer& StateTags)
{
	OnWeaponStateChanged.Broadcast(this, StateTags);
}

void AWeaponBase::Server_Equip_Implementation(ACharacter* OwnerCharacter)
{
	Equip(OwnerCharacter);
}

bool AWeaponBase::Server_Equip_Validate(ACharacter* OwnerCharacter)
{
	if (!OwnerCharacter || !WeaponData.Get() || !WeaponMesh)
	{
		UE_LOG(LogWeaponSystem, Error, TEXT("Server_Equip validation failed: Invalid OwnerCharacter, WeaponData, or WeaponMesh"));
		return false;
	}
	return true;
}

void AWeaponBase::Server_Unequip_Implementation()
{
	Unequip();
}

bool AWeaponBase::Server_Unequip_Validate()
{
	if (!StateComponent || !StateComponent->bIsEquipped || !WeaponMesh)
	{
		UE_LOG(LogWeaponSystem, Error, TEXT("Server_Unequip validation failed: Weapon is not equipped or invalid StateComponent/WeaponMesh"));
		return false;
	}
	return true;
}

void AWeaponBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AWeaponBase, WeaponData);
}
