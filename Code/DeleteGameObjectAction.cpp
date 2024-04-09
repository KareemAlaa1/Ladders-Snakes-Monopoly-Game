#include "DeleteGameObjectAction.h"
#include"Input.h"
#include"Grid.h"
#include"CellPosition.h"

DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) : Action(pApp)
{
}

void DeleteGameObjectAction::SetPosition(CellPosition pos)
{
	position = pos;

}

void DeleteGameObjectAction::ReadActionParameters()
{
	Grid* pgrid = pManager->GetGrid();
	Input* pIn = pgrid->GetInput();
	Output* pOut = pgrid->GetOutput();

	pOut->PrintMessage("DeleteGameObject: Click on the cell...");
	CellPosition pos = pIn->GetCellClicked(pOut);
	SetPosition(pos);
}

void DeleteGameObjectAction::Execute()
{
	ReadActionParameters();
	Grid* pgrid = pManager->GetGrid();
	Input* pIn = pgrid->GetInput();
	Output* pOut = pgrid->GetOutput();

	int x=pgrid->RemoveObjectFromCell(position);
	if (x == 1)
		pOut->PrintMessage("The Object has been deleted");
	else if(x==2)
		pOut->PrintMessage("The Cell has no object");
	else
		pOut->PrintMessage("The Position you clicked is invalid");



}

DeleteGameObjectAction::~DeleteGameObjectAction()
{
}