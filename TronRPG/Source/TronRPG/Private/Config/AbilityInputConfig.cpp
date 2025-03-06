// Tron


#include "Config/AbilityInputConfig.h"

FAbilityInputBinding UAbilityInputConfig::FindBindingByTag(FGameplayTag AbilityTag) const
{
	for (const FAbilityInputBinding& Binding : AbilityBindings)
	{
		if (Binding.AbilityTag == AbilityTag)
		{
			return Binding;
		}
	}

	return FAbilityInputBinding();
}

FAbilityInputBinding UAbilityInputConfig::FindBindingByInputAction(const UInputAction* InputAction) const
{
	if (!InputAction)
	{
		return FAbilityInputBinding();
	}

	for (const FAbilityInputBinding& Binding : AbilityBindings)
	{
		if (Binding.InputAction == InputAction)
		{
			return Binding;
		}
	}

	return FAbilityInputBinding();
}
