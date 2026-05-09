// Raymond Study

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtensionComponentBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WARRIOR_API UPawnExtensionComponentBase : public UActorComponent
{
	GENERATED_BODY()
	
protected:
	template <class T>
	T* GetOwningPawn() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "'T' Template must be convertible from APawn type.");
		return CastChecked<T>(GetOwner());
	}
	
	APawn* GetOwningPawn() const
	{
		return GetOwningPawn<APawn>();
	}
	
	template <class T>
	T* GetOwningController() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AController>::Value, "'T' Template must be convertible from AController type.");
		return GetOwningPawn()->GetController<T>();
	}
};
