/*
 * TicTacToe.h
 *
 *  Created on: 17 Aug 2020
 *      Author: Kevin Vo Le (19396431)
 */

#ifndef TICTACTOE_H_
#define TICTACTOE_H_

//Tic-Tac-Toe Header file

class ticTacToe {
public:
	ticTacToe(const ticTacToe& cboard) {
		for (int row = 0; row < 3; row++)
			for (int col = 0; col < 3; col++)
				board[row][col] = cboard.board[row][col];

		noOfMoves = cboard.noOfMoves;
	}

	int getGrid(int i, int j) {
		return board[i][j];
	}

	bool isFull() {
		return (noOfMoves >= 9);
	}

	int getNoOfMoves() {
		return noOfMoves;
	}

	void displayBoard() const;
	//Function to print the board.

	bool isValidMove(int x, int y) const;
	//Function to determine if a move is valid.

	void addMove(int playerNumber, int x, int y);
	//Function to get a move for a player

	vector<int> getEmptyPositions();
	//Function to get empty positions

	char gameStatus();
	//Function to determine the current status of the game.

	void reStart();
	//Function to restart the game.

	ticTacToe();
	//Default constructor.
	//Postcondition: Initializes the board to an empty state.

private:
	int board[3][3];
	int noOfMoves;
};



void ticTacToe::displayBoard() const {

	for (int row = 0; row < 3; row++) {
		cout << " ";
		for (int col = 0; col < 3; col++) {
			cout << setw(3) << board[row][col];

			if (col != 2)
				cout << " |";
		}

		cout << endl;

		if (row != 2)
			cout << " ____|____|____" << endl << "     |    |    " << endl;
	}

	cout << endl;
}

bool ticTacToe::isValidMove(int row, int col) const {
	if (0 <= row && row <= 2 && 0 <= col && col <= 2 && board[row][col] == 0)
		return true;
	else{
		cout << "Invalid Move!" <<endl;
		return false;
	}
	return true;
}

vector<int> ticTacToe:: getEmptyPositions() {
	vector<int> emptyCells;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == 0)
				emptyCells.push_back(i * 3 + j);
		}
	}
    return emptyCells;
}

void ticTacToe::addMove(int playerNumber, int x, int y) {
	if (!isValidMove(x, y))
		return;

	board[x][y] = playerNumber;

	noOfMoves++;
}

char ticTacToe::gameStatus() {
	//Check rows for a win
	for (int row = 0; row < 3; row++){
		if(board[row][0] + board[row][1] +
				board[row][2] == 15){
			return 'W';
		}
	}

	//Check columns for a win
	for (int col = 0; col < 3; col++){
		if(board[0][col] + board[1][col] +
				board[2][col] == 15){
			return 'W';
		}
	}

	//Check diagonals for a win
	if(board[0][0] + board[1][1] + board[2][2] == 15){
		return 'W';
	}

	if(board[2][0] + board[1][1] + board[0][2] == 15){
			return 'W';
		}

	if (noOfMoves < 9) {
		return 'C';
	}

	if (noOfMoves > 9) {
		return 'F';
	}


	return 'D';
}



void ticTacToe::reStart() {
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = ' ';

	noOfMoves = 0;
}

ticTacToe::ticTacToe() {
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = 0;

	noOfMoves = 0;
}





#endif /* TICTACTOE_H_ */
