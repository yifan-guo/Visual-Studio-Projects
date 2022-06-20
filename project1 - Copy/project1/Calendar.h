// File name: Calendar.h
// Author: Yifan Guo
// VUnetid: guoy5
// Email: yifan.guo@vanderbilt.edu
// Class: CS201
// Date: 9/16/15
// Honor statement: I pledge to the honor statement.
// Assignment Number: 01
// Description: This is the declaration of the Calendar class, which supports a collection of Reminders


// Change the following line as appropriate -- this is the only line you should change in this file
// besides filling in the comment header above.
#define GRAD_STUDENT 0   // if you are a grad student, set this to 1, otherwise set it to 0


#ifndef CALENDAR_H
#define CALENDAR_H


#include "Date.h"
#include "Reminder.h"
#include <stdexcept>
using namespace std;


const size_t MAX_REM = 50;  // set the value of maximum number of reminders to store here

class Calendar
{
	
private:
	size_t numRem;	            //number of reminders in array
	Reminder remArr[MAX_REM];	//array of reminders


public:
	// Default Constructor
	// Create an empty Calendar (one with zero Reminders)
	Calendar();
	
	// getNumRem
	// Return the total number of Reminders in the Calendar
	size_t getNumRem() const;





	//addRem(const Reminder &r)
	//
	//Purpose: add/insert a reminder in the array of reminder objects
	//Parameters: Reminder r - the reminder to be added
	//Returns: size_t – the index position of the inserted reminder
	//
	//Behavior: 
	//1.	In case of the array being empty: insert as the first element
	//2.    In case the array is full: throw an overflow_error exception
	//3.	In case of a non-empty array with space available: insert Reminder in sorted order, 
	//      shifting other items up to make space
	//4.	In case of already existing Reminder with same date: insert new reminder 
	//      before (ahead of) the existing one.
	//5.	Return the index of the inserted reminder, using zero-based indexing
	size_t addRem(const Reminder &r);	


	//getRem(size_t index) 
	//
	//Purpose: returns the reminder at the specified index in the Calendar, throw exception if index is bad
	//Parameters: size_t index - the index of the desired reminder; using zero-based indexing
	//Returns: Reminder - the reminder at the specified index
	//
	//Behavior:
	//1.	If the index is invalid, throw an std::invalid_argument exception
	//2.	Otherwise, return the reminder at the specified index
	Reminder getRem(size_t index) const;


	//displayRem()
	//
	//Purpose: Return a string of all reminders 
	//Parameters: None
	//Return: string containing all the reminders in sorted order with each reminder followed 
	//   immediately by a newline character. Returns an empty string if the Calendar is empty
	string displayRem() const;	   


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
	string displayRem(size_t index) const;


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
	string displayRem(const string& str) const;


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
	string displayRem(const Date& d) const;



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
	string displayRem(const Date& d1, const Date& d2) const;



	//findRem(const Date& d)
	//
	//Purpose: Find first reminder for the given date and return its index
	//Parameters: Date d, the date to search for
	//Return: int value containing the index of the first reminder with the specified date,
	//        or -1 if no reminders with that date exist
	int findRem(const Date& d) const;


	// deleteRem()
	//
	//Purpose: Deletes all reminders earlier than today’s date
	//Parameters: None
	//Return: the number of reminders deleted (a size_t value)
	//
	//Behavior:
	//1) Reminders are shifted down in the array to fill any vacated entries.
	//
	//Implementation Notes: 
	//1) The default constructor of the Date class initializes a Date object to today's date.
	size_t deleteRem();			    



	// deleteRem(size_t index)
	//
	//Purpose: Deletes reminder object at a provided index position
	//Parameters: size_t index 
	//Return: the number of reminders deleted (a size_t value)
	//
	//Notes: 
	//1) Reminders are shifted down in the array to fill any vacated entries.
	//2) If the index is invalid, no deletions will be performed and zero is returned
	size_t deleteRem(size_t);	          



	// deleteRem(const string& str)
	//
	//Purpose: Delete all reminders whose message matches a given string
	//Parameters: string str (whose match we want to find, case sensitive)
	//Return: number of reminders deleted (size_t value)
	//
	//Notes: 
	//1) Reminders are shifted down in the array to fill any vacated entries.
	size_t deleteRem(const string& str);


	// deleteRem(const Date& d)
	//
	//Purpose: Deletes all reminders on a particular date
	//Parameters: Date d 
	//Return: number of reminders deleted (size_t value)
	//
	//Notes: 
	//1) Reminders are shifted down in the array to fill any vacated entries.
	size_t deleteRem(const Date& d);



	// deleteRem(const Date& d1, const Date& d2)
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
	size_t deleteRem(const Date& d1, const Date& d2);
	



   ///////////////////////////////////////////////////
   // THE FOLLOWING METHODS ARE FOR GRAD STUDENTS ONLY

#if GRAD_STUDENT==1


	// repeatRem(const Reminder& r, size_t repCount, char repType)
	//
	//Purpose: Adds a reminder repeatedly based on repetition type and the number of repetitions.
	//Parameters:  Reminder r – the first reminder to be inserted
	//             size_t repCount – the number of times reminder is to be repeated
	//             char repType – daily, weekly, monthly, yearly ('d', 'w', 'm', 'y')
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
	size_t repeatRem(const Reminder& r, size_t repCount, char repType);



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
	void mergeCal(const Calendar& c);

#endif

   // END GRAD STUDENT ONLY METHODS
   ///////////////////////////////////////////////////

};


#endif

