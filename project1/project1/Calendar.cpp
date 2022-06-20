// File name: Calendar.cpp
// Author: Yifan Guo
// VUnetid: guoy5
// Email: yifan.guo@vanderbilt.edu
// Class: CS201
// Date: 9/28/15
// Honor statement: I pledge to the honor statement.
// Assignment Number: 02
// Description: These methods implement the Calendar class

#include <string>
#include <stdexcept>
#include <cassert>
#include "Calendar.h"
using namespace std;


// Default Constructor
// Create an empty Calendar (one with zero Reminders)
Calendar::Calendar(): 
	maxRem(DEFAULT_MAX), 
	numRem(0), 
	remArr(new Reminder[maxRem])
{
	// add your code here or on initialization list
}

// Alternate constructor
// Create an empty Calendar (one with zero Reminders) but with an array of initSize elements
// Precondition: initSize > 0; throws invalid_argument exception if not the case
Calendar::Calendar(size_t initSize) : 
	maxRem(initSize), 
	numRem(0), 
	remArr(new Reminder[maxRem])
{
	if (initSize <= 0) {
		throw std::invalid_argument("Invalid parameter for maxRem.");
	}
}



// Copy ctor
Calendar::Calendar(const Calendar& rhs) : 
	maxRem(rhs.maxRem), 
	numRem(rhs.numRem), 
	remArr(new Reminder[maxRem])
{
	for (size_t i = 0; i < numRem; i++) {
		remArr[i] = rhs.remArr[i];
	}
}



// Assignment operator
const Calendar& Calendar::operator= (const Calendar& rhs)
{
	if (this == &rhs) {
		return *this;
	}
	Calendar temp(rhs);
	std::swap(maxRem, temp.maxRem);
	std::swap(numRem, temp.numRem);
	std::swap(remArr, temp.remArr);
	return *this;
}


// Destructor
Calendar::~Calendar()
{
	delete []remArr;
	remArr = nullptr;
}



// getNumRem
// Return the total number of Reminders in the Calendar
size_t Calendar::getNumRem() const
{
	return numRem; 
}

// maxSize
// Return the size of the Reminder array
size_t Calendar::maxSize() const
{
	return maxRem;
}


//addRem(const Reminder &r)
//
//Purpose: add/insert a reminder in the array of reminder objects
//Parameters: Reminder r - the reminder to be added
//Returns: size_t – the index position of the inserted reminder
//
//Behavior: 
//1.	In case of the array being empty: insert as the first element
//2.    In case the array is full: double the size of the array and then add the Reminder
//3.	In case of a non-empty array with space available: insert Reminder in sorted order, 
//      shifting other items up to make space
//4.	In case of already existing Reminder with same date: insert new reminder 
//      before (ahead of) the existing one.
//5.	Return the index of the inserted reminder, using zero-based indexing
size_t Calendar::addRem(const Reminder &r)	
{
	if (numRem == 0) {	//insert reminder into empty array
		remArr[numRem] = r;
		numRem++;
		return 0;
	}
	else {			//non-empty calendar
		if (numRem == maxRem) {			//full Calendar
			grow(maxRem * 2);
		}
		if (r <= remArr[0]) {	
			//reminder to be inserted is the most earliest
			size_t shifter = numRem;
			while (shifter > 0) {
				remArr[shifter] = remArr[shifter - 1];
				shifter--;
			}
			remArr[shifter] = r;
			numRem++;
			return shifter;
		}
		else {	
			// reminder to be inserted is either in the middle or at the end 
			//of the partially filled calendar
			size_t index = 0;
			while (index < numRem && r > remArr[index]) {
				index++;
			}
			if (index == numRem) {	
				//reminder to be inserted is the most recent
				remArr[index] = r;
				numRem++;
				return index;
			}
			else {	
			//reminder is to be inserted a particular index
			//of the partially filled array
				size_t shifter = numRem;
				while (shifter > index) {
					remArr[shifter] = remArr[shifter - 1];
					shifter--;
				}
				remArr[index] = r;
				numRem++;
				return index;
			}
		}
	}
}


//getReminder(size_t index) 
//
//Purpose: returns the reminder at the specified index in the Calendar, throw exception if index is bad
//Parameters: size_t index - the index of the desired reminder; using zero-based indexing
//Returns: Reminder - the reminder at the specified index
//
//Behavior:
//1.	If the index is invalid, throw an std::invalid_argument exception
//2.	Otherwise, return the reminder at the specified index
Reminder Calendar::getRem(size_t index) const
{
	if (index >= 0 && index < numRem) {
		Reminder temp = remArr[index];
		return temp;
	}
	else {
		throw std::invalid_argument("Invalid index.");
	}
}



