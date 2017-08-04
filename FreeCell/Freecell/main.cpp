/***********************************************************
* Author:					Taylor Caldwell
* Date Created:				5/1/13
* Last Modification Date:	5/7/13
* Lab Number:				CST 211 Lab 3 - FreeCell
* Filename:					main.cpp
*
* Overview:
*	This program is a text-based version of the classic
* 	Windows FreeCell card game. It implements various 
* 	data structures such as Arrays, Doubly Linked Lists,
* 	and Stacks of both types.
*
* Input:
* 	The user inputs their coordinates
*	and number of cards they would like to move and 
*	the console screen is updated each time they move.
*
* Output:
*	The Output for the program is a Display that 
*	emulates the style of the classic Windows version.
* 	After a move is entered, the screen is updated 
*	and displays the card movements.
************************************************************/
#include "FreecellGame.h"
#include <iostream>
#include <windows.h>
#include <crtdbg.h> 
#define _CRTDBG_MAP_ALLOC

COORD CONSOLE_SIZE = {151,151}; //size of console output buffer.
SMALL_RECT WIN_SIZE = {0,0,150,150}; //size of console window.
HANDLE CONSOLE_OUT(GetStdHandle(STD_OUTPUT_HANDLE));

int main()
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	SetConsoleMode(CONSOLE_OUT, ENABLE_INSERT_MODE);
	SetConsoleScreenBufferSize(CONSOLE_OUT, CONSOLE_SIZE);
	SetConsoleWindowInfo(CONSOLE_OUT, true, &WIN_SIZE);

	FreeCellGame::PlayGame();

	system ("pause");
	return 0;
}