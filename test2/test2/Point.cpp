// File name: Point.cpp
// Author: CS201 Instructor
// userid: 
// Email: 
// Class: C201 @ Vanderbilt U.
// Assignment Number:
// Description:  Represent a point via x & y coordinates.
// Last Changed: 8-4-2009


#include "Point.h"
using namespace std;

// Default Constructor
// post: Initializes x and y to zero
Point::Point(): x(0), y(0)
{}

// Alternate Constructor
// post: Initializes x and y 
Point::Point(int xVal, int yVal): x(xVal), y(yVal)
{}


// accessor methods
int Point::getX()
{
    return x;
}

int Point::getY()
{
    return y;
}


// Equality operator
bool Point::operator== (const Point& rhs)
{
    return (x==rhs.x && y==rhs.y);
}


// Friend operator for printing a Point
ostream & operator << (ostream &out, const Point& p)
{
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

