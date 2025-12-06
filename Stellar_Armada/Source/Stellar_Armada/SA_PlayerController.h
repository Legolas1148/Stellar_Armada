#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SA_ShipUnit.h"
#include "SA_PlayerController.generated.h"

class AActor;

UCLASS()
class ASA_PlayerController : public APlayerController
{
        GENERATED_BODY()

public:
        virtual void SetupInputComponent() override;

protected:
        /** Currently selected player-controlled ship. */
        UPROPERTY(BlueprintReadWrite, Category = "Stellar Armada|Selection")
        TObjectPtr<ASA_ShipUnit> SelectedShip = nullptr;

        /** Current turn state used to gate attack interactions. */
        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stellar Armada|Turn")
        ESA_TurnState TurnState = ESA_TurnState::PlayerTurn;
        UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Stellar Armada|Turn", meta = (AllowPrivateAccess = "true"))
        TObjectPtr<AActor> TurnManager;

        UPROPERTY(BlueprintReadOnly, Category = "Stellar Armada|Selection")
        TObjectPtr<AActor> SelectedActor;

        bool IsPlayerTurnActive() const;

        UFUNCTION()
        void HandleLeftClick();

	// Lets your Blueprint add visuals like highlight rings
	UFUNCTION(BlueprintImplementableEvent, Category = "Stellar Armada|Selection")
	void BP_OnSelected(AActor* Actor);

	UFUNCTION(BlueprintImplementableEvent, Category = "Stellar Armada|Selection")
	void BP_OnDeselected(AActor* Actor);
};
