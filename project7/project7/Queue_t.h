// File name: Queue_t.h
// Author: Yifan Guo
// userid: guoy5
// Email: yifan.guo@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 07
// Honor Statement: I pledge to the honor statement.
// Description:  
// Last Changed: 11/9/15



#ifndef QUEUE_T_H
#define QUEUE_T_H

template<typename ItemType>
class Queue {

private:

	struct Node
	{
		ItemType data;
		Node* next;
	};

	typedef Node* NodePtr;
	NodePtr myFront, myBack;
	size_t mySize;

public:
	// Class Constructor
	Queue();

	// Copy Constructor
	// pre:  Class object, aQueue, exists
	// post: Object is initialized to be a copy of the parameter
	Queue(const Queue<ItemType>& aQueue);

	// Class Destructor
	// Destroys a queue
	// pre:  Class object exists
	// post: Class object does not exist
	~Queue();

	// Assignment operator
	// Assigns a queue to another
	// pre: both class objects exist
	// post: this class object gets assigned a copy of the parameter class object
	const Queue<ItemType>& operator= (const Queue<ItemType>& rhs);

	// isEmpty
	// Checks if the queue is empty
	// pre:  A queue exists.
	// post: Returns true if it IS empty, false if NOT empty.
	bool isEmpty() const;

	// enqueue
	// enqueues an item to back of the queue.
	// pre:  DblQueue exists and item is passed.
	// post: adds the given item to the end of the queue.
	void enqueue(const ItemType& item);

	// dequeue
	// dequeues the front item off the queue 
	// pre:  DblQueue exists.
	// post: Removes item on front of the queue. If the queue
	//       was already empty, throws an std::underflow_error exception.
	void dequeue();

	// front
	// Returns the front item of the queue without dequeueing it.
	// pre:  DblQueue exists.
	// post: Returns item at front of queue.  If the queue is empty,
	//       throws an std::underflow_error exception.
	ItemType front() const;

	// size
	// Returns the number of items on the queue.
	size_t size() const;

};

#include "Queue_t.cpp"
#endif

