// Raymond Study


#include "Characters/WarriorEnemyCharacter.h"

#include "Components/Combat/EnemyCombatComponent.h"
#include "Components/UI/EnemyUIComponent.h"
#include "DataAssets/StartupData/DataAsset_StartupDataBase.h"
#include "Engine/AssetManager.h"
#include "GameFramework/CharacterMovementComponent.h"

AWarriorEnemyCharacter::AWarriorEnemyCharacter()
{
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 180.0f, 0.0f);
	GetCharacterMovement()->MaxWalkSpeed = 300.0f;
	GetCharacterMovement()->BrakingDecelerationWalking = 1000.f;
	
	EnemyCombatComponent = CreateDefaultSubobject<UEnemyCombatComponent>("EnemyCombatComponent");
	EnemyUIComponent = CreateDefaultSubobject<UEnemyUIComponent>("EnemyUIComponent");
}

UPawnCombatComponent* AWarriorEnemyCharacter::GetPawnCombatComponent() const
{
	return EnemyCombatComponent;
}

UPawnUIComponent* AWarriorEnemyCharacter::GetPawnUIComponent() const
{
	return EnemyUIComponent;
}

void AWarriorEnemyCharacter::PossessedBy(AController* PossessedController)
{
	Super::PossessedBy(PossessedController);
	
	InitEnemyStartupData();
}

void AWarriorEnemyCharacter::InitEnemyStartupData()
{
	if (CharacterStartUpData.IsNull()) return;
	
	UAssetManager::GetStreamableManager().RequestAsyncLoad(
		CharacterStartUpData.ToSoftObjectPath(),
		FStreamableDelegate::CreateLambda(
			[this]()
			{
				if (UDataAsset_StartupDataBase* LoadedData = CharacterStartUpData.Get())
				{
					LoadedData->GiveToAbilitySystemComponent(WarriorAbilitySystemComponent);
				}
				
			})
		);
}
