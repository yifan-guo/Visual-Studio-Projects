// File name: Calendar.cpp
// Author: Yifan Guo	
// VUnetid: guoy5
// Email: yifan.guo@vanderbilt.edu
// Class: CS2201
// Date: 10/8/15
// Honor statement: I pledge to the honor statement
// Assignment Number: 03
// Description: These methods implement the Calendar class

#include <string>
#include <stdexcept>
#include <cassert>
#include "Calendar.h"
using namespace std;


// Default Constructor
// Create an empty Calendar (one with zero Reminders)
Calendar::Calendar(): 
	numRem(0), 
	remList(nullptr)
{
}


	
// Copy ctor
Calendar::Calendar(const Calendar& rhs): 
	numRem(rhs.numRem), 
	remList(nullptr)
{
	if (rhs.remList != nullptr) {
		//copy the first node
		remList = new RemNode;
		remList->rem = rhs.remList->rem;
		//copy rest of list
		RemNodePtr newPtr = remList;
		for (RemNodePtr origPtr = rhs.remList->next; 
		origPtr != nullptr;
			origPtr = origPtr->next) {
			newPtr->next = new RemNode;
			newPtr = newPtr->next;
			newPtr->rem = origPtr->rem;
		}
		newPtr->next = nullptr;
	}
}


// Destructor
Calendar::~Calendar()
{
	RemNodePtr temp;
	while (remList != nullptr) {
		temp = remList;
		remList = temp->next;
		delete temp;
	}
	numRem = 0;
}



// Assignment operator
const Calendar& Calendar::operator= (const Calendar& rhs)
{
	if (this == &rhs) {
		return *this;
	}
	Calendar temp(rhs);	//copy ctor
	std::swap(numRem, temp.numRem);
	std::swap(remList, temp.remList);
	return *this;
}



// getNumRem
// Return the total number of Reminders in the Calendar
size_t Calendar::getNumRem() const
{
	return numRem;
}


//addRem(const Reminder &r)
//
//Purpose: add/insert a reminder in the list of reminder objects
//Parameters: Reminder r - the reminder to be added
//Returns: size_t - the index position of the inserted reminder
//
//Behavior: 
//1.	In case of the list being empty: insert as the first element
//2.	In case of a non-empty Calendar: insert Reminder in sorted order
//3.	In case of already existing Reminder with same date: insert new reminder 
//      before (ahead of) the existing one
//4.	Return the index of the inserted reminder, using zero-based indexing
size_t Calendar::addRem(const Reminder &r)
{
	size_t index = 0;
	RemNodePtr newPtr = new RemNode;
	newPtr->rem = r;
	newPtr->next = nullptr;

	RemNodePtr cur, prev;

	for (prev = nullptr, cur = remList; 
	cur != nullptr && newPtr->rem.getDate() > cur->rem.getDate(); 
		prev = cur, cur = cur->next) {
		index++;
	}
	if (prev == nullptr) {
		remList = newPtr;
	}
	else {
		prev-> next = newPtr;
	}
	newPtr->next = cur;
	numRem++;
	return index;
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
	Reminder r;
	if (index < 0 || index >= numRem) {
		throw std::invalid_argument("Invalid index.");
	}
	RemNodePtr cur = remList;
	for (size_t i = 0; i < index; cur = cur->next, i++) {
		//do nothing
	}
	r = cur->rem;
	return r;
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
	RemNodePtr cur = remList;
	if (numRem == 0) {		//empty calendar
		//do nothing
	}
	else {
		for (size_t i = 0; i < numRem; cur = cur->next, i++) {
			s = s + cur->rem.toString() + "\n";
		}
	}
	return s;
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
	string s = "";
	RemNodePtr cur = remList;
	if (numRem == 0 || index < 0 || index >= numRem) {	
		//empty calendar or invalid index
		//do nothing
	}
	else {
		//non-empty calendar with valid index
		for (size_t i = 0; i < index; cur = cur->next, i++) {
			// do nothing
		}
		s = cur->rem.toString();
	}
	return s;
}


//displayRem(string str)
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
	RemNodePtr cur = remList;
	string s = "";
	for (size_t i = 0; 
	cur != nullptr && i < numRem; 
		cur = cur->next, i++) {
		if (cur->rem.getMsg() == str) {
			s = s + cur->rem.toString() + "\n";
		}
	}
	return s;
}


//displayRem(Date d)
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


//displayRem(Date d1, Date d2)
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
	RemNodePtr cur = remList;
	string s = "";
	for (size_t i = 0; i < numRem; cur = cur->next, i++) {
		if (cur->rem.getDate() >= earlier 
			&& cur->rem.getDate() <= later) {
			s = s + cur->rem.toString() + "\n";
		}
	}
	return s;
}


//findRem(Date d)
//
//Purpose: Find first reminder for the given date and return its index
//Parameters: Date d, the date to search for
//Return: int value containing the index of the first reminder with the specified date,
//        or -1 if no reminders with that date exist
int Calendar::findRem(const Date& d) const
{
	RemNodePtr cur = remList;
	int index = -1;
	for (size_t i = 0; 
	cur != nullptr && i < numRem; 
		cur = cur->next, i++) {
		if (cur->rem.getDate() == d) {
			index = (int) i;
			return index;
		}
	}
	return index;
}


