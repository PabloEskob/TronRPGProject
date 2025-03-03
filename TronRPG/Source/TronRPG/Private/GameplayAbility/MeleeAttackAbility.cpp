#include "GameplayAbility/MeleeAttackAbility.h"
#include "Character/TronRpgBaseCharacter.h"
#include "Component/TronRpgComboComponent.h"
#include "Component/Animation/AnimationComponent.h"
#include "GAS/TronRpgAbilitySystemComponent.h"
#include "GameplayCueManager.h"
#include "AbilitySystemGlobals.h"
#include "Object/GameplayTagsLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "TronRPG/TronRPG.h"

UMeleeAttackAbility::UMeleeAttackAbility()
{
    InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;

    BlockAbilitiesWithTag.AddTag(TAG_State_Dead);
    BlockAbilitiesWithTag.AddTag(TAG_State_Disabled);
    BlockAbilitiesWithTag.AddTag(TAG_State_Stunned);

    FGameplayTagContainer AbilityAssetTags;
    AbilityAssetTags.AddTag(TAG_Ability_Combat_Melee);
    SetAssetTags(AbilityAssetTags);

    ActivationOwnedTags.AddTag(TAG_State_Attacking);
    DamageEventTag = TAG_Attack_Melee;

    DefaultTraceSocketNames.Add(FName("Weapon_Tip"));
    DefaultTraceSocketNames.Add(FName("Weapon_Mid"));
    DefaultTraceSocketNames.Add(FName("Weapon_Root"));

    ComboConfig.MaxComboCount = 3;
    ComboConfig.SectionPrefix = "Attack_";
    ComboConfig.bResetOnCancel = true;
    ComboConfig.bRequireAnimationForDamage = true;

    AttackConfig.BaseDamage = 20.0f;
    AttackConfig.AttackRadius = 150.0f;
    AttackConfig.AttackAngle = 60.0f;
    AttackConfig.CriticalMultiplier = 2.0f;
    AttackConfig.CriticalChance = 0.1f;
    AttackConfig.ComboMultiplierPerHit = 0.2f;
    AttackConfig.MinimumDamage = 1.0f;
    AttackConfig.MaxTargetsPerAttack = 5;
}

bool UMeleeAttackAbility::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                             const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags,
                                             FGameplayTagContainer* OptionalRelevantTags) const
{
    if (!Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags))
        return false;

    AActor* Actor = ActorInfo ? ActorInfo->AvatarActor.Get() : nullptr;
    if (!Actor || !SupportsMeleeInterface(Actor))
    {
        if (OptionalRelevantTags)
            OptionalRelevantTags->AddTag(FGameplayTag::RequestGameplayTag(TEXT("Status.UnsupportedActor")));
        return false;
    }

    UTronRpgAbilitySystemComponent* ASC = Cast<UTronRpgAbilitySystemComponent>(ActorInfo->AbilitySystemComponent.Get());
    if (ASC && !ASC->HasMatchingGameplayTag(TAG_Weapon_Equipped))
    {
        if (OptionalRelevantTags)
            OptionalRelevantTags->AddTag(TAG_Status_NoWeaponEquipped);
        return false;
    }

    if (ASC && ASC->HasAnyMatchingGameplayTags(ActivationBlockedTags))
    {
        if (OptionalRelevantTags)
            OptionalRelevantTags->AppendTags(ASC->GetBlockedAbilityTags());
        return false;
    }

    return true;
}

void UMeleeAttackAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                          const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
    float StartTime = FPlatformTime::Seconds();

    if (!CommitAbility(Handle, ActorInfo, ActivationInfo) || !ActorInfo || !ActorInfo->AvatarActor.IsValid())
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
        return;
    }

    AActor* SourceActor = ActorInfo->AvatarActor.Get();
    if (!SourceActor || !SupportsMeleeInterface(SourceActor))
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
        return;
    }

    CurrentActivation = { Handle, ActorInfo, ActivationInfo, 0, TArray<AActor*>() };

    int32 CurrentCombo = 0;
    if (SourceActor->GetClass()->ImplementsInterface(UMeleeAttackInterface::StaticClass()))
        CurrentCombo = IMeleeAttackInterface::Execute_GetComboCount(SourceActor);
    else if (ATronRpgBaseCharacter* BaseCharacter = Cast<ATronRpgBaseCharacter>(SourceActor))
    {
        UTronRpgComboComponent* ComboComp = BaseCharacter->GetComboComponent();
        CurrentCombo = ComboComp ? ComboComp->GetComboCount() : 0;
    }
    CurrentActivation.ComboCount = FMath::Min(CurrentCombo, ComboConfig.MaxComboCount - 1);

    UTronRpgAbilitySystemComponent* ASC = Cast<UTronRpgAbilitySystemComponent>(ActorInfo->AbilitySystemComponent.Get());
    if (ASC)
        ASC->AddLooseGameplayTags(ActivationOwnedTags);

    FName MontageSection = GetMontageSectionName(CurrentActivation.ComboCount);
    bool bAnimationStarted = false;
    float PlayRate = 1.0f;

    if (SourceActor->GetClass()->ImplementsInterface(UMeleeAttackInterface::StaticClass()))
    {
        if (MeleeAttackMontage)
        {
            // Примечание: для интерфейса предполагается, что реализация сама вызывает ApplyDamageToTargets
            bAnimationStarted = IMeleeAttackInterface::Execute_PlayAttackAnimation(SourceActor, MeleeAttackMontage, PlayRate, MontageSection) > 0.0f;
            if (!bAnimationStarted && !ComboConfig.bRequireAnimationForDamage)
            {
                ApplyDamageToTargets(SourceActor, CurrentActivation.ComboCount);
                IMeleeAttackInterface::Execute_IncrementCombo(SourceActor, true);
                EndAbility(Handle, ActorInfo, ActivationInfo, false, false);
                return;
            }
        }
    }
    else if (ATronRpgBaseCharacter* BaseCharacter = Cast<ATronRpgBaseCharacter>(SourceActor))
    {
        UAnimationComponent* AnimComp = BaseCharacter->GetAnimationComponent();
        if (AnimComp && MeleeAttackMontage)
        {
            AnimComp->OnMontageNotifyBegin.AddDynamic(this, &UMeleeAttackAbility::OnApplyDamageNotify);
            AnimComp->OnMontageEnded.AddDynamic(this, &UMeleeAttackAbility::OnMontageComplete);
            bAnimationStarted = AnimComp->PlayMontage(MeleeAttackMontage, PlayRate, MontageSection) > 0.0f;
        
            if (bAnimationStarted)
            {
                // Увеличиваем комбо сразу после начала анимации
                if (UTronRpgComboComponent* ComboComp = BaseCharacter->GetComboComponent())
                {
                    ComboComp->IncrementCombo(true);
                    CurrentActivation.ComboCount = FMath::Min(ComboComp->GetComboCount(), ComboConfig.MaxComboCount - 1);
                }
            }
            else if (!ComboConfig.bRequireAnimationForDamage)
            {
                ApplyDamageToTargets(SourceActor, CurrentActivation.ComboCount);
                if (UTronRpgComboComponent* ComboComp = BaseCharacter->GetComboComponent())
                    ComboComp->IncrementCombo(true);
                EndAbility(Handle, ActorInfo, ActivationInfo, false, false);
                return;
            }
        }
    }

    if (ASC)
    {
        FGameplayCueParameters CueParams;
        CueParams.Location = SourceActor->GetActorLocation();
        CueParams.Instigator = SourceActor;
        CueParams.SourceObject = this;
        ASC->GetOwnedGameplayTags(CueParams.AggregatedSourceTags);
        UAbilitySystemGlobals::Get().GetGameplayCueManager()->HandleGameplayCue(
            SourceActor, TAG_Attack_Melee, EGameplayCueEvent::Executed, CueParams);
    }

    LogPerformance(TEXT("ActivateAbility"), StartTime);
}

