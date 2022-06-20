// File name: P_Reminder.cpp
// Author: Yifan Guo
// VUnetid: guoy5
// Email: yifan.guo@vanderbilt.edu
// Class: CS270
// Date: 9/17/16
// Honor statement: I pledge to the honor statement.
// Assignment Number: 03

#ifndef P_REMINDER_CPP
#define P_REMINDER_CPP

#include "P_Reminder.h"
#include <string>

PriorityReminder::PriorityReminder() {
    // nothing to do
}


PriorityReminder::PriorityReminder(const Date &d, const std::string &m)
        : Reminder(d, m) {
    // nothing else to do
}


void PriorityReminder::print(std::ostream &out) const {
    out << "On " << getDate() << ": <<IMPORTANT>> " << getmsg();
}

std::ostream &operator<<(std::ostream &os, const PriorityReminder &rem) {
    rem.print(os);
    return os;
}


#endif
