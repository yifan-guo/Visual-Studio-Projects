// File name: CalTest.cpp
// Author: Yifan Guo
// VUnetid: guoy5
// Email: yifan.guo@vanderbilt.edu
// Class: CS201
// Date: 9/21/15
// Honor statement: I pledge to the honor statement.
// Assignment Number: 02
// Description: This program will test the Calendar class

#include <iostream>
#include <string>
#include <stdexcept>
#include "Calendar.h"
using namespace std;




void main(void)
{

	Calendar c1;
	if (c1.getNumRem() != (size_t)0) {
		cout << "error 1" << endl;
	}

	if (c1.maxSize() != (size_t)50) {
		cout << "error 2" << endl;
	}

	Reminder r1(Date("1/1/2011"),"r1"), r2(Date("1/2/2011"),"r2");
	c1.addRem(r1); c1.addRem(r2);

	if (c1.getNumRem() != (size_t)2) {
		cout << "error 3" << endl;
	}

	if (c1.getRem(0) != r1) {
		cout << "error 4" << endl;
	}



	cout << "\nEnd of tests. Press a key to exit.";
	cin.get();

}

