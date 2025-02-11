#include "Object/GameplayTagsLibrary.h"

#include "GameplayTagContainer.h"

// Инициализируем статические константы. 
// FGameplayTag::RequestGameplayTag ищет тег по имени, убедитесь, что в вашем проекте этот тег добавлен в DefaultGameplayTags.ini или в настройках Gameplay Tags.
const FGameplayTag UGameplayTagsLibrary::Attack_Melee = FGameplayTag::RequestGameplayTag(FName("GameplayCue.Attack.Melee"));

// Пример других тегов:
// const FGameplayTag UGameplayTagsLibrary::Spell_MagicOrb = FGameplayTag::RequestGameplayTag(FName("GameplayCue.Spell.MagicOrb"));
// const FGameplayTag UGameplayTagsLibrary::State_Stunned = FGameplayTag::RequestGameplayTag(FName("State.Stunned"));
// const FGameplayTag UGameplayTagsLibrary::State_Attacking = FGameplayTag::RequestGameplayTag(FName("State.Attacking"));