// deleteRem()
//
//Purpose: Deletes all reminders earlier than today's date
//Parameters: None
//Return: the number of reminders deleted (a size_t value)
//
//Implementation Notes: 
//1) The default constructor of the Date class initializes a Date object to today's date.
size_t Calendar::deleteRem()
{
	Date today;	//constructs a date object to today's date
	size_t count = 0;	//number of deleted reminders

	RemNodePtr cur;
	for (cur = remList; 
	cur != nullptr && cur->rem.getDate() < today; 
		cur = cur->next) {
		count++;
		numRem--;
	}
	if (count == 0) {	//nothing to delete
		return count;	
	}
	else {
		RemNodePtr prev = remList;
		RemNodePtr tmp;
		while (prev != cur) {
			tmp = prev;
			prev = prev->next;
			delete tmp;		
		}
		remList = prev;	
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
//1) If the index is invalid, no deletions will be performed and zero is returned
size_t Calendar::deleteRem(size_t index)
{
	if (index < 0 || index >= numRem) {
		return 0;
	}
	RemNodePtr cur = remList;
	for (size_t i = 0; i < index; i++) {
		cur = cur->next;
	}
	if (remList == cur) {	//delete first node
		remList = cur->next;
	}
	else {	//delete at middle or end of list
		RemNodePtr prev;
		for (prev = remList; 
		prev->next != cur; 
			prev = prev->next) {
			//nothing to do
		}
		prev->next = cur->next;
	}
	delete cur;
	cur = nullptr;
	numRem--;
	return 1;
}


// deleteRem(string str)
//
//Purpose: Delete all reminders whose message matches a given string
//Parameters: string str (whose match we want to find, case sensitive)
//Return: number of reminders deleted (size_t value)
size_t Calendar::deleteRem(const string& str)
{
	size_t count = 0;	//number of deleted reminders

	RemNodePtr cur = remList;
	RemNodePtr tmp;
	while (cur != nullptr) {
		if (cur->rem.getMsg() == str) {	//deleting something
			if (cur == remList) {	//first node
				//delete first node
				remList = cur->next;
			}
			else {	//middle or last node
				RemNodePtr prev;		
				for (prev = remList; 
				prev->next != cur; 
					prev = prev->next) {
					//nothing to do
				}
				prev->next = cur->next;
			}
			tmp = cur;
			cur = cur->next;
			delete tmp;
			numRem--;
			count++;
		}
		else {	//no match
			cur = cur->next;
		}
	}
	return count;
}


// deleteRem(Date d)
//
//Purpose: Deletes all reminders on a particular date
//Parameters: Date d 
//Return: number of reminders deleted (size_t value)
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
size_t Calendar::deleteRem(const Date& d1, const Date& d2)
{
	Date earlier = d1;
	Date later = d2;

	if (d1 > d2) {		// if d1 is more recent than d2
		earlier = d2;
		later = d1;
	}
	size_t count = 0;	//number of deleted reminders

	RemNodePtr cur = remList;
	RemNodePtr tmp;
	while (cur != nullptr) {
		if (cur->rem.getDate() >= earlier 
			&& cur->rem.getDate() <= later) {	
			//deleting something
			if (cur == remList) {	//first node
			//delete first node
				remList = cur->next;
			}
			else {	//middle or last node
				RemNodePtr prev;		
				for (prev = remList;
				prev->next != cur; 
					prev = prev->next) {
					//nothing to do
				}
				prev->next = cur->next;
			}
			tmp = cur;
			cur = cur->next;
			delete tmp;
			numRem--;
			count++;
		}
		else {	//no match
			cur = cur->next;
		}
	}
	return count;
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
//
//Additional constraint: full credit will only be given for this function if it is efficient; that is only
//if each linked list is traversed only a constant number of times
void Calendar::mergeCal(const Calendar& c)	
{
}






// repeatRem(Reminder r, size_t repCount, char repType)
//
//Purpose: Adds a reminder repeatedly based on repetition type and the number of repetitions.
//Parameters:  Reminder r -- the first reminder to be inserted
//             size_t repCount -- the number of times reminder is to be repeated
//             char repType -- daily, weekly, monthly, yearly ('d', 'w', 'm', 'y')
//Return: size_t -- index of the first reminder inserted
//Preconditions: repCount > 0; ie the reminder is going to be inserted at least once
//               repType is one of 'd', 'w', 'm', 'y'
//
//Behavior:
//0. In case repCount == 0 or an invalid repType: throw an invalid_argument exception
//1. Inserts reminders in the list in the sorted order of date
//2. In case of already existing Reminder with same date: insert new reminder 
//   before (ahead of) the existing one.
//3. Return the index of the first inserted reminder
//
//Additional constraint: full credit will only be given for this function if it is efficient; that is only
//if the linked list is traversed a constant number of times
size_t Calendar::repeatRem(const Reminder& r, size_t repCount, char repType)
{
	return 123456789;  // replace this
}





// getReminders(Date d1, Date d2)
//
//Purpose: Returns a new Calendar containing all reminders between a range of two given dates
//Parameters: Date d1, Date d2 (the range of Dates)
//Return: A new Calendar
//
//Behavior:
//1.  If the Calendar contains no dates in the given range, return a new, empty, default Calendar
//2.  Create a new Calendar that contains the desired Reminders from the current Calendar; all 
//    Reminders stay in their same relative order. 
//
//Additional constraint: full credit will only be given for this function if it is efficient; that is only
//if each linked list is traversed only a constant number of times
Calendar Calendar::getReminders(const Date& d1, const Date& d2) const	 
{
	Calendar c;
	return c;
}
	


#endif  

// END GRAD STUDENT ONLY METHODS
///////////////////////////////////////////////////
