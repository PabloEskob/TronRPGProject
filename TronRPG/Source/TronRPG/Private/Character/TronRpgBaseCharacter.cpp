// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/TronRpgBaseCharacter.h"
#include "Component/TronRpgComboComponent.h"
#include "GAS/TronRpgAbilitySystemComponent.h"
#include "GAS/TronRpgAttributeSet.h"

ATronRpgBaseCharacter::ATronRpgBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = CreateDefaultSubobject<UTronRpgAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AttributeSet = CreateDefaultSubobject<UTronRpgAttributeSet>(TEXT("AttributeSet"));
	ComboComponent = CreateDefaultSubobject<UTronRpgComboComponent>(TEXT("ComboComponent"));
}

void ATronRpgBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Получаем ссылку на Animation Instance из Skeletal Mesh (если он установлен)
	if (GetMesh())
	{
		AnimInstance = GetMesh()->GetAnimInstance();
	}
}

void ATronRpgBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

UAbilitySystemComponent* ATronRpgBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ATronRpgBaseCharacter::InjectDependencies(UGameManager* InGameManager, UUIManager* InUIManager)
{
	GameManager = InGameManager;
	UIManager = InUIManager;
}