void UMeleeAttackAbility::CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                        const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility)
{
    if (ActorInfo && ActorInfo->AvatarActor.IsValid())
    {
        AActor* SourceActor = ActorInfo->AvatarActor.Get();
        if (SourceActor->GetClass()->ImplementsInterface(UMeleeAttackInterface::StaticClass()))
            IMeleeAttackInterface::Execute_PlayAttackAnimation(SourceActor, nullptr, 1.0f, NAME_None);
        else if (ATronRpgBaseCharacter* BaseCharacter = Cast<ATronRpgBaseCharacter>(SourceActor))
        {
            if (UAnimationComponent* AnimComp = BaseCharacter->GetAnimationComponent())
            {
                AnimComp->StopMontage(MeleeAttackMontage);
                AnimComp->OnMontageNotifyBegin.RemoveDynamic(this, &UMeleeAttackAbility::OnApplyDamageNotify);
                AnimComp->OnMontageEnded.RemoveDynamic(this, &UMeleeAttackAbility::OnMontageComplete);
            }
        }

        UTronRpgAbilitySystemComponent* ASC = Cast<UTronRpgAbilitySystemComponent>(ActorInfo->AbilitySystemComponent.Get());
        if (ASC)
            ASC->RemoveLooseGameplayTags(ActivationOwnedTags);

        if (ComboConfig.bResetOnCancel)
        {
            if (SourceActor->GetClass()->ImplementsInterface(UMeleeAttackInterface::StaticClass()))
                IMeleeAttackInterface::Execute_ResetCombo(SourceActor, true);
            else if (ATronRpgBaseCharacter* BaseCharacter = Cast<ATronRpgBaseCharacter>(SourceActor))
                if (UTronRpgComboComponent* ComboComp = BaseCharacter->GetComboComponent())
                    ComboComp->ResetCombo(true);
        }
    }
    Super::CancelAbility(Handle, ActorInfo, ActivationInfo, bReplicateCancelAbility);
}

void UMeleeAttackAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                     const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
    Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
    CurrentActivation = FActivationContext(); // Очистка контекста
}

FName UMeleeAttackAbility::GetMontageSectionName(int32 ComboCount) const
{
    return FName(*FString::Printf(TEXT("%s%d"), *ComboConfig.SectionPrefix, ComboCount + 1));
}

void UMeleeAttackAbility::OnMontageComplete(UAnimMontage* Montage, bool bInterrupted)
{
    if (!CurrentActivation.ActorInfo || !CurrentActivation.ActorInfo->AvatarActor.IsValid())
        return;

    float StartTime = FPlatformTime::Seconds();
    AActor* SourceActor = CurrentActivation.ActorInfo->AvatarActor.Get();

    if (ATronRpgBaseCharacter* BaseChar = Cast<ATronRpgBaseCharacter>(SourceActor))
    {
        if (UAnimationComponent* AnimComponent = BaseChar->GetAnimationComponent())
        {
            AnimComponent->OnMontageNotifyBegin.RemoveDynamic(this, &UMeleeAttackAbility::OnApplyDamageNotify);
            AnimComponent->OnMontageEnded.RemoveDynamic(this, &UMeleeAttackAbility::OnMontageComplete);
        }
    }

    UTronRpgAbilitySystemComponent* ASC = Cast<UTronRpgAbilitySystemComponent>(CurrentActivation.ActorInfo->AbilitySystemComponent.Get());
    if (ASC)
        ASC->RemoveLooseGameplayTags(ActivationOwnedTags);

    if (bInterrupted && ComboConfig.bResetOnCancel)
    {
        if (SourceActor->GetClass()->ImplementsInterface(UMeleeAttackInterface::StaticClass()))
            IMeleeAttackInterface::Execute_ResetCombo(SourceActor, true);
        else if (ATronRpgBaseCharacter* BaseChar = Cast<ATronRpgBaseCharacter>(SourceActor))
            if (UTronRpgComboComponent* ComboComp = BaseChar->GetComboComponent())
                ComboComp->ResetCombo(true);
    }

    EndAbility(CurrentActivation.SpecHandle, CurrentActivation.ActorInfo, CurrentActivation.ActivationInfo, false, bInterrupted);
    LogPerformance(TEXT("OnMontageComplete"), StartTime);
}

