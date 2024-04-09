#pragma once

#include "Card.h"

class Card_7 : public Card
{
	//no parameters
public:
	Card_7(const CellPosition& pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player

	virtual void save(ofstream& outfile, int type);

	virtual void Load(ifstream& infile);

	virtual Card_7* GetCopy();

	virtual ~Card_7(); // A Virtual Destructor
};