#pragma once
#include"Grid.h"
#include"Player.h"
class SuperPowers
{
protected:
	int AttackNumber;
public:
	virtual void ReadParameters(Grid*,Player*)=0 ;
	virtual	void Apply(Grid*,Player*)=0;
};

