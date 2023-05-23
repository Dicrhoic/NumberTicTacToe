/*
 * main.cpp
 *
 *  Created on: 17 Aug 2020
 *      Author: Kevin Vo Le (19396431)
 */

//Main program

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cctype>

using namespace std;

#include "TicTacToe.h"
#include "Game.h"
#include "AI.h"
#include "HumanPlayer.h"

int main() {
	srand(time(0));


	Game g;
	g.play();

	return 0;


}


