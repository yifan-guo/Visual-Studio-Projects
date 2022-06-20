// File name: Boggle.cpp
// Author: Yifan Guo
// Userid: guoy5
// Email: yifan.guo@vanderbilt.edu	
// Class: CS 2201
// Assignment Number: 10
// Honor Statement: I pledge to the honor statement.
// Description:  
// Last Changed: 12/2/15

#include <iostream>
#include <fstream>
#include "Boggle.h"
using namespace std;

// Default ctor. Loads a fully configured board from input file.
//pre:	must have "boggle-in.txt" to load board configuration && 
//		must have "ospd.txt" to read list of acceptable words
Boggle::Boggle() :	isUsed(), 
					playerScore(0), 
					computerScore(0)
{
	initiateBoard("boggle-in.txt");
	readOspd("ospd.txt");
}



//Computer finds all words NOT found by the user on the Boggle board, 
//prints list of found words, word count, and computer's score
void Boggle::solve() {

	for (size_t i = 0; i < BOARD_SIZE; i++) {
		for (size_t j = 0; j < BOARD_SIZE; j++) {
			findWords("", i, j);	
		}
	}
	
	printComputerWords();
}

//reads the list of acceptable words into the lexicon
//pre:	file contains only lowercase words
//post: throws invalid_argument exception if file could not be opened
void Boggle::readOspd(const string& filename) {

	/*string str;
	ifstream file(filename.c_str());
	if (!file) {
		cout << "Unable to open file. Press Enter to exit." << endl;
		getline(cin, str);
		cin.get();
		exit(99);
	}

	while (file >> str) {
		lexicon.insert(str);
	}

	file.close();*/
	lexicon.loadFromFile(filename);
}

//Displays the Boggle board on the output console
//pre:	board must be initialized
void Boggle::displayBoard()
{
	for (int row = 0; row < BOARD_SIZE; row++) {
		for (int col = 0; col < BOARD_SIZE; col++) {
			cout << myBoard[row][col]; 
		}
		cout << endl;
	}
}

//reads the Boggle board configuration from the file parameter
//and initializes myBoard
//pre:	file contains only lowercase letters
void Boggle::initiateBoard(const string& filename) {

	string str;
	ifstream file(filename.c_str());

	if (!file) {
		cout << "Unable to open file. Press Enter to exit." << endl;
		getline(cin, str);
		cin.get();
		exit(99);
	}

	for (size_t i = 0; i < BOARD_SIZE; i++) {
		for (size_t j = 0; j < BOARD_SIZE; j++) {
			file >> myBoard[i][j];
		}
	}

	file.close();
}

//pre:	str contains only lowercase letters, or is empty
//		cdts (x,y) are inside the Board
//post:	computer finds all possible words with the prefix str 
//		concatenated with the char at the current board position
//		NOT found by user, inserts them into a lexicon, and
//		updates computer's score
void Boggle::findWords(const string& str, int x, int y) {	

	string tmp = str + myBoard[x][y];
	if (lexicon.isPrefix(tmp)) {
		isUsed[x][y] = true;	
		//check if tmp is a word to be inserted in the computer's lexicon
		if (tmp.length() >= MIN_WORD_LENGTH && lexicon.isWord(tmp)
				&& !userFoundWords.isWord(tmp)) {
			if (!computerFoundWords.isWord(tmp)) {
				computerScore += tmp.length() - MIN_SCORE_LENGTH;
			}
			computerFoundWords.insert(tmp);
		}
		//look through neighbors
		for (int row = LEFT; row <= RIGHT; row++) {
			for (int col = TOP; col <= BOTTOM; col++) {
				if (isValidNeighbor(x + row, y + col)) {
					findWords(tmp, x + row, y + col);
				}
			}
		}
		isUsed[x][y] = false;
	}
}

//post:	returns true if board position has not already been used && is in bounds
//		else returns false
bool Boggle::isValidNeighbor(int x, int y) {
	return (!isUsed[x][y] && x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE);
}

//---------------EXTRA CREDIT-----------------

//keeps a lexicon of all words found by user && lexicon of words NOT found by the user
//pre:	user can only input lowercase words
//		EOF is denoted by 'Q' or 'q'
//post:	list of user found words is printed with its count && score
//		list of computer found words is printed with its count && score
//		warning message given for unacceptable words
void Boggle::playAgainstComputer() {
	displayBoard();
	processUsersWords();
	printUserWords();
	//computer finds and prints the words not found by the user, wordCount, and score
	solve();	

}

//reads all words typed by the user until a 'Q' or 'q' is input
//pre:	user can only type in lowercase words
//post:	inserts valid words (that appear on the board) in a lexicon
//		warning message given for unacceptable words
void Boggle::processUsersWords() {
	string str;
	while (cin >> str && str != "Q" && str != "q") {
		if (str.length() >= MIN_WORD_LENGTH && lexicon.isWord(str) && isWordPresent(str)) {
			if (!userFoundWords.isWord(str)) {
				playerScore += str.length() - MIN_SCORE_LENGTH;
			}
			userFoundWords.insert(str);
		}
		else {
			cout << str << " is not an acceptable word." << endl;
		}
	}
}

//prints user found words, count, and score
void Boggle::printUserWords() {
	cout << "You found the following words:" << endl;
	cout << "===========" << endl;
	userFoundWords.print();
	cout << "=========" << endl;
	cout << "You found: " << userFoundWords.wordCount() << " words." << endl;
	cout << "Your score was: " << playerScore << endl;
}

//prints words NOT found by user, count, and score
void Boggle::printComputerWords() {
	cout << "The computer found the following words:" << endl;
	cout << "===========" << endl;
	computerFoundWords.print();
	cout << "===========" << endl;
	cout << "The computer found " << computerFoundWords.wordCount() << " words." << endl;
	cout << "The computer's score: " << computerScore << endl;
}

//pre:	str contains only lowercase letters
//post:	returns true if word is on the Board, else returns false
bool Boggle::isWordPresent(const string& str) {

	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (myBoard[i][j] == str[0]) {		//first char is on board
				if (lookforWord(str.substr(1), i, j)) {
					return true;
				}
			}
		}
	}
	return false;
}

//looks for str in the neighborhood of board position (x,y)
//pre:	cdts (x,y) are on the Board
//		str is only lowercase letters 
//post:	returns true if str is found, else false
bool Boggle::lookforWord(const string& str, int x, int y) {
	if (str == "") {
		return true;
	}
	isUsed[x][y] = true;
	//look through neighbors
	for (int row = LEFT; row <= RIGHT; row++) {
		for (int col = TOP; col <= BOTTOM; col++) {
			if (isValidNeighbor(x + row, y + col) && myBoard[x+row][y+col] == str[0]) {
				if (lookforWord(str.substr(1), x + row, y + col)) {
					isUsed[x][y] = false;
					return true;
				}
			}
		}
	}
	isUsed[x][y] = false;
	return false;
}