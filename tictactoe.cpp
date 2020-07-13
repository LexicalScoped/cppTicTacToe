#include "tictactoe.h"
#include <iostream>

char TicTacToe::GetTurn() { return turn; }
bool TicTacToe::GetGameState() { return playing; }
char TicTacToe::GetWinner() { return winner; }
void TicTacToe::SetBoardValue(int input1, int input2) { board[input1][input2] = turn; }
bool TicTacToe::ValidBoardLocation(int input1, int input2)
{
	if (board[input1][input2] == ' ') { return true; }
	else { return false; }
}

void TicTacToe::CycleTurn() 
{
	if (turn == 'x') { turn = 'o'; }
	else { turn = 'x'; }
}

void TicTacToe::PrintBoard()
{
	std::cout << "Welcome to Tic Tac Toe\n\n" << std::endl;
	std::cout << "Column:   1 | 2 | 3 " << std::endl;
	std::cout << "Row: 1    " << board[0][0] << " | "
		<< board[0][1] << " | " << board[0][2]
		<< std::endl;
	std::cout << "         -----------" << std::endl;
	std::cout << "Row: 2    " << board[1][0] << " | "
		<< board[1][1] << " | " << board[1][2]
		<< std::endl;
	std::cout << "         -----------" << std::endl;
	std::cout << "Row: 3    " << board[2][0] << " | "
		<< board[2][1] << " | " << board[2][2]
		<< std::endl;
	std::cout << std::endl;
}

int TicTacToe::GetInput()
{
	int input;
	bool goodinput = false;
	do
	{
		std::cin >> input;
		if (std::cin.fail() || input > 3 || input < 1)
		{
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "\nPlease Input valid Board Coordinates\n " << std::endl;
			goodinput = false;
			PrintBoard();
			continue;
		}
		else { goodinput = true; }

	} while (!goodinput);
	input--; // This reduction is to match up to Array indexing.
	return input;
}

void TicTacToe::CheckForWin()
{
	//horizontal
	if (board[0][0] == board[0][1] && board[0][1] == board[0][2]) { winner = board[0][0]; }
	if (board[1][0] == board[1][1] && board[1][1] == board[1][2]) { winner = board[1][0]; }
	if (board[2][0] == board[2][1] && board[2][1] == board[2][2]) { winner = board[2][0]; }
	//vertical
	if (board[0][0] == board[1][0] && board[1][0] == board[2][0]) { winner = board[0][0]; }
	if (board[0][1] == board[1][1] && board[1][1] == board[2][1]) { winner = board[0][1]; }
	if (board[0][2] == board[1][2] && board[1][2] == board[2][2]) { winner = board[0][2]; }
	//Diagnal
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) { winner = board[1][1]; }
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) { winner = board[1][1]; }
	if (winner != ' ') { playing = false; }
}

void TicTacToe::CheckForDraw() 
{
	int PlayableCells = 9;
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if (board[i][j] != ' ') { PlayableCells--; }
		}
	}
	if (PlayableCells != 0) { playing = true; }
	else { playing = false; }
}
