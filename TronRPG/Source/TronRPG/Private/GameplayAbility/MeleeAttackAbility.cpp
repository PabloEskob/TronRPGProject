// Базовая реализация способности атаки ближнего боя с комбо-ударами

#include "GameplayAbility/MeleeAttackAbility.h"

#include "Character/TronRpgBaseCharacter.h"
#include "Component/TronRpgComboComponent.h"
#include "Component/Animation/AnimationComponent.h"
#include "Component/Weapon/WeaponComponent.h"
#include "GAS/TronRpgAbilitySystemComponent.h"
#include "GameplayCueManager.h"
#include "AbilitySystemGlobals.h"
#include "Object/GameplayTagsLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "TronRPG/TronRPG.h"

UMeleeAttackAbility::UMeleeAttackAbility()
{
    // Настраиваем базовые параметры способности
    InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
    
    // Настройка теговых ограничений - атака невозможна если персонаж мертв, оглушен, и т.д.
    BlockAbilitiesWithTag.AddTag(TAG_State_Dead);
    BlockAbilitiesWithTag.AddTag(TAG_State_Disabled);
    BlockAbilitiesWithTag.AddTag(TAG_State_Stunned);
    
    // Устанавливаем теги, идентифицирующие эту способность
    FGameplayTagContainer AbilityAssetTags;
    AbilityAssetTags.AddTag(TAG_Ability_Combat_Melee);
    SetAssetTags(AbilityAssetTags);
    
    // Теги, которые добавляются при активации способности
    ActivationOwnedTags.AddTag(TAG_State_Attacking);
    
    // Настройка тега события урона
    DamageEventTag = TAG_Attack_Melee;
    
    // Инициализация сокетов для трассировки оружия
    WeaponTraceSocketNames.Add(FName("Weapon_Tip"));
    WeaponTraceSocketNames.Add(FName("Weapon_Mid"));
    WeaponTraceSocketNames.Add(FName("Weapon_Root"));
    
    // Инициализация максимального количества ударов в комбо
    MaxComboCount = 3;
}

bool UMeleeAttackAbility::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                          const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags,
                                          OUT FGameplayTagContainer* OptionalRelevantTags) const
{
    // Сначала проверяем базовые условия из родительского класса
    if (!Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags))
    {
        return false;
    }
    
    // Получаем персонажа
    ATronRpgBaseCharacter* Character = Cast<ATronRpgBaseCharacter>(ActorInfo->AvatarActor.Get());
    if (!Character)
    {
        return false;
    }
    
    // Проверяем наличие оружия - персонаж должен иметь экипированное оружие для атаки
    UTronRpgAbilitySystemComponent* ASC = Cast<UTronRpgAbilitySystemComponent>(Character->GetAbilitySystemComponent());
    if (ASC && !ASC->HasMatchingGameplayTag(TAG_Weapon_Equipped))
    {
        if (OptionalRelevantTags)
        {
            OptionalRelevantTags->AddTag(TAG_Status_NoWeaponEquipped);
        }
        return false;
    }
    
    // Проверяем, не находится ли персонаж в состоянии, которое блокирует атаку
    if (ASC && ASC->HasAnyMatchingGameplayTags(ActivationBlockedTags))
    {
        if (OptionalRelevantTags)
        {
            OptionalRelevantTags->AppendTags(ASC->GetBlockedAbilityTags());
        }
        return false;
    }
    
    return true;
}

void UMeleeAttackAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                        const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
    // Проверяем, можем ли мы активировать способность (списание стоимости, проверка кулдаунов и т.д.)
    if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
        return;
    }
    
    // Проверяем валидность ActorInfo
    if (!ActorInfo || !ActorInfo->AvatarActor.IsValid())
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
        return;
    }

    // Получаем персонажа
    ATronRpgBaseCharacter* BaseCharacter = Cast<ATronRpgBaseCharacter>(ActorInfo->AvatarActor.Get());
    if (!BaseCharacter)
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
        return;
    }

    // Получаем компонент комбо для определения текущего счетчика
    UTronRpgComboComponent* ComboComp = BaseCharacter->GetComboComponent();
    int32 CurrentCombo = (ComboComp) ? ComboComp->GetComboCount() : 0;
    
    // Ограничиваем комбо максимальным значением
    CurrentCombo = FMath::Min(CurrentCombo, MaxComboCount - 1);

    // Добавляем теги состояния атаки
    UTronRpgAbilitySystemComponent* ASC = Cast<UTronRpgAbilitySystemComponent>(BaseCharacter->GetAbilitySystemComponent());
    if (ASC)
    {
        ASC->AddLooseGameplayTags(ActivationOwnedTags);
    }

    // Выбираем нужную секцию Montage для текущего комбо-удара
    FName MontageSection = GetMontageSectionName(CurrentCombo);

    // Получаем компонент анимации
    UAnimationComponent* AnimComp = BaseCharacter->GetAnimationComponent();
    if (AnimComp && MeleeAttackMontage)
    {
        // Сохраняем информацию о текущей активации для использования в коллбэках
        CurrentSpecHandle = Handle;
        CurrentActorInfo = ActorInfo;
        CurrentActivationInfo = ActivationInfo;
        
        // Регистрируем обработчики для событий анимации
        AnimComp->OnMontageNotifyBegin.AddDynamic(this, &UMeleeAttackAbility::OnApplyDamageNotify);
        AnimComp->OnMontageEnded.AddDynamic(this, &UMeleeAttackAbility::OnMontageComplete);
        
        // Запускаем анимацию атаки
        float PlayRate = 1.0f;
        AnimComp->PlayMontage(MeleeAttackMontage, PlayRate, MontageSection);
        
        UE_LOG(LogWeaponSystem, Log, TEXT("Playing MeleeAttack montage. Combo: %d, Section: %s"), 
            CurrentCombo, *MontageSection.ToString());
    }
    else
    {
        // Если компонент анимации или монтаж не найдены, сразу наносим урон и завершаем способность
        UE_LOG(LogWeaponSystem, Warning, TEXT("Failed to play attack animation. AnimComp: %d, Montage: %d"), 
            (AnimComp != nullptr), (MeleeAttackMontage != nullptr));
            
        ApplyDamageToTargets(BaseCharacter, CurrentCombo);
        EndAbility(Handle, ActorInfo, ActivationInfo, false, false);
        return;
    }

    // Запускаем Gameplay Cue для визуальных эффектов атаки
    if (ASC)
    {
        FGameplayCueParameters CueParams;
        CueParams.Location = BaseCharacter->GetActorLocation();
        CueParams.Instigator = BaseCharacter;
        CueParams.SourceObject = this;
        
        FGameplayTagContainer SourceTags;
        ASC->GetOwnedGameplayTags(SourceTags);
        CueParams.AggregatedSourceTags = SourceTags;
        
        UAbilitySystemGlobals::Get().GetGameplayCueManager()->HandleGameplayCue(
            BaseCharacter,
            TAG_Attack_Melee,
            EGameplayCueEvent::Executed,
            CueParams);
    }

    // Инкрементируем счетчик комбо
    if (ComboComp)
    {
        ComboComp->IncrementCombo(true); // true = сбросить таймер комбо
    }
}

