#include "HomeCells.h"
#include <iostream>
using std::cout;
using std::endl;

/**************************************************************
*	  Purpose:  Constructor
*                 
*     Entry: None
*
*     Exit:  All HomeCells constructued and set to empty
****************************************************************/
HomeCells::HomeCells():home_cells(4)
{
	MyStack<Card> temp(13);

	//intialize each element stacks to size of 13;
	try
	{
		for(int i = 0; i < 4; i++)
		{
			//each stack in array size  = 13
			home_cells[i] = temp;

			//set empty initially
			home_cells[i].GetArrayStack()[0].SetEmpty();
		}
	}
	catch(char * ex)
	{
		cout << ex << endl;
	}
}
/**************************************************************
*	  Purpose:  Constructor
*                 
*     Entry: None
*
*     Exit:  All FreeCells displayed to the screen
****************************************************************/
void HomeCells::DisplayHomeCells(COORD coords)
{
	try
	{
		for(int i = 0; i < 4; i++)
		{
			if(home_cells[i].IsEmpty() == true)
			{
				Card temp;
				temp.SetEmpty();
				temp.Display(coords);
				coords.X = (coords.X + 8);
			}
			else
			{
				home_cells[i].Peek().Display(coords);
				coords.X = (coords.X + 8);
			}
		}
	}
	catch(char * ex)
	{
		cout << ex << endl;
	}
}