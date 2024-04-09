#include "Card_5.h"
Card_5::Card_5(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (5 here)
}

Card_5::~Card_5(void)
{
}

void Card_5::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer); // print the message that you reached this card number
	steps = -1 * pPlayer->getjustRolledDiceNum(); // setting steps value
	pPlayer->Move(pGrid, steps); // moving  the player backward with the same number of steps that he just rolled
}

void Card_5::save(ofstream& outfile, int type)
{
	if (type == 3)
	{
		Card::save(outfile, type);
		outfile << endl;
	}
}

void Card_5::Load(ifstream& infile)
{
	Card::Load(infile);
}

Card_5* Card_5::GetCopy()
{
	Card_5* pCard = new Card_5(position);
	return pCard;
}