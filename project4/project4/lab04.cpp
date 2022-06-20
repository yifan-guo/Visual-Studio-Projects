// File name: lab04.cpp
// Author: Yifan Guo	
// VUnetid: guoy5	
// Email: yifan.guo@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 04 
// Honor statement: I pledge to the honor statement.
// Description: write a brief but complete description
//  of what the program does. Use multiple lines as needed.
// Last Changed: 10/21/15

// Recursive programming lab


#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <cassert>
#include <cmath>
#include "lab04.h"
using namespace std;

//Task: compute the sum of an array of integers
//Pre: anArray is an array of 'size' integers, size is nonnegative
//Post: the sum of anArray[0]...anArray[size-1] is returned
// Additional requirement: This function must be done by dividing the array 
//   in half and performing recursive calls on each half (as opposed to just 
//   shrinking the size by one each time). Hint: use pointer arithmetic
int sumArray(int anArray[], int size) {
	if (size == 0) {	
		return 0;
	}
	if (size == 1) {	
		return anArray[0];
	}
	int mid = size/2;
	int * upperHalf = anArray + mid;
	return sumArray(anArray, mid) + sumArray(upperHalf, size - mid);
}

//Task: determine if target is in the set
//Pre: set is an array of 'size' integers, size is nonnegative
//Post: true is returned if target is in the set, else false;
//  the set is unchanged
bool member(int target, const int set[], int size) {
	if (size == 0) {
		return false;
	}
	if (target == set[0]) {
		return true;
	}
	else {
		return member(target, set + 1, size - 1);
	}
}

// Task: Given a string, compute recursively a new string where all the adjacent 
//   chars are now separated by a "*".
// Pre: str is a string (may be empty).
// Post: a correctly starred string is returned.
// Examples:  
//   addStar("hello") --> "h*e*l*l*o"
//   addStar("abc") --> "a*b*c"
//   addStar("ab") --> "a*b"

string addStar(const string& str) {
	if (str.length() == 0) {
		return str;
	}
	if (str.length() == 1) {
		return str;
	}
	return str.substr(0, 1) + "*" + addStar(str.substr(1, str.length() - 1));
}

//Task: compute the sum of the first n harmonic terms
//Pre: n is a positive integer
//Post: the sum of the first n harmonic terms is returned.
// The harmonic series is 1 + (1/2) + (1/3) + (1/4) + ...
double harmonicSum(int n) {
	if (n == 1) {
		return double(1);
	}
	return 1.0 / n + harmonicSum(n - 1);
}

//Task: determine if a string is a palindrome
//Pre: str is a string object
//Post: returns true if str is a palindrome, otherwise returns false
//      The test is case insensitive [look up toupper() and
//      tolower()]. You do not need to worry about
//      trimming blanks from the ends of the string.
//Note: the empty string is a palindrome
bool isPalindrome(const string& str) {
	if (str.length() <= 1) {
		return true;
	}
	return (tolower(str[0]) == tolower(str[str.length() - 1]) 
		&& isPalindrome(str.substr(1, str.length() - 2) ) );
}

//Task: replace all occurrences of 'target' in the array 'numbers'
//      with 'replacement'
//Pre: 'numbers' is an array of 'size' integers, size is nonnegative
//Post: all occurrences of 'target' in 'numbers' have been replaced
//      with 'replacement'; the number of replacements performed is
//      returned to the caller.
int replace(int target, int replacement, int numbers[], int size) {
	if (size == 0) {
		return 0;
	}
	int count = 0;
	if (numbers[0] == target) {
		numbers[0] = replacement;
		count++;
	}
	return count + replace(target, replacement, numbers + 1, size - 1);
}

// Task: compute the Greatest Common Divisor (GCD) of two nonnegative
//       integers using Euclid's formula:
//
// Euclid's method for computing the greatest common divisor (GCD) of two 
// nonnegative integers a and b is as follows. Divide a and b to obtain the 
// integer quotient q and remainder r, so that a = bq+r (if b = 0, 
// then GCD(a, b) = a). Then GCD(a, b) = GCD(b, r). Replace a with b and 
// b with r and repeat the procedure. Because the remainders are decreasing, 
// eventually a remainder of 0 will result. The last nonzero remainder is 
// the greatest common divisor of a and b.
//
// Pre: the parameters x & y are nonnegative
// Post: the GCD of x & y is returned
int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

