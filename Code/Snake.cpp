#include "Snake.h"
#include"GameObject.h"
#include"Cell.h"
#include"Ladder.h"
#include"Player.h"
Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	int x, y;
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	
	pOut->PrintMessage("You have reached a Snake. Click to continue ...");
	pIn->GetPointClicked(x, y);
	int tempdice = endCellPos.GetCellNum() - position.GetCellNum();
	pPlayer->Move(pGrid, tempdice);
	pOut->ClearStatusBar();

}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

bool Snake:: IsOverlapping(GameObject* newobj, Grid* pGrid)
{
	CellPosition oldstartpos = this->GetPosition();
	CellPosition oldendpos = this->GetEndPosition();
	Snake* newsnake = dynamic_cast<Snake*>(newobj);


	if (newsnake != NULL)
	{
		CellPosition newstartpos = newsnake->GetPosition();
		CellPosition newendpos = newsnake->endCellPos;

		if (newstartpos.VCell() > oldstartpos.VCell() && newstartpos.VCell() <= oldendpos.VCell())
			return true;
		else if (oldstartpos.VCell() > newstartpos.VCell() && oldstartpos.VCell() <= newendpos.VCell())
			return true;
	}
	Ladder* newladder = dynamic_cast<Ladder*>(newobj);
	if (newladder != NULL)
	{
		CellPosition newstartpos = newladder->GetPosition();
		CellPosition newendpos = newladder->GetEndPosition();

		if ((oldendpos.VCell() == newstartpos.VCell()) && (oldendpos.HCell() == newstartpos.HCell()))
			return true;
	}
	return false;
}

void Snake::save(ofstream& outfile, int type)
{

	if (type == 2)
	{
		outfile << position.GetCellNum() << " " << endCellPos.GetCellNum() << " " << endl;
	}
}

void Snake::Load(ifstream& infile)
{
	int startPosNum;
	int endPosNum;
	infile >> startPosNum >> endPosNum;

	CellPosition startPos(startPosNum);
	CellPosition endPos(endPosNum);

	this->position = startPos;
	this->endCellPos = endPos;

}

Snake* Snake::GetCopy()
{
	Snake* pSnake = new Snake(position, endCellPos);
	return pSnake;
}

Snake::~Snake()
{
}