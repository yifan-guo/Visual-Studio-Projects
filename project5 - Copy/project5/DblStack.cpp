// File name: Stack_t.cpp
// Author: Yifan Guo
// userid: guoy5
// Email: yifan.guo@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 07
// Description:  
// Last Changed: 11/9/15 


#include <cstddef>  //for NULL
#include <stdexcept>
using namespace std;

// Class Constructor
// post: stack is created & initialized to be empty
template<typename ItemType>
Stack<ItemType>::Stack() :
	numItems(0),
	ItemList(nullptr)
{
}

// Copy Constructor
// pre: parameter object, rhs, exists
// post: stack is created to be a copy of the parameter stack
template<typename ItemType>
Stack<ItemType>::Stack(const Stack<ItemType>& rhs) :
	numItems(rhs.numItems),
	ItemList(nullptr)
{
	if (rhs.ItemList != nullptr) {
		//copy the first node
		ItemList = new Node;
		ItemList->data = rhs.ItemList->data;
		//copy rest of list
		NodePtr newPtr = ItemList;
		for (NodePtr origPtr = rhs.ItemList->next;
		origPtr != nullptr; origPtr = origPtr->next) {
			newPtr->next = new Node;
			newPtr = newPtr->next;
			newPtr->data = origPtr->data;
		}
		newPtr->next = nullptr;
	}
}



// Class Deconstructor
// pre: the stack exists
// post: the stack is destroyed and any dynamic memory is returned to the system
template<typename ItemType>
Stack<ItemType>::~Stack()
{
	while (ItemList != nullptr) {
		pop();
	}
}


// Assignment operator
// Assigns a stack to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class object
template<typename ItemType>
const Stack<ItemType>& Stack<ItemType>::operator= (const Stack<ItemType>& rhs)
{
	if (this == &rhs) {
		return *this;
	}
	Stack<ItemType> temp(rhs);		//copy ctor
	std::swap(numItems, temp.numItems);
	std::swap(ItemList, temp.ItemList);
	return *this;
}


// isEmpty
// Checks if the stack is empty
// pre:  A stack exists.
// post: Returns true if it IS empty, false if NOT empty.
template<typename ItemType>
bool Stack<ItemType>::isEmpty() const
{
	if (numItems == 0) {
		return true;
	}
	else {
		return false;
	}
}


// push
// Pushes an item on top of the stack.
// pre:  Stack exists and item is passed.
// post: the item is placed on top of the stack, and size is incremented.
template<typename ItemType>
void Stack<ItemType>::push(const ItemType& item)
{
	NodePtr tmp = ItemList;
	ItemList = new Node;
	ItemList->data = item;
	ItemList->next = tmp;
	numItems++;
}


// pop
// Pops the top item off the stack.
// pre:  Stack exists.
// post: Removes item on top of stack.  If the stack
//       was already empty, throws a std::underflow_error exception.
template<typename ItemType>
void Stack<ItemType>::pop()
{
	if (numItems == 0) {
		throw std::underflow_error("The stack is empty.");
	}
	NodePtr tmp = ItemList;
	ItemList = tmp->next;
	delete tmp;
	numItems--;
}


// top
// Returns the top item of the stack without popping it.
// pre:  Stack exists.
// post: Returns item on top of stack.  If the stack
//       was already empty, throws a std::underflow_error exception.
template<typename ItemType>
ItemType Stack<ItemType>::top() const
{
	if (numItems == 0) {
		throw std::underflow_error("The stack is empty.");
	}
	return ItemList->data;
}


// size
// Returns the number of items on the stack.
// post: Returns size from the private section of class.
template<typename ItemType>
size_t Stack<ItemType>::size() const
{
	return numItems;
}
