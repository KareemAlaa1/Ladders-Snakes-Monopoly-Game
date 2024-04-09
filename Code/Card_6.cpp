#include "Card_6.h"


Card_6::Card_6(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; // set the inherited cardNumber data member with the card number (6 here)
}

void Card_6::ReadCardParameters(Grid* pGrid)
{
	int x = 0;
	Input* pIn = pGrid->GetInput(); // Get a Pointer to the Input Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();// Get a Pointer to the Output Interfaces from the Grid
	pOut->PrintMessage("New Card six : Enter its cellnum amount ..."); //print to a descriptive message to the user
	x = pIn->GetInteger(pOut);// Read an Integer from the user...need validations
	while ((x < 1 || x > NumVerticalCells*NumHorizontalCells)||x==this->GetPosition().GetCellNum()) // validate x value
	{
		pOut->PrintMessage("invalid cellnum amount,[Hint: you can't choose this card position], Try again.....");
		x = pIn->GetInteger(pOut);
	}
	movetoCellnum = x; // setting movetoCellnum
	pOut->ClearStatusBar();// clearing the status bar
}

void Card_6::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer); // print the message that you reached this card number
	CellPosition movetocell(movetoCellnum);
	int Tempdice = (movetocell.GetCellNum()) - (pPlayer->GetCell()->GetCellPosition().GetCellNum());
	pPlayer->Move(pGrid, Tempdice); // moving the player to cell_num (movetoCellnum) & If the destination cell contains a ladder, snake, or card, take it.
}

void Card_6::save(ofstream& outfile, int type)
{
	if (type == 3)
	{
		Card::save(outfile, type);
		outfile << movetoCellnum << " ";
		outfile << endl;
	}
}

void Card_6::Load(ifstream& infile)
{
	Card::Load(infile);

	int MoveToCellNum;
	infile >> MoveToCellNum;
	this->movetoCellnum = MoveToCellNum;
}

Card_6* Card_6::GetCopy()
{
	Card_6* pCard = new Card_6(position);
	pCard->movetoCellnum = this->movetoCellnum;
	return pCard;
}

Card_6::~Card_6()
{
}