// File name: GuitarString.h
// Author: Yifan Guo	
// userid: guoy5
// Email: yifan.guo@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 06
// Description:  
// Honor statement: I pledge to the honor statement.
// Last Changed: 11/5/15

#ifndef GUITARSTRING_H
#define GUITARSTRING_H

#include "DblQueue.h"
using namespace std;

const int SAMPLE_RATE = 44100;
const double DECAY_FACTOR = 0.996;

class GuitarString
{
  private :

	  DblQueue ringBuffer;
	  int count;		//number of times tic was called
	  double freq;	

  public:
	// create a guitar string representing the given frequency
	GuitarString(double frequency);

	// pluck the string - excite with white noise between -0.5 and 0.5
	void pluck();

	// advance the simulation one step
	void tic();
	
	// current sample
	double sample() const;

	// number of time steps = number of calls to tic()
	int getTime() const;

	// return the frequency of the string
	double getFrequency() const;

};

#endif
