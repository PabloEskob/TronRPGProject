// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TronRpgComboComponent.generated.h"

// Делегат для событий изменения комбо
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnComboCountChanged, int32, NewComboCount);

// Делегат для события завершения комбо
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnComboEnded);

/**
 * Компонент для управления комбо-атаками
 * Отслеживает текущее количество ударов в комбо и обеспечивает таймер сброса комбо
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TRONRPG_API UTronRpgComboComponent : public UActorComponent
{
	GENERATED_BODY()
};
