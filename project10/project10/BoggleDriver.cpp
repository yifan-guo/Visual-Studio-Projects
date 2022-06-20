// File name: BoggleDriver.cpp
// Author: Yifan Guo
// Userid: guoy5
// Email: yifan.guo@vanderbilt.edu	
// Class: CS 2201
// Assignment Number: 10
// Honor Statement: I pledge to the honor statement.
// Description:  
// Last Changed: 12/2/15

#include <iostream>
#include <fstream>
#include <string>
#include "Boggle.h"

using namespace std;

int main() {

	Boggle myBoggle;		//create a game

	myBoggle.playAgainstComputer();		//solve it

	string str;
	cout << "Press enter to exit." << endl;
	getline(cin, str);
	cin.get();
	return 0;
}