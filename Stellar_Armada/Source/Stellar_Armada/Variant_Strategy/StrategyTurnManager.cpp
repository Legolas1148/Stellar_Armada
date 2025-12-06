// Copyright Epic Games, Inc. All Rights Reserved.

#include "Variant_Strategy/StrategyTurnManager.h"

#include "Blueprint/UserWidget.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Variant_Strategy/StrategyUnit.h"

AStrategyTurnManager::AStrategyTurnManager()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AStrategyTurnManager::RegisterUnit(AStrategyUnit* Unit, bool bIsPlayerUnit)
{
    if (Unit == nullptr)
    {
        return;
    }

    if (bIsPlayerUnit)
    {
        PlayerUnits.AddUnique(Unit);
    }
    else
    {
        EnemyUnits.AddUnique(Unit);
    }
}

void AStrategyTurnManager::CheckBattleEnd()
{
    // do not process once the battle has already ended
    if (TurnState == ETurnState::BattleEnd)
    {
        return;
    }

    // remove any null or destroyed units before evaluating
    PruneInvalidUnits(PlayerUnits);
    PruneInvalidUnits(EnemyUnits);

    if (EnemyUnits.Num() == 0)
    {
        EnterBattleEnd(VictoryOverlayClass);
    }
    else if (PlayerUnits.Num() == 0)
    {
        EnterBattleEnd(DefeatOverlayClass);
    }
}

void AStrategyTurnManager::PruneInvalidUnits(TArray<TWeakObjectPtr<AStrategyUnit>>& Units)
{
    Units.RemoveAll([](const TWeakObjectPtr<AStrategyUnit>& UnitPtr)
    {
        return !UnitPtr.IsValid() || UnitPtr->IsActorBeingDestroyed();
    });
}

void AStrategyTurnManager::EnterBattleEnd(TSubclassOf<UUserWidget> OverlayClass)
{
    TurnState = ETurnState::BattleEnd;

    // prevent further player input when the battle ends
    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
    {
        if (APlayerController* PC = It->Get())
        {
            PC->SetIgnoreLookInput(true);
            PC->SetIgnoreMoveInput(true);

            // switch to a UI-only input mode so the overlay can be interacted with
            FInputModeUIOnly InputMode;
            PC->SetInputMode(InputMode);
            PC->bShowMouseCursor = true;
        }
    }

    if (OverlayClass == nullptr)
    {
        return;
    }

    if (UWorld* World = GetWorld())
    {
        if (APlayerController* PC = World->GetFirstPlayerController())
        {
            if (UUserWidget* Overlay = CreateWidget<UUserWidget>(PC, OverlayClass))
            {
                Overlay->AddToViewport();
            }
        }
    }
}
