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
  private:
    int x;
    int y;
	
  public:
    // Default Constructor
    // post: Initializes x and y to zero
    Point();

    // Alternate Constructor
    // post: Initializes x and y 
    Point(int x, int y);

    // accessor methods
    int getX();
    int getY();

    // Equality operator
    bool operator== (const Point& rhs);

    // insertion operator for output
    friend ostream& operator<< (ostream& os, const Point &p);

};

#endif
