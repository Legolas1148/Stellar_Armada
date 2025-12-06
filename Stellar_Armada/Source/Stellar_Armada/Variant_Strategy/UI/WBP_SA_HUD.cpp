// Copyright Epic Games, Inc. All Rights Reserved.


#include "WBP_SA_HUD.h"
#include "Blueprint/WidgetTree.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"

UWBP_SA_HUD::UWBP_SA_HUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UWBP_SA_HUD::SetTurnManager(AActor* InTurnManager)
{
	TurnManager = InTurnManager;
}

void UWBP_SA_HUD::SetTurnIndicatorText(const FText& InTurnIndicatorText)
{
	TurnIndicatorLabel = InTurnIndicatorText;

	if (TurnIndicatorText)
	{
		TurnIndicatorText->SetText(TurnIndicatorLabel);
	}
}

void UWBP_SA_HUD::NativeConstruct()
{
	Super::NativeConstruct();

	EnsureWidgetTree();

	if (TurnIndicatorText)
	{
		TurnIndicatorText->SetText(TurnIndicatorLabel);
	}

	if (EndTurnButton)
	{
		EndTurnButton->OnClicked.AddDynamic(this, &UWBP_SA_HUD::HandleEndTurnClicked);
	}
}

void UWBP_SA_HUD::NativeDestruct()
{
	if (EndTurnButton)
	{
		EndTurnButton->OnClicked.RemoveDynamic(this, &UWBP_SA_HUD::HandleEndTurnClicked);
	}

	Super::NativeDestruct();
}

void UWBP_SA_HUD::HandleEndTurnClicked()
{
	InvokeEndPlayerTurn();
}

void UWBP_SA_HUD::InvokeEndPlayerTurn() const
{
	static const FName EndTurnFunctionName(TEXT("EndPlayerTurn"));

	if (!TurnManager)
	{
		UE_LOG(LogTemp, Warning, TEXT("TurnManager reference was not set before invoking EndPlayerTurn."));
		return;
	}

	if (UFunction* EndTurnFunction = TurnManager->FindFunction(EndTurnFunctionName))
	{
		TurnManager->ProcessEvent(EndTurnFunction, nullptr);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TurnManager %s is missing an EndPlayerTurn function."), *GetNameSafe(TurnManager));
	}
}

void UWBP_SA_HUD::EnsureWidgetTree()
{
	if (WidgetTree == nullptr)
	{
		return;
	}

	if (WidgetTree->RootWidget == nullptr)
	{
		UVerticalBox* Root = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("Root"));
		WidgetTree->RootWidget = Root;

		TurnIndicatorText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("TurnIndicatorText"));
		TurnIndicatorText->SetText(TurnIndicatorLabel);
		UVerticalBoxSlot* TextSlot = Root->AddChildToVerticalBox(TurnIndicatorText);
		TextSlot->SetPadding(FMargin(8.0f, 8.0f));

		EndTurnButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("EndTurnButton"));
		UTextBlock* ButtonLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("EndTurnLabel"));
		ButtonLabel->SetText(EndTurnLabel);
		EndTurnButton->AddChild(ButtonLabel);
		UVerticalBoxSlot* ButtonSlot = Root->AddChildToVerticalBox(EndTurnButton);
		ButtonSlot->SetPadding(FMargin(8.0f, 4.0f));
	}
	else
	{
		TurnIndicatorText = Cast<UTextBlock>(WidgetTree->FindWidget(TEXT("TurnIndicatorText")));
		EndTurnButton = Cast<UButton>(WidgetTree->FindWidget(TEXT("EndTurnButton")));
	}
}
