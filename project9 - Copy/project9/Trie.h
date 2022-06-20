// File name: Trie.h
// Author: Yifan Guo
// Userid: guoy5
// Email: yifan.guo@vanderbilt.edu	
// Class: CS 2201
// Assignment Number: 09
// Honor Statement: I pledge to the honor statement.
// Description:  
// Last Changed: 11/30/15


#ifndef TRIE_H
#define TRIE_H

#include "TrieNode.h"

class Trie {
private:
	TrieNode myRoot;

	//pre:	none
	//post: parses the word to lowercase letters and inserts it into the Trie
	//		if string is empty after parsing, does not insert empty string
	void parseInsert(const string &str);

public:
	//default ctor
	//constructs the root node of the Trie
	Trie();

	//pre:	word is not empty and contains only lowercase letters
	//post:	inserts word into the Trie (if not already present)
	void insert(const string& word);

	//pre:	words are not empty and contain only lowercase letters
	//post:	insert all words in the specified file into the Trie (if not already present)
	//	throws a std::invalid_argument exception if the specified file cannot be opened
	void loadFromFile(const string& filename);

	//pre:	word contains only lowercase letters
	//		if word is empty string, isWord returns false
	//post:	returns true if word is in the Trie, else returns false
	bool isWord(const string& word);

	//pre:	prefix contains only lowercase letters (or is empty)
	//post:	returns true if pre is a prefix of a word in the Trie, else returns false
	bool isPrefix(const string& pre) const; 

	//pre:	Object exists
	//post:	prints all words (if any) in the Trie, one per line
	//	prints in alphabetical order
	void print() const;

	//pre:	Object exists
	//post: returns a count of all the words in the Trie
	//	returns 0 if no words
	size_t wordCount() const;
};

#endif