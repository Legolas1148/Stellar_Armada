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
