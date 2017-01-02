#include <iostream>
#include <windows.h>
#include <conio.h>
#include "GameBoard.h"

using namespace std;

int main()
{
	//console resize
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions
    MoveWindow(console, r.left, r.top, 500, 500, TRUE); // 500 width, 500 height

    //game description
    cout << "Snake Game" << endl;
    cout << "'w': UP" << endl;
    cout << "'s': DOWN" << endl;
    cout << "'a': LEFT" << endl;
    cout << "'d': RIGHT" << endl;
    cout << "press enter to start the game" << endl;
    string s;
    getline(cin, s);

    //start the game
	GameBoard gb;
	while(gb.isNotEnd())
		gb.run();
	gb.end();
	return 0;
}
