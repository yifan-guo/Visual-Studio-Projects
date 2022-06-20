#include <iostream>
#include <string>
using namespace std;

void main() {
	int* grid = new int[4];
	*grid = 1;
	grid[1] = 2;
	grid[2] = 3;
	grid[3] = 4;

	/*int a[4];
	*(a + 1) = 1;
	cout << a << endl;
	for (size_t i = 0; i < 4; i++) {
		cout << a[i] << endl;
	}*/

	string empty = "a";
	bool isempty = false;
	if (empty.substr(1) == "") {
		isempty = true;
	}
	cout << isempty << endl;
	cin.get();
}