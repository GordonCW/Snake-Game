#include "Snake.h"

void Snake::setDir(Dir inputDir)
{
	switch(inputDir)
	{
		case Dir::UP:
			if(dir != Dir::DOWN)
				dir = inputDir;
			break;
		case Dir::DOWN:
			if(dir != Dir::UP)
				dir = inputDir;
			break;
		case Dir::LEFT:
			if(dir != Dir::RIGHT)
				dir = inputDir;
			break;
		case Dir::RIGHT:
			if(dir != Dir::LEFT)
				dir = inputDir;
			break;
	}
	cout << (int)dir << endl;
}

void Snake::moveHead()
{
	array<int, 2> temp = snakeCoor.front();
	switch(dir)
	{
		case Dir::UP:
			temp[1]--;
			break;
		case Dir::DOWN:
			temp[1]++;
			break;
		case Dir::LEFT:
			temp[0]--;
			break;
		case Dir::RIGHT:
			temp[0]++;
			break;
	}

	snakeCoor.push_front(temp);
}
