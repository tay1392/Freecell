/************************************************************************
* Class: FreeCellGame
*
* Constructors:	
*	FreeCellGame() 
*		Cards are dealt to play cells, m_Max and m_Grab are set to 0
*
* Mutators:
*	none
*
* Methods:		
*
*	static void PlayGame()
*		static function to start the game with a menu
*	void Display()
*		This function takes care of the entire game display
*		by using COORDS
*	void GetMove()
*		User inputs their move
*	void CalcMax()
*		calculates the maximum number of cards
*		the user can grab at once
*	void MoveCards()
*		Moves the cards to their correct spots
*		with a series of Pushes and Pops
*	bool IsValid()
*		checks whether or not the users input is valid
*	bool CheckWin()
*		checks the game for a win
*	void DisplayWin()
*		displays a winning message to the screen
*	bool GrabMultiple()
*		checks if the input to move 2+ cards is valid
*	void MoveMultiple()
*		handles the task of moving multiple cards at once
*	void TestWin();
*		function to test hardcoded win situation
*	void Menu()
*		Displays the main game menu 
*		and handles the direction of the program
**************************************************************************/

#ifndef FREECELL_GAME
#define FREECELL_GAME

#include <string>
using std::string;

#include "FreeCells.h"
#include "HomeCells.h"
#include "PlayCells.h"

#include "Deck.h"

class FreeCellGame
{
	public:
		FreeCellGame();
		static void PlayGame();
		void Display();
		void GetMove();
		void CalcMax();
		void MoveCards();
		bool IsValid();
		bool CheckWin();
		void DisplayWin();
		bool GrabMultiple();
		void MoveMultiple();
		void TestWin();
		void Menu();
		
	private:
		int src_coord;
		int dst_coord;
		string m_src;
		string m_dst;
		int m_Grab;
		int m_Max;
		Deck GameDeck;
		FreeCells m_FreeCells;
		HomeCells m_HomeCells;
		PlayCells m_PlayCells;
	
};
#endif;