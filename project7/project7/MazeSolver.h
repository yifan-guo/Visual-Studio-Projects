// File name: MazeSolver.h
// Author: Yifan Guo
// userid: guoy5
// Email: yifan.guo@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 07 
// Honor Statement:I pledge to the honor statement.
// Description:   
// Last Changed:  11/12/15


#ifndef MAZESOLVER_H
#define MAZESOLVER_H
#include "Maze.h"
#include "PointAgenda.h"
class MazeSolver {
private:
	Maze& myMaze;
	PointAgenda& myAgenda;
	int count;	//how many points are visited

	// Private helper function to ensure x & y are within the maze (edges included)
	// pre: myMaze references a maze
	// post: returns true if (x,y) is within maze, false otherwise
	bool insideMaze(int x, int y) const;

	// Private helper function to add a Point to the agenda
	// checks if (1) cdts are within the maze and (2) represent an open location
	// only adds the point if both of the above conditions are true
	// pre: agenda exists
	// post: adds point with cdts (x,y) to the agenda 
	void addNeighbor(int x, int y);

public:
	// Class Constructor
	// pre: parameter objects, newMaze & newAgenda, exist
	// post: Object is initialized to reference the parameters
	MazeSolver(Maze& newMaze, PointAgenda& newAgenda);

	// explores the maze
	// pre: maze has one start and one stop location
	// post: returns true if maze is solveable, false if not
	// post: lists all visited points and prints number of unique points visited
	// if trace is true, visually shows the progress of the maze exploration 
	bool solve(bool trace);
};


#endif /* ifndef */