#include "PlayCells.h"

/**************************************************************
*	  Purpose:  Constructor
*                 
*     Entry: None
*
*     Exit:  All PlayCells constructued and dealt cards
****************************************************************/
PlayCells::PlayCells(Deck gd):play_cells(8)
{
	gd.Shuffle();
	gd.Shuffle();
	gd.Shuffle();

	//fills first 4 columns with 7 cards
	for(int i = 0; i < 8; i++)
	{
		if(i >= 0 && i <= 3)
		{
			for(int x = 0; x < 7; x++)
			{
				play_cells[i].Push(gd.Deal());
			}
		}
		//fills last 4 columns with 6 cards
		if(i > 3)
		{
			for(int x = 0; x < 6; x++)
			{
				play_cells[i].Push(gd.Deal());
			}
		}
	}
}
/**************************************************************
*	  Purpose:  Constructor
*                 
*     Entry: None
*
*     Exit:  All PlayCells are Displayed to screen
****************************************************************/
void PlayCells::DisplayPlayCells(COORD coords)
{
	Node<Card> * Travel;
	int temp = coords.Y;

	try
	{
		for(int i = 0; i < 8; i++)
		{
			//Travel = play_cells[i].m_Stack.m_Head;
			Travel = play_cells[i].GetStack().getHead();
			while(Travel != nullptr)
			{
				Travel->GetData().Display(coords);
				Travel = Travel->GetNext();
				coords.Y = (coords.Y + 2);
			}
			coords.X = (coords.X + 8);
			coords.Y = temp;
		}
	}
	catch(char * ex)
	{
		cout << ex << endl;
	}
}