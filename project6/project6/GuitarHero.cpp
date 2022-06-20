// File name: GuitarHero.cpp
// Author: Yifan Guo	
// userid: guoy5
// Email: yifan.guo@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 06
// Description:  
// Honor statement: I pledge to the honor statement.
// Last Changed: 11/5/15

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include "GuitarString.h"
using namespace std;


const double CONCERT_A = 440.0;
const int NUM_STRINGS = 37;
const double STEP = (double)1/((double)SAMPLE_RATE);   //SAMPLE_RATE declared in GuitarString.h


// open input and output files
// pre: user is prepared to enter file names at the keyboard
// post: files have been opened
void openFiles (ifstream &infile, ofstream &outfile);

// If you want to create your own helper functons (highly recommended), declare them
// here and then define them after the main() function.

//sample and tic all strings 
//pre: all strings are initialized, and have more than one sample
//post: all guitar strings are sampled and tic'ed
double sampleAndTic(GuitarString* strings[]);


int main() {

	// create the array of guitar strings (3 octaves)
	GuitarString* strings[NUM_STRINGS];
	for (int i = 0; i < NUM_STRINGS; i++) {
		double factor = pow(2, (i - 24) / 12.0);
		strings[i] = new GuitarString(CONCERT_A * factor);
	}

	//open data file
	ifstream infile;
	ofstream outfile;
	openFiles(infile, outfile);

	cout << "Reading the input file and generating a .dat file for sox" << endl;
	outfile.setf(ios::fixed, ios::floatfield);
	outfile.precision(10);

	//prime the output file 
	string firstLine  = "; Sample Rate 44100";
	string secondLine = "; Channels 1";
	outfile << firstLine << endl;
	outfile << secondLine << endl;


	// your task is to read & process all the data in the input stream "infile", 
	// and create & write the correct data to the output stream "outfile".
	// That work should be done here before the files are closed.
	// Define and use helper functions as needed for good style.

	int value;
	double i = 0;
	ItemType time;
	while (infile >> time >> value) {
		if (i - time >= STEP || value < -1 || value >= NUM_STRINGS) {
			throw std::out_of_range("a value is out of range.");
		}
		
		while (i < time) {
			if (i / 0.5 > 1 && i - (int)(i / 0.5) * 0.5 < STEP) {
				cout << ".";
			}
			//write i and cumulative sample to outfile
			outfile << "  " << i << "\t" << sampleAndTic(strings) << endl;		
			i = i + STEP;
		}
		if (value == -1)
			break;
		strings[value]->pluck();
	}




	// close the files
	infile.close();
	outfile.close();
	cout << "Done." << endl;

	//Clean up all the strings
	for (int i = 0; i < NUM_STRINGS; i++) {
		if(strings[i] != 0)
			delete strings[i];
	}
	return 1;
}

//sample and tic all strings 
//pre: all strings are initialized, and have more than one sample
//post: all guitar strings are sampled and tic'ed
double sampleAndTic(GuitarString* strings[]) {
	double sum = 0;
	for (int i = 0; i < NUM_STRINGS; i++) {
		sum += strings[i]->sample();
		strings[i]->tic();
	}
	return sum;
}

// open input and output files
// pre: user is prepared to enter file names at the keyboard
// post: files have been opened
void openFiles (ifstream &infile, ofstream &outfile)
{

	// open input data file
	string inFileName;
	cout << "Enter the name of the input file: ";
	cin >> inFileName;
	infile.open(inFileName.c_str());
	if (infile.fail()) {
		cout << "Error opening input data file" << endl;
		char junk;
		cout << "press enter to exit";
		junk = cin.get();
		junk = cin.get();
		exit(1);
	}
	// open output data file
	string outFileName;
	cout << "Enter the name of the output file: ";
	cin >> outFileName;
	outfile.open(outFileName.c_str());
	if (outfile.fail()) {
		cout << "Error opening output data file" << endl;
		char junk;
		cout << "press enter to exit";
		junk = cin.get();
		junk = cin.get();
		exit(1);
	}

}