//displayRem()
//
//Purpose: Return a string of all reminders 
//Parameters: None
//Return: string containing all the reminders in sorted order with each reminder followed 
//   immediately by a newline character. Returns an empty string if the Calendar is empty
string Calendar::displayRem() const
{
	string s = "";
	if (numRem == 0) {		//empty calendar
		return s;
	}
	else {
		for (size_t i = 0; i < numRem; i++) {
			s = s + remArr[i].toString() + "\n";
		}
		return s;
	}
}


//displayRem(size_t index)
//
//Purpose: Return a string of the reminder at a particular index in the Calendar
//Parameters: size_t index
//Return: string containing the reminder 
//
//Behavior:
//1.	Returns string containing the reminder at the given index (no newline character added)
//2.	Follows 0-indexing
//3.	If array is empty or the index is invalid, returns an empty string
string Calendar::displayRem(size_t index) const	
{
	if (numRem == 0) {	//empty calendar
		return "";
	}
	else if (numRem != 0 && index >= 0 && index < numRem) {		
		//non-empty calendar with valid index
		return remArr[index].toString();
	}
	else {		//invalid index
		return "";
	}
}


//displayRem(const string& str)
//
//Purpose: Return a string of all reminders whose message matches the provided string
//Parameters: string str - the string we are supposed to check for match
//Return: string containing all the matching reminders, in sorted order, each reminder 
//   followed immediately by a newline character.
//
//Behavior:
//1.	Finds any reminders having its message same as the provided string (in a case 
//      sensitive manner)
//2.	If no match is found, returns an empty string
//3.	If matches are found, append them on the return string in sorted order each followed 
//      by a newline character. 
string Calendar::displayRem(const string& str) const
{
	string s = "";
	for (size_t i = 0; i < numRem; i++) {
		if (remArr[i].getMsg() == str) {
			s = s + remArr[i].toString() + "\n";
		}
	}
	return s;
}


//displayRem(const Date& d)
//
//Purpose: Return a string of all reminders for a given date
//Parameters: Date d - the date we are supposed to check for match
//Return: string containing all the matching reminders, in sorted order, each reminder 
//        followed immediately by a newline character.
//
//Behavior:
//1.	Finds any reminders on the provided date
//2.	If no match is found, returns an empty string
//3.	If matches are found, append them on the return string in sorted order each 
//      followed by a newline character.
//
//Note: see addRem() for the definition of sorted order of Reminders with the same date.
string Calendar::displayRem(const Date& d) const	// searches reminders by date
{
	return displayRem(d, d);
}


//displayRem(const Date& d1, const Date& d2)
//
//Purpose: Displays reminders in a range of two given dates
//Parameters: Date d1, Date d2 (the range of Dates)
//Return: string containing all the matching reminders, in sorted order, each reminder followed 
//        immediately by a newline character.
//
//Behavior:
//1.  If the Calendar contains no dates in the given range, return an empty string
//2.  Create a string containing all the reminders, in sorted order, which are later than or equal to
//    the smaller of the two dates and are earlier than or equal to the larger of the two dates, with
//    each reminder followed immediately by a newline character.
string Calendar::displayRem(const Date& d1, const Date& d2) const
{
	Date earlier = d1;
	Date later = d2;

	if (d1 > d2) {		// if d1 is more recent than d2
		earlier = d2;
		later = d1;
	}
	string s = "";

	for (size_t i = 0; i < numRem; i++) {
		if (remArr[i].getDate() >= earlier && remArr[i].getDate() <= later) {
			s = s + remArr[i].toString() + "\n";
		}
	}
	return s;
}


//findRem(const Date& d)
//
//Purpose: Find first reminder for the given date and return its index
//Parameters: Date d, the date to search for
//Return: int value containing the index of the first reminder with the specified date,
//        or -1 if no reminders with that date exist
int Calendar::findRem(const Date& d) const
{
	int index = -1;
	for (int i = numRem - 1; i >= 0; i--) {	
		//go from the last element to the first element 
		//in order to avoid having to use a break statement
		if (remArr[i].getDate() == d) {
			index = i;
		}
	}
	return index;
}



