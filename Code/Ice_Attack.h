#pragma once
#include "SuperPowers.h"
class Ice_Attack :  public SuperPowers
{
protected:
	int playernum;
public:
	Ice_Attack();
	void ReadParameters(Grid*, Player*);
	void Apply(Grid*,Player*);
};

