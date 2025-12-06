// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WBP_SA_HUD.generated.h"

class UButton;
class UTextBlock;
class AActor;

/**
 * Simple HUD widget that exposes a turn indicator label and a button for ending the turn.
 */
UCLASS()
class UWBP_SA_HUD : public UUserWidget
{
GENERATED_BODY()

public:

UWBP_SA_HUD(const FObjectInitializer& ObjectInitializer);

/** Sets the turn manager reference this widget should notify. */
void SetTurnManager(AActor* InTurnManager);

/** Updates the displayed turn indicator text. */
void SetTurnIndicatorText(const FText& InTurnIndicatorText);

protected:

/** Constructs the internal widget tree. */
virtual void NativeConstruct() override;

/** Removes delegates when the widget is destroyed. */
virtual void NativeDestruct() override;

private:

/** Handles click events on the End Turn button. */
UFUNCTION()
void HandleEndTurnClicked();

/** Attempts to call EndPlayerTurn on the assigned turn manager. */
void InvokeEndPlayerTurn() const;

/** Adds the indicator text and button to the widget tree if they have not been created. */
void EnsureWidgetTree();

private:

/** Reference to the placed turn manager actor. */
UPROPERTY()
TObjectPtr<AActor> TurnManager = nullptr;

/** UI text to describe the current turn. */
UPROPERTY(EditAnywhere, Category = "Turn")
FText TurnIndicatorLabel = FText::FromString(TEXT("Player Turn"));

/** Label used on the button. */
UPROPERTY(EditAnywhere, Category = "Turn")
FText EndTurnLabel = FText::FromString(TEXT("End Turn"));

/** UI element used to display the turn indicator. */
UPROPERTY()
TObjectPtr<UTextBlock> TurnIndicatorText = nullptr;

/** Button that signals the end of the player's turn. */
UPROPERTY()
TObjectPtr<UButton> EndTurnButton = nullptr;
};
