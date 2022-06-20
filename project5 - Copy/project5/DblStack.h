// File name: DblStack.h
// Name: Yifan Guo
// VUnetid: guoy5	
// Email: yifan.guo@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 05
// Honor statement: I pledge to the honor statement.
// Description:  Maintains a stack of ItemType.  Contains functions
//     prototypes to push, pop, retrieve top, and retrieve size of the 
//     stack.
// Last Changed:  10/26/15

#ifndef DBLSTACK_H
#define DBLSTACK_H

typedef double ItemType; // stack currently holds doubles

template<typename ItemType>
class Stack {

private:

	struct Node
	{
		ItemType data;
		Node *next;
	};

	typedef Node* NodePtr;

	size_t numItems;		//number of items in linked list
	Node *ItemList;		//pointer to head of linked list, is null if stack is empty


public:
	// Class Constructor
	// post: stack is created & initialized to be empty
	Stack();

	// Copy Constructor
	// pre: parameter object, rhs, exists
	// post: stack is created to be a copy of the parameter stack
	Stack(const Stack<ItemType>& rhs);

	// Class Deconstructor
	// pre: the stack exists
	// post: the stack is destroyed and any dynamic memory is returned to the system
	~Stack();

	// Assignment operator
	// Assigns a stack to another
	// pre: both class objects exist
	// post: this class object gets assigned a copy of the parameter class object
	const Stack<ItemType>& operator= (const Stack<ItemType>& rhs);

	// isEmpty
	// Checks if the stack is empty
	// pre:  A stack exists.
	// post: Returns true if it IS empty, false if NOT empty.
	bool isEmpty() const;

	// push
	// Pushes an item on top of the stack.
	// pre:  Stack exists and item is passed.
	// post: the item is placed on top of the stack, and size is incremented.
	void push(const ItemType& item);

	// pop
	// Pops the top item off the stack.
	// pre:  Stack exists.
	// post: Removes item on top of stack.  If the stack
	//       was already empty, throws a std::underflow_error exception.
	void pop();

	// top
	// Returns the top item of the stack without popping it.
	// pre:  Stack exists.
	// post: Returns item on top of stack.  If the stack
	//       was already empty, throws a std::underflow_error exception.
	ItemType top() const;

	// size
	// Returns the number of items on the stack.
	// post: Returns size from the private section of class.
	size_t size() const;
};

#include "DblStack.cpp"
#endif
