#include "SA_PlayerController.h"

#include "UObject/UnrealType.h"

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
        if (!IsPlayerTurnActive())
        {
                return;
        }

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
	);

	if (!bHit)
	{
		if (SelectedActor)
		{
			BP_OnDeselected(SelectedActor);
			SelectedActor = nullptr;
		}
		return;
	}

	AActor* HitActor = Hit.GetActor();

	// Very simple selection logic (refine later)
	if (HitActor)
	{
		if (SelectedActor && SelectedActor != HitActor)
		{
			BP_OnDeselected(SelectedActor);
		}

                SelectedActor = HitActor;
                BP_OnSelected(SelectedActor);
        }
}

bool ASA_PlayerController::IsPlayerTurnActive() const
{
        if (!TurnManager)
        {
                return true;
        }

        const FProperty* TurnStateProperty = TurnManager->GetClass()->FindPropertyByName(TEXT("TurnState"));
        if (!TurnStateProperty)
        {
                return true;
        }

        const UEnum* TurnStateEnum = nullptr;
        int64 CurrentTurnValue = 0;

        if (const FEnumProperty* EnumProperty = CastField<FEnumProperty>(TurnStateProperty))
        {
                const void* PropertyAddress = EnumProperty->ContainerPtrToValuePtr<void>(TurnManager);
                TurnStateEnum = EnumProperty->GetEnum();
                CurrentTurnValue = EnumProperty->GetUnderlyingProperty()->GetSignedIntPropertyValue(PropertyAddress);
        }
        else if (const FByteProperty* ByteProperty = CastField<FByteProperty>(TurnStateProperty))
        {
                const void* PropertyAddress = ByteProperty->ContainerPtrToValuePtr<void>(TurnManager);
                TurnStateEnum = ByteProperty->Enum;
                CurrentTurnValue = ByteProperty->GetSignedIntPropertyValue(PropertyAddress);
        }

        if (TurnStateEnum)
        {
                const int64 PlayerTurnValue = TurnStateEnum->GetValueByNameString(TEXT("PlayerTurn"));
                if (PlayerTurnValue != INDEX_NONE)
                {
                        return CurrentTurnValue == PlayerTurnValue;
                }
        }

        return true;
}
