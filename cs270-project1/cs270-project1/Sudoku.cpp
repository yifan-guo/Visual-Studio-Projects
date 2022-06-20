// File name: Sudoku.cpp
// Author: Yifan Guo
// VUnetid: guoy5
// Email: yifan.guo@vanderbilt.edu
// Class: CS270
// Date: 9/17/16
// Honor statement: I pledge to the honor statement.
// Project Number: 01

#include "Sudoku.h"
#include <iostream>		//for cin and cout
#include <fstream>		//for ifstream
using namespace std;

// creates an empty Sudoku puzzle (all entries set to 0)
Sudoku::Sudoku() {
	for (size_t i = 0; i < BOARD_SIZE; i++) {
		for (size_t j = 0; j < BOARD_SIZE; j++) {
			myPuzzle[i][j] = 0;
		}
	}
}

// initializes the Sudoku object with a new puzzle
// from the specified file
// pre: filename refers to a file in the working directory
// re-initializes the file (if it exists)
// otherwise exits with status code 99
void Sudoku::loadFromFile(string filename) {
	string str;
	ifstream file(filename.c_str());

	if (!file) {
		cout << "Unable to open file. Press Enter to exit. " << endl;
		getline(cin, str);
		cin.get();
		exit(99);
	}

	for (size_t i = 0; i < BOARD_SIZE; i++) {
		for (size_t j = 0; j < BOARD_SIZE; j++) {
			file >> myPuzzle[i][j];
		}
	}

	file.close();
}

// find next unassigned square scanning from left to right,
// top to bottom, if any exist
// pre: x and y point to values initialized to -1 (no value found so far)
// post: the values that x and y point to will be assigned
//		the cdts of the next unassigned square
//		or remain -1, if none exist
void Sudoku::findUnassignedSquare(int *x, int *y) {
	for (int i = 0; i < (int) BOARD_SIZE; i++) {
		for (int j = 0; j < (int) BOARD_SIZE; j++) {
			if (!isAssigned(i, j)) {
				*x = i;
				*y = j;
				break;
			}
		}
		if (*x != -1 && *y != -1) {
			// found an unassigned square
			break;
		}
	}
}

// assign the value x at (row, col) in the Sudoku board
// pre: row and col are in bounds
bool Sudoku::assignHelper(int row, int col, size_t x) {
	myPuzzle[row][col] = x;		// try the value in that spot
	int next_x = -1;
	int next_y = -1;

	// find next unassigned square (next_x, next_y)
	findUnassignedSquare(&next_x, &next_y);

	if (next_x == -1 && next_y == -1) {		//all squares are validly assigned
		return true;
	}

	// assign next unassigned square
	bool assigned = false;
	// range of values for Sudoku are always 1 through BOARD_SIZE
	for (size_t value = 1; value <= BOARD_SIZE; value++) {
		if (isValidAssignment(next_x, next_y, value) 
			&& assignHelper(next_x, next_y, value)) {
			assigned = true;
			break;
		}
	}
	if (!assigned) {		
		// no valid assignment possible for (row + i, col + j)
		// need to backtrack
		myPuzzle[row][col] = 0;
		return false;
	}
	return true;	// valid legal value assignment to (row, col)
}

// returns true if a solution was found
// otherwise returns false
// pre: all assigned values in myPuzzle are valid
bool Sudoku::solve() {
	int start_x = -1;
	int start_y = -1;

	// find first unassigned square, if any
	findUnassignedSquare(&start_x, &start_y);

	if (start_x == -1 && start_y == -1) {
		// no unassigned squares exist
		// and all squares are validly assigned (pre-condition)
		return true;
	}

	bool assigned = false;
	// assigned value to unassigned square
	// range of values for Sudoku are always 1 through BOARD_SIZE
	for (size_t value = 1; value <= BOARD_SIZE; value++) {
		if (isValidAssignment(start_x, start_y, value) 
			&& assignHelper(start_x, start_y, value)) {
			// try the value in that spot
			assigned = true;
			break;
		}
	}
	if (!assigned) {
		// no valid assignment possible for (i, j)
		return false;
	}
	return true;
}

// check if (row, col) are inside the bounds of the Sudoku puzzle
bool Sudoku::isInBounds(int row, int col) {
	return (row >= 0 && row < (int) BOARD_SIZE && col >= 0 && col < (int) BOARD_SIZE);
}

