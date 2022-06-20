// File name: Main.cpp
// Author: CS201 Instructor
// userid: 
// Email: 
// Class: C201 @ Vanderbilt U.
// Assignment Number: 
// Description:  Determine if a maze has a solution (and print a trace).
//    A basic exercise for stacks and queues (or any agenda-type container).
// Last Changed:  3-24-2010


#include <iostream>
#include <algorithm>
#include "Maze.h"
#include "PointAgenda.h"
#include "LifoPointAgenda.h"
#include "FifoPointAgenda.h"
#include "MazeSolver.h"
using namespace std;


// chooseAgenda() function 
// Prompts the user for the desired agenda type, 
// instantiates such an agenda via new, and returns it.
PointAgenda* chooseAgenda();



int main()
{
   string choice;
   string filename;

   cout << "MAZE SOLVER!!\n" << endl;

   do
   {
      cout << "Please enter name of file containing the maze: ";
      cin >> filename;
      Maze newMaze(filename);
      cout << "Here is the maze to be solved:\n" << newMaze.toString() << endl;
 
      PointAgenda* myAgenda = chooseAgenda();
 
      MazeSolver solver(newMaze, *myAgenda);

      cout << "\nDo you want to trace the execution of the solver? (Y|N)" << endl;
      cin >> choice;
      cout << endl;
      bool trace = choice.at(0)=='Y' || choice.at(0)=='y';

      solver.solve(trace);  

      delete myAgenda;

      cout << "\nDo you want to solve another maze? (Y|N)" << endl;
      cin >> choice;
   }while(choice.at(0)=='Y' || choice.at(0)=='y');
   return 0;
}


// chooseAgenda() function 
// Prompts the user for the desired agenda type, 
// instantiates such an agenda via new, and returns it.
PointAgenda* chooseAgenda() 
{
   int choice = 0;
   do {
      cout << "\nPlease select the type of agenda you want to use by entering its number:" << endl;
      cout << "1: Stack-based agenda" << endl;
      cout << "2: Queue-based agenda" << endl;
      cout << "Enter choice: ";
      cin >> choice;
      if (choice<1 || choice>2) 
      {
         cout << "Invalid choice. Try again." << endl;
      }
   } while ((choice<1 || choice>2) & cin.good());

   switch (choice)
   {
   case 1:
      cout << "\nSolving the maze with a stack-based agenda:" << endl;
      return new LifoPointAgenda;
   case 2:
      cout << "\nSolving the maze with a queue-based agenda:" << endl;
      return new FifoPointAgenda;
   default:
      cout << "Non-int input. Halting program." << endl;
      exit(1);
   }
}

