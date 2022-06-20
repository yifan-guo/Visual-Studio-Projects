// File name: Reminder.h
// Author: Yifan Guo
// VUnetid: guoy5
// Email: yifan.guo@vanderbilt.edu
// Class: CS270
// Date: 9/17/16
// Honor statement: I pledge to the honor statement.
// Assignment Number: 03

#ifndef REMINDER_H
#define REMINDER_H

#include "Date.h"
#include <string>
#include <iostream>


class Reminder : public Date {
private:
    std::string msg;
public:
    Reminder();  //default ctor

    Reminder(const Date &d, const std::string &m = "");  //alt ctor

    // Reminder(const Reminder &); //default copy ctor is sufficient
    // ~Reminder();  //default dtor is sufficient

    void setmsg(const std::string &m);

    std::string getmsg(void) const;

    virtual void print(std::ostream &out = std::cout) const;
};

std::ostream &operator<<(std::ostream &os, const Reminder &rem);

#endif
