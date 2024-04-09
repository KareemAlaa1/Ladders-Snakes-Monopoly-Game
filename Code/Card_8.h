#pragma once
#include "Card.h"
class Card_8 :public Card
{
	int coinsToExit; // the PayToExit value to to go out of the prison
public:
	Card_8(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of Card_8 which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card_8 on the passed Player
													  // by getting him in prison or pay coins to exit

	virtual void save(ofstream& outfile, int type);

	virtual void Load(ifstream& infile);

	virtual Card_8* GetCopy();

	virtual ~Card_8(); // A Virtual Destructor
};