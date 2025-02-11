// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "TronRpgBaseCharacter.generated.h"

class UTronRpgAbilitySystemComponent;
class UTronRpgAttributeSet;
class UTronRpgComboComponent;

class UGameManager;
class UUIManager;

UCLASS(Abstract)
class TRONRPG_API ATronRpgBaseCharacter : public ACharacter,public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ATronRpgBaseCharacter();
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
	UFUNCTION(BlueprintCallable, Category = "DI")
	void InjectDependencies(UGameManager* InGameManager, UUIManager* InUIManager);

	// Ability System Component для работы с GAS
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	UTronRpgAbilitySystemComponent* AbilitySystemComponent;

	// Attribute Set с основными атрибутами (Health, Mana, Strength, Agility, Intelligence)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
	UTronRpgAttributeSet* AttributeSet;

	// Компонент для управления комбо-атаками
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	UTronRpgComboComponent* ComboComponent;

	// Ссылка на Animation Instance (для интеграции с Motion Matching)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Animation")
	UAnimInstance* AnimInstance;

	// Зависимости, внедряемые через DI (например, менеджеры)
	UPROPERTY(Transient, BlueprintReadOnly, Category = "Managers")
	UGameManager* GameManager;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Managers")
	UUIManager* UIManager;

protected:
	virtual void BeginPlay() override;
};
