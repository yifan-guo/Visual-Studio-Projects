// File name: Point.h
// Author: CS201 Instructor
// userid: 
// Email: 
// Class: C201 @ Vanderbilt U.
// Assignment Number:
// Description:  Represent a point via x & y coordinates.
// Last Changed: 8-4-2009

#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class Point
{
public:
	int x;
	int y;
	
	// Class Constructor
    // post: Initializes x and y to zero
    Point();

	// Class Constructor
    // post: Initializes x and y 
	Point(int x,int y);


    // Equality operators
    bool operator== (const Point& rhs) const;
    bool operator!= (const Point& rhs) const;

};

// insertion operator for output
ostream& operator<< (ostream& os, const Point &p);

#endif
