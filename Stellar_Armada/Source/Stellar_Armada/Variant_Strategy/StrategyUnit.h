// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AIController.h"
#include "StrategyUnit.generated.h"

class AStrategyUnit;
class USphereComponent;

/** Delegate fired whenever health changes */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChanged, AStrategyUnit*, Unit, float, NewHealth);

/** Delegate to report that this unit has finished moving */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUnitMoveCompletedDelegate, AStrategyUnit*, Unit);

/**
 *  A simple strategy game unit
 *  Rather than react to inputs, it's controlled indirectly by the Strategy Player Controller
 */
UCLASS(abstract)
class AStrategyUnit : public ACharacter
{
	GENERATED_BODY()

private:

	/** Interaction range sphere */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USphereComponent* InteractionRange;

protected:

        /** Cast reference to the AI Controlling this unit */
        TObjectPtr<AAIController> AIController;

        /** Team identifier for friendly-fire checks */
        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
        int32 Team;

        /** How far this unit can attack */
        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
        float AttackRange;

        /** Damage dealt per attack */
        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
        float Damage;

        /** Current health of the unit */
        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
        float Health;

        /** True if the unit has already acted this turn */
        UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
        bool bHasActedThisTurn;

public:

        /** Constructor */
        AStrategyUnit();

        /** Event for health changes */
        UPROPERTY(BlueprintAssignable, Category = "Combat")
        FOnHealthChanged OnHealthChanged;

protected:

	virtual void NotifyControllerChanged() override;

public:

	/** Stops unit movement immediately */
	void StopMoving();

	/** Notifies this unit that it was selected */
	void UnitSelected();

	/** Notifies this unit that it was deselected */
	void UnitDeselected();

	/** Notifies this unit that it's been interacted with by another actor */
        void Interact(AStrategyUnit* Interactor);

        /** Attempts to move this unit to its */
        bool MoveToLocation(const FVector& Location, float AcceptanceRadius);

        /** Attempts to attack the provided target */
        UFUNCTION(BlueprintCallable, Category = "Combat")
        void AttackTarget(AStrategyUnit* TargetShip);

protected:

	/** called by the AI controller when this unit has finished moving */
	void OnMoveFinished(FAIRequestID RequestID, const FPathFollowingResult& Result);

protected:

	/** Blueprint handler for strategy game selection */
	UFUNCTION(BlueprintImplementableEvent, Category="NPC", meta = (DisplayName="Unit Selected"))
	void BP_UnitSelected();

	/** Blueprint handler for strategy game deselection */
	UFUNCTION(BlueprintImplementableEvent, Category="NPC", meta = (DisplayName="Unit Deselected"))
	void BP_UnitDeselected();

	/** Blueprint handler for strategy game interactions */
	UFUNCTION(BlueprintImplementableEvent, Category="NPC", meta = (DisplayName="Interaction Behavior"))
	void BP_InteractionBehavior(AStrategyUnit* Interactor);

public:

	FOnUnitMoveCompletedDelegate OnMoveCompleted;
};
