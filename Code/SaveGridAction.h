#pragma once

#include "Action.h"

#include "Input.h"
#include "Output.h"
#include "Grid.h"


class SaveGridAction : public Action
{

	int gridNum;


public:

	SaveGridAction(ApplicationManager* pApp);


	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~SaveGridAction();




};