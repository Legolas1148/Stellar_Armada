#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SA_PlayerController.generated.h"

UCLASS()
class ASA_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetupInputComponent() override;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Stellar Armada|Selection")
	TObjectPtr<AActor> SelectedActor;

	UFUNCTION()
	void HandleLeftClick();

	// Lets your Blueprint add visuals like highlight rings
	UFUNCTION(BlueprintImplementableEvent, Category = "Stellar Armada|Selection")
	void BP_OnSelected(AActor* Actor);

	UFUNCTION(BlueprintImplementableEvent, Category = "Stellar Armada|Selection")
	void BP_OnDeselected(AActor* Actor);
};
