// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TurnManager.generated.h"

class AStrategyUnit;

/** Turn states for the battle loop */
UENUM(BlueprintType)
enum class ETurnState : uint8
{
    PlayerTurn,
    EnemyTurn,
    BattleEnd
};

/** Actor responsible for tracking turn order and unit lists */
UCLASS()
class ATurnManager : public AActor
{
    GENERATED_BODY()

public:
    ATurnManager();

protected:
    virtual void BeginPlay() override;

private:
    /** Attempts to read the Team property from the given unit. Returns INDEX_NONE if missing. */
    int32 ResolveUnitTeam(const AStrategyUnit* Unit) const;

public:
    /** Current state of the turn sequence */
    UPROPERTY(BlueprintReadOnly, Category = "Turn Manager")
    ETurnState TurnState = ETurnState::PlayerTurn;

    /** All player-controlled units */
    UPROPERTY(BlueprintReadOnly, Category = "Turn Manager")
    TArray<AStrategyUnit*> PlayerUnits;

    /** All enemy units */
    UPROPERTY(BlueprintReadOnly, Category = "Turn Manager")
    TArray<AStrategyUnit*> EnemyUnits;
};
