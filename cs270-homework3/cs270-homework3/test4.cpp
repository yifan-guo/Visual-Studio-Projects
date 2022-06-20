#include <iostream>
#include <cstdlib>
#include "Date.h"
#include "Reminder.h"
#include "P_Reminder.h"

int main() 
{
  Date today, *date_ptr;
  int i;

  for (i=1; i<4000000; i++) {
    date_ptr = new PriorityReminder(today, "Here is a long reminder string......Here is a long reminder string......Here is a long reminder string......Here is a long reminder string......Here is a long reminder string......Here is a long reminder string......Here is a long reminder string......Here is a long reminder string......Here is a long reminder string......Here is a long reminder string......Here is a long reminder string......Here is a long reminder string......Here is a long reminder string......Here is a long reminder string......Here is a long reminder string......Here is a long reminder string......Here is a long reminder string......Here is a long reminder string......Here is a long reminder string......Here is a long reminder string......Here is a long reminder string......");

    delete date_ptr;
  }

  return 0;
}