void UMeleeAttackAbility::CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                      const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility)
{
    // Прерываем любые выполняемые анимации атаки
    if (ActorInfo && ActorInfo->AvatarActor.IsValid())
    {
        if (ATronRpgBaseCharacter* BaseCharacter = Cast<ATronRpgBaseCharacter>(ActorInfo->AvatarActor.Get()))
        {
            if (UAnimationComponent* AnimComp = BaseCharacter->GetAnimationComponent())
            {
                AnimComp->StopMontage(MeleeAttackMontage);
                
                // Отключаем делегаты
                AnimComp->OnMontageNotifyBegin.RemoveDynamic(this, &UMeleeAttackAbility::OnApplyDamageNotify);
                AnimComp->OnMontageEnded.RemoveDynamic(this, &UMeleeAttackAbility::OnMontageComplete);
            }
            
            // Удаляем теги состояния атаки
            if (UTronRpgAbilitySystemComponent* ASC = Cast<UTronRpgAbilitySystemComponent>(BaseCharacter->GetAbilitySystemComponent()))
            {
                ASC->RemoveLooseGameplayTags(ActivationOwnedTags);
            }
            
            // Сбрасываем комбо при отмене
            if (UTronRpgComboComponent* ComboComp = BaseCharacter->GetComboComponent())
            {
                ComboComp->ResetCombo(true);
            }
        }
    }
    
    Super::CancelAbility(Handle, ActorInfo, ActivationInfo, bReplicateCancelAbility);
}

FName UMeleeAttackAbility::GetMontageSectionName(int32 ComboCount) const
{
    // Формируем имя секции в зависимости от номера комбо-удара
    // Например: "Attack_1", "Attack_2", "Attack_3", и т.д.
    FString SectionName = FString::Printf(TEXT("%s%d"), *ComboSectionPrefix, ComboCount + 1);
    return FName(*SectionName);
}

void UMeleeAttackAbility::OnMontageComplete(UAnimMontage* Montage, bool bInterrupted)
{
    // Обрабатываем завершение анимации атаки
    if (CurrentActorInfo && CurrentActorInfo->AvatarActor.IsValid())
    {
        ATronRpgBaseCharacter* BaseChar = Cast<ATronRpgBaseCharacter>(CurrentActorInfo->AvatarActor.Get());
        if (BaseChar)
        {
            // Отписываемся от делегатов
            UAnimationComponent* AnimComponent = BaseChar->GetAnimationComponent();
            if (AnimComponent)
            {
                AnimComponent->OnMontageNotifyBegin.RemoveDynamic(this, &UMeleeAttackAbility::OnApplyDamageNotify);
                AnimComponent->OnMontageEnded.RemoveDynamic(this, &UMeleeAttackAbility::OnMontageComplete);
            }

            // Удаляем теги состояния атаки
            UTronRpgAbilitySystemComponent* ASC = Cast<UTronRpgAbilitySystemComponent>(BaseChar->GetAbilitySystemComponent());
            if (ASC)
            {
                ASC->RemoveLooseGameplayTags(ActivationOwnedTags);
            }

            // Если монтаж был прерван, сбрасываем комбо
            if (bInterrupted)
            {
                UTronRpgComboComponent* ComboComp = BaseChar->GetComboComponent();
                if (ComboComp)
                {
                    ComboComp->ResetCombo(true);
                }
            }
        }
    }

    // Завершаем способность
    EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, false, false);
}

void UMeleeAttackAbility::OnApplyDamageNotify(FName NotifyName)
{
    // Этот метод вызывается когда анимация достигает Animation Notify с указанным именем
    // Например, имя "ApplyDamage" будет соответствовать моменту нанесения урона в анимации
    
    if (NotifyName == FName("ApplyDamage") && CurrentActorInfo)
    {
        if (ATronRpgBaseCharacter* BaseCharacter = Cast<ATronRpgBaseCharacter>(CurrentActorInfo->AvatarActor.Get()))
        {
            // Получаем текущий счетчик комбо
            UTronRpgComboComponent* ComboComp = BaseCharacter->GetComboComponent();
            int32 CurrentCombo = (ComboComp) ? ComboComp->GetComboCount() - 1 : 0;
            
            // Ограничиваем значение комбо
            CurrentCombo = FMath::Clamp(CurrentCombo, 0, MaxComboCount - 1);
            
            // Применяем урон в момент указанный в анимации
            ApplyDamageToTargets(BaseCharacter, CurrentCombo);
            
            UE_LOG(LogWeaponSystem, Log, TEXT("Apply damage notify triggered. Combo: %d"), CurrentCombo);
        }
    }
}

