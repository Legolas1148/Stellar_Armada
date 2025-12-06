// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TurnManager.generated.h"

class AAIController;

/** Turn states for the basic strategy battle loop */
UENUM(BlueprintType)
enum class ETurnState : uint8
{
    PlayerTurn,
    EnemyTurn,
    BattleEnded
};

/**
 *  Lightweight turn manager used by the strategy variant.
 *  Designed to be driven from Blueprint and to operate on Blueprint-authored units.
 */
UCLASS()
class ATurnManager : public AActor
{
    GENERATED_BODY()

public:
    ATurnManager();

    /** Begin the player's turn. Resets per-turn flags on player units. */
    UFUNCTION(BlueprintCallable, Category = "Turn Manager")
    void StartPlayerTurn();

    /** Ends the player's turn and triggers the enemy phase. */
    UFUNCTION(BlueprintCallable, Category = "Turn Manager")
    void EndPlayerTurn();

    /** Executes the full enemy turn sequence. */
    UFUNCTION(BlueprintCallable, Category = "Turn Manager")
    void RunEnemyTurn();

protected:
    /** Called after each enemy turn to determine whether the battle should continue. */
    UFUNCTION(BlueprintImplementableEvent, Category = "Turn Manager")
    bool CheckBattleEnd();

    /** Current state of the turn loop. */
    UPROPERTY(BlueprintReadWrite, Category = "Turn Manager")
    ETurnState TurnState;

    /** Units controlled by the player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turn Manager")
    TArray<TObjectPtr<AActor>> PlayerUnits;

    /** Units controlled by the AI. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turn Manager")
    TArray<TObjectPtr<AActor>> EnemyUnits;

private:
    float GetAttackRange(AActor* EnemyUnit) const;
    void ResetPlayerUnitTurnFlags();
    void AttackTarget(AActor* Attacker, AActor* Target) const;
    void MoveEnemyTowardTarget(AActor* EnemyUnit, const FVector& TargetLocation) const;
};
