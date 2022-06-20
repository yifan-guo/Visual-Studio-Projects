// File name: P_Reminder.h
// Author: Yifan Guo
// VUnetid: guoy5
// Email: yifan.guo@vanderbilt.edu
// Class: CS270
// Date: 9/17/16
// Honor statement: I pledge to the honor statement.
// Assignment Number: 03

#ifndef P_REMINDER_H
#define P_REMINDER_H

#include "Reminder.h"
#include <string>
#include <iostream>

class PriorityReminder : public Reminder {
private:
    // nothing
public:
    PriorityReminder();

    PriorityReminder(const Date &d, const std::string &m = "");

    virtual void print(std::ostream &out = std::cout) const;
};

std::ostream &operator<<(std::ostream &os, const PriorityReminder &rem);

#endif
