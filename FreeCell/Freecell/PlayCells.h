/************************************************************************
* Class: PlayCells
*
* Constructors:	
*	PlayCells() 
*		each element of the array of stacks is dealt 6-7 cards
*
* Mutators:
*	none
*
* Methods:		
*	void DisplayFreeCells()
*		Displays the series of 8 PlayCells and their current cards
*************************************************************************/
#ifndef PLAYCELLS_H
#define PLAYCELLS_H

#include "Deck.h"
#include "Card.h"
#include "LinkStack.h"
#include "Array.h"

class PlayCells
{
	friend class FreeCellGame;
	public:
		PlayCells(Deck gd);
		void DisplayPlayCells(COORD coords);
	private:
		Array<LinkStack<Card>> play_cells;

};
#endif