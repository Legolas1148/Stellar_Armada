// Copyright Epic Games, Inc. All Rights Reserved.


#include "StrategyGameMode.h"

#include "Kismet/GameplayStatics.h"
#include "Variant_Strategy/TurnManager.h"

AStrategyGameMode::AStrategyGameMode()
{
    TurnManagerClass = ATurnManager::StaticClass();
}

void AStrategyGameMode::BeginPlay()
{
    Super::BeginPlay();

    TArray<AActor*> ExistingManagers;
    UGameplayStatics::GetAllActorsOfClass(this, ATurnManager::StaticClass(), ExistingManagers);

    if (ExistingManagers.Num() > 0)
    {
        TurnManager = Cast<ATurnManager>(ExistingManagers[0]);
    }
    else if (TurnManagerClass)
    {
        TurnManager = GetWorld()->SpawnActor<ATurnManager>(TurnManagerClass);
    }
}

