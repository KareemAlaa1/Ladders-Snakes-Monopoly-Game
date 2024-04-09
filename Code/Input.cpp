#include "Input.h"

#include "Output.h"
using namespace std;

//======================================================================================//
//								General Functions									    //
//======================================================================================//

Input::Input(window* pW)
{
	pWind = pW; // point to the passed window
}

////////////////////////////////////////////////////////////////////////////////////////// 

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y); // Note: x and y of WaitMouseClick are sent by reference
}

////////////////////////////////////////////////////////////////////////////////////////// 

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	// ESCAPE key is pressed
			return "";	// returns nothing as user has cancelled label
		if (Key == 13)	// ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	// BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

////////////////////////////////////////////////////////////////////////////////////////// 

int Input::GetInteger(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	// ESCAPE key is pressed
			return 0;	// returns nothing as user has cancelled label
		if (Key == 13)	// ENTER key is pressed
		{
			if (Label.empty())
				pWind->WaitKeyPress(Key);
			else
				return stoi(Label);
		}
		if (Key > 47 && Key < 58)
		{
			Label += Key;
			if (pO)
				pO->PrintMessage(Label);
		}
		if (Key == 8)
		{

			if (Label.empty())
				pWind->WaitKeyPress(Key);
			else
				Label.erase(Label.end() - 1);
		}
		if (pO)
			pO->PrintMessage(Label);










		///TODO: implement the GetInteger function as described in Input.h file 
		//       using function GetString() defined above and function stoi()




		// Note: stoi(s) converts string s into its equivalent integer (for example, "55" is converted to 55)

	//	return 0; // this line should be changed with your implementation
	}
}

//======================================================================================//
//								Game  Functions									        //
//======================================================================================//

ActionType Input::GetUserAction() const
{
	int x = -1, y = -1;
	GetPointClicked(x, y);

	//  ============ GUI in the Design mode ============
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// [1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			// Check which Menu item was clicked
			// ==> This assumes that menu items are lined up horizontally <==

			int ClickedItemOrder = (x / UI.MenuItemWidth);

			// Divide x coord of the point clicked by the menu item width (integer division)
			// If division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_ADD_LADDER: return ADD_LADDER;
			case ITM_ADD_SNAKE: return ADD_SNAKE;
			case ITM_ADD_CARD: return ADD_CARD;
			case ITM_EXIT1: return EXIT1;
			case ITM_SWITCH_TO_PLAY_MODE: return TO_PLAY_MODE;
			case ITM_Copy_Card: return Copy_Card;
			case ITM_Cut_Card: return Cut_card;
			case ITM_Paste_Card: return Paste_Card;
			case ITM_Delete_Game_Object: return Delete_Game_Object;
			case ITM_Save_Grid: return Save_Grid;
			case ITM_Open_Grid: return Open_Grid;
			case ITM_Clear_Grid: return Clear_Grid;

				///TODO: Add cases for the other items of Design Mode




			default: return EMPTY;	// A click on empty place in toolbar
			}
		}

		// [2] User clicks on the grid area
		if ((y >= UI.ToolBarHeight) && (y < UI.height - UI.StatusBarHeight))
		{
			return GRID_AREA;
		}

		// [3] User clicks on the status bar
		return STATUS;
	}

	// ============ GUI in the Play mode ============
	else
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_ROLL_DICE: return ROLL_DICE;
			case ITM_SWITCH_TO_DESIGN_MODE:	return TO_DESIGN_MODE;
			case ITM_Input_Dice_Value: return Input_Dice_Value;
			case ITM_New_Game: return New_Game;
			case ITM_EXIT2: return EXIT2;




			default: return EMPTY;
			}
		}
		if ((y >= UI.ToolBarHeight) && (y < UI.height - UI.StatusBarHeight))
		{
			return GRID_AREA;
		}
		return STATUS;
		///TODO:
		// perform checks similar to Design mode checks above for the Play Mode
		// and return the corresponding ActionType

			// just for now ==> This should be updated




	}

}

////////////////////////////////////////////////////////////////////////////////////////// 

CellPosition Input::GetCellClicked(Output* po) const
{

	int x, y;
	pWind->WaitMouseClick(x, y);	// Get the coordinates of the user click

	CellPosition cellPos;

	if (UI.InterfaceMode == MODE_DESIGN)
	{
		if (y >= UI.ToolBarHeight && y <= (UI.height - UI.StatusBarHeight))
		{




			///TODO: SetHCell and SetVCell of the object cellPost appropriately
			//       using the coordinates x, y and the appropriate variables of the UI_Info Object (UI)



			int v = (y - UI.ToolBarHeight) / UI.CellHeight;
			int h = x / UI.CellWidth;
			cellPos.SetVCell(v);
			cellPos.SetHCell(h);

		}


	}
	return cellPos;
}

////////////////////////////////////////////////////////////////////////////////////////// 
