#ifndef TICTACTOE_H
#define TICTACTOE_H
class TicTacToe
{
private:
	char board[3][3] = {
		{ ' ', ' ', ' ' },
		{ ' ', ' ', ' ' },
		{ ' ', ' ', ' ' }
	};

	bool playing = true;
	char turn = 'x';
	char winner = ' ';
	bool gameDraw = false;
public:
	char GetTurn();
	bool GetGameState();
	char GetWinner();
	void SetBoardValue(int input1, int input2);
	bool ValidBoardLocation(int input1, int input2);
	void CycleTurn();
	void PrintBoard();
	int GetInput();
	void CheckForWin();
	void CheckForDraw();

};
#endif