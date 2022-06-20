// File name: testStk.cpp
// Name: Yifan Guo
// VUnetid: guoy5	
// Email: yifan.guo@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 05
// Honor statement: I pledge to the honor statement.
// Description:  Tests the DblStack class by implementing the Big 3
//	   and functions to push, pop, retrieve top, 
//	   and retrieve size of the stack.
// Last Changed:  10/27/15


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "DblStack.h"
using namespace std;

int main () {
	DblStack stack1;			//default ctor
	ItemType digit0(0);
	ItemType digit1(1);
	stack1.push(digit0);		//test push()
	stack1.push(digit1);

	DblStack stack2(stack1);	//copy ctor

	if (stack1.top() == stack2.top()) {		//tests top()
		cout << "Success: Stacks have the same topmost Node.\n" << endl;
	}
	else {
		cout << "Test top() failed." << endl;
	}

	if (stack2.size() == (size_t) 2) {
		cout << "Success: Stack2 has appropriate size." << endl;
	}

	if (stack1.size() == stack2.size()) {
		cout << "Success: Stacks have the same number of Nodes.\n" << endl;
	}
	else {
		cout << "Test size() failed." << endl;
	}

	stack2.pop();			//tests pop()
	if (stack2.top() == digit0) {
		cout << "Success: Pop worked properly." << endl;
	}
	else {
		cout << "Pop failed." << endl;
	}

	stack2.pop();			//stack2 should be empty
	if (stack2.size() != 0) {		//tests size()
		cout << "Stack is not empty as expected." << endl;
	}

	if (!stack2.isEmpty()) {		//tests isEmpty()
		cout << "isEmpty not working properly." << endl;
	}

	try {
		stack2.pop();
	}
	catch (underflow_error &excpt) {
		cout << "Error successfully thrown and caught:: " << excpt.what() << endl;
	}

	try {
		stack2.top();
	}
	catch (underflow_error &excpt) {
		cout << "Error successfully thrown and caught:: " << excpt.what() << endl;
	}

	stack2 = stack1;		//tests assignment operator

	if (stack1.top() == stack2.top()) {		//tests top()
		cout << "Success: Stacks have the same topmost Node.\n" << endl;
	}
	else {
		cout << "Test top() failed." << endl;
	}

	if (stack1.size() == stack2.size()) {
		cout << "Success: Stacks have the same number of Nodes.\n" << endl;
	}
	else {
		cout << "Test size() failed." << endl;
	}

	cout << "\nEnd of tests. Press enter to exit.";
	char tt;
	tt = cin.get();
}