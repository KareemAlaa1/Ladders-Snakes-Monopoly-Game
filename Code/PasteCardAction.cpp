#include "PasteCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"

PasteCardAction::PasteCardAction ( ApplicationManager* pApp ) : Action ( pApp )
{
	// Initializes the pManager pointer of Action with the passed pointer
}

PasteCardAction::~PasteCardAction ( )
{
}


void PasteCardAction::ReadActionParameters ( )
{
	Grid* pGrid = pManager->GetGrid ( );
	Output* pOut = pGrid->GetOutput ( );
	Input* pIn = pGrid->GetInput ( );

	pOut->PrintMessage ( "Paste Card: Please Click On Cell ..." );
	cardPosition = pIn->GetCellClicked ( pOut);


	while (!cardPosition.IsValidCell() || (cardPosition.HCell() == 0 && cardPosition.VCell() == 8) || (cardPosition.HCell() == 10 && cardPosition.VCell() == 0))
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

	pOut->ClearStatusBar ( );

}

void PasteCardAction::Execute ( )
{
	Grid* pGrid = pManager->GetGrid();
	
	if (pGrid->Isemptyclipboard())
	{
		pGrid->PrintErrorMessage("Error, The clipboard is empty. Click to continue");
		return;
	}

	ReadActionParameters ( );
	
	if ( pGrid->HasCard ( cardPosition ) )
	{
		pGrid->PrintErrorMessage ( "Error: Cell has card ! Click to continue ..." );
	}
	else
	{
		Card* pCard = pGrid->GetClipboard ( );

		 pCard->SetCardPos ( cardPosition );
		bool added = pGrid->AddObjectToCell ( pCard);


		if ( !added )
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage ( "Error: Cell already has an object ! Click to continue ..." );
			return;
		}

		pGrid->PrintErrorMessage ( " Card has been Pasted succesfully ! Click to continue ..." );

	}

}
