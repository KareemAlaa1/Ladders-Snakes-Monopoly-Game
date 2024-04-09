#include "NewGameAction.h"
#include "Grid.h"
#include "Player.h"
#include"Card_9.h"
#include"Card_10.h"
#include"Card_11.h"

NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{
}

void NewGameAction::ReadActionParameters()
{
	// no parameters to read from user
}

void NewGameAction::Execute()
{
	Grid* pgrid = pManager->GetGrid();

	pgrid->resetplayers(); // reset players
	Card_9::SetOwner(0); // reset Card 9 Owner
	Card_10::SetOwner(0); // reset Card 10 Owner
	Card_11::SetOwner(0); // reset Card 11 Owner
	pgrid->GetOutput()->PrintMessage("New Game Has Started");
	pgrid->SetEndGame(false); // reset EndGame
}

NewGameAction::~NewGameAction()
{
}