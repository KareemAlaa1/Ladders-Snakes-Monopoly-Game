#pragma once
#include "SuperPowers.h"
class Lightning_Attack : public SuperPowers
{
protected:
	int playernum;
public:
	Lightning_Attack();
	void ReadParameters(Grid*,Player*);
	void Apply(Grid*, Player*);
};

