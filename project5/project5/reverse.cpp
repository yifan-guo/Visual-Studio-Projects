// Name: Yifan Guo
// Email: yifan.guo@vanderbilt.edu
// VUnetid: guoy5
// Class: CS 2201
// Date: 10/26/15
// Honor statement: I pledge to the honor statement. 
// Description:
// Reverse a sound data file by reading in all the data samples,
// pushing them onto a stack, and then creating a new sound data
// file while popping values off the stack.

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "DblStack.h"
using namespace std;


// open input and output files
// pre: user is prepared to enter file names at the keyboard
// post: files have been opened
void openFiles (ifstream &infile, ofstream &outfile);



int main ()
{

   // open input & output data files
   ifstream infile;
   ofstream outfile;
   openFiles(infile, outfile);

   cout << "Reading the input file..." << endl;

   // read in the data on the first line of the file
   string firstLine, secondLine;

   getline(infile,firstLine);    // read in the first line
   getline(infile,secondLine);   // read in the second line
   //cout << "DEBUG: First line : " << firstLine << endl;
   //cout << "DEBUG: Second line: " << secondLine << endl;


   // TO DO -- your job to read the rest of the input file and
   // process the data. Hint: use the extraction operator.
 
   DblStack time;
   DblStack value;
   ItemType timestamp, val;
   while (infile >> timestamp && infile >> val) {
	   time.push(timestamp);
	   value.push(val);
   }

   ItemType size = value.size();

   DblStack time_reversed;
   ItemType timestamp_reversed;
   while (!time.isEmpty()) {
	   timestamp_reversed = time.top();
	   time.pop();
	   time_reversed.push(timestamp_reversed);
   }


   cout << "There were " << size << " samples in the file." << endl;
   cout << "Creating output file... wait for Done message." << endl;


   //
   // Now we are ready to output the data values to output file.
   // But first, we need to output the header lines
   //
   outfile << firstLine << endl;
   outfile << secondLine << endl;
   

   // TO DO -- your job to write the rest of the output file.
   // Each line should start with two blanks, then the time-step
   // value, then a single tab character \t, then the sound data value.

   while (!time_reversed.isEmpty()) {
	   timestamp_reversed = time_reversed.top();
	   time_reversed.pop();
	   val = value.top();
	   value.pop();
	   outfile << "  " << timestamp_reversed << "\t" << val << endl;
   }


   // close the files
   infile.close();
   outfile.close();

   cout << "Done." << endl;

   char junk;
   cout << "press enter to exit";
   junk = cin.get();
   junk = cin.get();

}


// open input and output files
// pre: user is prepared to enter file names at the keyboard
// post: files have been opened
void openFiles(ifstream &infile, ofstream &outfile)
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

