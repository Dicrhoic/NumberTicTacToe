/*
 * AI.h
 *
 *  Created on: 19 Aug 2020
 *      Author: Home
 */

#ifndef AI_H_
#define AI_H_

class AI_Player{
private:
	char playerSymbol;
	double maxMove(ticTacToe board);
	double minMove(ticTacToe board);
	int steps;
public:
	vector<int> legalMoves {2,4,6,8};

	AI_Player(char ps) {
		playerSymbol = ps;
		steps = 100000;
	}

	void getMove(ticTacToe board, int& x, int& y){
		if (board.isFull()){
			return;
		}


	}
	int evaluate(ticTacToe board){
		char gStatus = board.gameStatus();
		if (gStaus != playerSymbol){
			return - 10;
		}
		else {
			return + 10;
		}
		return 0;
	}
	int minimax(ticTacToe board,int depth, bool isMax){
//		int score = 0;
//		score = evaluate(board);
//
//		if (score == 10){
//			return score;
//		}
//		if (score == -10){
//			return score;
//		}
//		if (board.isFull()){
//			return 0;
//		}
//
//		if (isMax)
//		{
//			int best = 1000;
//		}
		if()

	}
};




#endif /* AI_H_ */
