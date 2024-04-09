#pragma once
#include "Card.h"
class Card_6 :public Card
{
	int movetoCellnum;
public:

	Card_6(const CellPosition& pos); // A Constructor takes card position and sets the parameters: movetoCellnum 

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of Card_6 which is: movetoCellnum

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card_6 on the passed Player
													  // by moving the player to movetoCellnum

	virtual void save(ofstream& outfile, int type);

	virtual void Load(ifstream& infile);

	virtual Card_6* GetCopy();

	virtual ~Card_6(); // A Virtual Destructor
};

