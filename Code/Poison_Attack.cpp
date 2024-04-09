#include "Poison_Attack.h"
#include"Player.h"
#include"Output.h"
#include"Input.h"

Poison_Attack::Poison_Attack()
{
	AttackNumber = 3;
}

void Poison_Attack::ReadParameters(Grid* pGrid,Player*pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter the number of the player you want to attack...");
	int x = pIn->GetInteger(pOut);
	while ((x > 3 || x < 0) || (x == pPlayer->getplayernum()))
	{
		pOut->PrintMessage("Invalid number,It should be between 0-3 except yourself,Enter the Number again..");
		x = pIn->GetInteger(pOut);
	}
	playernum = x;

}

void Poison_Attack::Apply(Grid * pGrid, Player * pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	ReadParameters(pGrid, pPlayer);
	pOut->ClearStatusBar();
	Player* attackedplayer = pGrid->GetPlayerfromnum(playernum);
	attackedplayer->setpoison_count(attackedplayer->getpoison_count()+ 5);

}