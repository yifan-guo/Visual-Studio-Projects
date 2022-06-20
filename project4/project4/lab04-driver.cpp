// File name: lab04-driver.cpp
// Author: Yifan Guo	
// VUnetid: guoy5
// Email: yifan.guo@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 04 
// Description: write a brief but complete description
//  of what the program does. Use multiple lines as needed.
// Last Changed: 10/21/15

// Recursive programming lab

#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include "lab04.h"
using namespace std;


void printList(NodePtr head);


int main ()
{
  // INSTRUCTIONS:
  // Uncomment segments of test code below as you implement the corresponding functions.
  // You should add tests of your own to fully test the functions.

  //************************************************************************
  cout << "Test #1: ";
  int test[5] = {1, 2, 3, 4, 5};
  if (sumArray(test,5) == 15)
    cout << "Pass" << endl;
  else
    cout << "Fail" << endl;
  cout << endl;

  //************************************************************************
  cout << "Test #2: ";
  int tmp[10] = {12, 13, 21, 30, 2, 55, 1000, 5, 201, 789};
  if (member(55, tmp, 10))
    cout << "Pass" << endl;
  else
    cout << "Fail" << endl;
  cout << endl;

  //************************************************************************
  cout << "Test #3: ";
  if (addStar("abc")=="a*b*c") 
    cout << "Pass" << endl;
  else
    cout << "Fail: " << addStar("abc") << endl;
  cout << endl;

  if (addStar("  ") == " * ")
	  cout << "Pass" << endl;
  else
	  cout << "Fail: " << addStar("  ") << endl;
  cout << endl;

  if (addStar("**") == "***")
	  cout << "Pass" << endl;
  else
	  cout << "Fail: " << addStar("**") << endl;
  cout << endl;

  //************************************************************************
  cout << "Test #4: ";
  if (harmonicSum(20)==double(55835135)/double(15519504))
    cout << "Pass" << endl;
  else
    cout << "Fail" << endl;
  cout << endl;

  cout << "Test #5: the first 4 Harmonic sums are:" << endl;
  for (int i=1; i<5; i++) {
    cout << harmonicSum(i) << endl;
  }
  cout << endl;

  //************************************************************************
  cout << "Test #6: ";
  string my_str("abcdeedcba");
  if (isPalindrome(my_str))
    cout << "Pass" << endl;
  else
    cout << "Fail" << endl;
  cout << endl;

  if (isPalindrome("xX xX"))
	  cout << "Pass" << endl;
  else
	  cout << "Fail" << endl;
  cout << endl;

  if (isPalindrome("xX"))
	  cout << "Pass" << endl;
  else
	  cout << "Fail" << endl;
  cout << endl;

  //************************************************************************
  cout << "Test #7: ";
  int k = replace(2, 3, tmp, 10);
  if (k == 1 && tmp[4] == 3)
    cout << "Pass" << endl;
  else
    cout << "Fail" << endl;
  cout << endl;

  //************************************************************************
  cout << "Test #8: ";
  if (gcd(24,30) == 6)
    cout << "Pass" << endl;
  else
    cout << "Fail" << endl;
  cout << endl;

  if (gcd(0, 15) == 15)
	  cout << "Pass" << endl;
  else
	  cout << "Fail" << endl;
  cout << endl;

  if (gcd(0, 0) == 0)
	  cout << "Pass" << endl;
  else
	  cout << "Fail" << endl;
  cout << endl;

  if (gcd(923847, 923846) == 1)
	  cout << "Pass" << endl;
  else
	  cout << "Fail" << endl;
  cout << endl;
  //************************************************************************
  cout << "Test #9: ";
  int tmp2[10] = { 789, 201, 5, 1000, 55, 2, 30, 21, 13, 12 };
  int tmp3[10] = { 12, 13, 21, 30, 2, 55, 1000, 5, 201, 789 };
  reverseArray(tmp2, 0, 9);
  bool okay = true;
  for (int k = 0; k < 10; k++)
  {
     if (tmp2[k] != tmp3[k])
        okay = false;
  }
  if (okay)
     cout << "Pass" << endl;
  else
     cout << "Fail" << endl;
  cout << endl;


  //************************************************************************
  cout << "Test #10: ";
  if (convert2Binary(25) == "11001")
    cout << "Pass" << endl;
  else
    cout << "Fail" << endl;
  cout << endl;

  cout << convert2Binary(24) << endl;

  cout << "Test #11: The first ten binary numbers are: " << endl;
  for (int j=0; j<10; j++)
  {
      cout << j << " = " << convert2Binary(j) << endl;
  }
  cout << endl;

  //************************************************************************
  cout << "Test #12: A four star hourglass pattern: " << endl;
  printPattern(4);
  cout << endl;


  //************************************************************************
  cout << "Test #13: ";
  int testI[100];
  for (int k=0; k<100; k++)
     testI[k] = 0;
  arrayInitialize(testI, 5, 20, 80);
  bool OK = true;
  for (int k=0; k<20; k++)
     if (testI[k]!=0)
        OK = false;
  for (int k=20; k<=80; k++)
     if (testI[k]!=5)
        OK = false;
  for (int k=81; k<100; k++)
     if (testI[k]!=0)
        OK = false;
  if (OK)
    cout << "Pass" << endl;
  else
    cout << "Fail" << endl;
  cout << endl;


  //************************************************************************
  cout << "Test #14: ";
  if (binomialCoeff(4,2)==6) 
    cout << "Pass" << endl;
  else
    cout << "Fail" << endl;
  cout << endl;

  if (binomialCoeff(0, 0) == 1)
	  cout << "Pass" << endl;
  else
	  cout << "Fail" << endl;
  cout << endl;

  if (binomialCoeff(2, 0) == 1)
	  cout << "Pass" << endl;
  else
	  cout << "Fail" << endl;
  cout << endl;


  //************************************************************************
  cout << "Test #15: ";
  if (count2(212)==2) 
    cout << "Pass" << endl;
  else
    cout << "Fail" << endl;
  cout << endl;

  if (count2(22222222) == 15)
	  cout << "Pass" << endl;
  else
	  cout << "Fail" << endl;
  cout << endl;

  //************************************************************************
  cout << "Test #16: ";
  if (countSubs("catcowcat","cat")==2) 
    cout << "Pass" << endl;
  else
    cout << "Fail" << countSubs("catcowcat", "cat") << endl;
  cout << endl;

  if (countSubs("xyxyxyxyxy", "xyx") == 2)
	  cout << "Pass" << endl;
  else
	  cout << "Fail" << countSubs("xyxyxyxyxy", "xyx") << endl;
  cout << endl;

  if (countSubs("", "a") == 0)
	  cout << "Pass" << endl;
  else
	  cout << "Fail" << countSubs("", "a") << endl;
  cout << endl;

  if (countSubs("aaaaaaa", "a") == 7)
	  cout << "Pass" << endl;
  else
	  cout << "Fail" << countSubs("aaaaaaa", "a") << endl;
  cout << endl;

  //************************************************************************
  cout << "Test #17: ";
  if (moveXs("xxre")=="rexx")
     cout << "Pass" << endl;
  else
     cout << "Fail" << endl;
  cout << endl;

  if (moveXs("Xxre") == "Xrex")
	  cout << "Pass" << endl;
  else
	  cout << "Fail" << endl;
  cout << endl;

  if (moveXs("XxXxy") == "XXyxx")
	  cout << "Pass" << endl;
  else
	  cout << "Fail" << endl;
  cout << endl;

  if (moveXs("x    ") == "    x")
	  cout << "Pass" << endl;
  else
	  cout << "Fail" << endl;
  cout << endl;

  if (moveXs("xxxxx") == "xxxxx")
	  cout << "Pass" << endl;
  else
	  cout << "Fail" << endl;
  cout << endl;

  if (moveXs("xXxXxXxXxX") == "XXXXXxxxxx")
	  cout << "Pass" << endl;
  else
	  cout << "Fail" << endl;
  cout << endl;

  //************************************************************************
  cout << "Test #18: ";
  if (abs(newton(33333, 10) - sqrt(33333)) < 0.00001)   // test that Newton's approximate is within 0.00001 of actual
      cout << "Pass" << endl;
  else
      cout << "Fail" << endl;
  cout << endl;


  //************************************************************************
  // create a linked list
  NodePtr head = NULL;
  NodePtr tmpPtr;
  int cnt = 0;
  for (int k = 0; k<20; k++)
  {
	  tmpPtr = new Node;
	  tmpPtr->value = ((k % 3) == 0) ? 0 : k;
	  if (tmpPtr->value != 0) cnt++;
	  tmpPtr->next = head;
	  head = tmpPtr;
  }

  //************************************************************************
  cout << "Test #19: ";
  if (numOfTerms(head) == cnt)
      cout << "Pass" << endl;
  else
      cout << "Fail" << endl;
  cout << endl;


  //************************************************************************
  cout << "Test #20: " << endl;
  cout << "These two lists should be identical" << endl;
  cout << "list 1 -----------" << endl;
  for (int k = 0; k<20; k++)
  {
      cout << (((k % 3) == 0) ? 0 : k) << endl;
  }
  cout << "list 2 -----------" << endl;
  printReverse(head);
  cout << "Done   -----------" << endl;
  cout << endl;


  //************************************************************************
  // add some zeros at the end of the list
  for (tmpPtr = head; tmpPtr->next!=nullptr; tmpPtr=tmpPtr->next) 
  {} // nothing to do
  for (size_t i=0; i<6; i++) {
	  NodePtr newPtr = new Node;
	  newPtr->value = 0;
	  newPtr->next = tmpPtr->next;
	  tmpPtr->next = newPtr;
  }

  //************************************************************************
  cout << "Test #21: " << endl;
  cout << "These two lists should be identical except for zeros at the end" << endl;
  printList(head);
  normalizeBigNum(head);
  printList(head);

#if GRAD_STUDENT==1

  //************************************************************************
  cout << "Test #22: ";
  //head = reverseList(head);
  //tmpPtr = head;
  //bool ok = true;
  //for (int k = 0; k<20; k++)
  //{
  //    if (tmpPtr == 0 || tmpPtr->value != (((k % 3) == 0) ? 0 : k)) {
  //        ok = false;
  //        break;
  //    }
  //    tmpPtr = tmpPtr->next;
  //}
  //if (ok && tmpPtr == NULL)
  //   cout << "Pass" << endl;
  //else
  //   cout << "Fail" << endl;
  cout << endl;

#endif

  // free the linked list
  while (head != NULL)
  {
	  NodePtr tmp = head;
	  head = head->next;
	  delete tmp;
  }




  cout << "\n\nDone testing" << endl;

  char junk;
  cout << "press enter to exit";
  junk = cin.get();



  return 0;
}



void printList(NodePtr head)
{

	cout << "contents of list: ";
	for (NodePtr cur = head; cur != nullptr; cur = cur->next) {
		cout << cur->value;
	}
	cout << " Done" << endl;

}
