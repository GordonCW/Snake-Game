#include "GameManager.h"

GameManager::~GameManager()
{
	for(int i = 0; i < ROW_SIZE; i++)
		delete [] coor[i];
	delete [] coor;
}

void GameManager::genFruit()
{
	int fruitPosittion = rand()%( ROW_SIZE * COLUMN_SIZE - fenceLen - s.getLen() );
	int counter = 0;
	for(int i = 0; i < ROW_SIZE; i++)
	{
		for(int j = 0; j < COLUMN_SIZE; j++)
		{
			if(coor[i][j] == ' ')
			{
				if(counter == fruitPosittion)
				{
					coor[i][j] = '*';
					return;
				}
				counter++;
			}
		}
	}
	assert(!"cannot generate a fruit");
}

void GameManager::update(const char input)
{
	switch(input)
	{
		//up
		case 'w':
			s.setDir(Dir::UP);
			break;
		//down
		case 's':
			s.setDir(Dir::DOWN);
			break;
		//left
		case 'a':
			s.setDir(Dir::LEFT);
			break;
		// right
		case 'd':
			s.setDir(Dir::RIGHT);
			break;
	}

	array<int ,2> temp = s.getHead();
	coor[ temp[0] ][ temp[1] ] = 'o';

	//try to move the head
	s.moveHead();
	temp = s.getHead();

	if(coor[ temp[0] ][ temp[1] ] == '*')
	{
		//eat fruit
		coor[ temp[0] ][ temp[1] ] = 'H';
		genFruit();
	}else if(coor[ temp[0] ][ temp[1] ] == ' ')
	{
		//move one unit
		coor[ temp[0] ][ temp[1] ] = 'H';
		temp = s.getTail();
		coor[ temp[0] ][ temp[1] ] = ' ';
		s.removeTail();
	}else{
		//snake collides with something
		//game over
		state = false;
	}
}
