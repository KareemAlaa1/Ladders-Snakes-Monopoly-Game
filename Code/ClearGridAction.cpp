#include "ClearGridAction.h"
#include"Grid.h"


ClearGridAction::ClearGridAction(ApplicationManager* pApp) : Action(pApp)
{
}

void ClearGridAction::ReadActionParameters()
{
	// no parameters to read from user
}

void ClearGridAction::Execute()
{
	Grid* pgrid = pManager->GetGrid();

	pgrid->ClearGrid();

	pgrid->PrintErrorMessage("Grid has been cleared. Click to continue ...");

}

ClearGridAction::~ClearGridAction()
{
}