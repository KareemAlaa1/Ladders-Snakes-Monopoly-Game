#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnakeAction::AddSnakeAction ( ApplicationManager* pApp ) : Action ( pApp )
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction ( )
{
}

void AddSnakeAction::ReadActionParameters ( )
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid ( );
	Output* pOut = pGrid->GetOutput ( );
	Input* pIn = pGrid->GetInput ( );

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked ( pOut);

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked ( pOut);

	// Clear messages
	pOut->ClearStatusBar ( );
}


// Execute the action
void AddSnakeAction::Execute ( )
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters ( );

	// Create a Ladder object with the parameters read from the user

	Grid* pGrid = pManager->GetGrid ( ); // We get a pointer to the Grid from the ApplicationManager

	if (!(startPos.IsValidCell()))
	{
		pGrid->PrintErrorMessage("Start cell is invalid...");
		return;
	}
	if (!(endPos.IsValidCell()))
	{
		pGrid->PrintErrorMessage("End cell is invalid...");
		return;
	}
	if (pGrid->Getcellfromcellposition(endPos)->HasLadder())
	{
		pGrid->PrintErrorMessage("End cell can't be start of a ladder");
		return;
	}

	
	if (startPos.HCell() != endPos.HCell())
	{
		pGrid->PrintErrorMessage("end cell and start cell are not in the same column");
		return;
	}
	if (endPos.VCell() == startPos.VCell())
	{
		pGrid->PrintErrorMessage("Start cell & End cell cannot be the same");
		return;
	}
	if (endPos.VCell() < startPos.VCell())
	{
		pGrid->PrintErrorMessage("start cell cannot be smaller than end cell");
		return;
	}
	if (startPos.VCell() == 0 && startPos.HCell() == (NumHorizontalCells - 1))
	{
		pGrid->PrintErrorMessage(" start cell cannot be the end");
		return;
	}

	Snake* pSnake = new Snake(startPos, endPos);


	if (pGrid->Isoverlapping(pSnake))
	{
		pGrid->PrintErrorMessage("Overlapping....");
		return;
	}

	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell ( pSnake );

	// if the GameObject cannot be added
	if ( !added  && startPos.GetCellNum() != 99)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage ( "Error: Cell already has an object ! Click to continue ..." );
	}
	

}
