#include <iostream>
#include "Deck.h"
#include <time.h>
#include <stdlib.h>
using std::cout;
using std::cin;
using std::endl;

/**************************************************************
*	  Purpose: constructor
*                 
*     Entry: None
*
*     Exit:  Deck is filled with cards
****************************************************************/
Deck::Deck()
{
	int rank = 0;
	int	suit = 0;
	int	r = 0 ;

	for( int i = 0; i < 4; i++ )
	{
		for( int z = 0; z < 13; z++, r++ )
		{
			m_deck[r].SetRank( static_cast<Rank>( rank++ ) );
			m_deck[r].SetSuit( static_cast<Suit>( suit ) );
		}
		rank = 0;
		suit++;
	}
	m_current_card = NUM_CARDS - 1;
}

/**************************************************************
*	  Purpose: shuffles the deck of cards
*                 
*     Entry: None
*
*     Exit:  shuffled deck
****************************************************************/
void Deck::Shuffle()
{
	Card temp_card;
	srand((unsigned)time(0));

	for( int x = 0, y = 0, z = 0; x < NUM_CARDS; x++)
	{
		y = ( rand() % NUM_CARDS);
		z = ( rand() % NUM_CARDS);

		temp_card.SetSuit( m_deck[x].GetSuit());
		temp_card.SetRank( m_deck[x].GetRank());

		m_deck[x].SetSuit( m_deck[y].GetSuit());
		m_deck[x].SetRank( m_deck[y].GetRank());

		m_deck[y].SetSuit(temp_card.GetSuit());
		m_deck[y].SetRank(temp_card.GetRank());
	}

	m_current_card = NUM_CARDS - 1;
}

/**************************************************************
*	  Purpose: A card is dealt from deck
*                 
*     Entry: None
*
*     Exit:  card returned
****************************************************************/
Card Deck::Deal()
{
	if (m_current_card >= 0)
		return m_deck[m_current_card--];
	else
	{
		cout << "No Cards" << endl;
		return m_deck[m_current_card--];
	}
}