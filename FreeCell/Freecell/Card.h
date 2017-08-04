/************************************************************************
* Class: Card
*
* Constructors:	
*	Card() 
*		Rank is initizaled to Ace and suit is initialezd to spades
*
* Mutators:
*	void SetRank(rank)
*		initialized to data member rank
*	Void SetSuit (suit)
*		initialized to data member suit
*	void GetSuit()
*		returns suit
*	void GetRank()
*		returns rank
*
* Methods:		
* void Display()
* formats and displays a hand of cards to the console window
*************************************************************************/
#include <iostream>
#ifndef CARD_H
#define CARD_H

#include <Windows.h>

enum Rank {ACE, DEUCE, TREY, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
enum Suit {SPADES, HEARTS, CLUBS, DIAMONDS};
enum Color{RED, BLUE};

static const char hearts(3);
static const char diamonds(4);
static const char clubs(5);
static const char spades(6);

class Card
{
	public:
		Card(Rank rank = ACE, Suit suit = SPADES);
		void Display(COORD cursor_coord);
		void SetRank(Rank rank);
		void SetSuit(Suit suit);
		char CheckSuit();
		char CheckRank();
		Rank GetRank();
		void SetEmpty();
		void SetRed();
		void SetBlue();
		Color GetColor();
		Suit GetSuit();
		bool IsEmpty();
	private:
		bool empty;
		Rank m_rank;
		Suit m_suit;
		Color m_color;
};
#endif