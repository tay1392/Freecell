/************************************************************************
* Class: FreeCells
*
* Constructors:	
*	FreeCells() 
*		all freecells are set to empty initially
*
* Mutators:
*	none
*
* Methods:		
*	void DisplayFreeCells()
*		Displays the series of 4 FreeCells and their current card
*
*************************************************************************/

#ifndef FREECELLS_H
#define FREECELLS_H

#include "Card.h"
#include "Array.h"

class FreeCells
{
	friend class FreeCellGame;
	public:
		FreeCells();
		void DisplayFreeCells(COORD coords);
	private:
		Array<Card> free_cells;

};
#endif