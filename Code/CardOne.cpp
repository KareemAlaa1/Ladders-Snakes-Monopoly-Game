#include "CardOne.h"

CardOne::CardOne(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
}

CardOne::~CardOne(void)
{
}

void CardOne::ReadCardParameters(Grid * pGrid)
{
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces from the Grid

	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	
	// [ Note ]:
	// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar

	int x = 0;
	Input* pIn = pGrid->GetInput(); // Get a Pointer to the Input Interfaces from the Grid
	Output* pOut = pGrid->GetOutput(); // Get a Pointer to the Output Interfaces from the Grid
	pOut->PrintMessage("New CardOne : Enter its wallet amount ..."); // print a descriptive message to the user
	x = pIn->GetInteger(pOut); // Read an Integer from the user...need validations
	while (x <= 0) // validate x value
	{
		pOut->PrintMessage("invalid amount try again...");
		x = pIn->GetInteger(pOut);
	}
	walletAmount = x; // setting walletAmount
	pOut->ClearStatusBar(); // clearing the status bar
}

void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number

	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne

	Card::Apply(pGrid, pPlayer); // print the message that you reached this card number

	pPlayer->Pay(walletAmount); // Decrement the wallet of pPlayer by the walletAmount
}

void CardOne::save(ofstream& outfile, int type)
{
	if (type == 3)
	{
		Card::save(outfile, type);
		outfile << walletAmount << " " << endl;
	}


}

void CardOne::Load(ifstream& infile)
{

	Card::Load(infile);

	int walletamount;
	infile >> walletamount;

	this->walletAmount = walletamount;

}

CardOne* CardOne::GetCopy()
{
	CardOne* pCard = new CardOne(position);
	pCard->walletAmount = (this->walletAmount);

	return pCard;
}
