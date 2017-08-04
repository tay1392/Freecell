/************************************************************************
* Class: Deck
*
* Constructors:	
*	Deck() 
*	default ctor used to initizalize an array of cards to the	
*	correct values that make up 1 entire deck
*
* Mutators:
*	None
*
* Methods:		
*	Shuffle()
*	This member function Shuffles the deck by using the predefined 
*	srand and rand classes to return a randomm integer between 0 and 52.
*
*	Deal()
*	This member function deals the user a hand of cards (7 cards
*	from the shuffled deck.)
*
*************************************************************************/
#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "Card.h"

const int NUM_CARDS = 52;

class Deck
{
	public:
		Deck();
		void Shuffle();
		Card Deal();
	private:
		Card m_deck[NUM_CARDS];
		int m_current_card;
};
#endif