#include "Input/TronRpgEnhancedInputComponent.h"

#include "Character/TronRpgBaseCharacter.h"
#include "Component/TronRpgComboComponent.h"
#include "GAS/TronRpgAbilitySystemComponent.h"
#include "AbilitySystemComponent.h"
#include "EnhancedInputSubsystemInterface.h"
#include "Object/GameplayTagsLibrary.h"
#include "GameplayAbility/MeleeAttackAbility.h"

UTronRpgEnhancedInputComponent::UTronRpgEnhancedInputComponent()
{
	// Инициализация по умолчанию
	OwningCharacter = nullptr;
	AbilitySystemComponent = nullptr;
}

void UTronRpgEnhancedInputComponent::BeginPlay()
{
	Super::BeginPlay();

	// Инициализация кэшированных ссылок
	UpdateCachedReferences();

	// Инициализация системы способностей
	InitializeAbilitySystem();
}

void UTronRpgEnhancedInputComponent::UpdateCachedReferences()
{
	// Получаем владельца компонента
	AActor* Owner = GetOwner();
	if (Owner)
	{
		OwningCharacter = Cast<ATronRpgBaseCharacter>(Owner);

		if (!OwningCharacter)
		{
			// Проверяем, не является ли владелец контроллером
			if (AController* Controller = Cast<AController>(Owner))
			{
				OwningCharacter = Cast<ATronRpgBaseCharacter>(Controller->GetPawn());
			}
		}
	}

	if (!OwningCharacter)
	{
		UE_LOG(LogTemp, Warning, TEXT("TronEnhancedRpgInputComponent: Failed to find owning character"));
	}
}

void UTronRpgEnhancedInputComponent::InitializeAbilitySystem()
{
	// Получаем AbilitySystemComponent из владельца если его еще нет
	if (!AbilitySystemComponent && OwningCharacter)
	{
		AbilitySystemComponent = Cast<UTronRpgAbilitySystemComponent>(
			OwningCharacter->GetAbilitySystemComponent());

		if (!AbilitySystemComponent)
		{
			UE_LOG(LogTemp, Warning, TEXT("TronEnhancedRpgInputComponent: Failed to find AbilitySystemComponent"));
		}
	}
}

void UTronRpgEnhancedInputComponent::SetupPlayerInput(UInputComponent* PlayerInputComponent)
{
	if (!PlayerInputComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("TronEnhancedRpgInputComponent: SetupPlayerInput failed - invalid component"));
		return;
	}

	// Настраиваем привязки способностей
	SetupAbilityBindings();
}

void UTronRpgEnhancedInputComponent::SetupAbilityBindings()
{
	// Обновляем ссылки если нужно
	if (!OwningCharacter || !AbilitySystemComponent)
	{
		UpdateCachedReferences();
		InitializeAbilitySystem();

		if (!OwningCharacter || !AbilitySystemComponent)
		{
			UE_LOG(LogTemp, Error, TEXT("TronEnhancedRpgInputComponent: Failed to setup ability bindings - missing references"));
			return;
		}
	}

	// Связываем действия ввода с соответствующими действиями способностей
	for (const FAbilityInputBinding& Binding : AbilityBindings)
	{
		if (Binding.InputAction)
		{
			// Привязываем EnhancedInput к нашим функциям-обработчикам
			BindAction(Binding.InputAction, ETriggerEvent::Started,
			           this, &UTronRpgEnhancedInputComponent::OnAbilityInputPressed, Binding);

			BindAction(Binding.InputAction, ETriggerEvent::Completed,
			           this, &UTronRpgEnhancedInputComponent::OnAbilityInputReleased, Binding);

			UE_LOG(LogTemp, Log, TEXT("TronEnhancedRpgInputComponent: Bound input action %s to tag %s"),
			       *Binding.InputAction->GetName(), *Binding.AbilityTag.ToString());
		}
	}
}

