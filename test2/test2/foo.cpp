#include "foo.h"
#include <iostream>
using namespace std;

foo::foo()
{
	name = "No name yet";
}

foo::foo(string initName)
{
	name = initName;
}

void foo::intro()
{
	cout << "Hello " << name << endl; //assertion operator, asserts each string to cout
	cout << "Welcome to CS 201. I hope you enjoy it." << endl;
}
