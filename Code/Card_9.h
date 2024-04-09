#pragma once
#include "Card.h"
class Card_9 : public Card
{
	static Player* owner;
	static int fees;
	static int price;
	

public:

	static bool isSaved;

	static bool isLoaded;

	Card_9(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of Card_9 which is: cardnum, price, fee

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card_9 on the passed Player
													  // by >>>
	static int GetPrice(); // static getter for price

	static Player* GetOwner(); // static getter for owner

	static void SetOwner(Player* NewOwner); // static setter for owner

	virtual void save(ofstream& outfile, int type);

	virtual void Load(ifstream& infile);

	virtual Card_9* GetCopy();

	virtual ~Card_9(); // A Virtual Destructor
};