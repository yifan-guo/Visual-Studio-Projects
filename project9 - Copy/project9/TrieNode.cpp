// File name: TrieNode.cpp
// Author: Yifan Guo
// Userid: guoy5
// Email: yifan.guo@vanderbilt.edu	
// Class: CS 2201
// Assignment Number: 09
// Honor Statement: I pledge to the honor statement.
// Description:  
// Last Changed: 11/30/15

#include <cassert>
#include <iostream>
#include <string>
#include "TrieNode.h"

using namespace std;

//Constructor
//pre:	takes a character for the node
//	and a bool indicating whether it represents the end of a word
//post: creates a TrieNode Object with the parameters
TrieNode::TrieNode(char c, bool b) : 
	myChar(c), 
	isEnd(b), 
	nextLetter()	//initializes elements to nullptr C++11
{}

//Copy Constructor
//pre:	TrieNode object (rhs) exists
//post: creates a deep copy of rhs (entire subTrie)
TrieNode::TrieNode(const TrieNode& rhs) :
	myChar(rhs.myChar),
	isEnd(rhs.isEnd), 
	nextLetter() {
	for (size_t i = 0; i < ARRAY_SIZE; i++) {
		if (rhs.nextLetter[i] != nullptr) {
			nextLetter[i] = new TrieNode(*rhs.nextLetter[i]);	
		}
	}
}

//Destructor
//pre:	Node exists
//post: deletes the entire subTrie below the TrieNode, then deletes itself
TrieNode::~TrieNode() {
	for (size_t i = 0; i < ARRAY_SIZE; i++) {
		if (nextLetter[i] != nullptr) {
			delete nextLetter[i];	//calls dtor on the TrieNode
			nextLetter[i] = nullptr;
		}
	}
}

//Assignment Operator
//pre:	rhs exists
//post:	assigns rhs TrieNode (and entire subTrie) to the TrieNode being called on
const TrieNode& TrieNode::operator=(const TrieNode& rhs) {
	//check for self-assignment
	if (&rhs == this) {
		return *this;
	}
	TrieNode tmp(rhs);	//create a local copy
	std::swap(this->myChar, tmp.myChar);	//swap fields
	std::swap(this->isEnd, tmp.isEnd);
	std::swap(this->nextLetter, tmp.nextLetter);
	return *this;
}

//pre:	str contains only lowercase letters
//		insert("") is never called on myRoot 
//post:	inserts str at the TrieNode being called on
//		creates new TrieNodes as needed &&
//		sets boolean flag on the last node to true (if not already)
void TrieNode::insert(const string& str) {
	if (str == "") {
		isEnd = true;	
		return;
	}
	int index = str[0] - 'a';
	//assert(nextLetter[index] == nullptr);
	if (nextLetter[index] == nullptr) {	//if node didn't exist before	
		nextLetter[index] = new TrieNode(str[0], false);	//create the node
	}
	nextLetter[index]->insert(str.substr(1));	
	
}

//pre:	string contains only lowercase characters (or empty)
//post:	returns true if str is a word in the subTrie, else returns false
bool TrieNode::isWord(const string& str) const {	//O(n) runtime
	if (str == "") {	//base case
		if (isEnd) {	
			return true;
		}
		else {
			return false;
		}
	}
	int index = str[0] - 'a';
	if (nextLetter[index] == nullptr) {
		return false;
	}
	else {
		return nextLetter[index]->isWord(str.substr(1));
	}
}

//pre: prefix contains only lowercase letters (or empty)
//post:	returns true if pre is a prefix of a word in the sub-Trie
//	of the TrieNode, else returns false
bool TrieNode::isPrefix(const string& pre) const {	//O(n) runtime
	if (pre == "") {
		return true;
	}
	int index = pre[0] - 'a';
	if (nextLetter[index] == nullptr) {
		return false;
	}
	else {
		return nextLetter[index]->isPrefix(pre.substr(1));
	}
}

//pre:	TrieNode exists
//post: prints all words in the subTrie of the TrieNode, in alphabetical order
//	str contains the letters of all ancestors of the given TrieNode
void TrieNode::print(const string& str) const {
	if (isEnd) {
		cout << str + myChar << endl;
	}
	for (size_t i = 0; i < ARRAY_SIZE; i++) {
		if (nextLetter[i] != nullptr) {
			if (myChar == ' ') {
				nextLetter[i]->print(str);
			}
			else {
				nextLetter[i]->print(str + myChar);
			}
		}
	}
}

//pre: TrieNode exists
//post:	returns the count of all words in the sub-Trie, 0 if none
size_t TrieNode::wordCount() const {
	size_t words = 0;
	if (isEnd) { words = 1; }
	for (size_t i = 0; i < ARRAY_SIZE; i++) {
		if (nextLetter[i] != nullptr) {
			words += nextLetter[i]->wordCount();
		}
	}
	return words;
}
