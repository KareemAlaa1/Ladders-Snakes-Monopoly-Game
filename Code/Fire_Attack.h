#pragma once
#include "SuperPowers.h"
class Fire_Attack : public SuperPowers
{
protected:
	int playernum;
public:
	Fire_Attack();
	void ReadParameters(Grid* pGrid, Player* pPlayer);
	void Apply(Grid*, Player*);
};
