//*******************************************************
// Source file queensdriver.cpp containing main driver
// author: Roth
//*******************************************************

#include <iostream>
#include "Queens.h"
using namespace std;


int main()
{
	cout << "Welcome to the " << BOARD_SIZE << " queens problem\n";

	EightQueens myQueens;   // create a puzzle

    myQueens.solve();       // solve it

    cout << "Press enter to exit." << endl;
    cin.get();
	return 0;
}
