// File name: testQueue.cpp
// Name: Yifan Guo
// VUnetid: guoy5	
// Email: yifan.guo@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 06
// Honor statement: I pledge to the honor statement.
// Description:  Tests the DblQueue class by implementing the Big 3
//	   and functions to push, pop, retrieve top, 
//	   and retrieve size of the stack.
// Last Changed:  11/1/15


#include <iostream>
#include "DblQueue.h"
using namespace std;


int main() {
	DblQueue queue1;			//default ctor
	ItemType digit0(0);
	ItemType digit1(1);
	queue1.enqueue(digit0);		//test enqueue()
	queue1.enqueue(digit1);

	DblQueue queue2(queue1);	//copy ctor

	if (queue1.front() == queue2.front()) {		//tests front()
		cout << "Success: Stacks have the same topmost Node." << endl;
	}
	else {
		cout << "Test front() failed." << endl;
	}

	if (queue2.size() == (size_t)2) {			//tests size()
		cout << "Success: queue2 has appropriate size." << endl;
	}
	else {
		cout << "Test size() failed." << endl;
	}

	if (queue1.size() == queue2.size()) {
		cout << "Success: Queues have the same number of Nodes." << endl;
	}
	else {
		cout << "Copy ctor did not work as expected." << endl;
	}
	
	queue2.dequeue();			//tests dequeue()
	if (queue2.front() == digit1) {
		cout << "Success: Dequeue worked properly." << endl;
	}
	else {
		cout << "Dequeue failed." << endl;
	}

	queue2.dequeue();			//queue2 should be empty
	if (queue2.size() != 0) {		//tests dequeue()
		cout << "Queue is not empty as expected." << endl;
	}

	if (!queue2.isEmpty()) {		//tests isEmpty()
		cout << "isEmpty not working properly." << endl;
	}

	try {
		queue2.dequeue();
	}
	catch (underflow_error &excpt) {
		cout << "Error successfully thrown and caught:: " << excpt.what() << endl;
	}

	try {
		queue2.front();
	}
	catch (underflow_error &excpt) {
		cout << "Error successfully thrown and caught:: " << excpt.what() << endl;
	}

	queue2 = queue1;		//tests assignment operator

	if (queue1.front() == queue2.front()) {		//tests front()
		cout << "Success: Queues have the same topmost Node." << endl;
	}
	else {
		cout << "Test front() failed." << endl;
	}

	if (queue2.size() == (size_t)2) {			//tests size()
		cout << "Success: queue2 has appropriate size." << endl;
	}
	else {
		cout << "Test size() failed." << endl;
	}

	if (queue1.size() == queue2.size()) {		//tests size
		cout << "Success: Queues have the same number of Nodes." << endl;
	}
	else {
		cout << "Test size() failed." << endl;
	}

	cout << "\nEnd of tests. Press enter to exit.";
	char tt;
	tt = cin.get();
}