void UTronRpgEnhancedInputComponent::AddAbilityBinding(UInputAction* InputAction, FGameplayTag AbilityTag, bool bCancelOnRelease)
{
	// Проверка валидности входных параметров
	if (!InputAction || !AbilityTag.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("TronEnhancedRpgInputComponent: AddAbilityBinding failed - invalid parameters"));
		return;
	}

	// Проверяем, не существует ли уже такая привязка
	for (const FAbilityInputBinding& Binding : AbilityBindings)
	{
		if (Binding.InputAction == InputAction && Binding.AbilityTag == AbilityTag)
		{
			UE_LOG(LogTemp, Warning, TEXT("TronEnhancedRpgInputComponent: Binding already exists for action %s with tag %s"),
			       *InputAction->GetName(), *AbilityTag.ToString());
			return;
		}
	}

	// Добавляем новую привязку
	FAbilityInputBinding NewBinding;
	NewBinding.InputAction = InputAction;
	NewBinding.AbilityTag = AbilityTag;
	NewBinding.bCancelOnRelease = bCancelOnRelease;

	AbilityBindings.Add(NewBinding);
	UE_LOG(LogTemp, Log, TEXT("TronEnhancedRpgInputComponent: Added input binding for action %s with tag %s"),
	       *InputAction->GetName(), *AbilityTag.ToString());
}

void UTronRpgEnhancedInputComponent::OnAbilityInputPressed(const FInputActionValue& InputValue, FAbilityInputBinding Binding)
{
	if (!OwningCharacter || !AbilitySystemComponent)
	{
		UpdateCachedReferences();
		InitializeAbilitySystem();

		if (!OwningCharacter || !AbilitySystemComponent)
		{
			UE_LOG(LogTemp, Warning, TEXT("TronEnhancedRpgInputComponent: OnAbilityInputPressed - missing references"));
			return;
		}
	}

	// Вызываем делегат
	OnActionTriggered.Broadcast(Binding.InputAction, InputValue);
	
	// Пытаемся активировать способность
	TryActivateAbilityByTag(Binding.AbilityTag);
}

void UTronRpgEnhancedInputComponent::OnAbilityInputReleased(const FInputActionValue& InputValue, FAbilityInputBinding Binding)
{
	if (!OwningCharacter || !AbilitySystemComponent)
	{
		UpdateCachedReferences();
		InitializeAbilitySystem();

		if (!OwningCharacter || !AbilitySystemComponent)
		{
			return;
		}
	}

	// Вызываем делегат
	OnActionCompleted.Broadcast(Binding.InputAction, InputValue);

	// Обрабатываем отпускание кнопки, если нужно отменить способность
	if (Binding.bCancelOnRelease)
	{
		// Создаем контейнер тегов для отмены
		FGameplayTagContainer TagContainer;
		TagContainer.AddTag(Binding.AbilityTag);

		// Отменяем способности с указанным тегом
		AbilitySystemComponent->CancelAbilities(&TagContainer);
	}
}

bool UTronRpgEnhancedInputComponent::TryActivateAbilityByTag(const FGameplayTag& AbilityTag)
{
	if (!AbilitySystemComponent)
	{
		InitializeAbilitySystem();
		if (!AbilitySystemComponent)
			return false;
	}

	// Создаем контейнер тегов для активации
	FGameplayTagContainer AbilityTags;
	AbilityTags.AddTag(AbilityTag);

	// Пытаемся активировать способность
	bool bActivated = AbilitySystemComponent->TryActivateAbilitiesByTag(AbilityTags);
	

	if (bActivated)
	{
		UE_LOG(LogTemp, Log, TEXT("TronEnhancedRpgInputComponent: Successfully activated ability with tag %s"),
		       *AbilityTag.ToString());
	}
	else
	{
		UE_LOG(LogTemp, Verbose, TEXT("TronEnhancedRpgInputComponent: Failed to activate ability with tag %s"),
		       *AbilityTag.ToString());
	}

	return bActivated;
}

