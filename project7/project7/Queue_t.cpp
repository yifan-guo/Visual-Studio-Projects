// File name: Queue_t.cpp
// Author: Yifan Guo
// userid: guoy5
// Email: yifan.guo@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 07
// Description:  
// Last Changed: 11/9/15


#include <stdexcept>
using namespace std;

// Class Constructor
template<typename ItemType>
Queue<ItemType>::Queue() :
	myFront(nullptr),
	myBack(nullptr),
	mySize(0)
{
}

// Copy Constructor
// pre:  Class object, aQueue, exists
// post: Object is initialized to be a copy of the parameter
template<typename ItemType>
Queue<ItemType>::Queue(const Queue<ItemType>& aQueue) :
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
template<typename ItemType>
Queue<ItemType>::~Queue() {
	while (!isEmpty()) {
		dequeue();
	}
}

// Assignment operator
// Assigns a queue to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class object
template<typename ItemType>
const Queue<ItemType>& Queue<ItemType>::operator= (const Queue<ItemType>& rhs) {
	if (this == &rhs) {
		return *this;
	}
	Queue<ItemType> tmp(rhs);		//copy ctor
	std::swap(myFront, tmp.myFront);
	std::swap(myBack, tmp.myBack);
	std::swap(mySize, tmp.mySize);
	return *this;
}

// isEmpty
// Checks if the queue is empty
// pre:  A queue exists.
// post: Returns true if it IS empty, false if NOT empty.
template<typename ItemType>
bool Queue<ItemType>::isEmpty() const {
	if (mySize == 0) {
		return true;
	}
	else {
		return false;
	}
}

// enqueue
// enqueues an item to back of the queue.
// pre:  Queue exists and item is passed.
// post: adds the given item to the end of the queue.
template<typename ItemType>
void Queue<ItemType>::enqueue(const ItemType& item) {
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
// pre:  Queue exists.
// post: Removes item on front of the queue. If the queue
//       was already empty, throws an std::underflow_error exception.
template<typename ItemType>
void Queue<ItemType>::dequeue() {
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
// pre:  Queue exists.
// post: Returns item at front of queue.  If the queue is empty,
//       throws an std::underflow_error exception.
template<typename ItemType>
ItemType Queue<ItemType>::front() const {
	if (isEmpty()) {
		throw std::underflow_error("The queue is empty.");
	}
	return myFront->data;
}

// size
// Returns the number of items on the queue.
template<typename ItemType>
size_t Queue<ItemType>::size() const {
	return mySize;
}
