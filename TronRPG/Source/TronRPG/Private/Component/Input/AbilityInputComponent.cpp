// Tron


#include "Component/Input/AbilityInputComponent.h"

#include "GAS/TronRpgAbilitySystemComponent.h"

UAbilityInputComponent::UAbilityInputComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAbilityInputComponent::BeginPlay()
{
	Super::BeginPlay();

	// Получаем AbilitySystemComponent из владельца
	AbilitySystemComponent = Cast<UTronRpgAbilitySystemComponent>(
		GetOwner()->GetComponentByClass(UTronRpgAbilitySystemComponent::StaticClass())
	);
}

void UAbilityInputComponent::SetupPlayerInput(UInputComponent* PlayerInputComponent)
{
	if (!PlayerInputComponent || !AbilitySystemComponent)
	{
		return;
	}
}
