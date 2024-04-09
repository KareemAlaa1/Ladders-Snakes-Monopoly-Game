#include "Card_4.h"

Card_4::Card_4(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	count = 0;
	cardNumber = 4; // set the inherited cardNumber data member with the card number
}

void Card_4::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	pPlayer->setpreventcount(1);
}

void Card_4::save(ofstream& outfile, int type)
{
	if (type == 3)
	{
		Card::save(outfile, type);
		outfile << endl;
	}
}

void Card_4::Load(ifstream& infile)
{
	Card::Load(infile);
}

Card_4* Card_4::GetCopy()
{
	Card_4* pCard = new Card_4(position);
	return pCard;
}

Card_4::~Card_4()
{

}