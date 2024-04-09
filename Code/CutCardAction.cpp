#include "CutCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"

CutCardAction::CutCardAction ( ApplicationManager* pApp ) : Action ( pApp )
{
	// Initializes the pManager pointer of Action with the passed pointer
}

CutCardAction::~CutCardAction ( )
{
}


void CutCardAction::ReadActionParameters ( )
{
	Grid* pGrid = pManager->GetGrid ( );
	Output* pOut = pGrid->GetOutput ( );
	Input* pIn = pGrid->GetInput ( );

	pOut->PrintMessage ( "Cut Card: Please Click On Card ..." );
	cardPosition = pIn->GetCellClicked ( pOut);

	while (!cardPosition.IsValidCell())
	{
		pOut->PrintMessage("Invalid Cell, Click on the cell again....");
		cardPosition = pIn->GetCellClicked(pOut);
	}

	pOut->ClearStatusBar ( );

}

void CutCardAction::Execute ( )
{

	ReadActionParameters ( );


	Grid* pGrid = pManager->GetGrid ( );
	if ( pGrid->HasCard ( cardPosition ) )
	{
		Card* pCard = pGrid->GetGameObject(cardPosition);// will point to the card object type
		
		pGrid->SetClipboard (pCard );

		pGrid->RemoveObjectFromCell ( cardPosition );


		pGrid->PrintErrorMessage ( "Card has been cut succesfully ! Click to continue ..." );

	}
	else
		pGrid->PrintErrorMessage ( "Error: Cell has no card ! Click to continue ..." );

}