void UMeleeAttackAbility::OnApplyDamageNotify(FName NotifyName)
{
    float StartTime = FPlatformTime::Seconds();
    if (NotifyName == FName("ApplyDamage") && CurrentActivation.ActorInfo && CurrentActivation.ActorInfo->AvatarActor.IsValid())
    {
        AActor* SourceActor = CurrentActivation.ActorInfo->AvatarActor.Get();
        ApplyDamageToTargets(SourceActor, CurrentActivation.ComboCount);

        // Увеличиваем комбо только после успешного нанесения урона
        if (SourceActor->GetClass()->ImplementsInterface(UMeleeAttackInterface::StaticClass()))
            IMeleeAttackInterface::Execute_IncrementCombo(SourceActor, true);
        else if (ATronRpgBaseCharacter* BaseCharacter = Cast<ATronRpgBaseCharacter>(SourceActor))
            if (UTronRpgComboComponent* ComboComp = BaseCharacter->GetComboComponent())
                ComboComp->IncrementCombo(true);

        UE_LOG(LogWeaponSystem, Log, TEXT("Damage applied via notify. Combo: %d"), CurrentActivation.ComboCount);
    }
    LogPerformance(TEXT("OnApplyDamageNotify"), StartTime);
}

void UMeleeAttackAbility::ApplyDamageToTargets(AActor* SourceActor, int32 ComboCount)
{
    float StartTime = FPlatformTime::Seconds();
    if (!SourceActor || !DamageEffect)
        return;

    TArray<AActor*> TargetsInRange = FindTargetsInAttackRange(SourceActor);
    if (TargetsInRange.Num() == 0)
        return;

    int32 MaxTargets = AttackConfig.MaxTargetsPerAttack;
    if (TargetsInRange.Num() > MaxTargets)
    {
        TargetsInRange.Sort([SourceActor](const AActor& A, const AActor& B) {
            return FVector::DistSquared(SourceActor->GetActorLocation(), A.GetActorLocation()) <
                   FVector::DistSquared(SourceActor->GetActorLocation(), B.GetActorLocation());
        });
        TargetsInRange.SetNum(MaxTargets);
    }

    int32 TargetsHit = 0;
    for (AActor* Target : TargetsInRange)
    {
        if (CurrentActivation.HitActors.Contains(Target) || !CanApplyDamageToTarget(Target))
            continue;

        bool bIsCritical = false;
        float DamageAmount = CalculateDamage(ComboCount, bIsCritical);
        FGameplayEffectSpecHandle DamageSpecHandle = CreateDamageEffectSpec(Target, DamageAmount, bIsCritical);

        if (DamageSpecHandle.IsValid())
        {
            UAbilitySystemComponent* TargetASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Target);
            if (TargetASC && TargetASC->ApplyGameplayEffectSpecToSelf(*DamageSpecHandle.Data.Get()).IsValid())
            {
                CurrentActivation.HitActors.Add(Target);
                TargetsHit++;
                UE_LOG(LogWeaponSystem, Log, TEXT("Damage applied: %.1f to %s (Combo: %d, Critical: %s)"),
                       DamageAmount, *Target->GetName(), ComboCount, bIsCritical ? TEXT("Yes") : TEXT("No"));
            }
        }
    }
    UE_LOG(LogWeaponSystem, Log, TEXT("Hit %d targets"), TargetsHit);
    LogPerformance(TEXT("ApplyDamageToTargets"), StartTime);
}

bool UMeleeAttackAbility::CanApplyDamageToTarget(AActor* Target) const
{
    if (!IsValid(Target) || Target == GetCurrentActorInfo()->AvatarActor.Get())
        return false;

    UAbilitySystemComponent* TargetASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Target);
    if (!TargetASC)
        return false;

    FGameplayTagContainer TargetTags;
    TargetASC->GetOwnedGameplayTags(TargetTags);
    return (!AttackConfig.TargetRequiredTags.IsEmpty() ? TargetTags.HasAny(AttackConfig.TargetRequiredTags) : true) &&
           !TargetTags.HasAny(AttackConfig.TargetBlockedTags);
}

TArray<AActor*> UMeleeAttackAbility::FindTargetsInAttackRange(AActor* SourceActor)
{
    float StartTime = FPlatformTime::Seconds();
    TArray<AActor*> TargetsInRange;
    if (!SourceActor)
        return TargetsInRange;

    PerformOptimizedTargetTrace(SourceActor, TargetsInRange);
    LogPerformance(TEXT("FindTargetsInAttackRange"), StartTime);
    return TargetsInRange;
}

