// Raymond Study


#include "WarriorFunctionLibrary.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"

UWarriorAbilitySystemComponent* UWarriorFunctionLibrary::NativeGetWarriorASCFromActor(AActor* InActor)
{
	check(InActor);
	return CastChecked<UWarriorAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
	
}

void UWarriorFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
	if (UWarriorAbilitySystemComponent* ASC = NativeGetWarriorASCFromActor(InActor); !ASC->HasMatchingGameplayTag(TagToAdd))
	{
		ASC->AddLooseGameplayTag(TagToAdd);
	}
}

void UWarriorFunctionLibrary::RemoveGameplayTagFromActor(AActor* InActor, FGameplayTag TagToRemove)
{
	if (UWarriorAbilitySystemComponent* ASC = NativeGetWarriorASCFromActor(InActor); ASC->HasMatchingGameplayTag(TagToRemove))
	{
		ASC->RemoveLooseGameplayTag(TagToRemove);
	}
}

bool UWarriorFunctionLibrary::NativeDoesActorHasTag(AActor* InActor, const FGameplayTag TagToCheck)
{
	const UWarriorAbilitySystemComponent* ASC = NativeGetWarriorASCFromActor(InActor);
	
	return ASC->HasMatchingGameplayTag(TagToCheck);
}

void UWarriorFunctionLibrary::BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck,
	EWarriorConfirmType& OutConfirmType)
{
	OutConfirmType = NativeDoesActorHasTag(InActor, TagToCheck)? EWarriorConfirmType::Yes : EWarriorConfirmType::No; 
}
