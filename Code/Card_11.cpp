#include "Card_11.h"


int Card_11::fees = -1; //
int Card_11::price = -1;  //
Player* Card_11::owner = NULL;


Card_11::Card_11(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 11; // set the inherited cardNumber data member with the card number (11 here)
}

Card_11::~Card_11(void)
{
}

void Card_11::ReadCardParameters(Grid* pGrid)
{
	int x = 0;
	Input* pIn = pGrid->GetInput(); // Get a Pointer to the Input Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();// Get a Pointer to the Output Interfaces from the Grid
	if (price == -1)
	{
		//reading card price
		pOut->PrintMessage("New Card 11 : Enter its price amount ..."); // print to a descriptive message to the user
		x = pIn->GetInteger(pOut);// Read an Integer from the user...need validations
		while (x <= 0) // validate x value
		{
			pOut->PrintMessage("invalid amount try again...");
			x = pIn->GetInteger(pOut);
		}
		price = x; // setting price amount
		pOut->ClearStatusBar();// clearing the status bar

		//reading card fees
		pOut->PrintMessage("New Card 11 : Enter its fees amount ..."); // print to a descriptive message to the user
		x = pIn->GetInteger(pOut);// Read an Integer from the user...need validations
		while (x <= 0) // validate x value
		{
			pOut->PrintMessage("invalid amount try again...");
			x = pIn->GetInteger(pOut);
		}
		fees = x; // setting price amount
		pOut->ClearStatusBar();// clearing the status bar
	}

}

void Card_11::Apply(Grid* pGrid, Player* pPlayer)
{
	string playerdecision;
	Input* pIn = pGrid->GetInput(); // Get a Pointer to the Input Interfaces from the Grid
	Output* pOut = pGrid->GetOutput(); // Get a Pointer to the Output Interfaces from the Grid
	Card::Apply(pGrid, pPlayer);
	if (owner == NULL)
	{
		pOut->PrintMessage("Enter (Y/y) to buy stations num : 11 Or otherwise to skip..."); // print to a descriptive message to the user
		playerdecision = pIn->GetSrting(pOut); // Read a char from the user
		if (playerdecision[0] == 'Y' || playerdecision[0] == 'y')
		{
			if (pPlayer->Buy(price))
				owner = pPlayer; // player has enough money to buy this station
			else
				pGrid->PrintErrorMessage("You don't have enough money to buy this station..");
		}
		pOut->ClearStatusBar();// clearing the status bar
	}
	else if (pPlayer != owner)
	{
		pPlayer->Pay(fees); // guest pay fees
		owner->Recharge(fees); // owner get fees
	}
}
int Card_11::GetPrice()
{
	return price;
}

Player* Card_11::GetOwner()
{
	return owner;
}

void Card_11::SetOwner(Player* NewOwner)
{
	owner = NewOwner;
}

void Card_11::save(ofstream& outfile, int type)
{
	if (type == 3)
	{
		Card::save(outfile, type);

		if (!(this->isSaved))
		{
			outfile << fees << " " << price << " " << endl;
			isSaved = true;
		}
		else
			outfile << endl;
	}
}

void Card_11::Load(ifstream& infile)
{
	Card::Load(infile);
	if (!(this->isLoaded))
	{
		int Fees;
		int Price;

		infile >> Fees >> Price;

		this->fees = Fees;
		this->price = Price;

		isLoaded = true;
	}
}

Card_11* Card_11::GetCopy()
{
	Card_11* pCard = new Card_11(position);
	pCard->fees = this->fees;
	pCard->price = this->price;
	return pCard;
}

bool Card_11::isSaved = false;
bool Card_11::isLoaded = false;