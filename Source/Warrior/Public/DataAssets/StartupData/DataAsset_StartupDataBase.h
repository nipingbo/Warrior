// Raymond Study

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartupDataBase.generated.h"

class UWarriorAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_StartupDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InWarriorASCToGive, int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Warrior|StartupData")
	TArray<TSubclassOf<class UWarriorGameplayAbility> >	ActivateOnGivenAbilities;
	
	UPROPERTY(EditDefaultsOnly, Category = "Warrior|StartupData")
	TArray<TSubclassOf<class UWarriorGameplayAbility> >	ReactiveAbilities;
	
	void GrandAbilities(const TArray<TSubclassOf <UWarriorGameplayAbility> >& InAbilitiesToGive, UWarriorAbilitySystemComponent* InWarriorASCToGive, int32 ApplyLevel = 1);	
};
