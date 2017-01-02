#include "GameBoard.h"

void GameBoard::print()
{
	system("clear");

	const char * const * coor = gm.getCoor();
	const int len = gm.getLen();

	for(int i = 0; i < ROW_SIZE; i++)
	{
		for(int j = 0; j < COLUMN_SIZE; j++)
			cout << coor[j][i];
		cout << endl;
	}

	//assume the length starts with 2
	cout << "length of the snake: " << len << "units" << endl;
}

void GameBoard::run()
{
	system("cls");

	//print the game to the console
	print();

	char input;

	//delay 0.5s and get the input from the user
	Sleep(UPDATE_TIME_INTERVAL);
	while(kbhit() != 0)
		input = (char) getch();

	//update the game
	gm.update(input);
}

void GameBoard::end()
{
	//the two ending condtion
	if(gm.isGameOver()){
		cout << "Gameover!!!!!" << endl;
		cout << "push ENTER to end the game..." << endl;
		string temp;
		getline(cin, temp);
	}else{
		cout << "You won!!!!!" << endl;
		cout << "push ENTER to end the game..." << endl;
		string temp;
		getline(cin, temp);
	}
}