void UTronRpgEnhancedInputComponent::ProcessComboInput(const FInputActionValue& InputValue)
{
    if (!OwningCharacter)
    {
        UpdateCachedReferences();
        if (!OwningCharacter)
            return;
    }
	
    // Получаем компонент комбо
    UTronRpgComboComponent* ComboComp = OwningCharacter->GetComboComponent_Implementation();
    if (!ComboComp)
    {
        UE_LOG(LogTemp, Warning, TEXT("ProcessComboInput: No ComboComponent found"));
        // Если нет компонента комбо, пытаемся активировать новую атаку
        TryActivateAbilityByTag(TAG_Ability_Combat_Melee);
        return;
    }
    
    // Если комбо в максимуме или окно не открыто, активируем новую атаку
    if (ComboComp->GetCurrentComboCount() >= ComboComp->GetMaxComboCount() - 1 || !ComboComp->IsComboWindowOpen())
    {
        // Если достигнут максимум комбо, сбрасываем его
        if (ComboComp->GetCurrentComboCount() >= ComboComp->GetMaxComboCount() - 1)
        {
            UE_LOG(LogTemp, Warning, TEXT("Maximum combo count reached, resetting combo"));
            ComboComp->ResetCombo();
        }
        
        // Активируем новую атаку
        UE_LOG(LogTemp, Log, TEXT("Starting new attack sequence"));
        TryActivateAbilityByTag(TAG_Ability_Combat_Melee);
        return;
    }
    
    // Обрабатываем комбо-ввод
    UE_LOG(LogTemp, Log, TEXT("Processing combo input in open window"));
    bool bComboProcessed = ComboComp->ProcessComboInput();
    
    // Если обработка комбо успешна, находим активную способность для продолжения
    if (bComboProcessed)
    {
        // Получаем AbilitySystemComponent
        UAbilitySystemComponent* ASC = OwningCharacter->GetAbilitySystemComponent();
        if (!ASC)
        {
            UE_LOG(LogTemp, Error, TEXT("No AbilitySystemComponent found"));
            return;
        }
        
        // Ищем активную способность атаки
        FGameplayTagContainer AbilityTags;
        AbilityTags.AddTag(TAG_Ability_Combat_Melee);
        TArray<FGameplayAbilitySpec*> ActiveAbilities;
        ASC->GetActivatableGameplayAbilitySpecsByAllMatchingTags(AbilityTags, ActiveAbilities);
        
        // Продолжаем комбо в активной способности
        bool foundActiveAbility = false;
        for (FGameplayAbilitySpec* AbilitySpec : ActiveAbilities)
        {
            if (AbilitySpec && AbilitySpec->IsActive())
            {
                UMeleeAttackAbility* MeleeAbility = Cast<UMeleeAttackAbility>(AbilitySpec->GetPrimaryInstance());
                if (MeleeAbility)
                {
                    foundActiveAbility = true;
                    UE_LOG(LogTemp, Log, TEXT("Found active MeleeAttackAbility - continuing combo"));
                    bool bComboContinued = MeleeAbility->ContinueComboAttack();
                    
                    if (!bComboContinued)
                    {
                        UE_LOG(LogTemp, Warning, TEXT("Failed to continue combo in ability"));
                    }
                    
                    return;
                }
            }
        }
        
        if (!foundActiveAbility)
        {
            UE_LOG(LogTemp, Error, TEXT("No active MeleeAttackAbility found despite open combo window"));
            // Восстанавливаем состояние, активируя новую атаку
            TryActivateAbilityByTag(TAG_Ability_Combat_Melee);
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to process combo input in ComboComponent"));
    }
}

void UTronRpgEnhancedInputComponent::SetAbilitySystemComponent(UTronRpgAbilitySystemComponent* InAbilitySystemComponent)
{
	AbilitySystemComponent = InAbilitySystemComponent;
}

ATronRpgBaseCharacter* UTronRpgEnhancedInputComponent::GetOwningCharacter() const
{
	return OwningCharacter;
}
