// File name: CalTest.cpp
// Author: Yifan Guo
// VUnetid: guoy5
// Email: yifan.guo@vanderbilt.edu
// Class: CS2201
// Date: 9/6/15
// Honor statement: I have read and will abide by the Honor statement.
// Assignment Number: 00
// Description: This program will test the Calendar class

#include <iostream>
#include <string>
#include <stdexcept>
#include "Calendar.h"
#include <cassert>
using namespace std;


int main(void)
{
	// Here is some sample code that does some simple testing of the Calendar class.
	// It creates an empty Calendar and performs some test on it.
	// It then adds a Reminder to the Calendar and performs some other tests on it.
	// This is only a simple sample, and is not considered to be very thorough.


	Calendar cal1;   // create an empty Calendar object via default ctor

	if (cal1.getNumRem() != 0) {  // test getNumRem()
		cout << "Default ctor failed to create an empty calendar" << endl;
		cout << "Reported that " << cal1.getNumRem() << " reminders exist" << endl;
	}

	if (cal1.displayRem() != "") {  // test displayRem()
		cout << "Default ctor should produce an empty calendar" << endl;
		cout << "displayRem returned the following reminders: " << cal1.displayRem() << endl;
	}


	Date d1("08/26/2015");
	Reminder rem1(d1, "First day of classes");

	size_t index = cal1.addRem(rem1);   // test addRem(); Calendar how has one Reminder

	if (index != 0) {
		cout << "addRem failed to return index 0 for first insertion" << endl;
		cout << "Returned index == " << index << endl;
	}

	if (cal1.getNumRem() != 1) {
		cout << "addRem/getNumRem failed after inserting one reminder" << endl;
		cout << "Reported that " << cal1.getNumRem() << " reminders exist" << endl;
	}

	if (cal1.displayRem() != "On 08/26/2015: First day of classes\n") {
		cout << "Unexpected reminder in calendar" << endl;
		cout << "displayRem returned the following reminders: " << cal1.displayRem() << endl;
	}

	if (cal1.displayRem(index) != "On 08/26/2015: First day of classes") {
		cout << "Unexpected reminder in calendar" << endl;
		cout << "displayRem returned the following reminders: " << cal1.displayRem(index) << endl;
	}


	// Add all your code here to fully test the Calendar class.
	// You can define helper functions if it would make your job easier or make this file cleaner.
	if (cal1.getRem(index) != rem1) {		// test getRem(size_t index)
		cout << "Unexpected reminder in calendar" << endl;
		cout << "getRem returned the following reminder: " << cal1.displayRem(index) << "at index: " << index << endl;
	}

	try {
		Reminder test = cal1.getRem(25);		//test getRem(size_t index), attempt to get the reminder at an index where a Reminder was not inserted
		cout << "\nTHIS MESSAGE SHOULD NOT BE SEEN. An overflow exception was not thrown!!" << endl;
	}
	catch (std::invalid_argument &excpt)
	{
		cout << "Exception succesfully thrown & caught:: " << excpt.what() << endl;
	}

	try {
		Reminder test = cal1.getRem(MAX_REM);	//test getRem(size_t index), attempt to get the reminder at an invalid index
		cout << "\nTHIS MESSAGE SHOULD NOT BE SEEN. An overflow exception was not thrown!!" << endl;
	}
	catch (std::invalid_argument &excpt)
	{
		cout << "Exception succesfully thrown & caught:: " << excpt.what() << endl;
	}

	try
	{
		Reminder test = cal1.getRem(-1); //test getRem() at another invalid index
	}
	catch (std::invalid_argument &excpt)
	{
		cout << "Exception successfully thrown & caught:: " << excpt.what() << endl;
	}

	if (cal1.displayRem(MAX_REM) != "") {	//test displayRem(size_t index), attempt to display a string of the reminder at a invalid index
		cout << "displayRem failed to recognize the invalid index" << endl;
		cout << "displayRem returned the following reminder: " << cal1.displayRem(MAX_REM) << endl;
	}

	if (cal1.displayRem(-1) != "") {
		cout << "displayRem failed to recognize the invalid index" << endl;
		cout << "displayRem returned the following reminder: " << cal1.displayRem(MAX_REM) << endl;
	}

	string message1 = rem1.getMsg();
	if (cal1.displayRem(message1) != "On 08/26/2015: First day of classes\n") {		//test displayRem(const string& str) works
		cout << "Unexpected reminder in calendar" << endl;
		cout << "displayRem returned the following reminder: " << cal1.displayRem(message1) << endl;
	}

	if (cal1.displayRem("First day of class") != "") {		//test displayRem(const string& str) when given a very similar string
		cout << "Unexpected reminder in calendar" << endl;
		cout << "displayRem returned the following reminder: " << cal1.displayRem(message1) << endl;
	}

	if (cal1.displayRem("Hello World!") != "") {	//test displayRem(const string& str) if no match is found
		cout << "There should be no reminders with the message: Hello World!" << endl;
		cout << "displayRem returned the following reminder: " << cal1.displayRem("Hello World!") << endl;
	}

	if (cal1.displayRem(d1) != "On 08/26/2015: First day of classes\n") {	// test displayRem(const Date& d) 
		cout << "Unexpected reminder in calendar" << endl;
		cout << "displayRem returned the following reminder: " << cal1.displayRem(d1) << endl;
	}
	
	Date armageddon("09/09/9999");	// arbitrary date on which no reminders should be set
	if (cal1.displayRem(armageddon) != "") {	// test displayRem(const Date& d) when no match is found
		cout << "There should be no reminders on judgement day." << endl;
		cout << "diplayRem returned the following reminder: " << cal1.displayRem(d1 - d1) << endl;
	}

	if (cal1.displayRem(d1, armageddon) != "On 08/26/2015: First day of classes\n") {	//test displayRem(const Date& d1, const Date& d2)
		cout << "displayRem failed to display reminders within this range" << endl;
		cout << "displayRem returned the following reminder, if any: " << cal1.displayRem(d1, armageddon) << endl;
	}

	if (cal1.displayRem(armageddon, armageddon) != "") {	//test displayRem(const Date& d1, const Date& d2) if no match is found
		cout << "There should be no reminders within this range" << endl;
		cout << "displayRem returned the following reminder: " << cal1.displayRem(d1, armageddon) << endl;
	}

	if (cal1.findRem(d1) != index) {	//test findRem(const Date& d)
		cout << "findRem failed to find the reminder with this date" << endl;
		cout << "findRem returned this index: " << cal1.findRem(d1) << endl;
	}

	if (cal1.findRem(armageddon) != -1) {	//test findRem(const Date& d) when no reminders with that date exist
		cout << "There should be no reminders on judgement day." << endl;
		cout << "findRem returned this index: " << cal1.findRem(d1) << endl;
	}

	Reminder rem2(d1, "Go over class syllabus"); //create reminder on same date for testing

	if (cal1.addRem(rem2) != 1) {	//test whether addRem() inserts rem2 before or after rem1 (both have the same date)
		if (cal1.getRem(0) == rem2) {
			cout << "CONFIRMED: In case of already existing reminder with the same date: addRem() inserts the new reminder before the existing reminder\n." << endl;
		}
		else {
			cout << "ERROR" << endl;
		}
	}

	if (cal1.displayRem(d1) == "On 08/26/2015: Go over class syllabus\nOn 08/26/2015: First day of classes\n") { //tests whether displayRem(const Date& d) returns a string containing all the reminders in sorted order (in the case of already existing reminders with the same date, displayRem inserts new reminder before existing one)
		cout << "CONFIRMED: In case of multiple reminders with the same date: displayRem appends more recently added reminders before (above) older reminders\n." << endl;
	}
	else {
		cout << "ERROR" << endl;
	}

	assert(index == 0);		//index should still be zero

	if (cal1.deleteRem(index) != 1) {	//tests whether deleteRem works given a existing reminder at a valid index
		cout << "deleteRem did not delete a reminder as expected" << endl;
	}

	if (cal1.getRem(index) == rem1) {	//tests whether deleteRem causes reminders to shift down in the array to fill any vacated entries
		cout << "CONFIRMED: Reminders are shifted down (index-wise) in the array to fill any vacated entries\n" << endl;
	}
	else {
		cout << "ERROR" << endl;
	}

	if (cal1.deleteRem(MAX_REM) != 0) {		//tests whether deleteRem returns 0 when given an invalid index
		cout << "deleteRem failed to identify an invalid index" << endl;
	}

	if (cal1.deleteRem(25) != 0) {		//tests whether deleteRem returns 0 when no reminders exist at that index
		cout << "deleteRem deleted a reminder that did not exist" << endl;
	}

	if (cal1.deleteRem(-1) != 0) {		//tests whether deleteRem returns 0 when given an invalid index
		cout << "deleteRem deleted a reminder that did not exist" << endl;
	}

	if (cal1.deleteRem(armageddon, armageddon) != 0) {		//tests whether deleteRem(range of dates) returns 0 if the calender contains no dates in the given range
		cout << "No reminders should be within this range." << endl;
	}

	assert(cal1.getNumRem() == 1 && cal1.getRem(index) == rem1);	//there should only be one reminder (rem1) in the calendar
	
	cal1.addRem(rem2);		

	if (cal1.deleteRem(d1) != 2) {	//delete 2 reminders
		cout << "deleteRem did not delete the targeted reminders" << endl;
	}

	assert(cal1.getNumRem() == 0);	//there should be no reminders in the calendar at this point

	Date d2("09/01/2015");
	Reminder rem3(d2, "Last day to drop a class");

	//the goal of the next 3 statements is to insert reminders with a more recent date first, followed by reminders with an earlier date

	cal1.addRem(rem3);	//date is 09.01.2015
	cal1.addRem(rem2);	//date is 08.26.2015
	cal1.addRem(rem1);	//date is 08.26.2015


	if (cal1.getRem(index) == rem1 && cal1.getRem(index + 1) == rem2 && cal1.getRem(index + 2) == rem3) {	//tests whether addRem inserts reminders in sorted order (earlier reminders are inserted ahead of later reminders)
		cout << "CONFIRMED: In case of a non-empty array with space available: addRem inserts reminders in sorted order\n" << endl;
	}
	else {
		cout << "ERROR" << endl;
	}

	//the next 3 if statements test the edge cases of the displayRem(const Date& d1, const Date& d2) method
	bool cond1 = false; 
	bool cond2 = false;
	if (cal1.displayRem(d1, d2 - 1) == "On 08/26/2015: First day of classes\nOn 08/26/2015: Go over class syllabus\n") {	//tests whether displayRem(const Date& d1, const Date& d2) creates a string containing reminders which are earlier than or equal to d2
		if (cal1.displayRem(d1, d2) == "On 08/26/2015: First day of classes\nOn 08/26/2015: Go over class syllabus\nOn 09/01/2015: Last day to drop a class\n") {
			cout << "CONFIRMED: given a range between date1 and date2, displayRem creates a string containing the reminders (in sorted order) which are earlier than or equal to date2\n" << endl;
			cond1 = true;
		}
		else {
			cout << "ERROR" << endl;
		}
	}

	if (cal1.displayRem(d1, d2) == "On 08/26/2015: First day of classes\nOn 08/26/2015: Go over class syllabus\nOn 09/01/2015: Last day to drop a class\n") {
		if (cal1.displayRem(d1 + 1, d2) == "On 09/01/2015: Last day to drop a class\n") {		//tests whether displayRem(const Date& d1, const Date& d2) creates a string containing reminders which are later than or equal to d1
			cout << "CONFIRMED: given a range between date1 and date2, displayRem creates a string containing the reminders (in sorted order) which are later than or equal to date1\n" << endl;
			cond2 = true;
		}
		else {
			cout << "ERROR" << endl;
		}		
	}

	if (cond1 == true && cond2 == true) {
		cout << "CONFIRMED: displayRem(const Date& d1, const Date& d2) creates a string containing only reminders which are later than or equal to date1 and are earlier than or equal to date2\n" << endl;
	}
	else {
		cout << "ERROR" << endl;
	}

	Date d3("01/15/2016");
	Reminder rem4(d3, "Last day to drop a class");	//another reminder (with a different date) with the same message as rem3 
	if (cal1.addRem(rem4) == 3) {		//tests whether addRem inserts reminders in sorted order: the most recent reminder should be inserted after every other reminder in the calendar
		cout << "CONFIRMED: addRem inserts reminders in sorted order: Reminders with more recent dates are inserted after reminders with earlier dates\n" << endl;
	}
	else {
		cout << "ERROR" << endl;
	}

	if (cal1.displayRem("Last day to drop a class") == "On 09/01/2015: Last day to drop a class\nOn 01/15/2016: Last day to drop a class\n") {	//tests whether displayRem appends reminders in sorted order if they have the same message
		cout << "CONFIRMED: If multiple reminders have the same message, displayRem appends them in sorted order (based on date)\n" << endl;
	}
	else {
		cout << "ERROR" << endl;
	}

	if (cal1.deleteRem("Last day to drop a class") == 2) {	//tests deleteRem(const string& str), there should be 2 reminders in the calendar with this message
		cout << "CONFIRMED: deleteRem deleted all reminders with the specified message\n" << endl;
	}
	else {
		cout << "ERROR" << endl;
	}

	if (cal1.deleteRem(d1) == 2) {		//tests deleteRem(const Date& d) deletes multiple methods on the same date
		if (cal1.findRem(d1) == -1) {
			cout << "CONFIRMED: deleteRem deleted multiple reminders on a particular date\n" << endl;
		}
		else {
			cout << "ERROR" << endl;
		}
	}

	assert(cal1.getNumRem() == 0);	//calender should be empty at this point
	cal1.addRem(rem4);

	Date d4;	//date having today's date
	Reminder rem5(d4, "Work on CS project");
	cal1.addRem(rem5);

	if (cal1.deleteRem() != 0) {	//tests whether deleteRem() deletes all reminders earlier than today's date, there should be none deleted
		cout << "Unexpected reminders deleted" << endl;
	}

	cal1.addRem(rem1);

	if (cal1.deleteRem() == 1) {	//verify deleteRem() deletes all reminders earlier than today's date
		cout << "CONFIRMED: deleteRem() deleted all reminders earlier than today's date\n" << endl;
		if (cal1.getRem(index) == rem5) {	//verify other reminders are shifted upward
			cout << "CONFIRMED: Reminders are shifted down in the array to fill any vacated entries\n" << endl;
		}
		else {
			cout << "ERROR" << endl;
		}
	}
	else {
		cout << "ERROR" << endl;
	}
	
	assert(cal1.getNumRem() == 2);	//there should still be two reminders in the calendar

	//d4 = today's date and d3 = 01/15/2016
	if (cal1.deleteRem(d4 + 1, d3 - 1) == 0) {	//test edge cases for deleteRem(date1, date2)
		if (cal1.deleteRem(d4, d3 - 1) == 1) {	//should delete today's reminder
			cout << "CONFIRMED: given a range between date1 and date2, deleteRem deletes reminders which are later than or equal to date1\n" << endl;
		}
		else {
			cout << "ERROR" << endl;
		}
	}

	if (cal1.getRem(index) == rem4) {	//tests whether remaining reminders are shifted down the array
		cout << "CONFIRMED: Reminders are shifted down in the array to fill any vacated entries\n" << endl;
	}
	else{
		cout << "ERROR" << endl;
	}

	if (cal1.deleteRem(d4, d3 - 1) == 0) {	//test edge cases for deleteRem(date1, date2)
		if (cal1.deleteRem(d4, d3) == 1) {	//should delete rem4 which has date d3
			cout << "CONFIRMED: given a range between date1 and date2, deleteRem deletes reminders which are earlier than or equal to date2\n" << endl;
		}
		else {
			cout << "ERROR" << endl;
		}
	}

	assert(cal1.getNumRem() == 0);	//should be no reminders in the calendar

	//the following for loop inserts 50 identical reminders into the calendar, but addRem should return 0 on each iteration because each newly inserted reminder has the same date as all the previously added reminders, and addRem should insert new reminders BEFORE existing ones with the same date
	for (int i = 0; i < MAX_REM; i++)
	{
		index = cal1.addRem(rem1);	
	}

	if (cal1.getNumRem() != 50) {
		cout << "getNumRem did not return the correct number of reminders stored in the calendar" << endl;
		cout << "it instead reported: " << cal1.getNumRem() << " reminders in the calendar" << endl;
	}

	if (index != 0) {	//tests whether addRem inserts new reminders before (ahead of) existing reminders with the same date
		cout << "addRem failed to insert identical reminders before (ahead of) existing ones with the same date" << endl;
	}

	if (cal1.findRem(d1) != 0) {	//tests whether findRem finds the first reminder for its given date and returns its index
		cout << "findRem failed to find the first reminder for the given date and return its index" << endl;
	}

	if (cal1.deleteRem() != 50) {
		cout << "deleteRem did not delete all reminders earlier than today" << endl;
	}

	assert(cal1.getNumRem() == 0);	//there should be no reminders in the array

	// Here is an example of using a try-catch block to test exception throwing.
	// You place your code that should generate an exception in the "try" block, and you
	// specify the exception you are catching in the "catch" expression. If an exception is
	// thrown, control will branch immediately to the "catch" block. If an exception is not
	// thrown, the "try" block will fully execute and then control goes to whatever follows
	// the try-catch block.
	// Experiment: change the number of iterations of the loop and observe the behavior. Try 10 & 100.
	try
	{
		for (int i = 0; i<100; i++)  // attempt to insert 100 reminders in a calendar that can only hold 50
		{
			cal1.addRem(rem1);
		}
		cout << "\nTHIS MESSAGE SHOULD NOT BE SEEN. An overflow exception was not thrown!!" << endl;
	}
	catch (std::overflow_error &excpt)
	{
		cout << "Exception successfully thrown & caught:: " << excpt.what() << endl;
	}



	cout << "\nEnd of tests. Press enter to exit.";
	char tt;
	tt = cin.get();

}

