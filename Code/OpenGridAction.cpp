#include "OpenGridAction.h"
#include"NewGameAction.h"


OpenGridAction::OpenGridAction(ApplicationManager* pApp) : Action(pApp)
{
}

OpenGridAction::~OpenGridAction()
{
}

void OpenGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Open Grid: please enter the grid number ...");
	gridNum = pIn->GetInteger(pOut);

	pOut->ClearStatusBar();


}

void OpenGridAction::Execute()
{

	ReadActionParameters();



	Grid* pGrid = pManager->GetGrid();

	Output* pOut = pGrid->GetOutput();


	string file = to_string(gridNum) + ".txt";
	ifstream infile(file);


	if (infile.is_open())
	{
		pGrid->ClearGrid();

		Card_9::isLoaded = false;
		Card_10::isLoaded = false;
		Card_11::isLoaded = false;
		int objectsNum;
		int startPosNum;
		int endPosNum;
		int cardNum;

		infile >> objectsNum;


		for (int i = 0; i < objectsNum; i++)
		{

			CellPosition startPos;
			CellPosition endPos;

			Ladder* pLadder = new Ladder(startPos, endPos);

			pLadder->Load(infile);
			pGrid->AddObjectToCell(pLadder);
		}


		infile >> objectsNum;

		for (int i = 0; i < objectsNum; i++)
		{

			CellPosition startPos;
			CellPosition endPos;

			Snake* pSnake = new Snake(startPos, endPos);

			pSnake->Load(infile);
			pGrid->AddObjectToCell(pSnake);
		}


		infile >> objectsNum;

		for (int i = 0; i < objectsNum; i++)
		{

			CellPosition startPos;

			infile >> cardNum;
			if (cardNum == 1)
			{
				CardOne* pCard = new CardOne(startPos);
				pCard->Load(infile);
				pGrid->AddObjectToCell(pCard);
			}
			else if (cardNum == 2)
			{
				Card_2* pCard = new Card_2(startPos);
				pCard->Load(infile);
				pGrid->AddObjectToCell(pCard);
			}
			else if (cardNum == 3)
			{
				Card_3* pCard = new Card_3(startPos);
				pCard->Load(infile);
				pGrid->AddObjectToCell(pCard);
			}
			else if (cardNum == 4)
			{
				Card_4* pCard = new Card_4(startPos);
				pCard->Load(infile);
				pGrid->AddObjectToCell(pCard);
			}
			else if (cardNum == 5)
			{
				Card_5* pCard = new Card_5(startPos);
				pCard->Load(infile);
				pGrid->AddObjectToCell(pCard);
			}
			else if (cardNum == 6)
			{
				Card_6* pCard = new Card_6(startPos);
				pCard->Load(infile);
				pGrid->AddObjectToCell(pCard);
			}
			else if (cardNum == 7)
			{
				Card_7* pCard = new Card_7(startPos);
				pCard->Load(infile);
				pGrid->AddObjectToCell(pCard);
			}
			else if (cardNum == 8)
			{
				Card_8* pCard = new Card_8(startPos);
				pCard->Load(infile);
				pGrid->AddObjectToCell(pCard);
			}
			else if (cardNum == 9)
			{
				Card_9* pCard = new Card_9(startPos);
				pCard->Load(infile);
				pGrid->AddObjectToCell(pCard);
			}
			else if (cardNum == 10)
			{
				Card_10* pCard = new Card_10(startPos);
				pCard->Load(infile);
				pGrid->AddObjectToCell(pCard);
			}
			else if (cardNum == 11)
			{
				Card_11* pCard = new Card_11(startPos);
				pCard->Load(infile);
				pGrid->AddObjectToCell(pCard);
			}
			else if (cardNum == 12)
			{
				Card_12* pCard = new Card_12(startPos);
				pCard->Load(infile);
				pGrid->AddObjectToCell(pCard);
			}
		}
		// New Game after loading Grid
		Action* pAct = new NewGameAction(pManager);
		pAct->Execute();
		delete pAct;
	}
	else
		pOut->PrintMessage("The Grid Is Not found");


}