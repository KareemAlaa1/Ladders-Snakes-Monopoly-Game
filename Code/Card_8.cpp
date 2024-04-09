#include "Card_8.h"

Card_8::Card_8(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 8; // set the inherited cardNumber data member with the card number (8 here)
}

Card_8::~Card_8(void)
{
}

void Card_8::ReadCardParameters(Grid* pGrid)
{
	int x = 0;
	Input* pIn = pGrid->GetInput(); // Get a Pointer to the Input Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();// Get a Pointer to the Output Interfaces from the Grid
	pOut->PrintMessage("New Card_8 : Enter amount of coins to go out of the prison ..."); // print to a descriptive message to the user
	x = pIn->GetInteger(pOut);// Read an Integer from the user...need validations
	while (x <= 0) // validate x value
	{
		pOut->PrintMessage("invalid amount try again...");
		x = pIn->GetInteger(pOut);
	}
	coinsToExit = x; // setting coinsToExit 
	pOut->ClearStatusBar();// clearing the status bar
}

void Card_8::Apply(Grid* pGrid, Player* pPlayer)
{
	string playerdecision;
	Input* pIn = pGrid->GetInput(); // Get a Pointer to the Input Interfaces from the Grid
	Output* pOut = pGrid->GetOutput(); // Get a Pointer to the Output Interfaces from the Grid
	Card::Apply(pGrid, pPlayer);
	pOut->PrintMessage("Enter (Y/y) to pay : " + to_string(coinsToExit) + " Or otherwise to stay in prison for 3 turns..."); // print to a descriptive message to the user
	playerdecision = pIn->GetSrting(pOut); // Read a char from the user
	if (playerdecision[0] == 'Y' || playerdecision[0] == 'y')
	{
		if (pPlayer->Buy(coinsToExit)) // decrementing the player's wallet by the coinsToExit data member if he has money
		{
		}
		else // player don,t have money and will stay for 3 turns in prison
		{
			pGrid->PrintErrorMessage("You don't have enough money..");
			pPlayer->gotoPrison(); // getting player in prison for 3 turns
		}
	}
	else
		pPlayer->gotoPrison(); // getting player in prison for 3 turns	
	pOut->ClearStatusBar(); // clearing the status bar
}

void Card_8::save(ofstream& outfile, int type)
{
	if (type == 3)
	{
		Card::save(outfile, type);

		outfile << coinsToExit << " " << endl;
	}
}

void Card_8::Load(ifstream& infile)
{
	Card::Load(infile);

	int CoinsToExit;
	infile >> CoinsToExit;
	this->coinsToExit = CoinsToExit;
}

Card_8* Card_8::GetCopy()
{
	Card_8* pCard = new Card_8(position);
	pCard->coinsToExit = this->coinsToExit;
	return pCard;
}