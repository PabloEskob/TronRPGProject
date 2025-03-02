#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "MeleeAttackDamageNotify.generated.h"

/**
 * Animation Notify для обозначения момента нанесения урона в анимации атаки
 */
UCLASS(Blueprintable, meta=(DisplayName="Apply Melee Damage"))
class TRONRPG_API UMeleeAttackDamageNotify : public UAnimNotify
{
	GENERATED_BODY()
    
public:
	UMeleeAttackDamageNotify();
    
	// Переопределение метода Notify из UAnimNotify
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
    
	// Название уведомления, которое передается в MeleeAttackAbility
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	FName NotifyName;
};