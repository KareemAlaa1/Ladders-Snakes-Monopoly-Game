#pragma once
#include"Action.h"
class ClearGridAction:public Action
{
public:
	ClearGridAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~ClearGridAction();
};

