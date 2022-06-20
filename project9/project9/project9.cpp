// File name: project9.cpp
// Author: Yifan Guo
// Userid: guoy5
// Email: yifan.guo@vanderbilt.edu	
// Class: CS 2201
// Assignment Number: 09
// Honor Statement: I pledge to the honor statement.
// Description:  
// Last Changed: 12/2/15

#include <iostream>
#include <string>
#include "Trie.h"
using namespace std;

void main() {
	//string str = "or";
	//cout << str.substr(1) << endl;

	//------------------------trie object is empty--------------------------------
	Trie trie1;	//tests default ctor (NO PARENTHESES!)

	if (trie1.wordCount() == 0) {		//tests WordCount()
		cout << "wordCount successful." << endl;
	}
	else {
		cout << "wordCount is not right." << endl;
	}

	trie1.print();	//should print nothing

	if (trie1.isWord("") == false) {	//case: empty string is not a Word
		cout << "isWord(empty string) edge case correct." << endl;
	}
	else {
		cout << "WRONG: empty string is NOT a word." << endl;
	}

	if (trie1.isPrefix("") == true) {	
		//case: empty string is a prefix of all words and of itself
		cout << "isPrefix(empty string) edge case correct." << endl;
	}
	else {
		cout << "WRONG: empty string is always a prefix." << endl;
	}

	if (trie1.isWord("anything") == false) {	//case:non -existent string
		cout << "isWord(non-existent string) edge case correct." << endl;
	}
	else {
		cout << "WRONG: non-existent string is NOT a word." << endl;
	}

	if (trie1.isPrefix("anything") == false) {
		//case: non-existent string 
		cout << "isPrefix(non-existent string) edge case correct." << endl;
	}
	else {
		cout << "WRONG: non-existent string is NOT a prefix." << endl;
	}

	try {		//case: inserting an empty string into the Trie
		trie1.insert("");
	}
	catch (invalid_argument &excpt) {
		cout << "An exception was successfully thrown and caught: " 
			<< excpt.what() << endl;
	}
	
	//---------------------trie object with one word------------------------------
	string str1 = "prologue";
	trie1.insert(str1);		//tests Trie insert() 

	if (trie1.wordCount() == 1) {
		cout << "wordCount successful." << endl;
	}
	else {
		cout << "wordCount is not right." << endl;
	}

	trie1.insert(str1);	//case: inserting "prologue" twice
	if (trie1.wordCount() == 1) {		
		//wordCount should not change when "prologue" is inserted twice
		cout << "wordCount after duplicate insertion successful." << endl;
	}
	else {
		cout << "wordCount is not right." << endl;
	}

	cout << "---Trie1 should have 1 word.\n" << endl;
	trie1.print();	//tests print() after inserting same word twice

	if (trie1.isPrefix("pro") && !trie1.isPrefix("pre")) {	//tests isPrefix()
		cout << "isPrefix successful" << endl;
	}
	else {
		cout << "Something went wrong" << endl;
	}

	if (trie1.isPrefix("") && trie1.isPrefix("prologue")) {	
		//tests isPrefix() edge conditions
		cout << "isPrefix edge conditions successful: empty and full word" << endl;
	}
	else {
		cout << "Something went wrong" << endl;
	}

	if (trie1.isWord("prologue") && !trie1.isWord("prolang")) {		//tests isWord()
		cout << "isWord successful" << endl;
	}
	else {
		cout << "Something went wrong" << endl;
	}

	if (!trie1.isWord("pro")) {		//tests isWord() edge condition
		cout << "isWord edge condition successful: prefix is not a word." << endl;
	}
	else {
		cout << "Something went wrong" << endl;
	}


	//-----------------Trie object with multiple words all with prefix "pro"--------
	//read from text file

	Trie trie2;		//default ctor
	trie2.loadFromFile("prowords.txt");		//tests loadFromFile()

	try {
		trie2.loadFromFile("doesNotExist.txt");
	}
	catch (std::invalid_argument &excpt) {
		cout << "An exception was succesfully thrown and caught: " 
			<< excpt.what() << endl;
	}

	if (trie2.isWord("prolang") && 
		!trie2.isWord("prologue") &&
		!trie2.isWord("pro") && 
		!trie2.isWord("")) {
		cout << "isWord successful" << endl;
	}
	else {
		cout << "Something went wrong" << endl;
	}

	if (trie2.isPrefix("pro") && 
		trie2.isPrefix("prolang") &&
		trie2.isPrefix("") && 
		!trie2.isPrefix("pre")) {
		cout << "isPrefix successful" << endl;
	}
	else {
		cout << "Something went wrong" << endl;
	}

	cout << "---Trie2 should have 7 words in alphabetical order.\n" << endl;
	trie2.print();		//tests print() [in alphabetical order]

	if (trie2.wordCount() == 7) {
		cout << "WordCount successful after loadFromFile into empty Trie." << endl;
	}
	else {
		cout << "WordCount not successful after loadFromFile into empty Trie." << endl;
	}
//-----------------------Compiler provided Big 3--------------------
	Trie trie3(trie1);	//tests copy ctor

	if (trie3.wordCount() == 1) {
		cout << "WordCount correct for copy ctor" << endl;
	}
	else {
		cout << "WRONG: WordCount incorrect for copy ctor." << endl;
	}

	cout << "---Trie3 should have 1 word.\n" << endl;
	trie3.print();

	if (!trie3.isWord("prolang") &&
		trie3.isWord("prologue") &&
		!trie3.isWord("pro") &&
		!trie3.isWord("")) {
		cout << "isWord after copy ctor successful" << endl;
	}
	else {
		cout << "Something went wrong" << endl;
	}

	if (trie3.isPrefix("pro") &&
		trie3.isPrefix("prologue") &&
		trie3.isPrefix("") &&
		!trie3.isPrefix("pre")) {
		cout << "isPrefix after copy ctor successful" << endl;
	}
	else {
		cout << "Something went wrong" << endl;
	}

	trie3 = trie2;	//tests assignment operator

	if (trie3.wordCount() == 7) {
		cout << "WordCount correct for assignment operator." << endl;
	}
	else {
		cout << "WRONG: WordCount incorrect for assignment operator." << endl;
	}

	cout << "---Trie3 should have 7 words in alphabetical order.\n" << endl;
	trie3.print();

	if (trie3.isWord("prolang") &&
		!trie3.isWord("prologue") &&
		!trie3.isWord("pro") &&
		!trie3.isWord("")) {
		cout << "isWord after assignment operator successful" << endl;
	}
	else {
		cout << "Something went wrong" << endl;
	}

	if (trie3.isPrefix("pro") &&
		trie3.isPrefix("prolang") &&
		trie3.isPrefix("") &&
		!trie3.isPrefix("pre")) {
		cout << "isPrefix after assignment operator successful" << endl;
	}
	else {
		cout << "Something went wrong" << endl;
	}

	//-------------loadFromFile into a Trie that is not empty--------
	trie3.loadFromFile("prowords.txt");	//insert same words again

	if (trie3.wordCount() == 7) {
		cout << "WordCount correct after loadFromFile twice." << endl;
	}
	else {
		cout << "WRONG: WordCount incorrect for loadFromFile twice." << endl;
	}

	cout << "---Trie3 should still have 7 words in alphabetical order.\n" << endl;
	trie3.print();	//print() after inserting duplicate words

	trie1.loadFromFile("prowords.txt");	//insert 7 additional words into 1-word Trie

	if (trie1.wordCount() == 8) {
		cout << "WordCount correct after loadFromFile into non-empty Trie." << endl;
	}
	else {
		cout << 
		"WRONG: WordCount incorrect after loadFromFile into non-empty Trie." << endl;
	}

	cout << "---Trie1 should have 8 words in alphabetical order.\n" << endl;
	trie1.print();

	//-------------insert non-existing word into a Trie that is not empty--------
	trie2.insert("yifan");

	if (trie2.wordCount() == 8) {
		cout << "wordCount successful." << endl;
	}
	else {
		cout << "wordCount is not right." << endl;
	}

	cout << "---Trie2 should have 8 words in alphabetical order.\n" << endl;
	trie2.print();	

	cout << "\nEnd of tests. Press Enter to exit.";
	cin.get();
}