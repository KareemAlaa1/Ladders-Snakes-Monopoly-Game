#include "Grid.h"

#include "Cell.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
#include "Player.h"
#include "CardOne.h"
#include "Card_2.h"
#include "Card_3.h"
#include "Card_4.h"
#include "Card_5.h"
#include "Card_6.h"
#include "Card_7.h"
#include "Card_8.h"
#include "Card_9.h"
#include "Card_10.h"
#include "Card_11.h"
#include "Card_12.h"

Grid::Grid(Input* pIn, Output* pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells - 1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;
}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject* pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject* pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if (pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}


// Note: You may need to change the return type of this function (Think)
int Grid::RemoveObjectFromCell(const CellPosition& pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		if (HasCard(pos) || HasLadder(pos) || HasSnake(pos))
		{ // Note: you can deallocate the object here before setting the pointer to null if it is needed

			CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
			return 1;//means that the object has been deleted
		}
		else
			return 2;//means that the cell has no object
	}
	return 3;//means that the position is invalid
}

void Grid::UpdatePlayerCell(Player* player, const CellPosition& newPosition)
{
	// Clear the player's circle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell* newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);

	// Draw the player's circle on the new cell position
	player->Draw(pOut);
}

void Grid::Gotostartcell(Player* player, const CellPosition& newPosition)
{
	Output* pOut = this->GetOutput();
	// Clear the player's circle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell* newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);

	// Draw the player's circle on the new cell position
	player->Draw(pOut);

}

// ========= Setters and Getters Functions =========
int Grid::GetCurrentPlayerNumber()
{
	return currPlayerNumber;
}

Input* Grid::GetInput() const
{
	return pIn;
}

Output* Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard(Card* pCard) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard = pCard;
}

Card* Grid::GetClipboard() const // to be used in paste
{
	return ((Clipboard)->GetCopy());
}

bool Grid::Isemptyclipboard()
{
	if (Clipboard == NULL)
		return true;
	return false;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

void Grid::DecreaseCurrentPlayer()
{
	currPlayerNumber--;
}

Cell* Grid::Getcellfromcellposition(CellPosition pos)
{
				return CellList[pos.VCell()][pos.HCell()];	
}

// ========= Other Getters =========


Player* Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Player* Grid::GetPlayerfromnum(int x)
{
	return PlayerList[x];
}

int Grid::getNumofLaddersSnakesCards(int& NumofSnakes, int& NumofCards)
{

	int NumofLadders = 0;
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			if (CellList[i][j]->HasLadder())
				NumofLadders++;
			if (CellList[i][j]->HasSnake())
				NumofSnakes++;
			if (CellList[i][j]->HasCard())
				NumofCards++;
		}
	}
	return NumofLadders;
}

Ladder* Grid::GetNextLadder(const CellPosition& position, CellPosition& laddercell)
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			Ladder* temp = CellList[i][j]->HasLadder();

			if (temp != NULL)
			{
				laddercell = CellList[i][j]->GetCellPosition();
				return temp;//return if found
			}



		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}

Player* Grid::GetPoorestPlayer()
{
	Player* poorest = PlayerList[0];
	for (int i = 1; i < MaxPlayerCount; i++)
	{
		poorest = poorest->getpoorer(PlayerList[i]);
	}
	return poorest;
}

bool Grid::GetNextplayer(const CellPosition& position, Player**& nextplayers)
{
	int currentcellnum = position.GetCellNum();
	for (int i = currentcellnum + 1; i < NumHorizontalCells * NumVerticalCells; i++) // searching from current cell to lastcell-1
		for (int j = 0; j < MaxPlayerCount; j++)
		{
			if (PlayerList[j]->GetCell()->GetCellPosition().GetCellNum() == i) // checking if there player in cell i
			{
				// found a player
				for (int w = j; w < MaxPlayerCount; w++) // serching for all players in the same cell
				{
					if (PlayerList[w]->GetCell()->GetCellPosition().GetCellNum() == i)
						nextplayers[w] = PlayerList[w]; // 
				}
				return true; // found
			}
		}
	return false; // not found
}

// ========= User Interface Functions =========


void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without cards 
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrCard(pOut);
			}
		}

		// 2- Draw other cell objects (ladders, snakes)
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawLadderOrSnake(pOut);
			}
		}

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount - 1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cards/snakes/ladders do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

void Grid::decreasewallets(Player* pPlayer, int amount)
{
	for (int i = 0; i < 4; i++)
	{
		if (PlayerList[i] != pPlayer)
		{
			PlayerList[i]->Pay(amount);
		}
	}
}

void Grid::resetplayers()
{
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		PlayerList[i]->Resetplayer(this); // reset players
	}
	currPlayerNumber = 0; // reset currPlayerNumber
}

bool Grid::HasCard(CellPosition cell)
{

	if (CellList[cell.VCell()][cell.HCell()]->HasCard())
		return true;

	return false;
}
bool Grid::HasLadder(CellPosition cell)
{

	if (CellList[cell.VCell()][cell.HCell()]->HasLadder())
		return true;

	return false;
}
bool Grid::HasSnake(CellPosition cell)
{

	if (CellList[cell.VCell()][cell.HCell()]->HasSnake())
		return true;

	return false;
}

bool Grid::Isoverlapping(GameObject* newobj)
{
	bool d = false;
	int hcell = newobj->GetPosition().HCell();
	for (int i = 8; i >= 0; i--)
	{
		if (CellList[i][hcell]->HasLadder())
		{
			Ladder* oldladder = CellList[i][hcell]->HasLadder();
			d = oldladder->IsOverlapping(newobj, this);
		}
		else if ((CellList[i][hcell]->HasSnake()))
		{
			Snake* oldsnake = CellList[i][hcell]->HasSnake();
			d = oldsnake->IsOverlapping(newobj, this);
		}
		else if (d == true)
			return d;
	}
	return d;
}



Card* Grid::GetGameObject(CellPosition pos)
{
	return dynamic_cast<Card*>(CellList[pos.VCell()][pos.HCell()]->GetGameObject());
}

void Grid::SaveAll(ofstream& outfile, int type)
{

	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->HasLadder() || CellList[i][j]->HasSnake() || CellList[i][j]->HasCard())
				(CellList[i][j]->GetGameObject())->save(outfile, type);
		}
	}

}

void Grid::ClearGrid()
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			CellList[i][j]->SetGameObject(NULL);
		}
	}

}

Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		delete PlayerList[i];
	}
}