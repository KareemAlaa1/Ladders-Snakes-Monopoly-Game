#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"
#include"SuperPowers.h"
#include"Ice_Attack.h"
#include"Fire_Attack.h"
#include"Poison_Attack.h"
#include"Lightning_Attack.h"

#include <time.h> // used in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager* pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()      
{

	Grid* pgrid = pManager->GetGrid();
	Output* pOut = pgrid->GetOutput();
	Input* pIn = pgrid->GetInput();
	pOut->ClearStatusBar();

	bool x = pgrid->GetEndGame();
	if (x == true)
	{
		pOut->PrintMessage("The game has ended");
		return;
	}
	else
	{
		srand((int)time(NULL)); // time is for different seed each run
		int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed
		Player* currentplayer = pgrid->GetCurrentPlayer();

		if (!(currentplayer->inPrison()))
		{
			if (currentplayer->isFired())
			{
				currentplayer->Pay(20);
			}
			if (currentplayer->isPoisoned())
			{
				diceNumber--; // currentplayer is poisoned: deduct 1 number from his dice roll
			}

			currentplayer->SetTurnCount(currentplayer->GetTurnCount() + 1);
			if (currentplayer->GetTurnCount() == 3)
			{
				if (currentplayer->haveattack())
				{

					pOut->PrintMessage("Click (Y/y) to attack a player instead of charging the wallet");
					string d = pIn->GetSrting(pOut);
					if (toupper(d[0]) == 'Y')
					{
						currentplayer->settotalattack(currentplayer->gettotalattack() - 1);
							SuperPowers* pPower = NULL;
							pOut->PrintMessage("Enter the number of the attack (1=ice , 2=fire , 3=poison , 4=lightning)");
							int attnum = pIn->GetInteger(pOut);
							while (attnum > 4 || attnum < 1)
							{
								pOut->PrintMessage("Invalid attack number (1=ice , 2=fire , 3=poison , 4=lightning), Try again...");
								attnum = pIn->GetInteger(pOut);
							}
							while (attnum == 1 && !currentplayer->haveiceattack())
							{
								pOut->PrintMessage("You don't have ice attacks,choose another attack (2=fire , 3=poison , 4=lightning)");
								attnum = pIn->GetInteger(pOut);
								while ((attnum > 4 || attnum < 1) || attnum == 1)
								{
									pOut->PrintMessage("Invalid attack number, choose another attack (2=fire , 3=poison , 4=lightning)");
									attnum = pIn->GetInteger(pOut);
								}
							}
							while (attnum == 2 && !currentplayer->havefireattack())
							{
								pOut->PrintMessage("You don't have fire attacks,choose another attack (1=ice , 3=poison , 4=lightning)");
								attnum = pIn->GetInteger(pOut);
								while ((attnum > 4 || attnum < 1) || attnum == 2)
								{
									pOut->PrintMessage("Invalid attack number,choose another attack (1=ice , 3=poison , 4=lightning)");
									attnum = pIn->GetInteger(pOut);
								}
							}
							while (attnum == 3 && !currentplayer->havepoisonattack())
							{
								pOut->PrintMessage("You don't have poison attacks,choose another attack (1=ice , 2=fire , 4=lightning)");
								attnum = pIn->GetInteger(pOut);
								while ((attnum > 4 || attnum < 1) || attnum == 3)
								{
									pOut->PrintMessage("Invalid attack number, choose another attack (1=ice , 2=fire , 4=lightning)");
									attnum = pIn->GetInteger(pOut);
								}
							}

							while (attnum == 4 && !currentplayer->havelightningattack())
							{
								pOut->PrintMessage("You don't have lightning attacks, choose another attack(1=ice , 2=fire , 3=poison)");
								attnum = pIn->GetInteger(pOut);
								while ((attnum > 4 || attnum < 1)||attnum==4)
								{
									pOut->PrintMessage("Invalid attack number, choose another attack(1=ice , 2=fire , 3=poison)");
									attnum = pIn->GetInteger(pOut);
								}
							}
							switch (attnum)
							{

							case 1:
								pPower = new Ice_Attack;
								break;
							case 2:
								pPower = new Fire_Attack;
								break;
							case 3:
								pPower = new Poison_Attack;
								break;
							case 4:
								pPower = new Lightning_Attack;
							}
							if (pPower != NULL)
							{

								pPower->Apply(pgrid, currentplayer);
								delete pPower;
								pPower = NULL;
							}
							currentplayer->SetTurnCount(0);

						
					}

					else
					{
						int CoinsIncrease = diceNumber * 10;
						currentplayer->Recharge(CoinsIncrease);
						currentplayer->SetTurnCount(0);
						pgrid->AdvanceCurrentPlayer();
						pOut->ClearStatusBar();

						return;
					}

				}
				currentplayer->SetTurnCount(0);

			}
			else
			{

				currentplayer->Move(pgrid, diceNumber);
				pgrid->AdvanceCurrentPlayer();
				return;
			}
		}
		pgrid->AdvanceCurrentPlayer();



	}
	pOut->ClearStatusBar();
}

RollDiceAction::~RollDiceAction()
{
}
