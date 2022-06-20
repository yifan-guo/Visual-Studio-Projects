// File name: GuitarString.cpp
// Author: Yifan Guo
// userid: guoy5
// Email: yifan.guo@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 06
// Description:  
// Honor statement: I pledge to the honor statement
// Last Changed: 11/5/15

#include <random>
#include <chrono>
#include "GuitarString.h"
using namespace std;

// create a guitar string representing the given frequency
GuitarString::GuitarString(double frequency): count(0), freq(frequency) {
	if (frequency <= 0) {
		throw std::invalid_argument("Frequency is not positive.");
	}
	int N = (int) ((SAMPLE_RATE / frequency) + 0.5);	//round
	ItemType tmp = 0;
	for (int i = 0; i < N; i++) {	
		ringBuffer.enqueue(tmp);		//enqueue N zeros
	}
}

// pluck the string - excite with white noise between -0.5 and 0.5
void GuitarString::pluck() {
	unsigned seed = (unsigned)std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<double> distribution(-0.5, 0.5);
	//size of Queue when enqueued with N zeros
	size_t N = ringBuffer.size();	

	for (size_t i = 0; i < N; i++) {
		ItemType num = distribution(generator);
		ringBuffer.dequeue();
		ringBuffer.enqueue(num);
	}
}

// advance the simulation one step
//what if you only have 1 sample in the queue??? (error)
void GuitarString::tic() {	
	ItemType front = ringBuffer.front();
	ringBuffer.dequeue();
	//cast to ItemType???
	ItemType add = DECAY_FACTOR * 0.5 * (front + ringBuffer.front());	
	ringBuffer.enqueue(add);
	count++;	
}

// current sample
//what if ringBuffer is empty??? (error)
double GuitarString::sample() const {	
	return ringBuffer.front();
}

// number of time steps = number of calls to tic()
int GuitarString::getTime() const {
	return count;
}

// return the frequency of the string
double GuitarString::getFrequency() const {
	return freq;
}