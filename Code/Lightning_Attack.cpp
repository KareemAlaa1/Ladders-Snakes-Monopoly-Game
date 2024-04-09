#include "Lightning_Attack.h"

Lightning_Attack::Lightning_Attack()
{
	AttackNumber = 4;
}

void Lightning_Attack::ReadParameters(Grid* pGrid,Player*)
{}

void Lightning_Attack::Apply(Grid* pGrid, Player* pPlayer)
{
	pGrid->decreasewallets(pPlayer, 20);
}
