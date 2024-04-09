#pragma once
#include "Action.h"
class DeleteGameObjectAction :public Action
{
	CellPosition position;//position of the cell to delete the game object
public:
	DeleteGameObjectAction(ApplicationManager* pApp);
	void SetPosition(CellPosition);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~DeleteGameObjectAction();

};
