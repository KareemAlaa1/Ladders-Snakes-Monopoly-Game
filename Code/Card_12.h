#pragma once
#include "Card.h"
#include "Card_9.h"
#include "Card_10.h"
#include "Card_11.h"

class Card_12 : public Card
{

	Player* poor = 0;

public:

	Card_12(const CellPosition& pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card_12 on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual void save(ofstream& outfile, int type);

	virtual void Load(ifstream& infile);

	virtual Card_12* GetCopy();

	virtual ~Card_12(); // A Virtual Destructor
};
