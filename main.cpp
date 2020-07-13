#include <iostream>
#include "tictactoe.h"

char MenuSelect()
{
	char input;
	bool goodinput = false;
	do
	{
		std::cin >> input;
		if (std::cin.fail() || toupper(input) != 'N' && toupper(input) != 'Y')
		{
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "\nPlease answer with Y for yes or N for no [Y/N]: ";
			goodinput = false;
			continue;
		}
		else { goodinput = true; }

	} while (!goodinput);
	return toupper(input);
}

int main()
{
	while (1) {
		std::cout << "Welcome, would you like to play a game of TicTacToe? [Y/N]: ";

		if (MenuSelect() == 'Y') {
			TicTacToe game;
			while (game.GetGameState())
			{
				game.PrintBoard();
				game.CheckForWin();
				game.CheckForDraw();

				if (game.GetWinner() != ' ')
				{
					std::cout << "Winner! " << game.GetWinner() << " Wins!\n" << std::endl;
					break;
				}
				if (!game.GetGameState())
				{
					std::cout << "No Winner! Game Draw!\n" << std::endl;
					break;
				}

				std::cout << game.GetTurn() << " : Enter Row number and Column Number [e.g 2 2 for middle square]: ";
				int input1 = game.GetInput();
				int input2 = game.GetInput();

				if (game.ValidBoardLocation(input1, input2))
				{
					game.SetBoardValue(input1, input2);
					game.CycleTurn();

				}
				else { std::cout << "\nSomeone has already played there, pick again\n " << std::endl; }
			}
		}
		else { break; }
	}

	std::cout << "Goodbye" << std::endl;

	return 0;
}
