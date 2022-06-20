#include <string>
using namespace std;

class foo
{
private:
	string name;

public:
	foo(); //default constructor
	foo(string initName); //alt constructor

	void intro(); // class method
};