// returns true if (row, col) is zero
// otherwise, returns false
// pre: (row, col) must be in bounds
bool Sudoku::isAssigned(int row, int col) {
	return myPuzzle[row][col] != 0;
}

// helper function to determine what grid of 9 squares
// in the puzzle to look at. This ensures that the assigned value
// at (row, col) does not conflict with any number in the grid
// pre: x is either the row or column cdt of the assigned value
// post: if x is row cdt, then assign LOWER and UPPER_BOUND
// post: if x is col cdt, then assign LEFT and RIGHT_BOUND
void Sudoku::setBounds(int x, int *bound1, int *bound2) {
	const int LOWEST_DIVIDER = 0;
	const int MIDDLE_DIVIDER = 3;
	const int UPPER_DIVIDER = 6;

	if (x < MIDDLE_DIVIDER) {
		*bound1 = LOWEST_DIVIDER;
		*bound2 = MIDDLE_DIVIDER;
	}
	else if (x < UPPER_DIVIDER) {
		*bound1 = MIDDLE_DIVIDER;
		*bound2 = UPPER_DIVIDER;
	}
	else {		// x >= UPPER_DIVIDER
		*bound1 = UPPER_DIVIDER;
		*bound2 = (int) BOARD_SIZE;
	}
}

// returns true if placing x at (rol, col) is legal
// i.e. neither the row or column or enclosing grid of 9 
// contains the same number as x
// pre: row and col are in bounds
// pre: (row, col) are the cdts of the square assigned value x
bool Sudoku::isValidAssignment(int row, int col, size_t x) {
	//if cdts (row, col) are within bounds
	if (isInBounds(row, col)) {
		//ensure that no other square in the same column has the same value as x
		for (size_t i = 0; i < BOARD_SIZE; i++) {
			if (i != (size_t) row && myPuzzle[i][col] == x) {
				return false;
			}
		}
		//ensure that no other square in the same row has the same value as x
		for (size_t j = 0; j < BOARD_SIZE; j++) {
			if (j != (size_t) col && myPuzzle[row][j] == x) {
				return false;
			}
		}
		// ensure that no other square in the enclosing grid of 9 
		// has the same value as x
		int LOWER_BOUND = 0;
		int UPPER_BOUND = 0;
		int LEFT_BOUND = 0;
		int RIGHT_BOUND = 0;
		//set the lower bound and upper bound
		setBounds(row, &LOWER_BOUND, &UPPER_BOUND);		
		//set the left and right bound
		setBounds(col, &LEFT_BOUND, &RIGHT_BOUND);

		for (int i = LOWER_BOUND; i < UPPER_BOUND; i++) {
			for (int j = LEFT_BOUND; j < RIGHT_BOUND; j++) {
				//check each square (except for the one x is placed in)
				//to see if x is already taken by another square
				//in the grid
				if (!(i == row && j == col) && myPuzzle[i][j] == x) {
					return false;
				}
			}
		}
		return true;
	}
	return false;		//cdts are not within bounds
}

// prints the contents of the Sudoku puzzle
void Sudoku::print() const {
	size_t row_count = 0;
	const size_t PRINT_SEPARATORS_1 = 3;
	const size_t PRINT_SEPARATORS_2 = 6;
	for (size_t row = 0; row < BOARD_SIZE; row++, row_count++) {
		if (row_count == PRINT_SEPARATORS_1 || row_count == PRINT_SEPARATORS_2) {
			//print out dashes and +'s
			cout << "------+-------+------" << endl;
		}
		size_t column_count = 0;		//reset the column_count
		for (size_t col = 0; col < BOARD_SIZE; col++, column_count++) {
			if (column_count == PRINT_SEPARATORS_1 
				|| column_count == PRINT_SEPARATORS_2) {
				//print out pipes
				cout << "| ";
			}
			cout << myPuzzle[row][col] << " ";
		}
		cout << endl;			//print new line for next row
	}
}

// returns true iff the contents of this puzzle 
// match that of the given puzzle exactly
// otherwise, return false
// pre: other puzzle is initialized
bool Sudoku::equals(const Sudoku &other) const {
	for (size_t row = 0; row < BOARD_SIZE; row++) {
		for (size_t col = 0; col < BOARD_SIZE; col++) {
			if (myPuzzle[row][col] != other.myPuzzle[row][col]) {
				return false;
			}
		}
	}
	return true;
}