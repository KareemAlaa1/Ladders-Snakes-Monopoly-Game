#include "Card_3.h"
Card_3::Card_3(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	count = 0;
	cardNumber = 3;
}

void Card_3::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	count = 1;
	while (count > 0)
	{
		pGrid->DecreaseCurrentPlayer();
		count--;
	}
}

void Card_3::save(ofstream& outfile, int type)
{
	if (type == 3)
	{
		Card::save(outfile, type);
		outfile << endl;
	}
}

void Card_3::Load(ifstream& infile)
{
	Card::Load(infile);
}

Card_3* Card_3::GetCopy()
{
	Card_3* pCard = new Card_3(position);
	return pCard;
}

Card_3::~Card_3()
{}