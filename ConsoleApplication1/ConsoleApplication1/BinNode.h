#ifndef BINNODE_H
#define BINNODE_H

template<typename ItemType>
class BinNode {
	typedef BinNode<ItemType>* BinNodePtr;
private:
	ItemType item;
	BinNode<ItemType>* left;
	BinNode<ItemType>* right;
	BinNode<ItemType>* findSuccessor();

public:
	BinNode(const ItemType& data);	//alt ctor
	BinNode(const BinNode<ItemType>& rhs);
	~BinNode();
	const BinNode<ItemType>& operator=(const BinNode<ItemType>& rhs);
	void insert(const ItemType& data);
	BinNode<ItemType>* remove(const ItemType& data);
	bool search(const ItemType& data) const;
	void print() const;
};

#include "BinNode.cpp"
#endif