// CS2201 Vanderbilt University
// Prof. Roth


#ifndef REMNODE_H
#define REMNODE_H


#include "Reminder.h"
using namespace std;


// the structure of a linked list node contains a single Reminder and a next pointer
struct RemNode
{
   Reminder rem;
   RemNode *next;
};

typedef RemNode* RemNodePtr;



#endif

