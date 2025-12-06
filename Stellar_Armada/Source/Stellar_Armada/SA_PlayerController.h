#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SA_PlayerController.generated.h"

class AActor;

UCLASS()
class ASA_PlayerController : public APlayerController
{
        GENERATED_BODY()

public:
        virtual void SetupInputComponent() override;

protected:
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
