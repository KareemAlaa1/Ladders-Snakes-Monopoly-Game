#include "CellPosition.h"
#include "UI_Info.h"
#include"Output.h"

CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)___________DONE
	if (v >= 0 && v < NumVerticalCells)
	{
		vCell = v;
		return true;
	}
	else vCell = -1;


	return false; // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)________DONE
	if (h >= 0 && h < NumHorizontalCells)
	{
		hCell = h;
		return true;
	}
	else hCell = -1;

	return false; // this line sould be changed with your implementation
}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	///TODO: Implement this function as described in the .h file___________DONE
	if (vCell >= 0 && vCell < NumVerticalCells && hCell >= 0 && hCell < NumHorizontalCells)
		return true;


	return false; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file__________DONE

	if (cellPosition.HCell() ==-1 || cellPosition.VCell() ==-1)
		return -1;
	int Cell_num = NumHorizontalCells * (NumVerticalCells - cellPosition.VCell()) - ((NumHorizontalCells-1) - cellPosition.HCell());
	return Cell_num;



             // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	/// TODO: Implement this function as described in the .h file_______DONE
	int v = -1;
	int h = -1;
	if (cellNum < 1 || cellNum>NumHorizontalCells*NumVerticalCells)
		return position;
	if (cellNum >= 1 && cellNum <= NumHorizontalCells)
	{
		v = 8; h = cellNum - 1;
	}
	else if (cellNum >= 1+ NumHorizontalCells && cellNum <= 2*NumHorizontalCells)
	{
		v = 7; h = cellNum - (1 + NumHorizontalCells);
	}
	else if (cellNum >= 1+2* NumHorizontalCells && cellNum <= 3* NumHorizontalCells)
	{
		v = 6; h = cellNum - (1 + 2 * NumHorizontalCells);
	}
	else if (cellNum >= 1+3* NumHorizontalCells && cellNum <= 4* NumHorizontalCells)
	{
		v = 5; h = cellNum - (1 + 3 * NumHorizontalCells);
	}
	else if (cellNum >= 1 + 4 * NumHorizontalCells && cellNum <= 5* NumHorizontalCells)
	{
		v = 4; h = cellNum - (1 + 4 * NumHorizontalCells);
	}
	else if (cellNum >= 1 + 5 * NumHorizontalCells && cellNum <= 6* NumHorizontalCells)
	{
		v = 3; h = cellNum - (1 + 5 * NumHorizontalCells);
	}
	else if (cellNum >= 1 + 6 * NumHorizontalCells && cellNum <= 7* NumHorizontalCells)
	{
		v = 2; h = cellNum -( 1 + 6 * NumHorizontalCells);
	}
	else if (cellNum >= 1 + 7 * NumHorizontalCells && cellNum <= 8* NumHorizontalCells)
	{
		v = 1; h = cellNum - (1 + 7 * NumHorizontalCells);
	}
	else if (cellNum >= 1 + 8 * NumHorizontalCells && cellNum <= 9* NumHorizontalCells)
	{
		v = 0; h = cellNum - (1 + 8 * NumHorizontalCells);
	}
	position.SetVCell(v);
	position.SetHCell(h);

	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


	return position;
}

void CellPosition::AddCellNum(int addedNum)//
{

	/// TODO: Implement this function as described in the .h file________DONE
	CellPosition pos= GetCellPositionFromNum(GetCellNum() + addedNum);
	vCell = pos.VCell();
	hCell = pos.HCell();

	// Note: this function updates the data members (vCell and hCell) of the calling object

}