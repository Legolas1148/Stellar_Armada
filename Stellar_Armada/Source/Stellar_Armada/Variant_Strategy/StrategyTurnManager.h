// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StrategyTurnManager.generated.h"

class AStrategyUnit;
class UUserWidget;

/** Simple turn states for the strategy prototype */
UENUM(BlueprintType)
enum class EStrategyTurnState : uint8
{
    PlayerTurn    UMETA(DisplayName = "Player Turn"),
    EnemyTurn     UMETA(DisplayName = "Enemy Turn"),
    BattleEnd     UMETA(DisplayName = "Battle End")
};

/**
 * Minimal turn manager used by BP_SA_TurnManager
 * Handles end-of-battle detection and victory/defeat overlays.
 */
UCLASS()
class AStrategyTurnManager : public AActor
{
    GENERATED_BODY()

public:
    /** Default constructor */
    AStrategyTurnManager();

protected:
    /** Current turn state of the battle */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turns")
    EStrategyTurnState TurnState = EStrategyTurnState::PlayerTurn;

    /** Units controlled by the player */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turns")
    TArray<TWeakObjectPtr<AStrategyUnit>> PlayerUnits;

    /** Units controlled by the enemy */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turns")
    TArray<TWeakObjectPtr<AStrategyUnit>> EnemyUnits;

    /** Simple overlay displayed when the player wins */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turns")
    TSubclassOf<UUserWidget> VictoryOverlayClass;

    /** Simple overlay displayed when the player loses */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turns")
    TSubclassOf<UUserWidget> DefeatOverlayClass;

public:
    /** Adds a unit to the tracked list */
    UFUNCTION(BlueprintCallable, Category = "Turns")
    void RegisterUnit(AStrategyUnit* Unit, bool bIsPlayerUnit);

    /** Removes any invalid units and ends the battle if either side is empty */
    UFUNCTION(BlueprintCallable, Category = "Turns")
    void CheckBattleEnd();

protected:
    /** Removes null or destroyed entries from the provided unit list */
    void PruneInvalidUnits(TArray<TWeakObjectPtr<AStrategyUnit>>& Units);

    /** Handles the transition to the battle end state */
    void EnterBattleEnd(TSubclassOf<UUserWidget> OverlayClass);
};
