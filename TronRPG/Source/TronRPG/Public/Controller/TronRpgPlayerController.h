#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Input/TronRpgEnhancedInputComponent.h"
#include "TronRpgPlayerController.generated.h"

struct FInputActionValue;
class UInputAction;
class UInputMappingContext;

/**
 * Player controller for the TronRPG game
 * Handles player input, camera control, and ability activation
 */
UCLASS()
class TRONRPG_API ATronRpgPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    ATronRpgPlayerController();

protected:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;

    /**
     * Set up ability bindings for the player character
     */
    UFUNCTION(BlueprintCallable, Category = "Input")
    void SetupAbilityBindings();

    /** Input mapping context for base RPG actions */
    UPROPERTY(EditAnywhere, Category = "Input")
    TObjectPtr<UInputMappingContext> RpgContext;

    /** Movement input action */
    UPROPERTY(EditAnywhere, Category = "Input")
    TObjectPtr<UInputAction> MoveAction;

    /** Camera look input action */
    UPROPERTY(EditAnywhere, Category = "Input")
    TObjectPtr<UInputAction> LookAction;

    /** Primary attack input action */
    UPROPERTY(EditAnywhere, Category = "Input|Abilities")
    TObjectPtr<UInputAction> PrimaryAttackAction;

    /** Combo attack input action */
    UPROPERTY(EditAnywhere, Category = "Input|Abilities")
    TObjectPtr<UInputAction> ComboAttackAction;

    /** Sprint input action */
    UPROPERTY(EditAnywhere, Category = "Input|Abilities")
    TObjectPtr<UInputAction> SprintAction;

    /** Handle movement input */
    void Move(const FInputActionValue& InputActionValue);

    /** Handle camera input */
    void Look(const FInputActionValue& InputActionValue);

    /**
     * Process combo attack input
     */
    void ProcessComboInput(const FInputActionValue& InputActionValue);

    /** Horizontal camera rotation speed */
    UPROPERTY(EditAnywhere, Category = "Camera", meta = (ClampMin = "0.1", ClampMax = "10.0"))
    float YawSpeed = 1.f;

    /** Vertical camera rotation speed */
    UPROPERTY(EditAnywhere, Category = "Camera", meta = (ClampMin = "0.1", ClampMax = "10.0"))
    float PitchSpeed = 1.f;

private:
    /** Cached reference to the enhanced input component */
    UPROPERTY()
    UTronRpgEnhancedInputComponent* EnhancedInputComp;
};