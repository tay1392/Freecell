#include "FreeCells.h"
/**************************************************************
*	  Purpose:  Constructor
*                 
*     Entry: None
*
*     Exit:  All FreeCells constructued and set to empty
****************************************************************/

FreeCells::FreeCells():free_cells(4)
{
	for(int i = 0; i < 4; i++)
	{
		free_cells[i].SetEmpty();
	}
}
/**************************************************************
*	  Purpose:  Constructor
*                 
*     Entry: COORD coordinates
*
*     Exit:  FreeCells Displayed to the screen
****************************************************************/
void FreeCells::DisplayFreeCells(COORD coords)
{
	for(int i = 0; i < 4; i++)
	{
		free_cells[i].Display(coords);
		coords.X = coords.X + 8;
	}
}