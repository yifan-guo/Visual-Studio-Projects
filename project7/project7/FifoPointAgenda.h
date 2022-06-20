// File name: FifoPointAgenda.h
// Author: Yifan Guo
// userid: guoy5
// Email: yifan.guo@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 07
// Honor Statement: I pledge to the honor statement.
// Description:  
// Last Changed: 11/10/15


#ifndef FifoPointAgenda_H
#define FifoPointAgenda_H
#include "PointAgenda.h"
#include "Queue_t.h"	
class FifoPointAgenda : public PointAgenda {	
private:
	Queue<Point> agenda;

public:

	// isEmpty (pure virtual)
	// Checks if the agenda is empty
	virtual bool isEmpty() const {
		return agenda.isEmpty();
	}

	// add (pure virtual)
	// adds a Point to the agenda.
	virtual void add(const Point& item) {
		agenda.enqueue(item);
	}

	// remove (pure virtual)
	// removes the next Point from the agenda.
	virtual void remove() {
		agenda.dequeue();	
	}

	// peek (pure virtual)
	// Returns the next Point from the agenda without removing it from the agenda.
	virtual Point peek() const {
		return agenda.front();
	}

	// size (pure virtual)
	// Returns the number of Points in the agenda.
	virtual size_t size() const {
		return agenda.size();
	}
};

#endif

