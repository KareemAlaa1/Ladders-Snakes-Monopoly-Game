#pragma once
#include"Action.h"
class InputRollDiceAction : public Action
{
	int Dicevalue;
public:
	InputRollDiceAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~InputRollDiceAction();
};

