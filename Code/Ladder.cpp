#include "Ladder.h"
#include"Snake.h"
#include"Player.h"

Ladder::Ladder(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer)
{
	int x, y;
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("You have reached a ladder. Click to continue ...");
	pIn->GetPointClicked(x, y);
	int tempdice = endCellPos.GetCellNum() - position.GetCellNum();
	pPlayer->Move(pGrid,tempdice);
	pOut->ClearStatusBar();


}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

bool Ladder::IsOverlapping(GameObject* newobj,Grid *pGrid)
{
	CellPosition oldstartpos = this->GetPosition();
	CellPosition oldendpos = this->GetEndPosition();
	Ladder* newladder = dynamic_cast<Ladder*>(newobj);

	
	if (newladder != NULL)
	{
		CellPosition newstartpos = newladder->GetPosition();
		CellPosition newendpos = newladder->endCellPos;
		
		if (newstartpos.VCell() < oldstartpos.VCell() && newstartpos.VCell() >= oldendpos.VCell())
			return true;
		else if (oldstartpos.VCell() < newstartpos.VCell() && oldstartpos.VCell() >= newendpos.VCell())
			return true;
	}
	Snake* newsnake = dynamic_cast<Snake*>(newobj);
	if (newsnake != NULL)
	{
		CellPosition newstartpos = newsnake->GetPosition();
		CellPosition newendpos = newsnake->GetEndPosition();

		if ((oldendpos.VCell() == newstartpos.VCell()) && (oldendpos.HCell() == newstartpos.HCell()))
			return true;
	}
	return false;


}

void Ladder::save(ofstream& outfile, int type)
{

	if (type == 1)
	{
		outfile << position.GetCellNum() << " " << endCellPos.GetCellNum() << " " << endl;
	}


}

void Ladder::Load(ifstream& infile)
{



	int startPosNum;
	int endPosNum;
	infile >> startPosNum >> endPosNum;

	CellPosition startPos;
	CellPosition endPos;


	startPos = CellPosition::GetCellPositionFromNum(startPosNum);
	endPos = CellPosition::GetCellPositionFromNum(endPosNum);


	this->position = startPos;
	this->endCellPos = endPos;

}

Ladder* Ladder::GetCopy()
{
	Ladder* pLadder = new Ladder(position, endCellPos);
	return pLadder;
}

Ladder::~Ladder()
{
}