void UMeleeAttackAbility::PerformOptimizedTargetTrace(AActor* SourceActor, TArray<AActor*>& OutHitActors)
{
    float StartTime = FPlatformTime::Seconds();
    if (!SourceActor || !SourceActor->GetWorld())
        return;

    TArray<AActor*> ActorsToIgnore = { SourceActor };
    TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes = { UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn) };

    FVector SourceLocation = SourceActor->GetActorLocation();
    FVector ForwardVector = SourceActor->GetActorForwardVector();
    FVector SphereCenter = SourceLocation + ForwardVector * (AttackConfig.AttackRadius * 0.5f);

    TArray<FHitResult> HitResults;
    bool bHit = UKismetSystemLibrary::SphereTraceMultiForObjects(
        SourceActor->GetWorld(), SphereCenter, SphereCenter, AttackConfig.AttackRadius, ObjectTypes, false,
        ActorsToIgnore, bEnablePerformanceLogging ? EDrawDebugTrace::ForDuration : EDrawDebugTrace::None,
        HitResults, true, FLinearColor::Red, FLinearColor::Green, 1.0f);

    if (bHit)
    {
        for (const FHitResult& Hit : HitResults)
        {
            if (AActor* HitActor = Hit.GetActor())
            {
                if (HitActor == SourceActor || OutHitActors.Contains(HitActor))
                    continue;

                FVector DirectionToTarget = (HitActor->GetActorLocation() - SourceLocation).GetSafeNormal2D();
                float AngleDegrees = FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(ForwardVector, DirectionToTarget)));
                if (AngleDegrees <= AttackConfig.AttackAngle * 0.5f)
                    OutHitActors.Add(HitActor);
            }
        }
    }

    // Уточняем трассировку через сокеты для повышения точности
    if (SupportsMeleeInterface(SourceActor))
    {
        TArray<FName> SocketNames = GetTraceSocketsForActor(SourceActor);
        USkeletalMeshComponent* SkeletalMesh = SourceActor->FindComponentByClass<USkeletalMeshComponent>();
        if (!SkeletalMesh || SocketNames.Num() == 0)
            return;

        float SocketTraceRadius = DefaultTraceRadius;
        FGameplayTag WeaponTypeTag = FGameplayTag::EmptyTag;
        if (SourceActor->GetClass()->ImplementsInterface(UMeleeAttackInterface::StaticClass()))
        {
            if (IMeleeAttackInterface::Execute_HasWeaponWithTag(SourceActor, TAG_WeaponType_Sword))
                WeaponTypeTag = TAG_WeaponType_Sword;
            else if (IMeleeAttackInterface::Execute_HasWeaponWithTag(SourceActor, TAG_WeaponType_SwordAndShield))
                WeaponTypeTag = TAG_WeaponType_SwordAndShield;
        }

        TArray<FName> WeaponSocketNames;
        GetWeaponTraceConfig(WeaponTypeTag, WeaponSocketNames, SocketTraceRadius);
        if (WeaponSocketNames.Num() > 0)
            SocketNames = WeaponSocketNames;

        for (const FName& SocketName : SocketNames)
        {
            if (!SkeletalMesh->DoesSocketExist(SocketName))
                continue;

            FVector SocketLocation = SkeletalMesh->GetSocketLocation(SocketName);
            TArray<FHitResult> SocketHitResults;
            bool bSocketHit = UKismetSystemLibrary::SphereTraceMultiForObjects(
                SourceActor->GetWorld(), SocketLocation, SocketLocation, SocketTraceRadius, ObjectTypes, false,
                ActorsToIgnore, bEnablePerformanceLogging ? EDrawDebugTrace::ForDuration : EDrawDebugTrace::None,
                SocketHitResults, true, FLinearColor::Blue, FLinearColor::Yellow, 1.0f);

            if (bSocketHit)
            {
                for (const FHitResult& Hit : SocketHitResults)
                {
                    if (AActor* HitActor = Hit.GetActor())
                        if (HitActor != SourceActor && !OutHitActors.Contains(HitActor))
                            OutHitActors.Add(HitActor);
                }
            }
        }
    }
    LogPerformance(TEXT("PerformOptimizedTargetTrace"), StartTime);
}

