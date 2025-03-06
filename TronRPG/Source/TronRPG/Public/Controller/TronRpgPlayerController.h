#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TronRpgPlayerController.generated.h"

struct FInputActionValue;
class UInputAction;
class UInputMappingContext;
class UTronRpgEnhancedInputComponent;

UCLASS()
class TRONRPG_API ATronRpgPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATronRpgPlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
	/** Контекст ввода для базовых действий */
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> RpgContext;

	/** Действие ввода для перемещения */
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	/** Действие ввода для вращения камеры */
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> LookAction;
	
	/** Обработчик ввода для перемещения */
	void Move(const FInputActionValue& InputActionValue);

	/** Обработчик ввода для вращения камеры */
	void Look(const FInputActionValue& InputActionValue);
	
	/** Скорость вращения камеры по горизонтали */
	UPROPERTY(EditAnywhere, Category = "Camera")
	float YawSpeed = 1.f;

	/** Скорость вращения камеры по вертикали */
	UPROPERTY(EditAnywhere, Category = "Camera")
	float PitchSpeed = 1.f;

private:
	/** Кэшированная ссылка на расширенный компонент ввода */
	UPROPERTY()
	UTronRpgEnhancedInputComponent* EnhancedInputComp;
};