/************************************************************************
* Class: HomeCells
*
* Constructors:	
*	HomeCells() 
*		all HomeCells are set to empty initially
*
* Methods:		
*	void DisplayFreeCells()
*		Displays the series of 4 HomeCells and the stacks top card
*************************************************************************/
#ifndef HOMECELLS_H
#define HOMECELLS_H

#include "ArrayStack.h"
#include "Card.h"

class HomeCells
{
	friend class FreeCellGame;
	public:
		HomeCells();
		void DisplayHomeCells(COORD coords);
	private:
		Array<MyStack<Card>> home_cells;

};
#endif