#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SA_ShipUnit.generated.h"

UENUM(BlueprintType)
enum class ESA_TurnState : uint8
{
PlayerTurn,
EnemyTurn
};

UCLASS()
class ASA_ShipUnit : public AActor
{
GENERATED_BODY()

public:
ASA_ShipUnit();

/** Returns true if this ship has already acted during the current turn. */
bool HasActedThisTurn() const;

/** Returns true if this ship should be treated as an enemy ship. */
bool IsEnemyShip() const;

/** Blueprint hook for executing an attack against another ship. */
UFUNCTION(BlueprintImplementableEvent, Category = "Stellar Armada|Combat")
void AttackTarget(ASA_ShipUnit* TargetShip);

/** Sets whether this ship has completed its action for the turn. */
void SetHasActedThisTurn(bool bInHasActed);

protected:
/** Whether this ship has already acted during the current turn. */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stellar Armada|Turn")
bool bHasActedThisTurn = false;

/** True if this ship belongs to an enemy faction relative to the player. */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stellar Armada|Turn")
bool bIsEnemyShip = false;
};
