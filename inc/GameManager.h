/*
 * GameManager.h
 *
 *  Created on: 28 Dec 2016
 *      Author: ChungWa
 */

#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_


#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "Snake.h"

/*

0------>x
|
|
|
v
y

'#':fence
' ':nothing
'H':snake head
'o':snake body
'*':fruit

 */

class GameManager
{
	char**  coor;
	Snake s;
	bool state;
	const int fenceLen;
	void genFruit();
public:
	GameManager():s(), state(true), fenceLen(ROW_SIZE*2+COLUMN_SIZE*2-4)
	{
		srand (time(NULL));

		coor = new char*[ROW_SIZE];
		for(int i = 0; i < ROW_SIZE; i++)
			coor[i] = new char[COLUMN_SIZE];

		//initial value of each coordinates
		for(int i = 0; i < COLUMN_SIZE; i++)
		{
			coor[0][i] = '#';
			coor[ROW_SIZE - 1][i] = '#';
		}

		for(int i = 1; i < ROW_SIZE - 1; i++)
		{
			for(int j = 0; j < COLUMN_SIZE; j++)
			{
				if(j == 0 || j == COLUMN_SIZE - 1)
					coor[i][j] = '#';
				else
					coor[i][j] = ' ';
			}
		}

		//assume initial length is 2
		array<int, 2> tempXY= s.getHead();
		coor[ tempXY[0] ][ tempXY[1] ] = 'H';
		tempXY = s.getTail();
		coor[ tempXY[0] ][ tempXY[1] ] = 'o';

		genFruit();
	}

	~GameManager();
	void update(const char);
	bool isNotEnd(){ return ( state && s.getLen() < WIN_LEN ); }
	bool isGameOver(){ return !state;}
	char** getCoor() const { return coor; }
	int getLen(){ return s.getLen(); }
};


#endif /* GAMEMANAGER_H_ */
