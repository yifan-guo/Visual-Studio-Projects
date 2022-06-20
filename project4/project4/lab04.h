// File name: lab04.h
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

#ifndef LAB04_H
#define LAB04_H

#include <string>
using namespace std;

// Change the following line as appropriate -- this is the only line you should change in this file
#define GRAD_STUDENT 0   // if you are a grad student, set this to 1, otherwise set it to 0



int sumArray(int anArray[], int size);
//Task: compute the sum of an array of integers
//Pre: anArray is an array of 'size' integers, size is nonnegative
//Post: the sum of anArray[0]...anArray[size-1] is returned
// Additional requirement: This function must be done by dividing the array 
//   in half and performing recursive calls on each half (as opposed to just 
//   shrinking the size by one each time). Hint: use pointer arithmetic


bool member(int target, const int set[], int size);
//Task: determine if target is in the set
//Pre: set is an array of 'size' integers, size is nonnegative
//Post: true is returned if target is in the set, else false;
//  the set is unchanged


string addStar(const string& str);
// Task: Given a string, compute recursively a new string where all the adjacent 
//   chars are now separated by a "*".
// Pre: str is a string (may be empty).
// Post: a correctly starred string is returned.
// Examples:  
//   addStar("hello") --> "h*e*l*l*o"
//   addStar("abc") --> "a*b*c"
//   addStar("ab") --> "a*b"


double harmonicSum(int n);
//Task: compute the sum of the first n harmonic terms
//Pre: n is a positive integer
//Post: the sum of the first n harmonic terms is returned.
// The harmonic series is 1 + (1/2) + (1/3) + (1/4) + ...


bool isPalindrome(const string& str);
//Task: determine if a string is a palindrome
//Pre: str is a string object
//Post: returns true if str is a palindrome, otherwise returns false
//      The test is case insensitive [look up toupper() and
//      tolower()]. You do not need to worry about
//      trimming blanks from the ends of the string.
//Note: the empty string is a palindrome


int replace(int target, int replacement, int numbers[], int size);
//Task: replace all occurrences of 'target' in the array 'numbers'
//      with 'replacement'
//Pre: 'numbers' is an array of 'size' integers, size is nonnegative
//Post: all occurrences of 'target' in 'numbers' have been replaced
//      with 'replacement'; the number of replacements performed is
//      returned to the caller.


int gcd(int x, int y);
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


void reverseArray(int a[], int first, int last);
// Task: reverse the contents of a[first]...a[last]
// Pre: 'a' is an array of at least 'last'+1 integers, first & last are nonnegative
// Post: the elements a[first]...a[last]have been reversed.


string convert2Binary(int num);
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


void printPattern (int num);
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


void arrayInitialize(int a[], int value, int lb, int ub);
// Task: initialize all elements of the array between indices lb and ub to the
//   given value, including the elements at lb & ub
// Note: lb = lower bound, ub = upper bound
// Pre: lb and ub are valid indices into the array a [the actual size of the array is
//   unknown]
// Post: the array elements in the segment a[lb..ub] have been initialized to value
// Additional requirement: This function must be done by dividing the array segment
//   in half and performing recursive calls on each half (as opposed to just shrinking
//   the array bound by one each time)


int binomialCoeff (int n, int r);
// Task: Compute the Binomial Coefficient using Pascal's Triangle.
// The Binomial Coefficient B(n, r) is the coefficient of the term x^r in the binormial 
// expansion of (1 + x)^n. For example, B(4, 2) = 6 because (1+x)^4 = 1 + 4x + 6x^2 + 4x^3 + x^4. 
// The Binomial Coefficient can be computed using the Pascal Triangle formula:
//	B(n, r) = 1                          if r = 0 or r = n
//	B(n, r) = B(n-1, r-1) + B(n-1, r)    otherwise
// Pre: r & n are non-negative, and r<=n


int count2(int n);
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


int countSubs(const string& str, const string& sub);
// Task: Given a string and a non-empty substring sub, compute recursively the number 
//   of times that sub appears in the string, without the sub strings overlapping. 
// Pre: sub is a non-empty string
// Post: the count of non-overlapping occurrences of sub in str is returned
// Examples:
//   countSubs("catcowcat", "cat") --> 2
//   countSubs("catcowcat", "cow") --> 1
//   countSubs("catcowcat", "dog") --> 0


string moveXs(const string& str);
// Task: Given a string, compute recursively a new string where all the lowercase 'x' chars 
//   have been moved to the end of the string. 
// Pre: str is a string (possibly empty)
// Post: return a new string where all lowercase 'x' chars have been moved to the end 
// Examples:
//   moveXs("xxre") --> "rexx"
//   moveXs("xxhixx") --> "hixxxx"
//   moveXs("xhixhix") --> "hihixxx"


double newton(int number, int iterations);
// Newtons method for approximating square roots.
// The next iteration is the average of the previous iteration and the
// ratio of the number in question to the previous iteration.
// In other words:
//     x_i = ( x_(i-1) + number/x_(i-1) ) / 2
// if i is 0 the approximation is simply half the number.
// Pre: number & interations are non-negative integers
// Post: return an approximation of sqrt(number)
// Note: number & iterations are integers, but the return value is double


struct Node
{
   int value;
   Node* next;
};

typedef Node* NodePtr;

int numOfTerms (NodePtr tmpPtr);
// Task: Count the number of nodes with a nonzero value in a linked list
// Pre: tmpPtr points to the first node of the list, or it is nullptr if the list is empty
// Post: the number of nodes with a nonzero value in the linked list is returned, and 
//  the linked list is unchanged.


void printReverse (NodePtr tmpPtr);
// Task: Print all the values in a linked list in reverse order
// Pre: tmpPtr points to the first node of the list, or it is nullptr if the list is empty
// Post: the values of all nodes in the linked list are printed in reverse order, one per line, and 
//  the linked list is unchanged.


void normalizeBigNum(NodePtr & tmpPtr);
// Task: Remove leading zeroes from a BigNum represented by a linked list.
// Pre: tmpPtr points to the first node of a list, or is nullptr if the list is empty
// Post: all nodes at the end of the list which have a zero have been removed
// Note 1: as discussed in lecture, a BigNum stores the digits of the number in reverse
//         order, with the ones digit at the front of the list. We are deleteing
//         leading zeroes, so they will appear at the end of the list
// Note 2: The parameter tmpPtr is passed by reference, so any changes to it will affect
//         the pointer in the caller


#if GRAD_STUDENT==1   // set in lab04.h

NodePtr reverseList (NodePtr tmpPtr);
// GRAD STUDENT ONLY PROBLEM
// Task: Reverse the nodes in the linked list.
// Pre: tmpPtr points to the first node of the list, or it is nullptr if the list is empty.
// Post: the list has been reversed and a pointer to the new first node is returned.
// This must be accomplished without allocating any new nodes or deleting existing nodes.
// To receive full credit, you must accomplish this task only with recursion and without
// any code to walk the list.

#endif


#endif
