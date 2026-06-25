// Raymond Study

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartupDataBase.generated.h"

class UGameplayEffect;
class UWarriorAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_StartupDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Warrior|StartupData")
	TArray<TSubclassOf<class UWarriorGameplayAbility> >	ActivateOnGivenAbilities;
	
	UPROPERTY(EditDefaultsOnly, Category = "Warrior|StartupData")
	TArray<TSubclassOf<class UWarriorGameplayAbility> >	ReactiveAbilities;
	
	UPROPERTY(EditDefaultsOnly, Category = "Warrior|StartupData")
	TArray< TSubclassOf<UGameplayEffect> >	StartUpGameplayEffects;
	
	void GrantAbilities(const TArray<TSubclassOf <UWarriorGameplayAbility> >& InAbilitiesToGive, UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);	
};
