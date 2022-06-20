// File name: Calendar.cpp
// Author: Yifan Guo
// VUnetid: guoy5	
// Email: yifan.guo@vanderbilt.edu
// Class: CS201
// Date: 9/21/15
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
Calendar::Calendar() : maxRem(DEFAULT_MAX), numRem(0), remArr(new Reminder[maxRem])
{
	// add your code here or on initialization list
}



// Alternate constructor
// Create an empty Calendar (one with zero Reminders) but with an array of initSize elements
// Precondition: initSize > 0; throws invalid_argument exception if not the case
Calendar::Calendar(size_t initSize) : maxRem(initSize), numRem(0), remArr(new Reminder[maxRem])
{
	if (initSize <= 0) {
		throw std::invalid_argument("Invalid number of elements to initialize.");
	}
}



// Copy ctor
Calendar::Calendar(const Calendar& rhs): maxRem(rhs.maxRem), numRem(rhs.numRem), remArr(new Reminder[maxRem])
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
	return 0;  // replace this!
}




//getRem(size_t index) 
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
	return Reminder();  // replace this!
}




//displayRem()
//
//Purpose: Return a string of all reminders 
//Parameters: None
//Return: string containing all the reminders in sorted order with each reminder followed 
//   immediately by a newline character. Returns an empty string if the Calendar is empty
string Calendar::displayRem() const
{
	return "";   // replace this!
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
	return "";   // replace this!
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
	return "";   // replace this!
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
	return "";   // replace this!
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
	return "";   // replace this!
}


//findRem(const Date& d)
//
//Purpose: Find first reminder for the given date and return its index
//Parameters: Date d, the date to search for
//Return: int value containing the index of the first reminder with the specified date,
//        or -1 if no reminders with that date exist
int Calendar::findRem(const Date& d) const
{
	return 0;   // replace this!
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
	return 0;   // replace this!
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
	return 0;   // replace this!
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
	return 0;   // replace this!
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
	return 0;   // replace this!
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
	return 0;   // replace this!
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
	int i = numRem - 1;
	int j = (int)c.getNumRem() - 1;
	while (i >= 0 && j >= 0) {
		if (c.remArr[j] > remArr[i]) {
			remArr[index] = c.remArr[j];
			j--;
		}
		else {
			remArr[index] = remArr[i];
			i--;
		}
		index--;
	}
	if (i == -1) {
		remArr[0] = c.remArr[j];
	}
	if (j == -1) {
		//do nothing
	}

	//int count = 0;
	//for (int i = (int) numRem - 1; i >= 0; i--) {
	//	for (int j = 0; j < (int) c.getNumRem(); j++) {
	//		if (c.remArr[j] < remArr[i]) {
	//			count++;
	//		}
	//	}
	//	count = count + i;
	//	remArr[count] = remArr[i];
	//	count = 0;
	//}
	//int index = 0;
	//for (int i = 0; i < (int) c.getNumRem(); i++) {
	//	while (c.remArr[i] > remArr[index]) {
	//		index++;
	//	}
	//	remArr[index] = c.remArr[i];
	//	index = 0;
	//}
	//return;   // replace this!
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
	
	ReminderPtr temp(new Reminder[newSize]);		//initializing new Reminder array of size newSize
	for (size_t i = 0; i < maxRem; i++) {
		temp[i] = remArr[i];		//assign reminders in remArr to the temp array 
	}
	maxRem = newSize;		//is this necessary?
	std::swap(remArr, temp);		//swap memory addresses s.t. remArr now points to temp
	delete []temp;
	temp = nullptr;
}





///////////////////////////////////////////////////
// THE FOLLOWING METHODS ARE FOR GRAD STUDENTS ONLY

#if GRAD_STUDENT==1



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
//1. In case the array cannot hold all the new reminders: increase the size of the array 
//   to make room for the Reminder being repeated. Grow the array to make it big enough to 
//   hold the total number of Reminders to be stored (current Reminders + repeated Reminders) 
//   plus an additional DEFAULT_MAX entries. You should only grow the array once, regardless 
//   of the repeat count on the repeated Reminder.
//2. Inserts reminders in the array in the sorted order of date, shifting other items
//   up to make space
//3. In case of already existing Reminder with same date: insert new reminder 
//   before (ahead of) the existing one.
//4. Return the index of the first inserted reminder
//
//Additional constraint: full credit will only be given for this function if it is efficient; 
//that is only if each reminder is moved/assigned only once in the target array
size_t Calendar::repeatRem(const Reminder& r, size_t repCount, char repType)
{
	return 0;   // replace this!
}




// getReminders(const Date& d1, const Date& d2)
//
//Purpose: Returns a new Calendar containing all reminders between a range of two given dates
//Parameters: Date d1, Date d2 (the range of Dates)
//Return: A new Calendar
//
//Behavior:
//1.  If the Calendar contains no dates in the given range, return a new, empty, default Calendar
//2.  Create a new Calendar that contains the desired Reminders from the current Calendar; all 
//    Reminders stay in their same relative order. The returned Calendar should have DEFAULT_MAX
//    unused (extra) array elements; ie, the size of the new Calendar array should be the number of
//    Reminders copied + DEFAULT_MAX.
//
//Additional constraint: full credit will only be given for this function if it is efficient; that is only
//if each array is traversed a constant number of times (ie, it is independent of the dates d1 & d2)
Calendar Calendar::getReminders(const Date& d1, const Date& d2) const
{
	return Calendar();   // replace this!
}




#endif  

// END GRAD STUDENT ONLY METHODS
///////////////////////////////////////////////////
