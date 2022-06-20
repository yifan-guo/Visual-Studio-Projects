#include "Header.h"
using namespace std;

int procedure1(int a, int b) {
	a = a - b;
	cout << a << endl;
	return a + 3*b;
}

void procedure2(int a, int* b) {
	a = a - 3;
	b = b + a;
}

int main() {
	int z = 37;
	int x, y;
	cin >> x >> y; 
	int sum = procedure1(x, y);
	cout << x << y << sum << endl;

	int* p = &z;
	procedure2(x, p);
	cout << x << z << endl;

	cout << "Press Enter to exit." << endl;
	cin.get();
	cin.get();
}