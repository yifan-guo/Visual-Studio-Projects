// File name: Trie.cpp
// Author: Yifan Guo
// Userid: guoy5
// Email: yifan.guo@vanderbilt.edu	
// Class: CS 2201
// Assignment Number: 09
// Honor Statement: I pledge to the honor statement.
// Description:  
// Last Changed: 11/30/15


#include <iostream>
#include<fstream>
#include "Trie.h"

using namespace std;

//default ctor
//constructs the root node of the Trie
Trie::Trie(): myRoot(' ', false) 
{}

//pre:	word is not empty and contains only lowercase letters
//post:	inserts word into the Trie (if not already present)
void Trie::insert(const string& word) {
	if (word == "") {
		throw invalid_argument("Empty string should never be inserted into a Trie.");
	}
	myRoot.insert(word);	//calls TrieNode insert method
}

//pre:	words are not empty and contain only lowercase letters
//post:	insert all words in the specified file into the Trie (if not already present)
//	throws a std::invalid_argument exception if the specified file cannot be opened
void Trie::loadFromFile(const string& filename) {
	string str;
	ifstream file(filename.c_str());

	if (!file) {
		throw std::invalid_argument("File could not be opened.");
		/*cout << "Unable to open file. Press enter to exit program.";
		getline(cin, str);
		cin.get();
		exit(1);*/
	}

	while (file >> str) {
		insert(str);		//calls Trie insert()
	}

	file.close();
}

//pre:	word contains only lowercase letters
//		if word is empty string, isWord returns false
//post:	returns true if word is in the Trie, else returns false
bool Trie::isWord(const string& word) {
	return myRoot.isWord(word);	//calls TrieNode isWord()
}

//pre:	prefix contains only lowercase letters (or is empty)
//post:	returns true if pre is a prefix of a word in the Trie, else returns false
bool Trie::isPrefix(const string& pre) const {
	return myRoot.isPrefix(pre);	//call TrieNode isPrefix()
}

//pre:	Object exists
//post:	prints all words (if any) in the Trie, one per line
//	prints in alphabetical order
void Trie::print() const {
	myRoot.print("");	
}

//pre:	Object exists
//post: returns a count of all the words in the Trie
//	returns 0 if no words
size_t Trie::wordCount() const {
	return myRoot.wordCount();
}