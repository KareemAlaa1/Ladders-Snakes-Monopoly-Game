#pragma once
#include "SuperPowers.h"
class Poison_Attack : public SuperPowers
{
protected:
	int playernum;
public:
	Poison_Attack();
	void ReadParameters(Grid*,Player*);
	void Apply(Grid*, Player*);
};