#include "Player.h"

#include "GameObject.h"
#include"Card.h"

Player::Player(Cell* pCell, int playerNum) : stepCount(1), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	this->prison_count = 0;
	preventcount = 0;
	poison_count = 0;
	burncount = 0;
	total_attacks = 2;
	ice_attacks = 1;
	fire_attacks = 1;
	poison_attacks = 1;
	lightning_attacks = 1;

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

const int Player::getplayernum()
{
	return playerNum;
}

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	if(wallet>0)
	this->wallet = wallet;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

void Player::Pay(int amount)
{
	if (amount > 0) // validate amount
		wallet = wallet - amount;
}

bool Player::Buy(int price)
{
	if (price > 0) // validate price
	{
		if (wallet >= price)
		{
			wallet = wallet - price;
			return true;  // player has enough money to buy
		}
		else
			return false; // player doesn't have enough money to buy
	}
}

void Player::Recharge(int AddAmount)
{
	if (AddAmount > 0) // validate AddAmount
		wallet = wallet + AddAmount;
}

void Player::SetTurnCount(int newturn)
{
	turnCount = newturn;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

void Player:: setstepcount(int x)
{
	if (x > 0 && x <= NumHorizontalCells * NumVerticalCells)
		stepCount = x;
}
void Player::setprisoncount(int x)
{
	prison_count = x;
}
void Player::setpreventcount(int x)
{
	preventcount = x;
}

void Player::increasepreventcount(int x)
{
	preventcount += x;
}
void Player::settotalattack(int x)
{
	total_attacks = x;
}

int Player::gettotalattack()
{
	return total_attacks;
}

void Player:: seticeattack(int x)
{
	ice_attacks = x;
}

int Player::geticeattack()
{
	return ice_attacks;
}

void Player:: setfireattack(int x)
{
	fire_attacks = x;
}
int Player::getfireattack()
{
	return fire_attacks;
}
void Player:: setpoisonattack(int x)
{
	poison_attacks = x;
}
int Player::getpoisonattack()
{

	return poison_attacks;
}
void Player:: setlightningattack(int x)
{
	lightning_attacks = x;
}
int Player::getlightningattack()
{
	return lightning_attacks;
}
void Player::setburncount(int x)
{
	burncount = x;
}

int Player::getburncount()
{
	return burncount;
}

void Player::setpoison_count(int x)
{
	if (x >= 0 || x <= 5)
		poison_count = x;
}

int Player::getpoison_count()
{
	return poison_count;
}

bool Player::isPoisoned()
{
	if (poison_count > 0)
	{
		poison_count--;
		return true;
	}
	return false;
}

int Player::getjustRolledDiceNum() const
{
	return justRolledDiceNum;
}

void Player::gotoPrison()
{
	prison_count = 3;
}

bool Player::inPrison()
{
	if (prison_count > 0)
	{
		prison_count--;
		return true;
	}
	return false;
}

bool Player::isprevented()
{
	if (preventcount > 0)
	{
		preventcount--;
		return true;
	}
	return false;
}

bool Player::isFired()
{
	if (burncount > 0)
	{
		burncount--;
		return true;
	}
	return false;
}

bool Player::haveattack()
{
	if (total_attacks > 0)
	
		return true;
	
	return false;
}

bool Player::haveiceattack()
{
	if (ice_attacks > 0)
	{
		ice_attacks--;
		return true;
	}
	return false;
}

bool Player::havefireattack()
{
	if (fire_attacks > 0)
	{
		fire_attacks--;
		return true;
	}
	return false;
}

bool Player::havepoisonattack()
{
	if (poison_attacks > 0)
	{
		poison_attacks--;
		return true;
	}
	return false;
}

bool Player::havelightningattack()
{
	if (lightning_attacks > 0)
	{
		lightning_attacks--;
		return true;
	}
	return false;
}

Player* Player::getpoorer(Player* P2)
{
	if (wallet <= P2->wallet)
		return this;
	else
		return P2;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];

	// use the appropriate output function to draw the player with "playerColor"

	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);

}

void Player::ClearDrawing(Output* pOut) const
{
	
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	
	if (pCell->HasCard())
	{
		Card* temp = pCell->HasCard();

		int cardnum = temp->GetCardNumber();

		if (cardnum == 9)
			cellColor = BROWN;
		else if (cardnum == 10)
			cellColor = DARKSALMON;
		else if (cardnum == 11)
			cellColor = ORCHID;
		else
			cellColor = UI.CellColor_HasCard;
	}
	else
	{
		cellColor = UI.CellColor_NoCard;
	}
	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);

}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{
	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once

	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)

	// 3- Set the justRolledDiceNum with the passed diceNumber

	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"

	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position

	// 6- Apply() the game object of the reached cell (if any)

	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	if (!isprevented())
	{
		justRolledDiceNum = diceNumber;
		stepCount += justRolledDiceNum;

		if (stepCount <= NumHorizontalCells * NumVerticalCells) // player still playing
		{
			CellPosition pos = pCell->GetCellPosition();
			pos.AddCellNum(justRolledDiceNum);
			pGrid->UpdatePlayerCell(this, pos);

			GameObject* TGOG = pCell->GetGameObject();
			if (TGOG != NULL) {
				TGOG->Apply(pGrid, this);
			}
		}

		else if (stepCount == (NumHorizontalCells * NumVerticalCells+1)) // player wins
		{
			CellPosition pos(NumHorizontalCells * NumVerticalCells); // cellnum 99
			pGrid->UpdatePlayerCell(this, pos);	// draw player in cellnum 99
			pGrid->PrintErrorMessage("We have a Winner... [player " + to_string(playerNum) + " win.] congratulations!");
			pGrid->SetEndGame(true);

		}
		else if (stepCount > (NumHorizontalCells * NumVerticalCells+1)) // player exceeded victory
		{
			stepCount -= justRolledDiceNum; // return stepCount to its value
		}
	}


}


void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}

void Player::Resetplayer(Grid* pGrid)
{
	CellPosition pos(1);
	pGrid->Gotostartcell(this, pos); // reset player cell
	this->SetCell(pGrid->Getcellfromcellposition(pos));
	wallet = 100; // reset wallet
	turnCount = 0; // reset turncount
	stepCount = 1; // reset stepcount
	fire_attacks = 1; // reset fire_attacks
	ice_attacks = 1; // reset ice_attacks
	poison_attacks = 1; // reset poison_attacks
	lightning_attacks = 1; // reset lightning_attacks
	total_attacks = 2; // reset total_attacks
	preventcount = 0; // reset preventcount
	prison_count = 0; // reset prison_count
	poison_count = 0; // reset poison_attack
}