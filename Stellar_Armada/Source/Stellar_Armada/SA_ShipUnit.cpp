#include "SA_ShipUnit.h"

ASA_ShipUnit::ASA_ShipUnit()
{
PrimaryActorTick.bCanEverTick = false;
}

bool ASA_ShipUnit::HasActedThisTurn() const
{
return bHasActedThisTurn;
}

bool ASA_ShipUnit::IsEnemyShip() const
{
return bIsEnemyShip;
}

void ASA_ShipUnit::SetHasActedThisTurn(bool bInHasActed)
{
bHasActedThisTurn = bInHasActed;
}
