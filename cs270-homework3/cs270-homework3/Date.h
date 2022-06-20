// File name: Date.h
// Author: Yifan Guo
// VUnetid: guoy5
// Email: yifan.guo@vanderbilt.edu
// Class: CS270
// Date: 9/10/16
// Honor statement: I pledge to the honor statement.
// Assignment Number: 02

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>


class Date {
private:
	int day;
	int month;
	int year;
	static int days[13];     // how many days in each month with 1-based indexing

public:

	// constructors
	Date();    // default ctor sets Date to today
	Date(const int m, const int d, const int y);

	Date(const std::string &dateStr);

	Date(const char *dateCStr);

	//destructor
	virtual ~Date();

	// mutators
	void setDate(const Date &d);

	void setDate(const int m, const int d, const int y);

	void setDate(const std::string &dateStr);

	void setDate(const char *cstr);

	void incrementDay();

	void decrementDay();

	void incrementMonth();

	void decrementMonth();

	void incrementYear();

	void decrementYear();

	// accessors
	std::string getDate() const;

	int getMonth() const;

	int getDay() const;

	int getYear() const;

	std::string toString() const;

	// output functions
	void display() const;

	virtual void print(std::ostream &os = std::cout) const;

	// logical methods
	bool equals(const Date &d) const;

	bool lessthan(const Date &d) const;


	// overloaded operators ======================

	// assignment operators
	const Date &operator+=(int add);

	const Date &operator-=(int sub);

	// arithmetic operators
	Date operator+(int add) const;       // add days to a date
	Date operator-(int sub) const;       // subtract days from a date
	int operator-(const Date &d) const; // find difference between two dates

	Date &operator++();                   // pre increment
	Date operator++(int);                 // post increment
	Date &operator--();                   // pre decrement
	Date operator--(int);                 // post decrement


										  // stream insertion as a friend function
	friend std::ostream &operator<<(std::ostream &os, const Date &d);
};


////// FREE FUNCTIONS DEFINED HERE, AFTER THE CLASS
Date operator+ (int add, const Date &rhs);
bool operator<(const Date &lhs, const Date &rhs);
bool operator==(const Date &lhs, const Date &rhs);
bool operator<=(const Date &lhs, const Date &rhs);
bool operator>(const Date &lhs, const Date &rhs);
bool operator>=(const Date &lhs, const Date &rhs);
bool operator!=(const Date &lhs, const Date &rhs);


#endif
