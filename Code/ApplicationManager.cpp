#include "ApplicationManager.h"

#include "Grid.h"

#include "AddLadderAction.h"
#include "AddCardAction.h"
#include "RollDiceAction.h"
#include"InputRollDiceAction.h"
#include"NewGameAction.h"
#include "AddSnakeAction.h"
#include "CopyCardAction.h"
#include "CutCardAction.h"
#include "PasteCardAction.h"
#include"DeleteGameObjectAction.h"
#include "SaveGridAction.h"
#include "OpenGridAction.h"
#include"ClearGridAction.h"

///TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid * ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_LADDER:
		pAct = new AddLadderAction(this);
		break;

	case ADD_CARD:
		// create an object of AddCardAction here
		pAct = new AddCardAction(this);
		break;

	case ADD_SNAKE:
		// create an object of AddCardAction here
		pAct = new AddSnakeAction(this);
		break;

	case EXIT1:
		break;

	case Copy_Card:
	
		pAct = new CopyCardAction(this);
		break;
	
	case Cut_card:
	
		pAct = new CutCardAction(this);
		break;
	
	case Paste_Card:
	
		pAct = new PasteCardAction(this);
		break;
	
	case Delete_Game_Object:
	
		pAct = new DeleteGameObjectAction(this);
		break;
	
	case Save_Grid:
	
		pAct = new SaveGridAction(this);
		break;
	
	case Open_Grid:
	
		pAct = new OpenGridAction(this);
		break;
	case Clear_Grid:
		pAct = new ClearGridAction(this);
		break;

	case TO_PLAY_MODE:
		pOut->CreatePlayModeToolBar(); // temporary till you made its action class (CHANGE THIS LATTER)
		break;

	case ROLL_DICE:
		// create an object of RollDiceAction here
		pAct = new RollDiceAction(this);
		break;

	case TO_DESIGN_MODE:
		pOut->CreateDesignModeToolBar(); // temporary till you made its action class (CHANGE THIS LATTER)
		break;

	case New_Game:
		pAct = new NewGameAction(this);
		break;
	
	case Input_Dice_Value:
	
		pAct = new InputRollDiceAction(this);
		break;

	///TODO:  ADD Cases similarly for ALL the remaining actions of PLAY Mode
	case EXIT2:
		break;
	
		///TODO: Add a case for EACH Action type in the Design mode or Play mode

	case STATUS:	// a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}
