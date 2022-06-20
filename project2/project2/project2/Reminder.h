// CS201 Vanderbilt University
// Prof. Roth

#ifndef REMINDER_H
#define REMINDER_H

#include "Date.h"
#include <string>
using namespace std;


class Reminder : public Date
{
private:
  string msg;

public:
  Reminder();  //default constructor set date to today's date and message to empty string
  Reminder(const Date& d, const string& m = "");   //alt constructor

  void setMsg(const string& msgStr);  //set the message of a Reminder

  string getMsg() const;  //get the message of a Reminder
  Date getDate() const;   //get the Date of a Reminder
  string toString() const; //get a string version of a Reminder

  // must override these operators so that they operate correctly for Reminders
  Reminder operator+ (int add) const;       // add days to a Reminder
  Reminder operator- (int sub) const;       // subtract days from a Reminder
  bool operator== (const Reminder& rhs) const;  // determine equality of two Reminders


  virtual void print(ostream &out = cout) const;
};

ostream& operator << (ostream& os, const Reminder& rem);

typedef Reminder* ReminderPtr;

#endif
