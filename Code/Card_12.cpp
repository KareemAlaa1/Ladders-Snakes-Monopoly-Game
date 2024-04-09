#include "Card_12.h"

Card_12::Card_12(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 12; // set the inherited cardNumber data member with the card number (12 here)
}

Card_12::~Card_12(void)
{
}


void Card_12::Apply(Grid* pGrid, Player* pPlayer)
{
	int MostExpensiveStation_Price = 0;
	int StationNum = 0;
	Card::Apply(pGrid, pPlayer);
	poor = pGrid->GetPoorestPlayer();
	if (Card_9::GetPrice() > MostExpensiveStation_Price && Card_9::GetOwner() == pPlayer)
	{
		MostExpensiveStation_Price = Card_9::GetPrice();
		StationNum = 9;
	}
	if (Card_10::GetPrice() > MostExpensiveStation_Price && Card_10::GetOwner() == pPlayer)
	{
		MostExpensiveStation_Price = Card_10::GetPrice();
		StationNum = 10;
	}
	if (Card_11::GetPrice() > MostExpensiveStation_Price && Card_11::GetOwner() == pPlayer)
	{
		MostExpensiveStation_Price = Card_11::GetPrice();
		StationNum = 11;
	}
	if (StationNum != 0) // check if current user owns any station 
	{
		switch (StationNum)
		{
		case 9:
			Card_9::SetOwner(poor);
			break;
		case 10:
			Card_10::SetOwner(poor);
			break;
		case 11:
			Card_11::SetOwner(poor);
			break;
		}
	}
}

void Card_12::save(ofstream& outfile, int type)
{
	if (type == 3)
	{
		Card::save(outfile, type);
		outfile << endl;
	}
}

void Card_12::Load(ifstream& infile)
{
	Card::Load(infile);
}

Card_12* Card_12::GetCopy()
{
	Card_12* pCard = new Card_12(position);
	return pCard;
}