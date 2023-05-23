/*
 * Game.h
 *
 *  Created on: 17 Aug 2020
 *      Author: Kevin Vo Le (19396431)
 */

#ifndef GAME_H_
#define GAME_H_

#include "HumanPlayer.h"

class Game {
public:
	void play() {
		ticTacToe board;
		board.displayBoard();

		HumanPlayer hp;
		//BestFirstPlayer mplayer('O');
		char option;
		bool done = false;
		char player = 'X';
		cout << "Do you wish to play odd? y/n " << endl;
		cin >> option;
		hp.loadOptions(option);
		while (!done) {
			int x = -1;
			int y = -1;
			if (player == 'X') {
				hp.getMove(board, x, y);
				board.addMove(hp.currentNum, x, y);
				cout << "X makes a move (" << (x + 1) << "," << (y + 1) << ") "
						<< hp.currentNum << " "<< endl;
				board.displayBoard();
				done = checkWin(player, board);
				//player = 'O';
			}
//				else {
//				mplayer.getMove(board, x, y);
//				board.addMove(player, x, y);
//				cout << "O makes a move (" << (x + 1) << "," << (y + 1) << ") "
//						<< endl;
//				board.displayBoard();
//				done = checkWin(player, board);
//				player = 'X';
//			}
		}
	}

	bool checkWin(char playerSymbol, ticTacToe board) {
		char gStatus = board.gameStatus();

		if (gStatus == 'W') {
			if (playerSymbol == 'X') {
				cout << "You win." << endl;
			} else {
				cout << "I win." << endl;
			}
			return true;
		} else {
			return false;
		}
	}
	char getPlayer(){
		return player;
	}
};




#endif /* GAME_H_ */
