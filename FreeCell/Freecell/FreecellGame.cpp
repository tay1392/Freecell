#include "FreecellGame.h"
#include <Windows.h>
#include <iostream>
#include <cmath>

using std::cin;

HANDLE m_out(GetStdHandle(STD_OUTPUT_HANDLE));

/**************************************************************
*	  Purpose:  Constructor
*                 
*     Entry: None
*
*     Exit:  All Data Members constructued
****************************************************************/
FreeCellGame::FreeCellGame()
	:m_FreeCells(), m_HomeCells(), GameDeck(),
	m_PlayCells(GameDeck), m_Grab(0), m_Max(0)
{

}
/**************************************************************
*	  Purpose:  Displays the game board
*                 
*     Entry: None
*
*     Exit:  The Entire Game Board displayed
****************************************************************/
void FreeCellGame::Display()
{
	COORD coords;
	coords.X = 0;
	coords.Y = 0;
	
	//Display FreeCells
	m_FreeCells.DisplayFreeCells(coords);

	coords.X = 2;
	coords.Y = 9;
	SetConsoleCursorPosition(m_out, coords);

	for(int i = 0; i < 4; i++)
	{
		cout << "F" << i;
		coords.X = (coords.X + 8);
		SetConsoleCursorPosition(m_out, coords);
	}

	//Display HomeCells
	coords.X = 36;
	coords.Y = 0;
	m_HomeCells.DisplayHomeCells(coords);

	coords.X = 38;
	coords.Y = 9;
	SetConsoleCursorPosition(m_out, coords);

	for(int i = 0; i < 4; i++)
	{
		cout << "H" << i;
		coords.X = (coords.X + 8);
		SetConsoleCursorPosition(m_out, coords);
	}
	
	//Display PlayCells
	coords.X = 4;
	coords.Y = 12;
	SetConsoleCursorPosition(m_out, coords);
	for(int i = 0; i < 8; i++)
	{
		cout << "P" << i;
		coords.X = (coords.X + 8);
		SetConsoleCursorPosition(m_out, coords);
	}

	coords.X = 2;
	coords.Y = 13;
	SetConsoleCursorPosition(m_out, coords);
	m_PlayCells.DisplayPlayCells(coords);

	coords.X = 0;
	coords.Y = 42; //could change
	SetConsoleCursorPosition(m_out, coords);
}
/**************************************************************
*	  Purpose:  Gets the users input for card movement
*                 
*     Entry: None
*
*     Exit: users move is stored
****************************************************************/
void FreeCellGame::GetMove()
{
	bool valid = false;
	int src_x(0);
	int dst_y(0);

	while(valid == false)
	{
		SetConsoleTextAttribute(m_out, 32);
		cout << "Enter your source ( P# / F# ): ";
		cin >> m_src;
		cout << "Enter your Destination ( P# / F# / H# ): ";
		cin >> m_dst;
		cout << "Enter # of cards to grab: ";
		cin >> m_Grab;

		if((m_src.length() > 0 && m_src.length() < 3)
			&& (m_dst.length() > 0 && m_dst.length() < 3))
		{
			if(isalpha(m_src[0]) && isalpha(m_dst[0]))
			{
				if(isdigit(m_src[1]) && isdigit(m_dst[1]))
				{
					valid = true;	
				}
				else
				{
					cout << "\nInvalid input. Please try again." << endl;
					valid = false;
				}
			}
			else
			{
				cout << "\nInvalid input. Please try again." << endl;
				valid = false;
			}
		}
		else
		{
			cout << "\nInvalid input. Please try again." << endl;
			valid = false;
		}
	}
}
/**************************************************************
*	  Purpose:  Checks if the users desired input is a 
*				Valid move.
*                 
*     Entry: None
*
*     Exit: returns true or false based on users input
****************************************************************/
bool FreeCellGame::IsValid()
{
	//convert input to integer
	if(m_src[1] == '0')
	{
		src_coord = 0;
	}
	else if(m_src[1] == '1')
	{
		src_coord = 1;
	}
	else if(m_src[1] == '2')
	{
		src_coord = 2;
	}
	else if(m_src[1] == '3')
	{
		src_coord = 3;
	}
	else if(m_src[1] == '4')
	{
		src_coord = 4;
	}
	else if(m_src[1] == '5')
	{
		src_coord = 5;
	}
	else if(m_src[1] == '6')
	{
		src_coord = 6;
	}
	else if(m_src[1] == '7')
	{
		src_coord = 7;
	}
	else
	{
		return false;
	}

	//convert input to integer
	if(m_dst[1] == '0')
	{
		dst_coord = 0;
	}
	else if(m_dst[1] == '1')
	{
		dst_coord = 1;
	}
	else if(m_dst[1] == '2')
	{
		dst_coord = 2;
	}
	else if(m_dst[1] == '3')
	{
		dst_coord = 3;
	}
	else if(m_dst[1] == '4')
	{
		dst_coord = 4;
	}
	else if(m_dst[1] == '5')
	{
		dst_coord = 5;
	}
	else if(m_dst[1] == '6')
	{
		dst_coord = 6;
	}
	else if(m_dst[1] == '7')
	{
		dst_coord = 7;
	}
	else
	{
		return false;
	}

	//CALL CALC MAX AFTER INPUT HAS BEEN CONVERTED
	CalcMax();


	//determining card movement
	//freecells to freecells
	if(m_src[0] == 'f' || m_src[0] == 'F')
	{
		if(m_dst[0] == 'f' || m_dst[0] == 'F')
		{
			
			if(m_FreeCells.free_cells[dst_coord].IsEmpty() == true)
			{
				return true;
			}
		}
		//freecells to homecells
		else if(m_dst[0] == 'h' || m_dst[0] == 'H')
		{
			if(m_HomeCells.home_cells[dst_coord].IsEmpty() == true 
			   && m_FreeCells.free_cells[src_coord].GetRank() == ACE)
			{
				return true;
			}
			//suit is the same
			else if((m_FreeCells.free_cells[src_coord].GetSuit() == 
				m_HomeCells.home_cells[dst_coord].Peek().GetSuit())
					&& // card is next in sequence
					(m_FreeCells.free_cells[src_coord].GetRank() == 
					m_HomeCells.home_cells[dst_coord].Peek().GetRank() + 1))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		//freecells to playcells
		else if(m_dst[0] == 'p' || m_dst[0] == 'P')
		{
			
			if(m_PlayCells.play_cells[dst_coord].IsEmpty() == true)
			{
				return true;
			}
			else if(m_FreeCells.free_cells[src_coord].GetColor() != 
					m_PlayCells.play_cells[dst_coord].Peek().GetColor())
			{
				if(m_FreeCells.free_cells[src_coord].GetRank() == 
					m_PlayCells.play_cells[dst_coord].Peek().GetRank() - 1)
				{
					return true;
				}
			}
			else
			{
				return false;
			}
		}
	}
	else if(m_src[0] == 'p' || m_src[0] == 'P')
	{
		if(m_dst[0] == 'p' || m_dst[0] == 'P')
		{

			if(m_Grab > 1 && m_Grab <= m_Max)
			{
				if(GrabMultiple() == true)
				{
					return true;
				}
				else
				{
					return false;
				}
			}

			//playcells to playcells
			if(m_Grab <= m_Max)
			{
				if(m_PlayCells.play_cells[dst_coord].IsEmpty() == true)
				{
					return true;
				}
				else if(m_PlayCells.play_cells[dst_coord].Peek().GetColor() !=
					    m_PlayCells.play_cells[src_coord].Peek().GetColor())
						
				{
					if(m_PlayCells.play_cells[src_coord].Peek().GetRank() ==
						m_PlayCells.play_cells[dst_coord].Peek().GetRank() - 1)
					{
						return true;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else if(m_dst[0] == 'h' || m_dst[0] == 'H')
		{
			if(m_HomeCells.home_cells[dst_coord].IsEmpty() == true 
				&& m_PlayCells.play_cells[src_coord].Peek().GetRank() != ACE)
			{
				return false;
			}

			//playcells to homecells
			if(m_HomeCells.home_cells[dst_coord].IsEmpty() == true
				&& m_PlayCells.play_cells[src_coord].Peek().GetRank() == ACE)
			{
				return true;
			}//check for same suit and ascending order
			else if((m_PlayCells.play_cells[src_coord].Peek().GetRank() == 
				m_HomeCells.home_cells[dst_coord].Peek().GetRank() + 1)
				&& (m_PlayCells.play_cells[src_coord].Peek().GetSuit() == 
				m_HomeCells.home_cells[dst_coord].Peek().GetSuit()))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if(m_dst[0] == 'f' || m_dst[0] == 'F')
		{
			//playcells to freecells
			if(m_FreeCells.free_cells[dst_coord].IsEmpty() == true)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else if(m_src[0] == 'h' || m_src[0] == 'H')
	{
		cout << "Error: cannot move home cells" << endl;
		return false;
	}
	else
	{
		cout << "Invalid input." << endl;
		return false;
	}
}
/**************************************************************
*	  Purpose:  Checks if the multiple card movement is valid
*                 
*     Entry: None
*
*     Exit:  True or false
****************************************************************/
bool FreeCellGame::GrabMultiple()
{
	Node<Card>  * travel = m_PlayCells.play_cells[src_coord].GetStack().getTail();

	int Gcount(0);
	int a = 0;

	for(int i = 0; i < m_Grab - 1; i++)
	{
		if((travel->GetData().GetRank() == 
			travel->GetPrevious()->GetData().GetRank() - 1) &&
			travel->GetData().GetColor() != 
			travel->GetPrevious()->GetData().GetColor())
		{
			Gcount++;
		}
		travel = travel->GetPrevious();
	}

	if(m_PlayCells.play_cells[dst_coord].IsEmpty() == true)
	{
		a = 1;
	}
	else if((m_PlayCells.play_cells[dst_coord].Peek().GetColor() !=
		travel->GetData().GetColor()) && 
		m_PlayCells.play_cells[dst_coord].Peek().GetRank() ==
		travel->GetData().GetRank() + 1)
	{
		a = 1;
	}

	if(Gcount == (m_Grab - 1) && a == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/**************************************************************
*	  Purpose:  Calculates the max # of cards a user can move
*				at once
*                 
*     Entry: None
*
*     Exit:  m_Max calculated
****************************************************************/
void FreeCellGame::CalcMax()
{
	int open_freecells(0);
	int open_columns(0);

	for(int i = 0; i < 4; i++)
	{
		if(m_FreeCells.free_cells[i].IsEmpty() == true)
		{
			open_freecells++;
		}
	}

	for(int i = 0; i < 8; i++)
	{
		if(m_PlayCells.play_cells[i].IsEmpty() == true)
		{
			open_columns++;
		}
	}

	m_Max = ((1 + open_freecells) * (pow(2, open_columns)));

	char spot = m_dst[0];
	if(spot == 'p' || spot == 'P')
	{
		// IF THE DESTINATION IS AN EMPTY COLUMN
		if(m_PlayCells.play_cells[dst_coord].IsEmpty() == true)
		{
			m_Max = 0;
			m_Max = ((1 + open_freecells) * (pow(2, open_columns-1)));
		}
	}
}
/**************************************************************
*	  Purpose: Handles card movement if Valid move = true
*                 
*     Entry: None
*
*     Exit:  Cards moved with a series of push and pop calls
****************************************************************/
void FreeCellGame::MoveCards()
{
	//freecells ->
	if(m_src[0] == 'f' || m_src[0] == 'F')
	{
		//freecells to home cells
		if(m_dst[0] == 'h' || m_dst[0] == 'H')
		{
			//push freecell onto homecell stack
			m_HomeCells.home_cells[dst_coord].Push(m_FreeCells.free_cells[src_coord]);
			//set freecell as empty
			m_FreeCells.free_cells[src_coord].SetEmpty();
		}
		//freecells to playcells
		else if(m_dst[0] == 'p' || m_dst[0] == 'P')
		{
			//move freecell to play cell
			m_PlayCells.play_cells[dst_coord].Push(m_FreeCells.free_cells[src_coord]);
			//set freecell to empty
			m_FreeCells.free_cells[src_coord].SetEmpty();
		}
		//freecells to freecells
		else if(m_dst[0] == 'f' || m_dst[0] == 'F')
		{
			//move freecell to freecell
			m_FreeCells.free_cells[dst_coord] = m_FreeCells.free_cells[src_coord];
			//set freecell to empty
			m_FreeCells.free_cells[src_coord].SetEmpty();
		}
	}

	//playcells ->
	if(m_src[0] == 'p' ||m_src[0] == 'P' )
	{
		//playcells to home cells
		if(m_dst[0] == 'h' || m_dst[0] == 'H')
		{
			//push onto home cell stack
			m_HomeCells.home_cells[dst_coord].Push(m_PlayCells.play_cells[src_coord].Pop());
		}
		//playcells to playcells
		else if(m_dst[0] == 'p' || m_dst[0] == 'P')
		{

			if(m_Grab> 1)
			{
				//for moving multiple cards at once
				MoveMultiple();
			}
			else
			{
				//push onto playcell stack
				try
				{
					m_PlayCells.play_cells[dst_coord].Push(m_PlayCells.play_cells[src_coord].Pop());
				}
				catch(char * msg)
				{
					cout << msg << endl;
				}
			}
		}
		//playcells to freecells
		else if(m_dst[0] == 'f' || m_dst[0] == 'F')
		{
			//set freecell equal to popped card
			m_FreeCells.free_cells[dst_coord] = m_PlayCells.play_cells[src_coord].Pop();
		}
	}
}

/**************************************************************
*	  Purpose: Moves multiple cards at once
*                 
*     Entry: None
*
*     Exit:  multiple cards moved
****************************************************************/
void FreeCellGame::MoveMultiple()
{
	//LinkStack<Card> temp;
	MyStack<Card> temp(m_Grab);

	for(int i = 0; i < m_Grab; i++)
	{
		temp.Push(m_PlayCells.play_cells[src_coord].Pop());
	}

	for(int i = 0; i < m_Grab; i++)
	{
		m_PlayCells.play_cells[dst_coord].Push(temp.Pop());
	}
}
/**************************************************************
*	  Purpose:  Checks for a winning situation
*                 
*     Entry: None
*
*     Exit:  True or false
****************************************************************/
bool FreeCellGame::CheckWin()
{
	int Win(0);
	for(int i = 0; i < 4; i++)
	{
		if(m_HomeCells.home_cells[i].IsEmpty() == false)
		{
			if(m_HomeCells.home_cells[i].Peek().GetRank() == KING)
			{
				Win++;
			}
		}
	}

	if(Win == 4)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/**************************************************************
*	  Purpose:  Display a winning game message
*                 
*     Entry: None
*
*     Exit: message displayed to screen
****************************************************************/
void FreeCellGame::DisplayWin()
{
	system ("CLS");
	this->Display();
	cout << "\n *** CONGRATULATIONS YOU WIN! *** " << endl;
	cout << "\n\nPress enter to go to the main menu" << endl;
	system("Pause");
}
/**************************************************************
*	  Purpose:  Starts the game with a menu selection
*                 
*     Entry: None
*
*     Exit:  Call to Game menu or Exit
****************************************************************/
void FreeCellGame::PlayGame()
{
	int ch(0);

	bool again = true;

	while(again == true)
	{
		SetConsoleTextAttribute(m_out, 32);
		system("CLS");
		cout << "\nPlease Maximize your console window!" << endl << endl;
		cout << "Welcome to FreeCell!"
			<< "\n1. New Game"
			<< "\n2. Exit";

		cout << "\nEnter your choice: ";
		cin >> ch;

		if(ch == 1)
		{
			FreeCellGame Game;
			system("CLS");
			Game.Menu();
		}
		else if(ch == 2)
		{
			again = false;
		}

	}
	cout << "\n\nGoodBye!" << endl;
}
/**************************************************************
*	  Purpose: Displays a menu to the user and 
*			   controls the gameplay 
*                 
*     Entry: None
*
*     Exit:  Loops until win or exit is chosen
****************************************************************/
void FreeCellGame::Menu()
{
	bool cont = true;
	char choice[3];

	while(cont == true)
	{
		SetConsoleTextAttribute(m_out, 34);
		system("CLS");
		this->Display();

		SetConsoleTextAttribute(m_out, 32);

		bool w = true;
		while(w == true)
		{
			cout << "\n\nFREECELL MENU"
				 << "\n-------------"
			   	 << "\nA. Enter Move"
				 << "\nB. Exit";
			cout << "\nEnter selection: ";
			cin >> choice;

			if((strlen(choice) > 0 && strlen(choice) < 2)
				 || (choice[0] == 'a' || choice[0] == 'A')
				 || (choice[0] == 'b' || choice[0] == 'B'))
			{
				w = false;
			}
			else
			{
				cout << "\nInvalid menu choice. Please try again." << endl;
				w = true;
			}
		}

		SetConsoleTextAttribute(m_out, 34);

		if(choice[0] == 'a' || choice[0] == 'A')
		{
			this->GetMove();
			if(this->IsValid() == true)
			{
				this->MoveCards();

				if(this->CheckWin() == true)
				{
					this->DisplayWin();
					cont = false;
				}
			}
			else
			{
				SetConsoleTextAttribute(m_out, 32);
				cout << "\n *** Invalid move. Please press enter to try again. ***" << endl;
				system("PAUSE");
			}
		}
		else if(choice[0] == 'b' || choice[0] == 'B')
		{
			cont = false;
		}
		else
		{
			SetConsoleTextAttribute(m_out, 32);
			cout << "\nInvalid Menu choice. Please try again" << endl;
		}
	}
}

/**************************************************************
*	  Purpose:  Test win situation
*                 
*     Entry: None
*
*     Exit:  Win or Lose
****************************************************************/
void FreeCellGame::TestWin()
{
	FreeCellGame win;

	Card KingSpades;
	KingSpades.SetRank(KING);
	KingSpades.SetSuit(SPADES);


	Card KingClubs;
	KingClubs.SetRank(KING);
	KingClubs.SetSuit(CLUBS);

	Card KingDiamonds;
	KingDiamonds.SetRank(KING);
	KingDiamonds.SetSuit(DIAMONDS);

	Card KingHearts;
	KingHearts.SetRank(KING);
	KingHearts.SetSuit(HEARTS);

	win.m_HomeCells.home_cells[0].Push(KingSpades);
	win.m_HomeCells.home_cells[1].Push(KingClubs);
	win.m_HomeCells.home_cells[2].Push(KingHearts);
	win.m_HomeCells.home_cells[3].Push(KingDiamonds);

	if(win.CheckWin() == true)
	{
		cout << "Win." << endl;
	}
	else
	{
		cout << "lose." << endl;
	}
}