#include <iostream>
#include "Card.h"
using std::cout;
using std::endl;

HANDLE text = GetStdHandle(STD_OUTPUT_HANDLE);

const int HEIGHT = 9; //default 9
const int WIDTH = 7;

HANDLE m_console_out(GetStdHandle(STD_OUTPUT_HANDLE));

const char * RANK_TITLE[] = {"Ace of ", "Deuce of ", "Trey of ", "Four of ",
							"Five of ", "Six of ", "Seven of ", "Eight of ", 
							"Nine of ", "Ten of ", "Jack of ", "Queen of ", 
							"King of "};

const char * SUIT_TITLE[] = {"Spades", "Hearts", "Clubs", "Diamonds"};

/**************************************************************
*	  Purpose:  Constructor
*                 
*     Entry: None
*
*     Exit:  Card constructed
****************************************************************/
Card::Card(Rank rank, Suit suit)
	:m_rank(rank), m_suit(suit), empty(false)
{	

}
/**************************************************************
*	  Purpose:  Sets the cards rank
*                 
*     Entry: None
*
*     Exit:  Cards rank set
****************************************************************/
void Card::SetRank(Rank rank)
{
	m_rank = rank;
}
/**************************************************************
*	  Purpose:  Sets the cards suit
*                 
*     Entry: None
*
*     Exit:  Cards suit set
****************************************************************/
void Card::SetSuit(Suit suit)
{
	m_suit = suit;
	if(m_suit == HEARTS || m_suit == DIAMONDS)
	{
		m_color = RED;
	}
	else
	{
		m_color = BLUE;
	}
}
/**************************************************************
*	  Purpose: returns the cards rank
*                 
*     Entry: None
*
*     Exit:  cards rank returned
****************************************************************/
Rank Card::GetRank()
{
	return m_rank;
}
/**************************************************************
*	  Purpose: returns the cards suit
*                 
*     Entry: None
*
*     Exit:  cards suit returned
****************************************************************/
Suit Card::GetSuit()
{
	return m_suit;
}
/**************************************************************
*	  Purpose: Displays a Card to the screen
*                 
*     Entry: None
*
*     Exit: A card displayed to the screen
****************************************************************/
void Card::Display(COORD cursor_coord)
{
	static int card_face[HEIGHT][WIDTH];

	for (int i(0); i < HEIGHT; i++)
	{
		for (int j(0); j < WIDTH; j++)
		{
			if (i == 0 && j == 0)
				card_face[i][j] = 218;
			else if (i == 8 && j == 0)
				card_face[i][j] = 192;
			else if (i == 0 && j == 6)
				card_face[i][j] = 191;
			else if((i == 1 && j == 5) || (i == 7 && j == 1))
				card_face[i][j] = static_cast<int>(this->CheckSuit());
			else if (i == 8 && j == 6)
				card_face[i][j] = 217;
			else if ((i == 0 || i == 8) && (j < 6 || j > 0))
				card_face[i][j] = 196;
			else if ((i < 8 || i > 0) && (j == 0 || j == 6))
				card_face[i][j] = 179;
			else if ((i == 1 && j == 1) || (i == 7 && j == 5))
				card_face[i][j] = static_cast<int>(this->CheckRank());
			else
				card_face[i][j] = 32;
		}
	}

	SetConsoleCursorPosition(m_console_out, cursor_coord);

	for (int i(0); i < HEIGHT; i++)
	{
		for (int j(0); j < WIDTH; j++)
		{
			if(((i == 1 && j == 5) || (i == 7 && j == 1)) || 
				((i == 1 && j == 1) || (i == 7 && j == 5)))
		 	{
				if(this->m_color == RED)
				{
					SetConsoleTextAttribute(text, 252);
					cout << static_cast<char>(card_face[i][j]);
					SetConsoleTextAttribute(text, 255);
				}
				else
				{
					SetConsoleTextAttribute(text, 240);
					cout << static_cast<char>(card_face[i][j]);
					SetConsoleTextAttribute(text, 255);
				}
			}
			else
			{
				SetConsoleTextAttribute(text, 248);
				cout << static_cast<char>(card_face[i][j]);
				SetConsoleTextAttribute(text, 7);
			}
		}
		cursor_coord.Y++;
		SetConsoleCursorPosition(m_console_out, cursor_coord);
	}
}

/**************************************************************
*	  Purpose: converts cards suit to correct ascii character
*                 
*     Entry: None
*
*     Exit:  ascii char returned
****************************************************************/
char Card::CheckSuit()
{
	char suit_char('\0');

	if(this->empty == true)
	{
		suit_char = ' ';
		return suit_char;
	}

	switch (this->m_suit)
	{
	case SPADES:
		suit_char = spades;
		break;
	case CLUBS:
		suit_char = clubs;
		break;
	case HEARTS:
		suit_char = hearts;
		break;
	case DIAMONDS:
		suit_char = diamonds;
		break;
	}

	return suit_char;
}
/**************************************************************
*	  Purpose: converts cards rank to correct ascii character
*                 
*     Entry: None
*
*     Exit:  ascii char returned
****************************************************************/
char Card::CheckRank()
{
	char rank_char('\0');

	if(this->empty == true)
	{
		rank_char = ' ';
		return rank_char;
	}

	switch (this->m_rank)
	{
	case DEUCE:
		rank_char = '2';
		break;
	case TREY:
		rank_char = '3';
		break;
	case FOUR:
		rank_char = '4';
		break;
	case FIVE:
		rank_char = '5';
		break;
	case SIX:
		rank_char = '6';
		break;
	case SEVEN:
		rank_char = '7';
		break;
	case EIGHT:
		rank_char = '8';
		break;
	case NINE:
		rank_char = '9';
		break;
	case TEN:
		rank_char = 'T';
		break;
	case JACK:
		rank_char = 'J';
		break;
	case QUEEN:
		rank_char = 'Q';
		break;
	case KING:
		rank_char = 'K';
		break;
	case ACE:
		rank_char = 'A';
		break;
	}

	return rank_char;
}

/**************************************************************
*	  Purpose: Sets cards current state to empty
*                 
*     Entry: None
*
*     Exit:  card set to empty
****************************************************************/
void Card::SetEmpty()
{
	empty = true;
}
/**************************************************************
*	  Purpose: checks if the cards state is empty
*                 
*     Entry: None
*
*     Exit:  true or false
****************************************************************/
bool Card::IsEmpty()
{
	if(empty == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/**************************************************************
*	  Purpose: sets color to blue
*                 
*     Entry: None
*
*     Exit:  color set to blue
****************************************************************/
void Card::SetBlue()
{
	m_color = BLUE;
}
/**************************************************************
*	  Purpose: sets color to red
*                 
*     Entry: None
*
*     Exit:  color set to red
****************************************************************/
void Card::SetRed()
{
	m_color = RED;
}
/**************************************************************
*	  Purpose: returns the cards color
*                 
*     Entry: None
*
*     Exit:  color returned
****************************************************************/
Color Card::GetColor()
{
	return m_color;
}