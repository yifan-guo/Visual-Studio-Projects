// File name: Sudoku.h
// Author: Yifan Guo
// VUnetid: guoy5
// Email: yifan.guo@vanderbilt.edu
// Class: CS270
// Date: 9/17/16
// Honor statement: I pledge to the honor statement.
// Project Number: 01

#ifndef SUDOKU_H
#define SUDOKU_H

#include <string>
using namespace std;

const int LEFT = -1;
const int RIGHT = 1;
const int TOP = -1;
const int BOTTOM = 1;
const size_t BOARD_SIZE = 9;

class Sudoku {
public:
	// creates an empty Sudoku puzzle (all entries set to 0)
	Sudoku();

	// initializes the Sudoku object with a new puzzle
	// from the specified file
	void loadFromFile(string filename);

	// returns true if a solution was found
	// otherwise returns false
	bool solve();

	// prints the contents of the Sudoku puzzle
	void print() const;

	// returns true iff the contents of this puzzle 
	// match that of the given puzzle exactly
	// otherwise, return false
	bool equals(const Sudoku &other) const;

private:
	size_t myPuzzle[BOARD_SIZE][BOARD_SIZE];

	// find next unassigned square scanning from left to right,
	// top to bottom, if any exist
	void findUnassignedSquare(int *x, int *y);

	// assign the value x at (row, col) in the Sudoku board
	bool assignHelper(int row, int col, size_t value);

	// check if (row, col) are inside the bounds of the Sudoku puzzle
	bool isInBounds(int row, int col);

	// helper function to determine what grid of 9 squares
	// in the puzzle to look at. This ensures that the assigned value
	// at (row, col) does not conflict with any number in the grid
	void setBounds(int x, int *bound1, int *bound2);

	// returns true if placing x at (rol, col) is legal
	// i.e. neither the row or column or enclosing grid of 9 
	// contains the same number as x
	bool isValidAssignment(int row, int col, size_t x);

	// returns true if (row, col) is zero
	// otherwise, returns false
	bool isAssigned(int row, int col);
};

#endif