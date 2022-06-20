// File name: TrieNode.h
// Author: Yifan Guo
// Userid: guoy5
// Email: yifan.guo@vanderbilt.edu	
// Class: CS 2201
// Assignment Number: 09
// Honor Statement: I pledge to the honor statement.
// Description:  
// Last Changed: 11/30/15

#ifndef TRIENODE_H
#define TRIENODE_H
#include <string>
using namespace std;

const int ARRAY_SIZE = 26;	//default size of nextLetter

class TrieNode {
private:
	char myChar;
	bool isEnd;
	TrieNode* nextLetter[ARRAY_SIZE]; //static array of TrieNodePointers

	typedef TrieNode* TrieNodePtr;

public:
	//Constructor
	//pre:	takes a character for the node
	//	and a bool indicating whether it represents the end of a word
	//post: creates a TrieNode Object with the parameters
	TrieNode::TrieNode(char c, bool b);

	//Copy Constructor
	//pre:	TrieNode object (rhs) exists
	//post: creates a deep copy of rhs (entire subTrie)
	TrieNode::TrieNode(const TrieNode& rhs);

	//Destructor
	//pre:	Node exists
	//post: deletes the entire subTrie below the TrieNode, then deletes itself
	TrieNode::~TrieNode();

	//Assignment Operator
	//pre:	rhs exists
	//post:	assigns rhs TrieNode (and entire subTrie) to the TrieNode being called on
	const TrieNode& TrieNode::operator=(const TrieNode& rhs);

	//pre:	str contains only lowercase letters
	//		insert("") is never called on myRoot 
	//post:	inserts str at the TrieNode being called on
	//		creates new TrieNodes as needed &&
	//		sets boolean flag on the last node to true (if not already)
	void TrieNode::insert(const string& str);

	//pre:	string contains only lowercase characters (or empty)
	//post:	returns true if str is a word in the subTrie, else returns false
	bool TrieNode::isWord(const string& str) const;

	//pre: prefix contains only lowercase letters (or empty)
	//post:	returns true if pre is a prefix of a word in the sub-Trie
	//	of the TrieNode, else returns false
	bool TrieNode::isPrefix(const string& pre) const;

	//pre:	TrieNode exists
	//post: prints all words in the subTrie of the TrieNode, in alphabetical order
	//	str contains the letters of all ancestors of the given TrieNode
	void TrieNode::print(const string& str) const;

	//pre: TrieNode exists
	//post:	returns the count of all words in the sub-Trie, 0 if none
	size_t TrieNode::wordCount() const;

};
#endif