#pragma once

#include "GameObject.h"

class Snake : public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the ladder's "Start Cell Position"

	CellPosition endCellPos; 
	CellPosition startCellPos;

public:

	Snake(const CellPosition& startCellPos, const CellPosition& endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a snake from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the snake by moving player to snake's end cell

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	bool IsOverlapping(GameObject* newobj, Grid* pGrid);

	virtual void save(ofstream& outfile, int type);

	virtual void Load(ifstream& infile);

	virtual Snake* GetCopy();

	virtual ~Snake(); // Virtual destructor
};
