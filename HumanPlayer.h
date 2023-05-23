/*
 * HumanPlayer.h
 *
 *  Created on: 19 Aug 2020
 *      Author: Kevin Vo Le (19396431)
 */

#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

class HumanPlayer {
public:
	int currentNum;
	vector<int> legalMovesEven {2,4,6,8};
	vector<int> legalMovesOdd {1,3,5,7,9};
	vector<int> legalMoves;
	int square;
	void loadOptions(char option){
		if (option == 'N' || option == 'n')
		{
			legalMoves = legalMovesEven;
		}
		else {
			legalMoves = legalMovesOdd;
		}
	}
	void printLegalMoves(){
		cout << "Player options: ";
		for (unsigned i = 0; i < legalMoves.size(); i++){
			cout << legalMoves.at(i) << ", ";
		}
		cout << endl;
	}

	bool numberAvaliable (int x){
		//cout << "Input: " <<x << endl;
		for (unsigned i = 0; i < legalMoves.size(); i++){
			//cout << legalMoves.at(i);
			if (x == legalMoves.at(i)){
				return true;
				break;
			}
		}
		cout << "Invalid number input" << endl;
		return false;

	}

	int findNumPos(int x){
		int b;
		//cout << "Searching for " << x << endl;
		for (unsigned i = 0; i < legalMoves.size(); i++){
				//cout << legalMoves.at(i) << " ,";
				if (legalMoves.at(i) == x){
					//cout << "Yea! Found at " << i << endl;
					break;
					return i+1;
				}
				b = i;
			}
			cout << endl;
			return b;
	}

	void getMove(ticTacToe board, int& x, int& y) {
		int num;
		int check = 0;
		do {
			do {
				printLegalMoves();
				cout << "Choose a number: ";
				cin >> check;
				num = check;
				cout << "Chosen: " <<num << endl;
			}
			while(!numberAvaliable(num));
			cout << "Choose where to place: " << num << endl;
			cin >> x >> y;
			cout << endl;
			x = x - 1;
			y = y - 1;
			currentNum = num;
		} while (!board.isValidMove(x, y));
		cout << "My move is number " << currentNum << " in square"
				<< ": " << calculateSquare(x,y)  << endl;
		legalMoves.erase(remove(legalMoves.begin(), legalMoves.end(), currentNum), legalMoves.end());

		return;
	}

	int calculateSquare(int x, int y) {
		if (x == 0) {
			if (y == 0) {
				return 1;
			}
			if (y == 1) {
				return 2;
			}
			if (y == 2) {
				return 3;
			}
		}
		if (x == 1) {
			if (y == 0) {
				return 4;
			}
			if (y == 1) {
				return 5;
			}
			if (y == 2) {
				return 6;
			}
		}
		if (x == 2) {
			if (y == 0) {
				return 7;
			}
			if (y == 1) {
				return 8;
			}
			if (y == 2) {
				return 9;
			}
		}
		return -1;
	}
};




#endif /* HUMANPLAYER_H_ */
