// Copyright Epic Games, Inc. All Rights Reserved.

#include "TurnManager.h"

#include "Kismet/GameplayStatics.h"
#include "Variant_Strategy/StrategyUnit.h"

ATurnManager::ATurnManager()
{
    PrimaryActorTick.bCanEverTick = false;
}

void ATurnManager::BeginPlay()
{
    Super::BeginPlay();

    TArray<AActor*> FoundUnits;
    UGameplayStatics::GetAllActorsOfClass(this, AStrategyUnit::StaticClass(), FoundUnits);

    PlayerUnits.Reset();
    EnemyUnits.Reset();

    for (AActor* Actor : FoundUnits)
    {
        AStrategyUnit* Unit = Cast<AStrategyUnit>(Actor);
        if (!Unit)
        {
            continue;
        }

        const int32 TeamId = ResolveUnitTeam(Unit);

        // Default assumption: team 0 is player, any other valid id is enemy.
        if (TeamId == 0)
        {
            PlayerUnits.Add(Unit);
        }
        else if (TeamId != INDEX_NONE)
        {
            EnemyUnits.Add(Unit);
        }
    }

    TurnState = ETurnState::PlayerTurn;
}

int32 ATurnManager::ResolveUnitTeam(const AStrategyUnit* Unit) const
{
    if (!Unit)
    {
        return INDEX_NONE;
    }

    const UClass* UnitClass = Unit->GetClass();
    const FProperty* TeamProperty = UnitClass->FindPropertyByName(TEXT("Team"));

    if (!TeamProperty)
    {
        return INDEX_NONE;
    }

    if (const FIntProperty* IntProperty = CastField<FIntProperty>(TeamProperty))
    {
        return IntProperty->GetPropertyValue_InContainer(Unit);
    }

    if (const FByteProperty* ByteProperty = CastField<FByteProperty>(TeamProperty))
    {
        return ByteProperty->GetPropertyValue_InContainer(Unit);
    }

    if (const FEnumProperty* EnumProperty = CastField<FEnumProperty>(TeamProperty))
    {
        const FProperty* Underlying = EnumProperty->GetUnderlyingProperty();
        if (const FIntProperty* EnumIntProperty = CastField<FIntProperty>(Underlying))
        {
            return EnumIntProperty->GetPropertyValue_InContainer(Unit);
        }
        if (const FByteProperty* EnumByteProperty = CastField<FByteProperty>(Underlying))
        {
            return EnumByteProperty->GetPropertyValue_InContainer(Unit);
        }
    }

    return INDEX_NONE;
}
