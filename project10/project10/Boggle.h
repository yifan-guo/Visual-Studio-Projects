// File name: Boggle.h
// Author: Yifan Guo
// Userid: guoy5
// Email: yifan.guo@vanderbilt.edu	
// Class: CS 2201
// Assignment Number: 10
// Honor Statement: I pledge to the honor statement.
// Description:  
// Last Changed: 12/2/15

#ifndef BOGGLE_H
#define BOGGLE_H
#include "Trie.h"

const int BOARD_SIZE = 4;
const int LEFT = -1;
const int TOP = -1;
const int RIGHT = 1;
const int BOTTOM = 1;
const int MIN_WORD_LENGTH = 4;
const int MIN_SCORE_LENGTH = 3;		//minimum length of the word before points are added

class Boggle {
private: 
	char myBoard[BOARD_SIZE][BOARD_SIZE];	
	bool isUsed[BOARD_SIZE][BOARD_SIZE];	//whether board position is used more than once
	Trie lexicon;			//lexicon of acceptable words
	Trie computerFoundWords;
	Trie userFoundWords;
	size_t playerScore;
	size_t computerScore;

	//Computer finds all words NOT found by the user on the Boggle board, 
	//prints list of found words, word count, and computer's score
	void solve();

	//reads the list of acceptable words into the lexicon
	//pre:	file contains only lowercase words
	void readOspd(const string& filename);

	//Displays the Boggle board on the output console
	//pre:	board must be initialized
	void displayBoard();

	//reads the Boggle board configuration from the file parameter
	//and initializes myBoard
	//pre:	file contains only lowercase letters
	void initiateBoard(const string& filename);

	//pre:	str contains only lowercase letters, or is empty
	//		cdts (x,y) are inside the Board
	//post:	computer finds all possible words with the prefix str 
	//		concatenated with the char at the current board position
	//		NOT found by user, inserts them into a lexicon, and
	//		updates computer's score
	void findWords(const string& str, int x, int y);
	
	//post:	returns true if board position has not already been used && is in bounds
	//		else returns false
	bool isValidNeighbor(int x, int y);

	//reads all words typed by the user until a 'Q' or 'q' is input
	//pre:	user can only type in lowercase words
	//post:	inserts valid words (that appear on the board) in a lexicon
	//		warning message given for unacceptable words
	void processUsersWords();

	//prints user found words, count, and score
	void printUserWords();

	//prints words NOT found by user, count, and score
	void printComputerWords();

	//pre:	str contains only lowercase letters
	//post:	returns true if word is on the Board, else returns false
	bool isWordPresent(const string& str);

	//looks for str in the neighborhood of board position (x,y)
	//pre:	cdts (x,y) are on the Board
	//		str is only lowercase letters 
	//post:	returns true if str is found, else false
	bool lookforWord(const string& str, int x, int y);

public:
	// Default ctor. Loads a fully configured board from input file.
	//pre:	must have "boggle-in.txt" to load board configuration && 
	//		must have "ospd.txt" to read list of acceptable words
	Boggle(); 

//EXTRA CREDIT: 
//keeps a lexicon of all words found by user && lexicon of words NOT found by the user
//pre:	user can only input lowercase words
//		EOF is denoted by 'Q' or 'q'
//post:	list of user found words is printed with its count && score
//		list of computer found words is printed with its count && score
//		warning message given for unacceptable words
	void playAgainstComputer();
};

#endif

