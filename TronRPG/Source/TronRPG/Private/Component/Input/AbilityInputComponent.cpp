#include "Component/Input/AbilityInputComponent.h"

#include "GAS/TronRpgAbilitySystemComponent.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "AbilitySystemGlobals.h"
#include "GameplayAbilitySpec.h"

UAbilityInputComponent::UAbilityInputComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	SetIsReplicatedByDefault(true);
}

void UAbilityInputComponent::BeginPlay()
{
	Super::BeginPlay();

	// Перенесем инициализацию AbilitySystemComponent из BeginPlay в отдельный метод
	InitializeAbilitySystem();
}

void UAbilityInputComponent::InitializeAbilitySystem()
{
	// Получаем AbilitySystemComponent из владельца
	if (!AbilitySystemComponent)
	{
		AbilitySystemComponent = Cast<UTronRpgAbilitySystemComponent>(
			GetOwner()->GetComponentByClass(UTronRpgAbilitySystemComponent::StaticClass())
		);

		if (!AbilitySystemComponent)
		{
			UE_LOG(LogTemp, Error, TEXT("AbilityInputComponent: Failed to find AbilitySystemComponent"));
		}
	}
}

void UAbilityInputComponent::SetupPlayerInput(UInputComponent* PlayerInputComponent)
{
	InitializeAbilitySystem();

	if (!PlayerInputComponent || !AbilitySystemComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("AbilityInputComponent: SetupPlayerInput failed - invalid components"));
		return;
	}

	// Приводим к EnhancedInputComponent
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!EnhancedInputComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("AbilityInputComponent: PlayerInputComponent is not UEnhancedInputComponent"));
		return;
	}

	// Связываем действия ввода с соответствующими действиями способностей
	for (const FAbilityInputBinding& Binding : AbilityInputBindings)
	{
		if (Binding.InputAction)
		{
			// Привязываем EnhancedInput к нашим функциям-обработчикам
			EnhancedInputComponent->BindAction(Binding.InputAction, ETriggerEvent::Started,
			                                   this, &UAbilityInputComponent::OnAbilityInputPressed, Binding);

			EnhancedInputComponent->BindAction(Binding.InputAction, ETriggerEvent::Completed,
			                                   this, &UAbilityInputComponent::OnAbilityInputReleased, Binding);

			UE_LOG(LogTemp, Log, TEXT("AbilityInputComponent: Bound input action %s to tag %s"),
			       *Binding.InputAction->GetName(), *Binding.AbilityTag.ToString());
		}
	}
}

void UAbilityInputComponent::OnAbilityInputPressed(const FInputActionValue& InputValue, FAbilityInputBinding Binding)
{
	if (!AbilitySystemComponent || !Binding.AbilityTag.IsValid())
	{
		return;
	}

	// Логируем нажатие клавиши для отладки
	UE_LOG(LogTemp, Log, TEXT("AbilityInputComponent: Input pressed for tag %s"), *Binding.AbilityTag.ToString());

	// Пытаемся найти способность с соответствующим тегом
	FGameplayAbilitySpec* FoundSpec = nullptr;
	for (const FGameplayAbilitySpec& Spec : AbilitySystemComponent->GetActivatableAbilities())
	{
		if (Spec.Ability && Spec.Ability->GetAssetTags().HasTag(Binding.AbilityTag))
		{
			FoundSpec = const_cast<FGameplayAbilitySpec*>(&Spec);
			break;
		}
	}

	// Если нашли способность, активируем её
	if (FoundSpec)
	{
		AbilitySystemComponent->TryActivateAbility(FoundSpec->Handle);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AbilityInputComponent: No ability found with tag %s"),
		       *Binding.AbilityTag.ToString());
	}
}

void UAbilityInputComponent::OnAbilityInputReleased(const FInputActionValue& InputValue, FAbilityInputBinding Binding)
{
	if (!AbilitySystemComponent || !Binding.AbilityTag.IsValid())
	{
		return;
	}

	// Обрабатываем отпускание кнопки, если нужно отменить способность
	if (Binding.bCancelOnRelease)
	{
		// Находим активные способности с соответствующим тегом
		FGameplayAbilitySpec* FoundSpec = nullptr;
		for (const FGameplayAbilitySpec& Spec : AbilitySystemComponent->GetActivatableAbilities())
		{
			if (Spec.Ability && Spec.Ability->GetAssetTags().HasTag(Binding.AbilityTag) && Spec.IsActive())
			{
				FoundSpec = const_cast<FGameplayAbilitySpec*>(&Spec);
				break;
			}
		}

		// Если нашли активную способность, отменяем её
		if (FoundSpec)
		{
			AbilitySystemComponent->CancelAbilityHandle(FoundSpec->Handle);
			UE_LOG(LogTemp, Log, TEXT("AbilityInputComponent: Canceled ability with tag %s"),
			       *Binding.AbilityTag.ToString());
		}
	}
}

void UAbilityInputComponent::AddInputBinding(UInputAction* InInputAction, FGameplayTag InAbilityTag, bool bInCancelOnRelease)
{
	// Проверка валидности входных параметров
	if (!InInputAction || !InAbilityTag.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("AbilityInputComponent: AddInputBinding failed - invalid parameters"));
		return;
	}

	// Проверяем, не существует ли уже такая привязка
	for (const FAbilityInputBinding& Binding : AbilityInputBindings)
	{
		if (Binding.InputAction == InInputAction && Binding.AbilityTag == InAbilityTag)
		{
			UE_LOG(LogTemp, Warning, TEXT("AbilityInputComponent: Binding already exists for action %s with tag %s"),
			       *InInputAction->GetName(), *InAbilityTag.ToString());
			return;
		}
	}

	// Добавляем новую привязку
	FAbilityInputBinding NewBinding;
	NewBinding.InputAction = InInputAction;
	NewBinding.AbilityTag = InAbilityTag;
	NewBinding.bCancelOnRelease = bInCancelOnRelease;

	AbilityInputBindings.Add(NewBinding);
	UE_LOG(LogTemp, Log, TEXT("AbilityInputComponent: Added input binding for action %s with tag %s"),
	       *InInputAction->GetName(), *InAbilityTag.ToString());
}
