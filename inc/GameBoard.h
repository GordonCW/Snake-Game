/*
 * GameBoard.h
 *
 *  Created on: 28 Dec 2016
 *      Author: ChungWa
 */

#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "GameManager.h"

#define UPDATE_TIME_INTERVAL 70

using namespace std;


class GameBoard
{
	GameManager gm;
	void print();
public:
	GameBoard(){}

	void run();
	bool isNotEnd(){ return gm.isNotEnd(); }
	void end();
};


#endif /* GAMEBOARD_H_ */
