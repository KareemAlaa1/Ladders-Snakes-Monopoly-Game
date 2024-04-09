#include "Card_7.h"

Card_7::Card_7(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 7; // set the inherited cardNumber data member with the card number (1 here)
}

Card_7::~Card_7(void)
{
}

void Card_7::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer); // print the message that you reached this card number
	Player** nextplayer = new Player * [MaxPlayerCount]; // array of next players pointer
	for (int c = 0; c < MaxPlayerCount; c++)  // make all pointer point to NULL
	{
		nextplayer[c] = NULL;
	}
	CellPosition currentplayerposition = pPlayer->GetCell()->GetCellPosition(); // current cell position
	bool found = pGrid->GetNextplayer(currentplayerposition, nextplayer); // getting pointer to next player

	if (found)
	{
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			if (nextplayer[i] != NULL)
			{
				int playercellnum = nextplayer[i]->GetCell()->GetCellPosition().GetCellNum();
				nextplayer[i]->Move(pGrid, -playercellnum + 1); // moving the next player to first cell
			}
		}
	}
	
	delete[] nextplayer;
}
void Card_7::save(ofstream& outfile, int type)
{
	if (type == 3)
	{
		Card::save(outfile, type);
		outfile << endl;
	}
}

void Card_7::Load(ifstream& infile)
{
	Card::Load(infile);
}

Card_7* Card_7::GetCopy()
{
	Card_7* pCard = new Card_7(position);
	return pCard;
}