#include "SA_PlayerController.h"

void ASA_PlayerController::SetupInputComponent()
{
        Super::SetupInputComponent();

        if (InputComponent)
        {
                InputComponent->BindAction("LeftClick", IE_Pressed, this, &ASA_PlayerController::HandleLeftClick);
        }
}

void ASA_PlayerController::HandleLeftClick()
{
        FHitResult Hit;
        const bool bHit = GetHitResultUnderCursorByChannel(
                UEngineTypes::ConvertToTraceType(ECC_Visibility),
                true,
                Hit
        );

        if (!bHit)
        {
                if (SelectedActor)
                {
                        BP_OnDeselected(SelectedActor);
                        SelectedActor = nullptr;
                        SelectedShip = nullptr;
                }
                return;
        }

        AActor* HitActor = Hit.GetActor();
        ASA_ShipUnit* ClickedShip = Cast<ASA_ShipUnit>(HitActor);

        const bool bCanAttack =
                TurnState == ESA_TurnState::PlayerTurn &&
                SelectedShip &&
                !SelectedShip->HasActedThisTurn() &&
                ClickedShip &&
                ClickedShip->IsEnemyShip();

        if (bCanAttack)
        {
                SelectedShip->AttackTarget(ClickedShip);
                return;
        }

        // Very simple selection logic (refine later)
        if (HitActor)
        {
                if (SelectedActor && SelectedActor != HitActor)
                {
                        BP_OnDeselected(SelectedActor);
                }

                SelectedActor = HitActor;
                SelectedShip = ClickedShip && !ClickedShip->IsEnemyShip() ? ClickedShip : nullptr;
                BP_OnSelected(SelectedActor);
        }
}
