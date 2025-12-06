// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StrategyGameMode.generated.h"

class ATurnManager;

/**
 *  Simple GameMode for a top down strategy game.
 */
UCLASS(abstract)
class AStrategyGameMode : public AGameModeBase
{
        GENERATED_BODY()

public:
        AStrategyGameMode();

protected:
        virtual void BeginPlay() override;

protected:
        /** Turn manager class to spawn when the game begins if one is not already present */
        UPROPERTY(EditDefaultsOnly, Category = "Turns")
        TSubclassOf<ATurnManager> TurnManagerClass;

        /** Spawned or placed turn manager instance */
        UPROPERTY(Transient)
        ATurnManager* TurnManager = nullptr;
};
