#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked(pOut);

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked(pOut);

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
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

	if (pGrid->Getcellfromcellposition(endPos)->HasSnake())
	{ 
		pGrid->PrintErrorMessage("End cell can't be start of a snake");
		return;
	}
	if (pGrid->Getcellfromcellposition(startPos)->HasSnake())
	{
		pGrid->PrintErrorMessage("Start cell can't be End of a ladder");
		return;
	}

	if (startPos.HCell() != endPos.HCell())
	{
		pGrid->PrintErrorMessage ("end cell and start cell are not in the same column");
		return;
	}
	if (endPos.VCell() == startPos.VCell())
	{
		pGrid->PrintErrorMessage("Start cell & End cell cannot be the same");
		return;
	}
	if (endPos.VCell() > startPos.VCell())
	{
		pGrid->PrintErrorMessage("end cell cannot be smaller than start cell");
		return;
	}
	if (endPos.VCell() == 0 && endPos.HCell() == (NumHorizontalCells - 1))
	{
		pGrid->PrintErrorMessage(" end cell cannot be the end");
		return;
	}
	if (startPos.VCell() == 8 && startPos.HCell() == 0)
	{
		pGrid->PrintErrorMessage(" Start cell cannot be the start");
		return;
	}

	Ladder* pLadder = new Ladder(startPos, endPos);


	if (pGrid->Isoverlapping(pLadder))
	{
		pGrid->PrintErrorMessage("Overlapping....");
		return;
	}

	
	// Create a Ladder object with the parameters read from the user

	// We get a pointer to the Grid from the ApplicationManager

	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pLadder);

	// if the GameObject cannot be added
	if (! added&&endPos.IsValidCell())
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}