// Task: reverse the contents of a[first]...a[last]
// Pre: 'a' is an array of at least 'last'+1 integers, first & last are nonnegative
// Post: the elements a[first]...a[last]have been reversed.
void reverseArray(int a[], int first, int last) {
	if (last == 0) {
		return;
	}
	if (first == last || first > last) {
		return;
	}
	int tmp = a[first];
	a[first] = a[last];
	a[last] = tmp;
	return reverseArray(a, first + 1, last - 1);
}

// Task: produce the binary representation of a decimal number
//   A decimal number is converted to binary by repeated
//   division by 2. For each division, keep track of the quotient
//   and remainder. The remainder becomes the low-order bit (rightmost
//   bit) of the binary representation. The higher-order bits are
//   determined by repeating the processes with the quotient.
//   The process stops when num is either zero or one.
// Pre: num is a nonnegative integer
// Post: the binary representation of num is produced and returned
//   as a string.
string convert2Binary(int num) {
	if (num == 1) {
		return std::to_string(1);
	}
	if (num == 0) {
		return std::to_string(0);
	}
	int quotient = num / 2;
	int remainder = num % 2;
	return convert2Binary(quotient) + std::to_string(remainder);
}

// Task: Print a pseudo hourglass pattern on the screen
// Pre: num is a positive integer
// Post: the desired pattern is displayed on cout
// You may use iteration to print a single line of *'s, but
// must use recursion to complete the pattern.
// Example: a call to printPattern(4) should produce the
// pattern below (excluding the beginning and ending comment):
/*
****
***
**
*
**
***
****
*/
void printPattern(int num) {
	if (num == 1) {
		cout << "*" << endl;
		return;
	}
	for (int i = 0; i < num; i++) {
		if (i == num - 1) {
			cout << "*" << endl;
		}
		else {
			cout << "*";
		}
	}
	printPattern(num - 1);
	for (int i = 0; i < num; i++) {
		if (i == num - 1) {
			cout << "*" << endl;
		}
		else {
			cout << "*";
		}
	}
}

// Task: initialize all elements of the array between indices lb and ub to the
//   given value, including the elements at lb & ub
// Note: lb = lower bound, ub = upper bound
// Pre: lb and ub are valid indices into the array a [the actual size of the array is
//   unknown]
// Post: the array elements in the segment a[lb..ub] have been initialized to value
// Additional requirement: This function must be done by dividing the array segment
//   in half and performing recursive calls on each half (as opposed to just shrinking
//   the array bound by one each time)
void arrayInitialize(int a[], int value, int lb, int ub) {
	if (ub == lb) {
		a[lb] = value;
		return;
	}
	if (ub < lb) {
		return;
	}
	if (ub - lb == 1) {
		a[lb] = value;
		a[ub] = value;
		return;
	}
	int mid = (ub + lb) / 2;
	arrayInitialize(a, value, lb, mid);
	arrayInitialize(a, value, mid, ub);
}

// Task: Compute the Binomial Coefficient using Pascal's Triangle.
// The Binomial Coefficient B(n, r) is the coefficient of the term x^r in the binormial 
// expansion of (1 + x)^n. For example, B(4, 2) = 6 because (1+x)^4 = 1 + 4x + 6x^2 + 4x^3 + x^4. 
// The Binomial Coefficient can be computed using the Pascal Triangle formula:
//	B(n, r) = 1                          if r = 0 or r = n
//	B(n, r) = B(n-1, r-1) + B(n-1, r)    otherwise
// Pre: r & n are non-negative, and r<=n
int binomialCoeff(int n, int r) {
	if (r == 0 || r == n) {
		return 1;
	}
	return binomialCoeff(n - 1, r - 1) + binomialCoeff(n - 1, r);
}

// Task: Given a non-negative int n, compute recursively (no loops) the count of the 
//   occurrences of 2 as a digit, except that a 2 with another 2 immediately to its 
//   left counts double, so 2212 yields 4. Note that mod (%) by 10 yields the rightmost 
//   digit (126 % 10 is 6), while divide (/) by 10 removes the rightmost digit (126 / 10 is 12). 
// Pre: n is non-negative
// Post: count of the occurrences of 2 is returned (with doubling as appropriate)
// Examples:
//   count2(2) --> 1
//   count2(212) --> 2
//   count2(2212) --> 4
int count2(int n) {
	if (n == 0) {
		return 0;
	}
	if (n % 10 == 2 && (n / 10) % 10 == 2) {
		return 2 + count2(n / 10);
	}
	else if (n % 10 == 2) {
		return 1 + count2(n / 10);
	}
	else {
		return count2(n / 10);
	}
}

