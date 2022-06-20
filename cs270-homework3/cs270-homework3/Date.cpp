// File name: Date.cpp
// Author: Yifan Guo
// VUnetid: guoy5
// Email: yifan.guo@vanderbilt.edu
// Class: CS270
// Date: 9/17/16
// Honor statement: I pledge to the honor statement.
// Assignment Number: 03

#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include "Date.h"


// initialize the class variable(s)
int Date::days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// Constructors

Date::Date()    // default constructor - set to today's date
{
	struct tm *today;

	time_t now;
	time(&now);
	today = localtime(&now);  //may issue a warning message with some compilers; please ignore them
	day = today->tm_mday;
	month = today->tm_mon + 1;
	year = today->tm_year +
		1900; // tm_year returns the number of years passed since 1900. To get the absolute value of today's year we add 1900
}

Date::Date(const int m, const int d, const int y) {
	setDate(m, d, y);
}

Date::Date(const std::string &dateStr)  // set to MM/DD/YY string
{
	setDate(dateStr);
	return;
}

Date::Date(const char *dateCStr) {
	std::string tmpDateStr = (std::string) dateCStr;
	setDate(tmpDateStr);
	return;
}

Date::~Date() {}


// Mutators


void Date::setDate(const int m, const int d, const int y) {
	if (m < 1 || m > 12)        // Validate month
	{
		throw std::invalid_argument("Month must be a value between 1 and 12.");
	}
	month = m;

	if (d < 1 || d > days[m])    // Validate day
	{
		throw std::invalid_argument("Day value invalid for the given month.");
	}
	day = d;

	if (y < 1 || y > 9999)        // Validate year
	{
		throw std::invalid_argument("Year must be a value between 0 and 9999");
	}
	year = y;
}

void Date::setDate(const Date &d) {
	day = d.day;
	month = d.month;
	year = d.year;
}

void Date::setDate(const std::string &dateStr) {
	std::string manipString = dateStr, subStr = "", errorStr = "", fwdSlash = "/";
	size_t index = 0, foundPos = 0;
	int m, d, y;


	foundPos = dateStr.find(fwdSlash);    // first slash
	if (foundPos != std::string::npos || foundPos == 1 || foundPos == 2) {
	}
	else
		throw std::invalid_argument("Please enter date in the format MM/DD/YYYY.");

	foundPos = dateStr.find(fwdSlash);    // second slash
	if (foundPos != std::string::npos || foundPos == 3 || foundPos == 4 || foundPos == 5) {
	}
	else
		throw std::invalid_argument("Please enter date in the format MM/DD/YYYY.");

	// ------------- End of format validation code ------------------------
	//-------------- Parsing starts here -----------------------------------

	index = manipString.find("/");
	subStr = manipString.substr(0, index);
	m = atoi(subStr.c_str());		//convert c-string to integer

	manipString = manipString.substr(index + 1);
	index = manipString.find("/");  // check to make sure / was found and throw an exception if not there
	subStr = manipString.substr(0, index);
	d = atoi(subStr.c_str());

	manipString = manipString.substr(index + 1);
	y = atoi(manipString.c_str());

	setDate(m, d, y);

}


void Date::setDate(const char *cstr) {
	std::string tmpDateStr = (std::string) cstr;
	setDate(tmpDateStr);
}


void Date::incrementDay() {
	++day;
	if (day > days[month]) {
		day = 1;    // have rolled over a month
		incrementMonth();
	}

}

void Date::decrementDay() {
	--day;
	if (day == 0) {
		decrementMonth();  // have rolled over a month
		day = days[month];
	}
}

void Date::incrementMonth() {
	++month;
	if (month > 12) {   // rolled over a year?
		month = 1;
		incrementYear();
	}
}

void Date::decrementMonth() {
	--month;
	if (month < 1) {   // rolled over a year?
		month = 12;
		decrementYear();
	}
}

void Date::incrementYear() {
	++year;
	if (year > 9999)
		throw std::out_of_range("Year value overflow; greater than 4 digits.");
}