// deleteRem()
//
//Purpose: Deletes all reminders earlier than today’s date
//Parameters: None
//Return: the number of reminders deleted (a size_t value)
//
//Notes: 
//1) Reminders are shifted down in the array to fill any vacated entries.
//2) The default constructor of the Date class initializes a Date object to today's date.
size_t Calendar::deleteRem()
{
	Date today;	//constructs a date object to today's date
	size_t index = 0;	//index of last reminder to be deleted
	size_t count = 0;	//number of deleted reminders

	if (numRem == 0) {		//empty calendar
		return 0;
	}

	if (today <= remArr[0].getDate()) {	
		//there are no reminders earlier than today's date
		return 0;
	}

	for (size_t i = 0; i < numRem; i++) {
		if (today > remArr[i].getDate()) {
			index++;
			count++;
		}
	}

	if (count == numRem) {	//wanna delete all reminders
		numRem = 0;
		return count;
	}
	//count must be non-zero at this point
	else {				//delete some reminders
		for (size_t i = index; i < numRem; i++) {
				remArr[index - count] = remArr[index];
				index++;
		}
		numRem = numRem- count;
		return count;
	}
}


// deleteRem(size_t index)
//
//Purpose: Deletes reminder object at a provided index position
//Parameters: size_t index 
//Return: the number of reminders deleted (a size_t value)
//
//Notes: 
//1) Reminders are shifted down in the array to fill any vacated entries.
//2) If the index is invalid, no deletions will be performed and zero is returned
size_t Calendar::deleteRem(size_t index)	
{
	if (index < 0 || index >= numRem) {		//invalid index
		return 0;
	}
	else {	//index is valid
		if (index == numRem - 1) {	
			//delete the latest reminder, so nothing to shift
			numRem = numRem - 1;
			return 1;
		}
		else {	//delete a reminder with stuff to shift
			for (size_t i = 0; i < (numRem - index) - 1; i++) {
				remArr[index + i] = remArr[index + i + 1];
			}
			numRem = numRem - 1;
			return 1;
		}
	}
}



// deleteRem(const string& str)
//
//Purpose: Delete all reminders whose message matches a given string
//Parameters: string str (whose match we want to find, case sensitive)
//Return: number of reminders deleted (size_t value)
//
//Notes: 
//1) Reminders are shifted down in the array to fill any vacated entries.
size_t Calendar::deleteRem(const string& str)
{
	size_t count = 0;	//number of reminders deleted
	if (numRem == 0) {	//empty calendar
		return count;
	}
	else {
		for (int i = numRem - 1; i >= 0; i--) {
			if (remArr[i].getMsg() == str) {
				for (int j = i; j < (int) numRem - 1; j++) {
					remArr[j] = remArr[j + 1];
				}
				numRem = numRem - 1;
				count++;
			}
		}
		return count;
	}
}


// deleteRem(const Date& d)
//
//Purpose: Deletes all reminders on a particular date
//Parameters: Date d 
//Return: number of reminders deleted (size_t value)
//
//Notes: 
//1) Reminders are shifted down in the array to fill any vacated entries.
size_t Calendar::deleteRem(const Date& d)
{
	return deleteRem(d, d);
}


// deleteRem(Date d1, Date d2)
//
//Purpose: Deletes all reminders between a range of two given dates
//Parameters: Date d1, Date d2 (the range of Dates)
//Return: number of reminders deleted (size_t value)
//
//Behavior:
//1.  If the Calendar contains no dates in the given range, perform no deletions & return zero
//2.  Delete all Reminders which are later than or equal to the smaller of the two dates and are 
//    earlier than or equal to the larger of the two dates. Return the number deleted.
//3.  Reminders are shifted down in the array to fill any vacated entries.
size_t Calendar::deleteRem(const Date& d1, const Date& d2)
{
	Date earlier = d1;
	Date later = d2;

	if (d1 > d2) {		// if d1 is more recent than d2
		earlier = d2;
		later = d1;
	}

	size_t index = 0;
	size_t count = 0;

	if (numRem == 0) {	//empty calendar
		return 0;
	}

	else {
		for (int i = numRem - 1; i >= 0; i--) {
			if (remArr[i].getDate() >= earlier && remArr[i].getDate() <= later) {
				count++;
				index = (size_t) i;
			}
		}
		if (count == 0) {	//no reminders to delete
			return 0;
		}
		else {
			for (size_t i = index; i + count < numRem; i++) {
				remArr[i] = remArr[i + count];
			}
			numRem = numRem - count;
			return count;
		}
	}
}