// Task: Given a string and a non-empty substring sub, compute recursively the number 
//   of times that sub appears in the string, without the sub strings overlapping. 
// Pre: sub is a non-empty string
// Post: the count of non-overlapping occurrences of sub in str is returned
// Examples:
//   countSubs("catcowcat", "cat") --> 2
//   countSubs("catcowcat", "cow") --> 1
//   countSubs("catcowcat", "dog") --> 0
int countSubs(const string& str, const string& sub) {
	if (str.length() < sub.length()) {
		return 0;
	}
	if (str == sub) {
		return 1;
	}
	if (str.substr(0, sub.length()) == sub) {
		return 1 + countSubs(str.substr(sub.length(), str.length() - sub.length()), sub);
	}
	else {
		return countSubs(str.substr(1, str.length() - 1), sub);
	}
}

// Task: Given a string, compute recursively a new string where all the lowercase 'x' chars 
//   have been moved to the end of the string. 
// Pre: str is a string (possibly empty)
// Post: return a new string where all lowercase 'x' chars have been moved to the end 
// Examples:
//   moveXs("xxre") --> "rexx"
//   moveXs("xxhixx") --> "hixxxx"
//   moveXs("xhixhix") --> "hihixxx"
string moveXs(const string& str) {
	if (str.length() <= 1) {
		return str;
	}
	if (str.substr(0, 1) == "x") {
		return moveXs(str.substr(1, str.length() - 1)) + "x";
	}
	else {
		return str.substr(0,1) + moveXs(str.substr(1, str.length() - 1));
	}
}

// Newtons method for approximating square roots.
// The next iteration is the average of the previous iteration and the
// ratio of the number in question to the previous iteration.
// In other words:
//     x_i = ( x_(i-1) + number/x_(i-1) ) / 2
// if i is 0 the approximation is simply half the number.
// Pre: number & interations are non-negative integers
// Post: return an approximation of sqrt(number)
// Note: number & iterations are integers, but the return value is double
double newton(int number, int iterations) {
	if (iterations == 0) {
		return (double) (number / 2.0);
	}
	return (newton(number, iterations - 1) + (double) number / newton(number, iterations - 1)) / 2;
}

// Task: Count the number of nodes with a nonzero value in a linked list
// Pre: tmpPtr points to the first node of the list, or it is nullptr if the list is empty
// Post: the number of nodes with a nonzero value in the linked list is returned, and 
//  the linked list is unchanged.
int numOfTerms(NodePtr tmpPtr) {
	if (tmpPtr == nullptr) {
		return 0;
	}
	if (tmpPtr->value != 0) {
		return 1 + numOfTerms(tmpPtr->next);
	}
	else {
		return numOfTerms(tmpPtr->next);
	}
}

// Task: Print all the values in a linked list in reverse order
// Pre: tmpPtr points to the first node of the list, or it is nullptr if the list is empty
// Post: the values of all nodes in the linked list are printed in reverse order, one per line, and 
//  the linked list is unchanged.
void printReverse(NodePtr tmpPtr) {
	if (tmpPtr == nullptr) {
		return;
	}
	printReverse(tmpPtr->next);
	cout << tmpPtr->value << endl;
}

// Task: Remove leading zeroes from a BigNum represented by a linked list.
// Pre: tmpPtr points to the first node of a list, or is nullptr if the list is empty
// Post: all nodes at the end of the list which have a zero have been removed
// Note 1: as discussed in lecture, a BigNum stores the digits of the number in reverse
//         order, with the ones digit at the front of the list. We are deleteing
//         leading zeroes, so they will appear at the end of the list
// Note 2: The parameter tmpPtr is passed by reference, so any changes to it will affect
//         the pointer in the caller
void normalizeBigNum(NodePtr & tmpPtr) {
	if (tmpPtr == nullptr) {
		return;
	}
	normalizeBigNum(tmpPtr->next);
	if (tmpPtr->value == 0 && tmpPtr->next == nullptr) {
		delete tmpPtr;
		tmpPtr = nullptr;
	}
}


