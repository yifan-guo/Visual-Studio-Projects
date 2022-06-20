// CS2201 Vanderbilt University
// Prof. Roth

#include <string>
#include "Reminder.h"
using namespace std;


//default constructor set date to today's date and message to empty string
Reminder::Reminder() : msg("")
{
}


//alt constructor
Reminder::Reminder(const Date& d, const string& m) : Date(d), msg(m)
{
}


//set the message of a reminder
void Reminder::setMsg(const string& msgStr)
{
	if (msgStr.length()!=0) 
	{
		msg=msgStr;
	} 
	else 
	{
		msg.clear();
   }
}

//get the message of a reminder
string Reminder::getMsg() const
{
  if (!msg.empty())
    return msg;
  else
    return "No Message";
}

//get the Date of a reminder
Date Reminder::getDate() const		// overridden getDate() function that returns date object instead of date string
{
	Date d;
	d.setDate(*this);
	return d;		// return date object
}

string Reminder::toString() const
{
	string tmp = "On " + Date::toString() + ": " + getMsg();
	return tmp;
}

void Reminder::print(ostream &out) const
{
  out << toString();
}

ostream& operator << (ostream& os, const Reminder& rem)
{
  rem.print(os);
  return os;
}


// Must override these operators so that they operate correctly for Reminders.
// We define them in terms of Date operators.
Reminder Reminder::operator+ (int add) const 
{
	Reminder temp(*this);
	temp += add;
	return temp;
}       


Reminder Reminder::operator- (int sub) const 
{
	Reminder temp(*this);
	temp -= sub;
	return temp;
}


// determine equality of two Reminders
bool Reminder::operator== (const Reminder& rhs) const 
{
	return this->getDate() == rhs.getDate() && this->msg == rhs.msg;
}