#pragma once

#include "Grid.h"
#include "Cell.h"

class Player
{
	Cell * pCell;		   // pointer to the current Cell of the player

	const int playerNum;   // the player number (from 0 to MaxPlayerCount-1)
	                       // player number does NOT change after construction (const.)

	int stepCount;		   // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells
	int wallet;		       // player's wallet (how many coins he has -- integer)
	int justRolledDiceNum; // the current dice number which is just rolled by the player
	int turnCount;         // a counter that starts with 0, is incremented with each dice roll
	                       // and reset again when reached 3
	                       // it is used to indicate when to move and when to add to your wallet
	int prison_count;      // counter for prison stars with 0
	int preventcount;      //counter for Card_4, initially =0
	int poison_count;      //counter for posion, initially =0
	int burncount;


	int total_attacks;
	int ice_attacks;
	int fire_attacks;
	int poison_attacks;
	int lightning_attacks;
	
public:

	Player(Cell * pCell, int playerNum); // Constructor making any needed initializations

	// ====== Setters and Getters ======
	const int getplayernum();

	void SetCell(Cell * cell);		// A setter for the pCell
	Cell* GetCell() const;			// A getter for the pCell

	void SetWallet(int wallet);		// A setter for the wallet
	int GetWallet() const;			// a getter for the wallet

	void Pay(int amount); 			// decrease player wallet by amount
	bool Buy(int price); 			// return true if player have money to buy and decrease price from  wallet
	void Recharge(int AddAmount); 		// increase player wallet with AddAmount

	void SetTurnCount(int);
	int GetTurnCount() const;		// A getter for the turnCount

	void setstepcount(int x);
	void setprisoncount(int x);
	void setpreventcount(int);
	void increasepreventcount(int);
	void settotalattack(int);
	int gettotalattack();
	void seticeattack(int);
	int geticeattack();
	void setfireattack(int);
	int getfireattack();
	void setpoisonattack(int);
	int getpoisonattack();
	void setlightningattack(int);
	int getlightningattack();
	void setburncount(int);
	int getburncount();

	void setpoison_count(int x);
	int getpoison_count();
	bool isPoisoned(); 			// retrun true if player is poisoned and dcrement his poison_count,false otherwise


	int getjustRolledDiceNum() const;	// A getter for the justRolledDiceNum

	void gotoPrison(); 			// set prison_count to 3
	bool inPrison();           // retrun true if player is inPrison and dcrement his prison_count,false otherwise
	bool isprevented();         //check if the player is prevented this turn
	bool isFired();
	bool haveattack();
	bool haveiceattack();
	bool havefireattack();
	bool havepoisonattack();
	bool havelightningattack();
	Player* getpoorer(Player* P2);




	///TODO: You can add setters and getters for data members here (if needed)

	// ====== Drawing Functions ======

	void Draw(Output* pOut) const;			// Draws the Player's Circle on its current cell

	void ClearDrawing(Output* pOut) const;	// Clears the Player's Circle from its current cell

	// ====== Game Functions ======

	void Move(Grid * pGrid, int diceNumber);	// Moves the Player with the passed diceNumber 
	                                            // and Applies the Game Object's effect (if any) of the end reached cell 
	                                            // for example, if the end cell contains a ladder, take it
	
	void AppendPlayerInfo(string & playersInfo) const; // Appends player's info to the input string, 
	                                                   // for example: P0(wallet, turnCount)

	void Resetplayer(Grid* pGrid); // reset player


};

