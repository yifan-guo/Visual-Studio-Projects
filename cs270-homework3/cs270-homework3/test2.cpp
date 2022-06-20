#include <iostream>
#include <cstdlib>
#include "Date.h"
#include "Reminder.h"
#include "P_Reminder.h"


int main() {
    Reminder test1, test2("1/2/34", "String for test2"), *test3;
    PriorityReminder test4, test5("1/1/07", "String for test5"), *test6;
    test1.setmsg("String for test1");
    test4.setmsg("String for test4");
    test4++;
    test3 = new Reminder;
    test6 = new PriorityReminder("4/3/21", "String for test6");
    test3->setmsg("String for test3");
    (*test3)++;
    (*test3)++;
    std::cout << std::endl;
    std::cout << "SECTION 1 ==========================" << std::endl;
    std::cout << "test1: " << test1 << std::endl;
    std::cout << "test2: " << test2 << std::endl;
    std::cout << "test3: " << *test3 << std::endl;
    std::cout << "test4: " << test4 << std::endl;
    std::cout << "test5: " << test5 << std::endl;
    std::cout << "test6: " << *test6 << std::endl;

    test3->setmsg("");
    test4.setmsg("");
    std::cout << std::endl;
    std::cout << "SECTION 2 ==========================" << std::endl;
    std::cout << "test1: " << test1 << std::endl;
    std::cout << "test2: " << test2 << std::endl;
    std::cout << "test3: " << *test3 << std::endl;
    std::cout << "test4: " << test4 << std::endl;
    std::cout << "test5: " << test5 << std::endl;
    std::cout << "test6: " << *test6 << std::endl;

    test3->setmsg("reset test3");
    test4.setmsg("reset test4");
    std::cout << std::endl;
    std::cout << "SECTION 3 ==========================" << std::endl;
    test1.print();
    std::cout << std::endl;
    test2.print();
    std::cout << std::endl;
    test3->print();
    std::cout << std::endl;
    test4.print();
    std::cout << std::endl;
    test5.print();
    std::cout << std::endl;
    test6->print();
    std::cout << std::endl;

    Date today;
    std::cout << std::endl;
    today.print();
    std::cout << std::endl;

    Date *dptr;


    std::cout << std::endl;
    std::cout << "SECTION 4 ==========================" << std::endl;

    dptr = &today;
    dptr->print();
    std::cout << std::endl;

    dptr = &test1;
    dptr->print();
    std::cout << std::endl;

    dptr = &test2;
    dptr->print();
    std::cout << std::endl;

    dptr = test3;
    dptr->print();
    std::cout << std::endl;

    dptr = &test4;
    dptr->print();
    std::cout << std::endl;

    dptr = &test5;
    dptr->print();
    std::cout << std::endl;

    dptr = test6;
    dptr->print();
    std::cout << std::endl;


    delete test3;
    delete test6;

    std::cout << "\n\nPress enter to quit";
    std::cin.get();

    return 0;
}

