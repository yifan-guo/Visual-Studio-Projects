// File name: DblQueue.cpp
// Author: Yifan Guo	
// userid: guoy5	
// Email: yifan.guo@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 06
// Description:  
// Honor statement: I pledge to the honor statement.
// Last Changed: 11/1/15

#include <stdexcept>
#include"DblQueue.h"
using namespace std;

// Class Constructor
DblQueue::DblQueue() :
	myFront(nullptr),
	myBack(nullptr),
	mySize(0)
{
}

// Copy Constructor
// pre:  Class object, aQueue, exists
// post: Object is initialized to be a copy of the parameter
DblQueue::DblQueue(const DblQueue& aQueue) :
	myFront(nullptr),
	myBack(nullptr),
	mySize(aQueue.mySize)
{
	if (aQueue.myFront != nullptr) {
		//copy first node
		myFront = new Node;
		myFront->data = aQueue.myFront->data;
		//copy rest of list
		NodePtr newPtr = myFront;
		for (NodePtr origPtr = aQueue.myFront->next; 
		origPtr != nullptr; origPtr = origPtr->next) {
			newPtr->next = new Node;
			newPtr = newPtr->next;
			newPtr->data = origPtr->data;
		}
		newPtr->next = nullptr;
		myBack = newPtr;
	}
}

// Class Destructor
// Destroys a queue
// pre:  Class object exists
// post: Class object does not exist
DblQueue::~DblQueue() {
	while (!isEmpty()) {
		dequeue();
	}
}

// Assignment operator
// Assigns a queue to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class object
const DblQueue& DblQueue::operator= (const DblQueue& rhs) {
	if (this == &rhs) {
		return *this;
	}
	DblQueue tmp(rhs);		//copy ctor
	std::swap(myFront, tmp.myFront);
	std::swap(myBack, tmp.myBack);
	std::swap(mySize, tmp.mySize);
	return *this;
}

// isEmpty
// Checks if the queue is empty
// pre:  A queue exists.
// post: Returns true if it IS empty, false if NOT empty.
bool DblQueue::isEmpty() const {
	if (mySize == 0) {
		return true;
	}
	else {
		return false;
	}
}

// enqueue
// enqueues an item to back of the queue.
// pre:  DblQueue exists and item is passed.
// post: adds the given item to the end of the queue.
void DblQueue::enqueue(const ItemType& item) {
	NodePtr tmp = new Node;
	tmp->data = item;
	tmp->next = nullptr;
	if (myBack != nullptr) {
		myBack->next = tmp;
		myBack = myBack->next;
	}
	else {
		myBack = tmp;
		myFront = tmp;
	}
	mySize++;
}

// dequeue
// dequeues the front item off the queue 
// pre:  DblQueue exists.
// post: Removes item on front of the queue. If the queue
//       was already empty, throws an std::underflow_error exception.
void DblQueue::dequeue() {
	if (isEmpty()) {
		throw std::underflow_error("The queue is empty.");
	}
	NodePtr tmp = myFront;	//not nullptr
	myFront = tmp->next;
	delete tmp;
	if (myFront == nullptr) {
		myBack = nullptr;
	}
	mySize--;
}

// front
// Returns the front item of the queue without dequeueing it.
// pre:  DblQueue exists.
// post: Returns item at front of queue.  If the queue is empty,
//       throws an std::underflow_error exception.
ItemType DblQueue::front() const {
	if(isEmpty()) {
		throw std::underflow_error("The queue is empty.");
	}
	return myFront->data;
}

// size
// Returns the number of items on the queue.
size_t DblQueue::size() const {
	return mySize;
}
