/*
 * Snake.h
 *
 *  Created on: 28 Dec 2016
 *      Author: ChungWa
 */

#ifndef SNAKE_H_
#define SNAKE_H_
#include <iostream>
#include <list>
#include <array>
using namespace std;

#define ROW_SIZE 32
#define COLUMN_SIZE 32
#define WIN_LEN 30

#define INITAIL_HEAD_X ROW_SIZE/2
#define INITAIL_HEAD_Y COLUMN_SIZE/2

enum class Dir {UP = 0, DOWN, LEFT, RIGHT};


class Snake
{
	Dir dir;

	//(x,y) of each unit of the snake
	list< array<int, 2> > snakeCoor;

public:
	Snake():dir(Dir::RIGHT)
	{
		//head
		array<int, 2> temp = {INITAIL_HEAD_X, INITAIL_HEAD_Y};
		snakeCoor.push_front(temp);

		//tail
		temp[0] = INITAIL_HEAD_X - 1;
		temp[1] = INITAIL_HEAD_Y;
		snakeCoor.push_back(temp);
	}

	Dir getDir(){ return dir; }
	int getLen(){ return snakeCoor.size(); }
	array<int, 2> getHead(){ return snakeCoor.front(); }
	array<int, 2> getTail(){ return snakeCoor.back(); }
	void setDir(Dir inputDir);
	void moveHead();
	void removeTail(){ snakeCoor.pop_back(); }
};


#endif /* SNAKE_H_ */
