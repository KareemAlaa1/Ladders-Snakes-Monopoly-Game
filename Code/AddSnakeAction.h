#pragma once

#include "Action.h"

class AddSnakeAction : public Action
{
	// Always add action parameters as private data members

	// [Action Parameters]
	CellPosition startPos;
	CellPosition endPos;
	// Note: These parameters should be read in ReadActionParameters()

public:

	AddSnakeAction ( ApplicationManager* pApp ); // A Constructor

	virtual void ReadActionParameters ( ); 

	virtual void Execute ( ); 

	virtual ~AddSnakeAction ( ); // Virtual Destructor

};

