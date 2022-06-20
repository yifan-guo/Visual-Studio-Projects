// File name: WordCount.cpp
// Author: Yifan Guo
// Userid: guoy5
// Email: yifan.guo@vanderbilt.edu	
// Class: CS 2201
// Assignment Number: 08
// Honor Statement: I pledge to the honor statement.
// Description:  
// Last Changed: 11/18/15


#include <cstdlib>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;



const double MINIMUM_APPEARANCE = 0.001;
const int STEM_LENGTH = 6;

typedef set<string> WordSet;
typedef map<string,int> WordCountMap;


// function prototypes
WordSet readCommonWords(const string & fname);

WordCountMap processFile(const string & fname, const WordSet & common);

double compareTexts(WordCountMap & firstDoc, WordCountMap & secondDoc, const string & fname);



/* main */
int main()
{
	string commonFile = "texts/common.txt";
	string fin1, fin2, fout, str;

	do {
		cout << "Enter name of the first input file: ";
		cin >> fin1;
		fin1 = "texts/" + fin1;

		cout << "Enter name of the second input file: ";
		cin >> fin2;
		fin2 = "texts/" + fin2;

		cout << "Enter name of the output file: ";
		cin >> fout;
		fout = "texts/" + fout;

		WordSet common = readCommonWords(commonFile);

		WordCountMap first = processFile(fin1, common);
		WordCountMap second = processFile(fin2, common);

		double dist = compareTexts(first, second, fout);

		cout << "Vector Distance: " << dist << endl;

		cout << "Would you like to run the program again (Y|N): ";
		cin >> str;
	} while (tolower(str[0]) == 'y');


    return 0;
}

/* readCommonWords
 * This method reads words from a given file and places them
 * into a WordSet, which it returns.
 *
 * pre:  a file name with 1 word per line, words all in lower case
 * post: all words int the file are placed in the WordSet
 */
WordSet readCommonWords(const string & fname)
{
    WordSet ret;

	string str;
	ifstream file(fname.c_str());
	//Do error checking here
	if (!file) {
		cout << "Unable to open file. Press enter to exit program.";
		getline(cin, str); //consume existing line
		cin.get();	//get the key press
		exit(1);
	}
	while (file >> str) {
		ret.insert(str);	//insert string into the set of strings
	}

	file.close();	//close the file
    return ret;
}



/* processFile
 * This function reads in all words from the given file
 * after reading a word it converts it to lower case,
 * removes non alphabetic characters and stems it to STEM_LENGTH.
 * If the resulting word is considered common it is ignored.
 * Otherwise, the count in the map that matches the word is
 * is incremented.
 *
 * pre:  the name of a text file and a set of words to be ignored.
 * post: The file has been read; a map of cleansed words is created and returned
 *       
 */
WordCountMap processFile(const string & fname, const WordSet & common)
{
    WordCountMap ret;

	string str;
	ifstream file(fname.c_str());
	if (!file) {
		cout << "Unable to open file. Press enter to exit program.";
		getline(cin, str);	//consume existing line
		cin.get();	//get the key press
		exit(1);
	}
	
	while (file >> str) {
		string tmp = "";	
		for (size_t i = 0; i < str.length(); i++) {
			if (isupper(str[i])) {	//convert to lowercase
				tmp = tmp + (char) tolower(str[i]);
			}
			else if (islower(str[i])) {
				tmp = tmp + str[i];
			}
		}
		tmp = tmp.substr(0, 6);
		if (tmp.length() != 0) {		//is not empty
			if (common.find(tmp) == common.end() ) {	//is not a common word

				ret[tmp]++;		
			}
		}	
	}

	file.close();
	return ret;
}



/* compareTexts
* Compares the count maps of 2 texts.
* The result returned is the euclidean distance
* where each word with a percentile appearance greater than
* MINIMUM_APPEARANCE counts as a dimesion of the vectors.
* (they still count toward the full sum used to calculate
*  percentile appearance)
*
* This method also prints out the results to a file using the following
* format (start and end tags added for clarity):
* / -- start example output --/
* word1:	distance = x.xxxxxe-xxx	(score1 = y.yyyyyyyy, score2 = z.zzzzzzz)
* word2:	distance = x.xxxxxe-xxx	(score1 = y.yyyyyyyy, score2 = z.zzzzzzz)
* ...
* wordN:	distance = x.xxxxxe-xxx	(score1 = y.yyyyyyyy, score2 = z.zzzzzzz)
*
* Counted words in document 1 = xxxx
* Counted words in document 2 = xxxx
*
* Vector Distance: dist
* /-- end example output --/
*
* word1-wordN are all words whose comparison is include in the final sum.
*             these words are ordered alphabetically.
* distance values are the square of the difference of the percentile
*                         scores from the two maps.
* score1 & score2 values are the scores from the two maps.
* dist is the final distance that is also returned,
*    it is the square root of the sum of all the individual distances.
* To help line things up, there is a tab character after the ":" and another
*    before the "(" on the line for each word.
*
* pre:  two maps of texts to be compared and the name of an output file
* post: returns the squared euclidean distance of the two files
*       if the output file cannot be opened, the method prints
*       an error mesage and exits the program.
*/
double compareTexts(WordCountMap & firstDoc, WordCountMap & secondDoc, const string & fname)
{
	ofstream file(fname.c_str());	//open output file
	WordCountMap::iterator it1, it2;
	double sum1 = 0, sum2 = 0;
	for (it1 = firstDoc.begin(); it1 != firstDoc.end(); it1++) {	//O(n) time
		sum1 += it1->second;
	}
	for (it2 = secondDoc.begin(); it2 != secondDoc.end(); it2++) {	//O(n) time
		sum2 += it2->second;
	}
	double score1 = 0, score2 = 0, vectorDistance = 0, totalDistance = 0;
	for (it1 = firstDoc.begin(); it1 != firstDoc.end(); it1++) {	//O(n) time
		//if key is contained in both maps
		if (secondDoc.find(it1->first) != secondDoc.end()) {	//lg(n)
			score1 = (double) it1->second / sum1;
			score2 = (double) secondDoc.find(it1->first)->second / sum2;
			if (score1 > MINIMUM_APPEARANCE && score2 > MINIMUM_APPEARANCE) {
				vectorDistance = pow(score1 - score2, 2);
				totalDistance += vectorDistance;
				file << it1->first << ":\t" << "distance = " << vectorDistance 
					<< "\t" << "(score1 = " << score1 
					<< ", score2 = " << score2 << ")" << endl;
			}
		}
	}
	file << "\n" << "Counted words in document 1 = " << sum1 << endl;
	file << "Counted words in document 2 = " << sum2 << endl;
	totalDistance = pow(totalDistance, 0.5);	//MODIFIED totalDistance
	file << "\n" << "Vector Distance: " << totalDistance << "\n" << endl;
	file.close();	//close the file
	return totalDistance;   // replace with your return value
}