void UMeleeAttackAbility::ApplyDamageToTargets(ATronRpgBaseCharacter* SourceCharacter, int32 ComboCount)
{
    if (!SourceCharacter || !DamageEffect)
    {
        UE_LOG(LogWeaponSystem, Warning, TEXT("Invalid parameters for ApplyDamageToTargets"));
        return;
    }
    
    // Находим цели в радиусе атаки
    TArray<AActor*> TargetsInRange = FindTargetsInAttackRange(SourceCharacter);
    
    // Если не нашли ни одной цели, выходим
    if (TargetsInRange.Num() == 0)
    {
        UE_LOG(LogWeaponSystem, Log, TEXT("No targets found in attack range"));
        return;
    }
    
    // Для каждой найденной цели проверяем возможность нанесения урона и применяем его
    for (AActor* Target : TargetsInRange)
    {
        if (CanApplyDamageToTarget(Target))
        {
            // Определяем, будет ли удар критическим
            bool bIsCritical = false;
            float DamageAmount = CalculateDamage(ComboCount, bIsCritical);
            
            // Создаем спецификацию эффекта для нанесения урона
            FGameplayEffectSpecHandle DamageSpecHandle = CreateDamageEffectSpec(Target, DamageAmount, bIsCritical);
            
            // Проверяем, что спецификация валидна
            if (DamageSpecHandle.IsValid())
            {
                // Получаем ASC цели
                UAbilitySystemComponent* TargetASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Target);
                if (TargetASC)
                {
                    // Применяем эффект к цели
                    FActiveGameplayEffectHandle ActiveGEHandle = TargetASC->ApplyGameplayEffectSpecToSelf(*DamageSpecHandle.Data.Get());
                    
                    // Логируем результат для отладки
                    if (ActiveGEHandle.IsValid())
                    {
                        UE_LOG(LogWeaponSystem, Log, TEXT("Applied damage (%.1f) to %s. Combo: %d, Critical: %s"),
                            DamageAmount, *Target->GetName(), ComboCount, bIsCritical ? TEXT("Yes") : TEXT("No"));
                    }
                    else
                    {
                        UE_LOG(LogWeaponSystem, Warning, TEXT("Failed to apply damage to %s"), *Target->GetName());
                    }
                }
            }
        }
    }
}

bool UMeleeAttackAbility::CanApplyDamageToTarget(AActor* Target) const
{
    // Проверка валидности цели
    if (!Target || !IsValid(Target))
    {
        return false;
    }
    
    // Проверка, что цель не является источником атаки
    if (const FGameplayAbilityActorInfo* ActorInfo = GetCurrentActorInfo())
    {
        if (Target == ActorInfo->AvatarActor.Get())
        {
            return false;
        }
    }
    
    // Проверка наличия у цели AbilitySystemComponent
    UAbilitySystemComponent* TargetASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Target);
    if (!TargetASC)
    {
        return false;
    }
    
    // Проверка тегов цели - теги, требуемые для возможности атаковать цель
    if (!AttackConfig.TargetRequiredTags.IsEmpty())
    {
        FGameplayTagContainer TargetTags;
        TargetASC->GetOwnedGameplayTags(TargetTags);
        
        // Цель должна иметь хотя бы один из требуемых тегов
        if (!TargetTags.HasAny(AttackConfig.TargetRequiredTags))
        {
            return false;
        }
    }
    
    // Проверка блокирующих тегов - теги, которые делают цель неуязвимой
    if (!AttackConfig.TargetBlockedTags.IsEmpty())
    {
        FGameplayTagContainer TargetTags;
        TargetASC->GetOwnedGameplayTags(TargetTags);
        
        // Если у цели есть хотя бы один блокирующий тег, она не может быть атакована
        if (TargetTags.HasAny(AttackConfig.TargetBlockedTags))
        {
            return false;
        }
    }
    
    return true;
}

