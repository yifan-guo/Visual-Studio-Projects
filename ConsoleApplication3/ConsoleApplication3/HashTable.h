#ifndef HASHTABLE_H
#define HASHTABLE_H

template <typename ItemType>
class HashTable {
private:

	int hash(const int& x);

public:
	ItemType** myHead;	//ptr to array of pointers
	HashTable(const int& size);
	//HashTable(const HashTable& rhs);	//copy ctor
	//const HashTable& operator=(const HashTable& rhs);	//assignment op
	//~HashTable();	//dtor
	//void insert(const ItemType& item);
	//bool search(const ItemType& item) const;
	//void remove(const ItemType& item);
};

#include "HashTable.cpp"
#endif
