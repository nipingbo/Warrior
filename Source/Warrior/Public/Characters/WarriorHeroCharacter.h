// Raymond Study

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Characters/WarriorBaseCharacter.h"
#include "WarriorHeroCharacter.generated.h"

class UHeroUIComponent;
struct FInputActionValue;
class UHeroCombatComponent;
class UDataAsset_InputConfig;
class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class WARRIOR_API AWarriorHeroCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()
	
public:
	AWarriorHeroCharacter();
	
	// Begin IPawnCombatInterface Interface
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
	// End IPawnCombatInterface Interface
	
	// Begin IPawnUIInterface Interface
	UPawnUIComponent* GetPawnUIComponent() const override;
	// End IPawnUIInterface Interface
	
protected:
	// Begin APawn Interface
	virtual void PossessedBy(AController* PossessedController) override;
	// End APawn Interface
	
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;
	
private:
		
#pragma region Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Warrior|Camera", meta = (AllowPrivateAccess = true))
	USpringArmComponent* CameraBoom;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Warrior|Camera", meta = (AllowPrivateAccess = true))
	UCameraComponent* FollowCamera;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Warrior|Combat", meta = (AllowPrivateAccess = true))
	UHeroCombatComponent* HeroCombatComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Warrior|UI", meta = (AllowPrivateAccess = true))
	UHeroUIComponent* HeroUIComponent;
	
#pragma endregion Components

#pragma region Inputs
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WarriorCharacter", meta = (AllowPrivateAccess = true))
	UDataAsset_InputConfig* InputConfigDataAsset;
	
	void Input_Move(const FInputActionValue& InputActionValue);
	void Input_Look(const FInputActionValue& InputActionValue);
	
	void Input_AbilityInputPressed(FGameplayTag InInputTag);
	void Input_AbilityInputReleased(FGameplayTag InInputTag);
	
#pragma endregion Inputs
	
public:
	FORCEINLINE UHeroCombatComponent* GetHeroCombatComponent() const { return HeroCombatComponent; }
};
