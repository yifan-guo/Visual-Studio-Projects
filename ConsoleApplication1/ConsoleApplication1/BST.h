#ifndef BST_H
#define BST_H

#include "BinNode.h"

template<typename ItemType>
class BST {
private:
	BinNode<ItemType>* myRoot;
public:
	BST();
	BST(const BST<ItemType>& rhs);
	~BST();
	const BST<ItemType>& operator=(const BST<ItemType>& rhs);
	bool isEmpty() const;
	void insert(const ItemType& data);
	void remove(const ItemType& data);
	bool search(const ItemType& data) const;
	void print() const;
};

#include "BST.cpp"	
#endif