#include <iostream>
#include <string>
#include "foo.h"
#include "Point.h"
using namespace std;

int main()
{
	cout << "Hello World!!" << endl;

	cout << "Please enter your name: ";
	string name;
	cin >> name; //reads only one token, only  first name
	foo you(name);
	you.intro();

	Point p1;
	cout << p1 << endl;

}