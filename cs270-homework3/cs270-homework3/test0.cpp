#include <iostream>
#include "Date.h"

int main() {


    Date d4;   // get today's date


    std::cout << "test1: ";
    std::cout << d4 << std::endl;

    std::cout << "test2: ";
    std::cout << d4 + 2 << std::endl;

    std::cout << "test3: ";
    std::cout << d4 - 2 << std::endl;

    std::cout << "test4: ";
    std::cout << d4++ << "   ";   // post increment
    std::cout << d4 << std::endl;

    std::cout << "test5: ";
    std::cout << --d4 << "   ";   // pre decrement
    std::cout << d4 << std::endl;

    Date d5(d4);             // call copy constructor
    d4 += 365;               // add 365 days
    std::cout << "test6: ";
    std::cout << d4 << std::endl;

    std::cout << "test7: ";
    std::cout << d4 - d5 << std::endl;   // find difference


/************************************************************/
    std::cout << "test8: ";
    if (d4 < d5)
        std::cout << d4 << " is less than " << d5 << std::endl;
    else
        std::cout << d4 << " is greater than or equal " << d5 << std::endl;
/************************************************************/


/************************************************************/
    Date d2(9, 12, 9);
    Date d3;
    d3.setDate(9, 17, 9);

    if (d2 == d3) {
        std::cout << d2 << " is equal to " << d3 << std::endl << std::endl;
    } else if (d2 < d3) {
        std::cout << d2 << " is earlier than " << d3 << std::endl;
        std::cout << "and the number of days between them is: "
                  << d3 - d2 << std::endl << std::endl;
    } else if (d2 > d3) {
        std::cout << d2 << " is later than " << d3 << std::endl;
        std::cout << "and the number of days between them is: "
                  << d2 - d3 << std::endl << std::endl;
    } else {
        std::cout << "ERROR!!";
    }

    d2 = d2 + 5;

    if (d2 == d3) {
        std::cout << d2 << " is equal to " << d3 << std::endl << std::endl;
    } else if (d2 < d3) {
        std::cout << d2 << " is earlier than " << d3 << std::endl;
        std::cout << "and the number of days between them is: "
                  << d3 - d2 << std::endl << std::endl;
    } else if (d2 > d3) {
        std::cout << d2 << " is later than " << d3 << std::endl;
        std::cout << "and the number of days between them is: "
                  << d2 - d3 << std::endl << std::endl;
    } else {
        std::cout << "ERROR!!";
    }

/************************************************************/



    std::cout << "\n\nPress enter to exit" << std::endl;
    std::cin.get();
    return 0;
}
