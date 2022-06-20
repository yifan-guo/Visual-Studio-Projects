#include <iostream>
#include <cstdlib>
#include "Date.h"
#include "Reminder.h"
#include "P_Reminder.h"

int main() {
    Reminder rem1, rem2("1/2/34", "String for rem2"), *rem3;
    rem1.setmsg("String for rem1");
    rem3 = new Reminder;
    rem3->setmsg("String for rem3");
    (*rem3)++;
    (*rem3)++;
    std::cout << std::endl;
    std::cout << "\nrem1:\n" << rem1 << std::endl;
    std::cout << "\nrem2:\n" << rem2 << std::endl;
    std::cout << "\nrem3:\n" << *rem3 << std::endl;


    if (rem1 < *rem3) {
        std::cout << "\nrem1 is before rem3" << std::endl;
    } else {
        std::cout << "\nrem1 is not before rem3" << std::endl;
    }


    delete rem3;

    std::cout << "\n\nPress enter to quit";
    std::cin.get();

    return 0;
}

