// File name: test3.cpp
// Author: Yifan Guo
// VUnetid: guoy5
// Email: yifan.guo@vanderbilt.edu
// Class: CS270
// Date: 9/17/16
// Honor statement: I pledge to the honor statement.
// Assignment Number: 03

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "Date.h"
#include "Reminder.h"
#include "P_Reminder.h"


const int MAX = 50;

// Dynamically create some sort of Date object and return its pointer via the
// function parameter, and return true.
// Return false if no Date object was created (i.e., the user selected quit)
bool getReminder(Date *&rem);


// Compare two Date objects for the purpose of sorting
bool remCompare(Date *a, Date *b);


int main() {
    Date *date_list[MAX];
    int in;

    std::cout << "\nWhen prompted, enter a 'd' for a Date, enter an 'r' for a \n";
    std::cout << "Reminder, enter a 'p' for a PriorityReminder, or enter a 'q'\n";
    std::cout << "to quit.\n\n";

    // call getReminder() to get a Date object.
    // the Date object may be a Date, Reminder, or PriorityReminder object.
    for (in = 0; getReminder(date_list[in]) && in < MAX; in++) {} // empty loop body


    // sort the array of Date objects
    std::sort(date_list, date_list + in, remCompare);


    // now print them out in sorted order
    std::cout << "\n\n\nDates to remember: \n" << std::endl;
    for (int out = 0; out < in; out++)
        std::cout << *date_list[out] << std::endl;
    // the above statement does the right thing if operator<<
    // is defined in terms of a virtual print() method


    // now delete all objects created
    for (int out = 0; out < in; out++) {
        delete date_list[out];
        date_list[out] = nullptr;
    }


    std::cout << "\n\nPress enter to quit";
    std::cin.get();

    return 0;
}


// Dynamically create some sort of Date object and return its pointer via the
// function parameter, and return true.
// Return false if no Date object was created (i.e., the user selected quit)
bool getReminder(Date *&rem) {
    static const int BUF_SIZE(256);
    static char buf[BUF_SIZE];
    std::string msgstr;
    std::string datestr;
    std::string ans;

    std::cout << std::endl;
    std::cout << "enter d|p|r|q: " << std::flush;
    std::cin.getline(buf, BUF_SIZE);
    ans = (std::string) buf;

    // dynamically create objects based on the type desired

    switch (ans[0]) {

        case 'd':
        case 'D':
            std::cout << "Enter date (mm/dd/yy): " << std::flush;
            std::cin.getline(buf, BUF_SIZE);
            datestr = (std::string) buf;
            Date *rem1;
            rem1 = new Date;
            rem1->setDate(datestr);
            rem = rem1;  // copy the pointer
            return true;

        case 'p':
        case 'P':
            std::cout << "Enter date (mm/dd/yy): " << std::flush;
            std::cin.getline(buf, BUF_SIZE);
            datestr = (std::string) buf;
            PriorityReminder *rem2;
            rem2 = new PriorityReminder;
            rem2->setDate(datestr);
            std::cout << "Enter priority reminder message for "
                      << rem2->getDate() << ": " << std::flush;
            std::cin.getline(buf, BUF_SIZE);
            msgstr = (std::string) buf;
            if (msgstr.length() > 0)
                rem2->setmsg(msgstr);
            rem = rem2;  // copy the pointer
            return true;

        case 'r':
        case 'R':
            std::cout << "Enter date (mm/dd/yy): " << std::flush;
            std::cin.getline(buf, BUF_SIZE);
            datestr = (std::string) buf;
            Reminder *rem3;
            rem3 = new Reminder;
            rem3->setDate(datestr);
            std::cout << "Enter reminder message for "
                      << rem3->getDate() << ": " << std::flush;
            std::cin.getline(buf, BUF_SIZE);
            msgstr = (std::string) buf;
            if (msgstr.length() > 0)
                rem3->setmsg(msgstr);
            rem = rem3;  // copy the pointer
            return true;

        case 'q':
        case 'Q':
        default:
            return false;

    }
}


// Compare two Date objects for the purpose of sorting
bool remCompare(Date *a, Date *b) {

    // Return ordering information on the Date objects by using
    // the overloaded relational operators of the Date class.
    // Impose a "strict weak ordering" (do a web search).

    // Return true if the first object should be sorted before the second,
    // otherwise return false

    if (*a < *b) {
        return true;     // sort a ahead of b
    } else if (*a > *b) {
        return false;    // sort b ahead of a
    } else if (*a == *b) {
		if (dynamic_cast<PriorityReminder*> (a) != 0 && dynamic_cast<PriorityReminder*> (b) == 0) {
			return true;
		}
		else {
			return false;		//if both a and b are PR's, don't sort a ahead of b
		}
    } else {
        throw std::logic_error("ERROR IN REMCOMPARE");
    }
}

