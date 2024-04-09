#pragma once
#include"Card.h"
class Card_2:public Card
{
public:
	Card_2(const CellPosition& pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card2 on the passed Player
												  
	virtual void save(ofstream& outfile, int type);

	virtual void Load(ifstream& infile);

	virtual Card_2* GetCopy();

	virtual ~Card_2(); // A Virtual Destructor

};

