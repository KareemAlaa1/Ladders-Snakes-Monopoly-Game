#pragma once
#include"Card.h"
class Card_3:public Card
{
	int count;
public:
	Card_3(const CellPosition& pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card2 on the passed Player

	virtual void save(ofstream& outfile, int type);

	virtual void Load(ifstream& infile);

	virtual Card_3* GetCopy();

	virtual ~Card_3(); // A Virtual Destructor

};

