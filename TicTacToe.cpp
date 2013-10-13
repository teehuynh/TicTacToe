#include <iostream>

using namespace std;

#include "TicTacToe.h"

TicTacToe::TicTacToe()
{
	player = 'O';
	moveCount = 0;
	
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			board[i][j] = ' ';

}

void TicTacToe::showBoard()
{
	int selection;
		for(int i = 0; i < 3; i ++){
			for(int j = 0; j <3; j++){
				cout << board[i][j];
					if(j != 2){
						cout << "|";
					}
			}
			cout << endl;
		}
}

void TicTacToe::play()
{
	int row, col;
	char theWinner;
	
	do { 
		showBoard();
		
		cout << "Please enter row number" << endl;
		cin >> row;
		cout << "Please enter column number" << endl;
		cin >> col;
		check(row,col,player);
		theWinner = winner();
		moveCount++;
		
	} while(moveCount < 9 && theWinner == 'D');

		showBoard();

		if(theWinner != 'D')
			cout << "The winner is " << theWinner << endl;
		else
			cout << "Resulted in a cat's game!" << endl;
}

bool TicTacToe::check(int row, int col, char& player)
{
	if(board[row-1][col-1] == 'X' || board[row-1][col-1] == 'O')
	{
		cout << "Already taken try again" << endl;
		cout << "It's " << player << " turn." << endl;
		moveCount--;
		return true;
	}
	else if(board[row-1][col-1] == ' ')
	{
		board[row-1][col-1] = player;
		currentPlayer(player);
		return false;
	}
}

void TicTacToe::currentPlayer(char& player)
{
	if(player == 'O')
	{
		player = 'X';
		cout << "It's X's turn" << endl;
	}
	else
	{
		player = 'O';
		cout << "It's O's turn" << endl;
	}
}

char TicTacToe::winner()
{
	//check for horizontal wins
	for (int i = 0; i < 3; i++){
            if (board[i][0] == board[i][1]
                 && board[i][1] == board[i][2]
                 && board[i][0] != ' '){
                 return board[i][0];
            }
      }
	//check for vertical wins
    for (int i = 0; i < 3; i++){
             if (board[0][i] == board[1][i]
                   && board[1][i] == board[2][i]
                   && board[0][i] != ' '){
                   return board[0][i];
             }
       }
	//checks for diagonal wins
       if (board[0][0] == board[1][1]
              && board[1][1] == board[2][2]
              && board[0][0] != ' ') {
              return board[0][0];
       }

       if (board[2][0] == board[1][1]
               && board[1][1] == board[0][2]
               && board[2][0] != ' ') {
               return board[2][0];
       }

       return 'D';
}