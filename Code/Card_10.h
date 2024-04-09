#pragma once
#include "Card.h"
class Card_10 : public Card
{
	static Player* owner;
	static int fees;
	static int price;
	
public:

	static bool isSaved;

	static bool isLoaded;

	Card_10(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of Card_10 which is: cardnum, price, fee

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card_10 on the passed Player
													  // by >>>
	static int GetPrice(); // static getter for price

	static Player* GetOwner(); // static getter for owner

	static void SetOwner(Player* NewOwner); // static setter for owner

	virtual void save(ofstream& outfile, int type);

	virtual void Load(ifstream& infile);

	virtual Card_10* GetCopy();

	virtual ~Card_10(); // A Virtual Destructor
};