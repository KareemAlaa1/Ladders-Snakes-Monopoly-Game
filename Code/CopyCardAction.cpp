#include "CopyCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"

CopyCardAction::CopyCardAction ( ApplicationManager* pApp ) : Action ( pApp )
{
	// Initializes the pManager pointer of Action with the passed pointer
}

CopyCardAction::~CopyCardAction ( )
{
}


void CopyCardAction::ReadActionParameters ( )
{
	Grid* pGrid = pManager->GetGrid ( );
	Output* pOut = pGrid->GetOutput ( );
	Input* pIn = pGrid->GetInput ( );

	pOut->PrintMessage ( "Copy Card: Please Click On Card ..." );
	cardPosition = pIn->GetCellClicked ( pOut);
	while (!cardPosition.IsValidCell())
	{
		pOut->PrintMessage("Invalid Cell, Click on the cell again....");
		cardPosition = pIn->GetCellClicked(pOut);
	}

	pOut->ClearStatusBar ( );

}

void CopyCardAction::Execute ( )
{

	ReadActionParameters ( );

	Grid* pGrid = pManager->GetGrid ( );
	if ( pGrid->HasCard ( cardPosition ) )
	{
		Card* pCard = new Card(cardPosition);
		pCard = ((pGrid->GetGameObject(cardPosition)))->GetCopy();
		pGrid->SetClipboard(pCard);


		pGrid->PrintErrorMessage ( "Card has been copied succesfully ! Click to continue ..." );

	}
	else
		pGrid->PrintErrorMessage ( "Error: Cell has no card ! Click to continue ..." );

}
