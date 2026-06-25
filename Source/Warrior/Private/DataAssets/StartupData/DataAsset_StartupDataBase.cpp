// Raymond Study


#include "DataAssets/StartupData/DataAsset_StartupDataBase.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"

void UDataAsset_StartupDataBase::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive,
                                                              int32 ApplyLevel)
{
	check(InASCToGive);
	GrandAbilities(ActivateOnGivenAbilities, InASCToGive, ApplyLevel);
	GrandAbilities(ReactiveAbilities, InASCToGive, ApplyLevel);
	if (!StartUpGameplayEffects.IsEmpty())
	{
		for (const auto& EffectClass: StartUpGameplayEffects)
		{
			if (!EffectClass) continue;
			
			UGameplayEffect* EffectCDO = EffectClass->GetDefaultObject<UGameplayEffect>();
			InASCToGive->ApplyGameplayEffectToSelf( EffectCDO, ApplyLevel, InASCToGive->MakeEffectContext());
		}
	}
	
}

void UDataAsset_StartupDataBase::GrantAbilities(const TArray<TSubclassOf<UWarriorGameplayAbility>>& InAbilitiesToGive,
	UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}
	
	for (const auto& Ability : InAbilitiesToGive)
	{
		if (!Ability) continue;
		
		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		
		InASCToGive->GiveAbility(AbilitySpec);
	}
}
