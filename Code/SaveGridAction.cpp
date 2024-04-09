#include "SaveGridAction.h"
#include"Card_10.h"
#include"Card_11.h"
#include"Card_9.h"


SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp)
{
}

SaveGridAction::~SaveGridAction()
{
}

void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Save Grid: please enter the grid number ...");
	gridNum = pIn->GetInteger(pOut);

	pOut->ClearStatusBar();


}

void SaveGridAction::Execute()
{

	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	string file = to_string(gridNum) + ".txt";
	ofstream outfile(file);
	Card_9::isSaved = false;
	Card_10::isSaved = false;
	Card_11::isSaved = false;
	int NumsofLadders = 0;
	int NumsofSnakes = 0;
	int NumsofCards = 0;
	NumsofLadders = pGrid->getNumofLaddersSnakesCards(NumsofSnakes, NumsofCards);
	outfile << NumsofLadders << endl;
	pGrid->SaveAll(outfile, 1);

	outfile << NumsofSnakes << endl;

	pGrid->SaveAll(outfile, 2);
	outfile << NumsofCards << endl;

	pGrid->SaveAll(outfile, 3);


}