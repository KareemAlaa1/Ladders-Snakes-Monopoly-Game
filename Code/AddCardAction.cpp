#include "AddCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include"Card_5.h"
#include"Card_6.h"
#include"Card_8.h"
#include"Card_7.h"
#include"Card_9.h"
#include"Card_10.h"
#include"Card_11.h"
#include"Card_2.h"
#include"Card_3.h"
#include"Card_4.h"
#include"Card_12.h"







AddCardAction::AddCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("New Card: Please Enter Card Number ...");
	cardNumber = pIn->GetInteger(pOut);
	while (cardNumber > 12 || cardNumber < 1)
	{
		pOut->PrintMessage("invalid cardNumber [Hint: It must be between 1 & 12], Try again....");
		cardNumber = pIn->GetInteger(pOut);

	}
	pOut->PrintMessage(" Please click on the cell ...");

	cardPosition = pIn->GetCellClicked(pOut);
	while (!cardPosition.IsValidCell() || (cardPosition.HCell() == 0 && cardPosition.VCell() == 8)||(cardPosition.HCell() == 10 && cardPosition.VCell()==0))
	{
		if ((cardPosition.HCell() == 0 && cardPosition.VCell() == 8) || (cardPosition.HCell() == 10 && cardPosition.VCell() == 0))
		{
			pOut->PrintMessage("Start cell and End cell can't have a card, Click on another cell...");
		}
		if (!cardPosition.IsValidCell())
		{
			pOut->PrintMessage("Invalid cell, please click on the cell again...");
		}
		cardPosition = pIn->GetCellClicked(pOut);
	}
	pOut->ClearStatusBar();
}

void AddCardAction::Execute()
{

	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	Card* pCard = NULL; // will point to the card object type
	switch (cardNumber)
	{
	case 1:
		pCard = new CardOne(cardPosition);
		break;
	case 2:
		pCard = new Card_2(cardPosition);
		break;

	case 3:
		pCard = new Card_3(cardPosition);
		break;

	case 4:
		pCard = new Card_4(cardPosition);
		break;
	case 5:
		pCard = new Card_5(cardPosition);
		break;
	case 6:
		pCard = new Card_6(cardPosition);
		break;
	case 7:
		pCard = new Card_7(cardPosition);
		break;
	case 8:
		pCard = new Card_8(cardPosition);
		break;
	case 9:
		pCard = new Card_9(cardPosition);
		break;
	case 10:
		pCard = new Card_10(cardPosition);
		break;
	case 11:
		pCard = new Card_11(cardPosition);
		break;

	case 12:
		pCard = new Card_12(cardPosition);
		break;
		// A- Add the remaining cases

	}

	if (pCard) // if pCard is pointing to an object
	{

		Grid* pGrid = pManager->GetGrid();

		pCard->ReadCardParameters(pGrid);

		bool added = pGrid->AddObjectToCell(pCard);

		if (!added)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		}
		
	}

	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}
