#include "Card_2.h"

Card_2::Card_2(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number
}

Card_2::~Card_2(void)
{
}

void Card_2::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer); // print the message that you reached this card number
	CellPosition currentposition = pPlayer->GetCell()->GetCellPosition();
	CellPosition ladderposition;
	Ladder* nextladder = pGrid->GetNextLadder((pPlayer->GetCell()->GetCellPosition()), ladderposition);// pointer to next ladder
	if (nextladder != NULL)
	{
		int tempdice = ladderposition.GetCellNumFromPosition(ladderposition) - currentposition.GetCellNumFromPosition(currentposition);
		pPlayer->Move(pGrid, tempdice);
		
	}


}

void Card_2::save(ofstream& outfile, int type)
{
	if (type == 3)
	{
		Card::save(outfile, type);
		outfile << endl;
	}

}

void Card_2::Load(ifstream& infile)
{
	Card::Load(infile);
}

Card_2* Card_2::GetCopy()
{
	Card_2* pCard = new Card_2(position);
	return pCard;
}