// mergeCal(const Calendar& c)
//
//Purpose: Merge a received parameter calendar into this calendar
//Parameters: Calendar c (the calendar to be merged)
//Return: None
//
//Behavior:
//1. Add each reminder of the parameter Calendar to the object Calendar; may result in duplicate entries
//   if both Calendars had the same reminders.
//2. All reminders that are added remain in the same order as they appeared in the parameter Calendar.
//3. Any added reminder with the same date of an existing reminder is added ahead of the existing reminder.
//4. If the total number of reminders is too big to be stored, we grow the array to a total size of
//   the total number of reminders from the two calendars plus DEFAULT_MAX.
//
//Additional constraint: full credit will only be given for this function if it is efficient; that is only
//if each reminder is moved/assigned only once in the target array
void Calendar::mergeCal(const Calendar& c)
{
	if (maxRem < numRem + c.getNumRem()) {
		grow(numRem + c.getNumRem() + DEFAULT_MAX);
	}
	size_t index = numRem + c.getNumRem() - 1;
	int i = (int)numRem - 1;
	int j = (int)c.getNumRem() - 1;
	while (i >= 0 && j >= 0) {
		if (c.remArr[j] > remArr[i]) {
			remArr[index] = c.remArr[j];
			j--;
			numRem++;
		}
		else {
			remArr[index] = remArr[i];
			i--;
		}
		index--;
	}
	if (i == -1) {
		for (j; j >= 0; j--) {
			remArr[j] = c.remArr[j];
			numRem++;
		}
	}
	if (j == -1) {
		//do nothing
	}
}



// grow
//
//Purpose: grow the remArr array
//Parameters: newSize, the new desired size of the array
//Return: nothing
//
//If the current size of the array is equal to or larger than newSize, we do nothing.
//Else we allocate a new array for the Calendar of the desired size and copy the 
//old data into it.
//NOTE: normally this method would be a private method, but it is public here to ease testing
void Calendar::grow(size_t newSize)
{
	if (maxRem >= newSize) {
		return;
	}
	//initializing new Reminder array of size newSize
	ReminderPtr temp(new Reminder[newSize]);		
	for (size_t i = 0; i < maxRem; i++) {
		temp[i] = remArr[i];		
	}
	maxRem = newSize;				
	//swap memory addresses s.t. remArr now points to temp
	std::swap(remArr, temp);		
	delete []temp;
	temp = nullptr;
}



///////////////////////////////////////////////////
// THE FOLLOWING METHODS ARE FOR GRAD STUDENTS ONLY

#if GRAD_STUDENT==1



// mergeCal(const Calendar& c)
//
//Purpose: Merge a received parameter calendar into this calendar
//Parameters: Calendar c (the calendar to be merged)
//Return: None
//
//Behavior:
//1. Add each reminder of the parameter Calendar to the object Calendar; may result in duplicate entries
//   if both Calendars had the same reminders.
//2. All reminders that are added remain in the same order as they appeared in the parameter Calendar.
//3. Any added reminder with the same date of an existing reminder is added ahead of the existing reminder.
//4. If the total number of reminders is too big to be stored, throws an std::overflow_error exception.
//
//Additional constraint: full credit will only be given for this function if it is efficient; that is only
//if each reminder is moved/assigned only once in the target array
void Calendar::mergeCal(const Calendar& c)	
{
	return;  // replace this!
}



// repeatRem(Reminder r, size_t repCount, char repType)
//
//Purpose: Adds a reminder repeatedly based on repetition type and the number of repetitions.
//Parameters:  Reminder r – the first reminder to be inserted
//             size_t repCount – the number of times reminder is to be repeated
//             char repType – daily, weekly, monthly, yearly (‘d’, ‘w’, ‘m’, ‘y’)
//Return: size_t – index of the first reminder inserted
//Preconditions: repCount > 0; ie the reminder is going to be inserted at least once
//               repType is one of 'd', 'w', 'm', 'y'
//
//Behavior:
//0. In case repCount == 0 or an invalid repType: throw an invalid_argument exception
//1. In case the array cannot hold all the new reminders: throw an overflow_error exception
//2. Inserts reminders in the array in the sorted order of date, shifting other items
//   up to make space
//3. In case of already existing Reminder with same date: insert new reminder 
//   before (ahead of) the existing one.
//4. Return the index of the first inserted reminder
//
//Additional constraint: full credit will only be given for this function if it is efficient; that is only
//if each reminder is moved/assigned only once in the target array
size_t Calendar::repeatRem(const Reminder& r, size_t repCount, char repType)
{
	return 0;  // replace this!
}


#endif  

// END GRAD STUDENT ONLY METHODS
///////////////////////////////////////////////////
