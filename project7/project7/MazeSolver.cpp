// File name: MazeSolver.cpp
// Author: Yifan Guo
// userid: guoy5
// Email: yifan.guo@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 07
// Honor Statement: I pledge to the honor statement.
// Description:  
// Last Changed: 11/12/15  

#include "MazeSolver.h"
#include "Maze.h"
#include <thread>

// Class Constructor
// pre: parameter objects, newMaze & newAgenda, exist
// post: Object is initialized to reference the parameters
MazeSolver::MazeSolver(Maze& newMaze, PointAgenda& newAgenda): 
	myMaze(newMaze), myAgenda(newAgenda), count(0) {

}

// explores the maze
// pre: maze has one start and one stop location
// post: returns true if maze is solveable, false if not
// post: lists all visited points and prints number of unique points visited
// if trace is true, visually shows the progress of the maze exploration 
bool MazeSolver::solve(bool trace) {
	myAgenda.add(myMaze.getStartLocation());
	while (!myAgenda.isEmpty()) {
		Point cur = myAgenda.peek();
		myAgenda.remove();
		if (!myMaze.hasBeenVisited(cur)) {	//explore it
			cout << cur << "->";
			count++;	
			if (cur == myMaze.getEndLocation()) {
				cout << "Solution found!" << endl;
				cout << "Number of nodes visited: " << count << endl;
				return true;		//maze is solveable
			}
			else {		//add neighbors
				addNeighbor(cur.x, cur.y + 1);
				addNeighbor(cur.x, cur.y - 1);
				addNeighbor(cur.x + 1, cur.y);
				addNeighbor(cur.x - 1, cur.y);
			}
			myMaze.markVisited(cur);		//mark it as visited
			if (trace == true) {
#if defined _WIN32
				system("cls");
#elif defined __APPLE__
				system("clear");
#endif
				myMaze.printVisitedMaze();
				this_thread::sleep_for(chrono::milliseconds(100));
			}
		}
		else {}		//has been visited
	}
	cout << "\nEnding point is unreachable." << endl;
	cout << "Number of nodes visited: " << count << endl;
	return false;		//maze is not solveable
}

// Private helper function to ensure x & y are within the maze (edges included)
// pre: myMaze references a maze
// post: returns true if (x,y) is within maze, false otherwise
bool MazeSolver::insideMaze(int x, int y) const
{
	if (y >= 0 && y < myMaze.getNumRows() && x >= 0 && x < myMaze.getNumCols())
	{
		return true;
	}
	else {
		return false;
	}
}

// Private helper function to add a Point to the agenda
// checks if (1) cdts are within the maze and (2) represent an open location
// only adds the point if both of the above conditions are true
// pre: agenda exists
// post: adds point to the agenda 
void MazeSolver::addNeighbor(int x, int y) {
	if (insideMaze(x, y) && myMaze.isOpen(x, y)) {
		Point tmp(x, y);
		myAgenda.add(tmp);
	}
}