// File name: CalTest.cpp
// Author: Yifan Guo
// VUnetid: guoy5
// Email: yifan.guo@vanderbilt.edu
// Class: CS2201
// Date: 9/28/15
// Honor statement: I pledge to the honor statement.
// Assignment Number: 02
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
		Reminder test = cal1.getRem(cal1.maxSize());	//test getRem(size_t index), attempt to get the reminder at an invalid index
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

	if (cal1.displayRem(cal1.maxSize()) != "") {	//test displayRem(size_t index), attempt to display a string of the reminder at a invalid index
		cout << "displayRem failed to recognize the invalid index" << endl;
		cout << "displayRem returned the following reminder: " << cal1.displayRem(cal1.maxSize()) << endl;
	}

	if (cal1.displayRem(-1) != "") {
		cout << "displayRem failed to recognize the invalid index" << endl;
		cout << "displayRem returned the following reminder: " << cal1.displayRem(cal1.maxSize()) << endl;
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

	if (cal1.deleteRem(cal1.maxSize()) != 0) {		//tests whether deleteRem returns 0 when given an invalid index
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
	else {
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
	for (int i = 0; i < (int) cal1.maxSize(); i++)
	{
		index = cal1.addRem(rem1);
	}

	if (cal1.getNumRem() != cal1.maxSize()) {
		cout << "getNumRem did not return the correct number of reminders stored in the calendar" << endl;
		cout << "it instead reported: " << cal1.getNumRem() << " reminders in the calendar" << endl;
	}

	if (index != 0) {	//tests whether addRem inserts new reminders before (ahead of) existing reminders with the same date
		cout << "addRem failed to insert identical reminders before (ahead of) existing ones with the same date" << endl;
	}

	if (cal1.findRem(d1) != 0) {	//tests whether findRem finds the first reminder for its given date and returns its index
		cout << "findRem failed to find the first reminder for the given date and return its index" << endl;
	}

	if (cal1.deleteRem() != cal1.maxSize()) {
		cout << "deleteRem did not delete all reminders earlier than today" << endl;
	}

	assert(cal1.getNumRem() == 0);	//there should be no reminders in the calendar

	//////////////////////////corrections/////////////////////////////////

	//Failed to test displayRem(size_t) on an empty calendar (-1pt)
	if (cal1.displayRem(0) != "") {
		cout << "unexpected reminder in calendar" << endl;
		cout << "displayRem returned the following calendar: " + cal1.displayRem(0) << endl;
	}
	//Failed to test deleteRem(string) function on an empty calendar(-1pt)
	if (cal1.deleteRem("Hello World") != 0) {
		cout << "Unexpected reminders deleted" << endl;
	}

	//Failed to test deleteRem(Date, Date) function on an empty calendar(-1pt)
	if (cal1.deleteRem(d1, d2) != 0) {
		cout << "Unexpected reminders deleted" << endl;
	}

	//Failed to test deleteRem() function w / o params on an empty calendar(-1pt)
	if (cal1.deleteRem() != 0) {
		cout << "Unexpected reminders deleted\n" << endl;
	}

	assert(cal1.getNumRem() == 0);

	//Failed to test displayRem(Date, Date) function with the first Date parameter being a later date than the second Date parameter(-1pt)
	cal1.addRem(rem1);
	cal1.addRem(rem2);
	cal1.addRem(rem3);
	cal1.addRem(rem4);
	cal1.addRem(rem5);


	if (cal1.displayRem(d2, d1) != "On 08/26/2015: Go over class syllabus\nOn 08/26/2015: First day of classes\nOn 09/01/2015: Last day to drop a class\n") {
		cout << "displayRem did not display the reminders between the specified range of dates\n" << endl;
		cout << cal1.displayRem(d2, d1) << endl;
	}

	//Failed to test displayRem(Date, Date) function with the larger Date parameter being smaller than all dates in the calendar(-1pt)
	if (cal1.displayRem(d1 - 3, d1 - 2) != "") {
		cout << "Unexpected reminder in calendar: " << cal1.displayRem(d1 - 3, d1 - 2) << endl;
	}

	//Failed to test displayRem(Date, Date) function with the range of Dates starting and ending in the middle of the calendar(-1pt)
	if (cal1.displayRem(d2, d4) != "On 09/01/2015: Last day to drop a class\nOn " + d4.toString() + ": Work on CS project\n") {
		cout << "displayRem did not work as expected\n" << endl;
		cout << cal1.displayRem(d2, d4) << endl;
	}

	//Failed to test deleteRem(string) function such that no matches were found / deleted(-1pt)
	if (cal1.deleteRem("Hello World!") != 0) {
		cout << "Unexpected reminders deleted\n" << endl;
	}

	//Failed to test deleteRem(Date, Date) function with the two date parameters out of order(the first one being later than the second one) (-1pt)
	if (cal1.deleteRem(d4, d2) != 2) {
		cout << "deleteRem did not function properly when given two date parameters out of order (the first one being later than the second one)" << endl;
	}

	cal1.deleteRem(d1, d3);
	assert(cal1.getNumRem() == 0);

	//Graded by : Alexis Russell


	// Here is an example of using a try-catch block to test exception throwing.
	// You place your code that should generate an exception in the "try" block, and you
	// specify the exception you are catching in the "catch" expression. If an exception is
	// thrown, control will branch immediately to the "catch" block. If an exception is not
	// thrown, the "try" block will fully execute and then control goes to whatever follows
	// the try-catch block.
	// Experiement: change the number of iterations of the loop and observe the behavior. Try 10 & 100.


	//insert 100 additional reminders in a calendar with maxRem = 50
	for (int i = 0; i < 100; i++)  
	{		
		cal1.addRem(rem1);
	}
	if (cal1.maxSize() != DEFAULT_MAX * 2) {
		cout << "maxRem did not double as expected" << endl;
	}

	cal1.deleteRem();
	assert(cal1.getNumRem() == 0);	

	cal1.addRem(rem1);
	cal1.addRem(rem2);
	cal1.addRem(rem3);
	cal1.addRem(rem4);
	cal1.addRem(rem5);

	//cout << cal1.displayRem() << cal1.getNumRem() << cal1.maxSize() << endl;
	
	Calendar cal2(cal1);		//copy ctor

	//cout << cal2.displayRem() << cal2.getNumRem() << cal2.maxSize() << endl;
	
	//maxSize of cal1 should not change when cal2 is merged
	cal1.mergeCal(cal2);
	if (cal1.maxSize() != DEFAULT_MAX * 2) {
		cout << "maxRem should not have changed" << endl;
	}

	//cout << cal1.getNumRem() << endl;
	//cout << cal1.displayRem(d1, d3) << endl;

	Date d5(8, 26, 2015);
	Reminder rem6(d5, "8/26");
	Date d6(8, 27, 2015);
	Reminder rem7(d6, "8/27");
	Date d7(8, 28, 2015);
	Reminder rem8(d7, "8/28");
	Date d8(8, 29, 2015);
	Reminder rem9(d8, "8/29");
	Date d9(8, 30, 2015);
	Reminder rem10(d9, "8/30");
	Date d10(8, 31, 2015);
	Reminder rem11(d10, "8/31");

	//even though cal3's maxRem was initialized to 1
	//3 reminders were added to cal3 to test whether it grows
	Calendar cal3(1);		//alt ctor
	assert(cal3.maxSize() == 1);
	cal3.addRem(rem11);
	cal3.addRem(rem10);
	cal3.addRem(rem9);
	if (cal3.getNumRem() != 3) {
		cout << "Error occurred in addRem, numRem is not correct" << endl;
	}
	if (cal3.maxSize() != 4) {
		cout << "Error: maxSize did not double as expected" << endl;
	}
	//cout << cal3.displayRem() <<cal3.maxSize() << endl;


	//assigning a smaller calendar to a bigger calendar
	Calendar cal4(1);
	cal4 = cal3;			//assignment operator
	if (cal4.maxSize() != cal3.maxSize()) {
		cout << "Error: maxSize did not change as expected" << endl;
	}
	//cout << cal4.displayRem() << cal4.maxSize() << endl;

	//assigning a bigger calendar to a smaller calendar
	Calendar cal8(cal1);
	//cout << cal8.displayRem() << endl;
	Calendar cal9(1);
	cal9.addRem(rem6);
	cal8 = cal9;
	if (cal8.getNumRem() != 1) {
		cout << "Incorrect number of reminders." << endl;
	}
	if (cal8.maxSize() != 1) {
		cout << "Incorrect value of maxSize" << endl;
	}

	//merge two calendars without growing the base calendar
	//edge condition: size of base calendar is just big enough 
	//to hold all reminders
	Calendar cal5(1);
	cal5.addRem(rem6);

	//add reminders out of order using addRem	
	Calendar cal6(4);	
	cal5.addRem(rem8);
	cal5.addRem(rem7);
	cal5.addRem(rem9);

	//maxSize should not change after merging 
	cal6.mergeCal(cal5);
	if (cal6.maxSize() != 4) {
		cout << "Error: maxSize should not have doubled" << endl;
	}
	//cout << cal6.displayRem() << cal6.maxSize() << endl;

	//merge two calendars while growing the base calendar
	Calendar cal10(3);
	cal10.addRem(rem9);
	cal10.addRem(rem8);
	cal10.addRem(rem6);

	Calendar cal11(3);
	cal11.addRem(rem7);
	cal11.addRem(rem10);
	cal11.addRem(rem11);

	cal11.mergeCal(cal10);
	//cout << cal11.displayRem() << endl;
	if (cal11.maxSize() != 3 + 3 + DEFAULT_MAX) {
		cout << "maxRem did not change as expected" << endl;
	}
	if (cal11.getNumRem() != 6) {
		cout << "numRem is not correct" << endl;
	}

	//give the alt ctor an invalid index
	try
	{
		Calendar cal7(0);
		cout << "\nTHIS MESSAGE SHOULD NOT BE SEEN. An invalid argument exception was not thrown!!" << endl;
	}
	catch (std::invalid_argument &excpt)
	{
		cout << "Exception successfully thrown & caught:: " << excpt.what() << endl;
	}

	cout << "\nEnd of tests. Press enter to exit.";
	char tt;
	tt = cin.get();

}

