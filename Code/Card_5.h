#pragma once
#include "Card.h"

class Card_5 :public Card
{
	int steps;
public:
	Card_5(const CellPosition& pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card5 on the passed Player
													  // by Moveing the player backward with the same number of steps that he just rolled by the steps data member

	virtual void save(ofstream& outfile, int type);

	virtual void Load(ifstream& infile);

	virtual Card_5* GetCopy();

	virtual ~Card_5(); // A Virtual Destructor
};

