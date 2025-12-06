// Copyright Epic Games, Inc. All Rights Reserved.

#include "TurnManager.h"

#include "AIController.h"
#include "GameFramework/Pawn.h"
#include "NavigationSystem.h"
#include "UObject/UnrealType.h"
#include "Kismet/GameplayStatics.h"
#include "Variant_Strategy/StrategyUnit.h"

ATurnManager::ATurnManager()
{
        PrimaryActorTick.bCanEverTick = false;
        TurnState = ETurnState::PlayerTurn;
}

void ATurnManager::StartPlayerTurn()
{
        TurnState = ETurnState::PlayerTurn;
        ResetPlayerUnitTurnFlags();
}

void ATurnManager::EndPlayerTurn()
{
        TurnState = ETurnState::EnemyTurn;
        RunEnemyTurn();
}

void ATurnManager::RunEnemyTurn()
{
        if (PlayerUnits.IsEmpty())
        {
                return;
        }

        for (AActor* EnemyUnit : EnemyUnits)
        {
                        if (!IsValid(EnemyUnit))
                        {
                                continue;
                        }

                        // Find nearest player target
                        AActor* ClosestTarget = nullptr;
                        float ClosestDistSq = MAX_flt;
                        for (AActor* PlayerUnit : PlayerUnits)
                        {
                                if (!IsValid(PlayerUnit))
                                {
                                        continue;
                                }

                                const float DistSq = FVector::DistSquared(EnemyUnit->GetActorLocation(), PlayerUnit->GetActorLocation());
                                if (DistSq < ClosestDistSq)
                                {
                                        ClosestDistSq = DistSq;
                                        ClosestTarget = PlayerUnit;
                                }
                        }

                        if (!ClosestTarget)
                        {
                                continue;
                        }

                        const float AttackRange = GetAttackRange(EnemyUnit);
                        const float DistanceToTarget = FMath::Sqrt(ClosestDistSq);

                        if (AttackRange > 0.0f && DistanceToTarget <= AttackRange)
                        {
                                AttackTarget(EnemyUnit, ClosestTarget);
                        }
                        else
                        {
                                MoveEnemyTowardTarget(EnemyUnit, ClosestTarget->GetActorLocation());
                        }
        }

        const bool bBattleEnded = CheckBattleEnd();
        if (!bBattleEnded)
        {
                StartPlayerTurn();
        }
        else
        {
                TurnState = ETurnState::BattleEnded;
        }
}

float ATurnManager::GetAttackRange(AActor* EnemyUnit) const
{
        if (!IsValid(EnemyUnit))
        {
                return 0.0f;
        }

        if (const FFloatProperty* AttackRangeProp = FindFProperty<FFloatProperty>(EnemyUnit->GetClass(), TEXT("AttackRange")))
        {
                return AttackRangeProp->GetPropertyValue_InContainer(EnemyUnit);
        }

        return 0.0f;
}

void ATurnManager::ResetPlayerUnitTurnFlags()
{
        for (AActor* PlayerUnit : PlayerUnits)
        {
                if (!IsValid(PlayerUnit))
                {
                        continue;
                }

                if (FBoolProperty* HasActedProp = FindFProperty<FBoolProperty>(PlayerUnit->GetClass(), TEXT("bHasActedThisTurn")))
                {
                        HasActedProp->SetPropertyValue_InContainer(PlayerUnit, false);
                }
        }
}

void ATurnManager::AttackTarget(AActor* Attacker, AActor* Target) const
{
        if (!IsValid(Attacker) || !IsValid(Target))
        {
                return;
        }

        static const FName AttackFuncName(TEXT("AttackTarget"));
        if (UFunction* AttackFunc = Attacker->FindFunction(AttackFuncName))
        {
                struct FAttackParams
                {
                        AActor* TargetActor;
                } Params{Target};

                Attacker->ProcessEvent(AttackFunc, &Params);
        }
}

void ATurnManager::MoveEnemyTowardTarget(AActor* EnemyUnit, const FVector& TargetLocation) const
{
        if (!IsValid(EnemyUnit))
        {
                return;
        }

        if (AStrategyUnit* StrategyUnit = Cast<AStrategyUnit>(EnemyUnit))
        {
                StrategyUnit->MoveToLocation(TargetLocation, /*AcceptanceRadius*/ 10.0f);
                return;
        }

        if (AAIController* AIController = Cast<AAIController>(EnemyUnit->GetInstigatorController()))
        {
                UNavigationSystemV1::SimpleMoveToLocation(AIController, TargetLocation);
                return;
        }

        if (APawn* Pawn = Cast<APawn>(EnemyUnit))
        {
                if (AAIController* PawnController = Cast<AAIController>(Pawn->GetController()))
                {
                        UNavigationSystemV1::SimpleMoveToLocation(PawnController, TargetLocation);
                        return;
                }
        }

        // Fall back to a simple teleport step if no movement logic is available
        const FVector NewLocation = FMath::VInterpConstantTo(EnemyUnit->GetActorLocation(), TargetLocation, 1.0f, 200.0f);
        EnemyUnit->SetActorLocation(NewLocation);
}

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
