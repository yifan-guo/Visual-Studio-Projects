//*******************************************************
// Header file queens.h for class EightQueens
// author: Roth
//*******************************************************

#ifndef EIGHT_QUEENS_H
#define EIGHT_QUEENS_H


const int BOARD_SIZE = 8; //squares per row or column

class EightQueens
{
public:
	EightQueens(); // Default ctor. Creates any empty board.

    void solve();  // Solve the queens problem.


private:

	enum Square {QUEEN, EMPTY};          //states of square
	Square board[BOARD_SIZE][BOARD_SIZE];//chess board
	
	void clearBoard(); //Sets all squares to empty

	void displayBoard(); //Displays board

	bool placeQueens(int column);
	// Places queens in columns of the board beginning at 
	// the column numbered Column.
	//Precondition: Queens are placed correctly in cols
	// 1 through column-1.
	//Postcondtion: If a solution is found, each column of
	// the board contains one queen and true is returned;
	// otherwise, false is returned (no solution exists for a
	// queen anywhere in the column).

	void setQueen(int row, int column);
	// Sets the square on the board in a given row and column
	// to QUEEN

	void removeQueen(int row, int column);
	// Sets the square on the board in a given row and column
	// to EMPTY

	bool isUnderAttack(int row, int column);
	// Determines whether the square on the board at a given
	// row and column is under attack by any queens
	// in cols 1 through column-1.
	//Precondition: Each col between 1 and column-1 has a
	//queen placed in a square at a specific row.   None of
	//these queens can be attacked by any other queen.
	//Postcondition: If the designated square is under
	// attack, returns true; otherwise, returns false.

}; //end class

#endif
