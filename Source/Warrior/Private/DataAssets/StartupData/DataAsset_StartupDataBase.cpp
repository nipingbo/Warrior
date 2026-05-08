// Raymond Study


#include "DataAssets/StartupData/DataAsset_StartupDataBase.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"

void UDataAsset_StartupDataBase::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InWarriorASCToGive,
                                                              int32 ApplyLevel)
{
	check(InWarriorASCToGive);
	GrandAbilities(ActivateOnGivenAbilities, InWarriorASCToGive, ApplyLevel);
	GrandAbilities(ReactiveAbilities, InWarriorASCToGive, ApplyLevel);
	
	
}

void UDataAsset_StartupDataBase::GrandAbilities(const TArray<TSubclassOf<UWarriorGameplayAbility>>& InAbilitiesToGive,
	UWarriorAbilitySystemComponent* InWarriorASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}
	
	for (const auto& Ability : InAbilitiesToGive)
	{
		if (!Ability) continue;
		
		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InWarriorASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		
		InWarriorASCToGive->GiveAbility(AbilitySpec);
	}
}