void Date::decrementYear() {
	--year;
	if (year < 1)
		throw std::out_of_range("Year value underflow; no longer positive.");
}


// Accessors

std::string Date::getDate() const {
	return toString();
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

int Date::getYear() const {
	return year;
}

std::string Date::toString() const {
	std::ostringstream result;
	if (month < 10) result << "0"; // produce a leading zero when necessary
	result << month << "/";
	if (day < 10) result << "0";
	result << day << "/"
		<< year;  // not adding leading zeros for year - e.g. 02/28/99 would mean 28th Feb 99 (year 99).
	return result.str();
}

// Output functions

void Date::display(void) const {
	print(std::cout);
}


void Date::print(std::ostream &os) const {
	os << toString();

}


// logical methods

bool Date::equals(const Date &d) const {
	return day == d.day &&
		month == d.month &&
		year == d.year;
}

bool Date::lessthan(const Date &d) const {
	return year < d.year ||
		(year == d.year && month < d.month) ||
		(year == d.year && month == d.month && day < d.day);
}


// overloaded operators ======================

// assignment operators

const Date &Date::operator+=(int add)   // adds days to date
{

	if (add < 0) {        // adding a negative?
		*this -= (-add);     // then call subtraction
		return *this;
	}
	while (add--) {
		incrementDay();
	}
	return *this;   // returns the updated date
}

const Date &Date::operator-=(int sub) {
	if (sub < 0) {        // subtracting a negative?
		*this += (-sub);     // then call addition
		return *this;
	}
	while (sub) {
		if (sub >= day) {
			sub -= day;
			decrementMonth();
			day = days[month];
		}
		else {
			day -= sub;
			sub = 0;    // exit condition
		}
	}
	return (*this);
}


// arithmetic operators

Date Date::operator+(int add) const {
	Date result = *this;   // make copy of date
	result += add;         // do addition
	return result;         // return it
}


Date Date::operator-(int sub) const {
	Date result = *this;   // make copy of date
	result -= sub;         // do subtraction
	return result;         // return it
}

Date &Date::operator++()   // prefix increment
{
	*this = *this + 1;
	return *this;
}

Date Date::operator++(int a)  // postfix increment
{
	Date d = *this;

	*this = *this + 1;
	return d;
}

Date &Date::operator--()   // prefix decrement
{
	*this = *this - 1;
	return *this;
}

Date Date::operator--(int a)  // postfix decrement
{
	Date d = *this;

	*this = *this - 1;
	return d;
}


// Number of days between two dates; i.e., difference operator
int Date::operator-(const Date &d) const {
	Date start = d;
	Date end = *this;
	int diff = 0;
	int minusflag = 1;   //make difference negative if needed

	if (this->lessthan(d)) {
		start = *this;
		end = d;
		minusflag = -1;
	}
	while ((start++).lessthan(end))
		diff++;
	return diff * minusflag;
}


////// FRIEND FUNCTIONS DEFINED HERE


// Friend operator
std::ostream &operator<<(std::ostream &out, const Date &d) {
	d.print(out);
	return out;
}


////// FREE FUNCTIONS DEFINED HERE
Date operator+ (int add, const Date &rhs) {
	return rhs + add;
}

bool operator<(const Date &lhs, const Date &rhs) {
	return lhs.lessthan(rhs);
}

bool operator==(const Date &lhs, const Date &rhs) {
	return lhs.equals(rhs);
}

bool operator<=(const Date &lhs, const Date &rhs) {
	return lhs.lessthan(rhs) || lhs.equals(rhs);
}

bool operator>(const Date &lhs, const Date &rhs) {
	return !lhs.lessthan(rhs) && !lhs.equals(rhs);
}

bool operator>=(const Date &lhs, const Date &rhs) {
	return !lhs.lessthan(rhs);
}

bool operator!=(const Date &lhs, const Date &rhs) {
	return !lhs.equals(rhs);
}