TArray<AActor*> UMeleeAttackAbility::FindTargetsInAttackRange(ATronRpgBaseCharacter* SourceCharacter) const
{
    TArray<AActor*> TargetsInRange;
    
    if (!SourceCharacter)
    {
        return TargetsInRange;
    }
    
    // Получаем меш оружия для более точной трассировки
    UStaticMeshComponent* WeaponMesh = nullptr;
    UWeaponComponent* WeaponComp = SourceCharacter->GetWeaponComponent();
    if (WeaponComp)
    {
        WeaponMesh = WeaponComp->MainHandMeshComponent;
    }
    
    if (!WeaponMesh || !WeaponMesh->IsVisible())
    {
        // Если не найден меш оружия или оно невидимо, 
        // используем сферическую трассировку от позиции персонажа
        FVector CharacterLocation = SourceCharacter->GetActorLocation();
        FVector ForwardVector = SourceCharacter->GetActorForwardVector();
        
        // Игнорируем источник атаки и его компоненты
        TArray<AActor*> ActorsToIgnore;
        ActorsToIgnore.Add(SourceCharacter);
        
        // Создаем массив типов объектов для трассировки (только акторы с коллизией)
        TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
        ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));
        
        // Выполняем сферическую трассировку перед персонажем
        TArray<AActor*> OutActors;
        FVector SphereCenter = CharacterLocation + ForwardVector * (AttackConfig.AttackRadius * 0.5f);
        UKismetSystemLibrary::SphereOverlapActors(
            SourceCharacter->GetWorld(),
            SphereCenter,
            AttackConfig.AttackRadius,
            ObjectTypes,
            nullptr, // Класс фильтрации (nullptr = все классы)
            ActorsToIgnore,
            OutActors
        );
        
        // Фильтруем результаты по углу атаки
        for (AActor* Actor : OutActors)
        {
            // Проверка угла между направлением персонажа и направлением к цели
            FVector DirectionToTarget = (Actor->GetActorLocation() - CharacterLocation).GetSafeNormal2D();
            float DotProduct = FVector::DotProduct(ForwardVector, DirectionToTarget);
            float AngleRadians = FMath::Acos(DotProduct);
            float AngleDegrees = FMath::RadiansToDegrees(AngleRadians);
            
            // Если цель находится в пределах угла атаки, добавляем ее
            if (AngleDegrees <= AttackConfig.AttackAngle * 0.5f)
            {
                TargetsInRange.Add(Actor);
            }
        }
    }
    else
    {
        // Если меш оружия найден, используем сокеты для более точной трассировки
        
        // Игнорируем источник атаки и его компоненты
        TArray<AActor*> ActorsToIgnore;
        ActorsToIgnore.Add(SourceCharacter);
        
        // Создаем массив типов объектов для трассировки
        TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
        ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));
        
        // Для каждого сокета трассировки выполняем проверку
        for (const FName& SocketName : WeaponTraceSocketNames)
        {
            if (WeaponMesh->DoesSocketExist(SocketName))
            {
                // Получаем положение сокета
                FVector SocketLocation = WeaponMesh->GetSocketLocation(SocketName);
                
                // Выполняем сферическую трассировку вокруг сокета
                TArray<AActor*> OutActors;
                UKismetSystemLibrary::SphereOverlapActors(
                    SourceCharacter->GetWorld(),
                    SocketLocation,
                    AttackConfig.AttackRadius * 0.25f, // Уменьшенный радиус для точной трассировки вокруг оружия
                    ObjectTypes,
                    nullptr,
                    ActorsToIgnore,
                    OutActors
                );
                
                // Добавляем найденные цели в результирующий массив
                for (AActor* Actor : OutActors)
                {
                    if (!TargetsInRange.Contains(Actor))
                    {
                        TargetsInRange.Add(Actor);
                    }
                }
            }
        }
        
        // Дополнительно выполняем трассировку вперед от персонажа для атак с большим охватом
        FVector CharacterLocation = SourceCharacter->GetActorLocation();
        FVector ForwardVector = SourceCharacter->GetActorForwardVector();
        
        TArray<AActor*> ForwardActors;
        FVector SphereCenter = CharacterLocation + ForwardVector * AttackConfig.AttackRadius * 0.5f;
        UKismetSystemLibrary::SphereOverlapActors(
            SourceCharacter->GetWorld(),
            SphereCenter,
            AttackConfig.AttackRadius,
            ObjectTypes,
            nullptr,
            ActorsToIgnore,
            ForwardActors
        );
        
        // Фильтруем результаты по углу атаки и добавляем новые цели
        for (AActor* Actor : ForwardActors)
        {
            if (!TargetsInRange.Contains(Actor))
            {
                // Проверка угла между направлением персонажа и направлением к цели
                FVector DirectionToTarget = (Actor->GetActorLocation() - CharacterLocation).GetSafeNormal2D();
                float DotProduct = FVector::DotProduct(ForwardVector, DirectionToTarget);
                float AngleRadians = FMath::Acos(DotProduct);
                float AngleDegrees = FMath::RadiansToDegrees(AngleRadians);
                
                // Если цель находится в пределах угла атаки, добавляем ее
                if (AngleDegrees <= AttackConfig.AttackAngle * 0.5f)
                {
                    TargetsInRange.Add(Actor);
                }
            }
        }
    }
    
    return TargetsInRange;
}

