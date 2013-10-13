#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{
private:
	char board[3][3];
	char player;
	int moveCount;

public:
	TicTacToe();
	void showBoard();
	void play();
	bool check(int row, int col, char& player);
	void currentPlayer(char& player);
	char winner();
};

#endif