float UMeleeAttackAbility::CalculateDamage(int32 ComboCount, bool& bIsCritical) const
{
    float BaseDamage = AttackConfig.BaseDamage;
    if (ComboDamageCurve)
        BaseDamage *= ComboDamageCurve->GetFloatValue(ComboCount);
    else
        BaseDamage += BaseDamage * ComboCount * AttackConfig.ComboMultiplierPerHit;

    bIsCritical = FMath::FRand() < AttackConfig.CriticalChance;
    float FinalDamage = bIsCritical ? BaseDamage * AttackConfig.CriticalMultiplier : BaseDamage;
    return FMath::Max(FinalDamage, AttackConfig.MinimumDamage);
}

FGameplayEffectSpecHandle UMeleeAttackAbility::CreateDamageEffectSpec(AActor* Target, float DamageAmount, bool bIsCritical)
{
    UAbilitySystemComponent* SourceASC = CurrentActivation.ActorInfo->AbilitySystemComponent.Get();
    if (!SourceASC || !DamageEffect)
        return FGameplayEffectSpecHandle();

    FGameplayEffectSpecHandle SpecHandle = MakeOutgoingGameplayEffectSpec(DamageEffect);
    if (SpecHandle.IsValid())
    {
        SpecHandle.Data->SetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(TEXT("Data.Damage")), DamageAmount);
        if (bIsCritical)
            SpecHandle.Data->SetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(TEXT("Data.Critical")), 1.0f);
    }
    return SpecHandle;
}

bool UMeleeAttackAbility::GetWeaponTraceConfig(const FGameplayTag& WeaponTypeTag, TArray<FName>& OutSocketNames, float& OutTraceRadius) const
{
    if (!WeaponTraceConfigTable || WeaponTypeTag.IsValid())
        return false;

    FWeaponTraceSocketConfig* Config = WeaponTraceConfigTable->FindRow<FWeaponTraceSocketConfig>(WeaponTypeTag.GetTagName(), TEXT("WeaponTraceConfig"));
    if (!Config)
        return false;

    OutSocketNames = Config->SocketNames;
    OutTraceRadius = Config->SocketTraceRadius;
    return true;
}

TArray<FName> UMeleeAttackAbility::GetTraceSocketsForActor(AActor* SourceActor) const
{
    if (!SourceActor || !SupportsMeleeInterface(SourceActor))
        return DefaultTraceSocketNames;

    TArray<FName> SocketNames = DefaultTraceSocketNames;
    float TraceRadius = DefaultTraceRadius;
    FGameplayTag WeaponTypeTag = FGameplayTag::EmptyTag;

    if (SourceActor->GetClass()->ImplementsInterface(UMeleeAttackInterface::StaticClass()))
    {
        if (IMeleeAttackInterface::Execute_HasWeaponWithTag(SourceActor, TAG_WeaponType_Sword))
            WeaponTypeTag = TAG_WeaponType_Sword;
        else if (IMeleeAttackInterface::Execute_HasWeaponWithTag(SourceActor, TAG_WeaponType_SwordAndShield))
            WeaponTypeTag = TAG_WeaponType_SwordAndShield;

        if (WeaponTypeTag.IsValid())
            GetWeaponTraceConfig(WeaponTypeTag, SocketNames, TraceRadius);
    }
    return SocketNames;
}

bool UMeleeAttackAbility::SupportsMeleeInterface(AActor* Actor) const
{
    return Actor && Actor->GetClass()->ImplementsInterface(UMeleeAttackInterface::StaticClass());
}

void UMeleeAttackAbility::LogPerformance(const FString& FunctionName, float StartTime) const
{
    if (bEnablePerformanceLogging)
    {
        float Duration = (FPlatformTime::Seconds() - StartTime) * 1000.0f;
        UE_LOG(LogWeaponSystem, Log, TEXT("Performance: %s took %.2f ms"), *FunctionName, Duration);
    }
}