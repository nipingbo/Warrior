// Raymond Study

#pragma once

#include "WarriorStructTypes.generated.h"

class UWarriorHeroLinkedAnimLayer;

USTRUCT(BlueprintType)
struct FWarriorHeroWeaponData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UWarriorHeroLinkedAnimLayer> WeaponAnimLayerToLink;
};