float UMeleeAttackAbility::CalculateDamage(int32 ComboCount, bool& bIsCritical) const
{
    // Базовый урон из конфигурации
    float Damage = AttackConfig.BaseDamage;
    
    // Если задана кривая изменения урона от комбо, используем ее
    if (ComboDamageCurve)
    {
        // Нормализуем значение комбо для кривой (0-1)
        float NormalizedCombo = ComboCount / static_cast<float>(MaxComboCount - 1);
        float DamageMultiplier = ComboDamageCurve->GetFloatValue(NormalizedCombo);
        
        // Применяем множитель к базовому урону
        Damage *= DamageMultiplier;
    }
    else
    {
        // Если кривая не задана, используем линейное увеличение урона с каждым комбо
        Damage *= (1.0f + 0.2f * ComboCount); // 20% увеличение за каждый удар в комбо
    }
    
    // Проверка на критический удар
    float CriticalRoll = FMath::FRand(); // Случайное число от 0 до 1
    bIsCritical = (CriticalRoll <= AttackConfig.CriticalChance);
    
    // Если удар критический, применяем множитель критического урона
    if (bIsCritical)
    {
        Damage *= AttackConfig.CriticalMultiplier;
    }
    
    return Damage;
}

FGameplayEffectSpecHandle UMeleeAttackAbility::CreateDamageEffectSpec(AActor* Target, float DamageAmount, bool bIsCritical)
{
    if (!DamageEffect || !Target)
    {
        return FGameplayEffectSpecHandle();
    }

    const FGameplayAbilityActorInfo* ActorInfo = GetCurrentActorInfo();
    if (!ActorInfo || !ActorInfo->AbilitySystemComponent.IsValid())
    {
        return FGameplayEffectSpecHandle();
    }

    // Создаем контекст эффекта
    FGameplayEffectContextHandle EffectContext = ActorInfo->AbilitySystemComponent->MakeEffectContext();
    EffectContext.AddSourceObject(this); // Источник эффекта - сама способность
    EffectContext.AddInstigator(ActorInfo->OwnerActor.Get(), ActorInfo->AvatarActor.Get());

    // Создаем спецификацию эффекта
    FGameplayEffectSpecHandle SpecHandle = ActorInfo->AbilitySystemComponent->MakeOutgoingSpec(
        DamageEffect, 1.0f, EffectContext);

    if (SpecHandle.IsValid())
    {
        // Устанавливаем значение урона через SetByCallerMagnitude
        SpecHandle.Data->SetSetByCallerMagnitude(TAG_Damage, DamageAmount);

        // Если удар критический, добавляем соответствующий тег
        if (bIsCritical)
        {
            SpecHandle.Data->AddDynamicAssetTag(TAG_Damage_Critical);
        }
    }

    return SpecHandle;
}