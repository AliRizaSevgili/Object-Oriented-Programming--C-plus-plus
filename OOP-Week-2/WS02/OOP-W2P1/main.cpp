/***********************************************************************
 Student Name     : Ali Riza Sevgili
   Student Number	: 135200228
   Student Email	: arsevgili@myseneca.ca
   Date			    : 09/23/2023 
   > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// OOP244 Workshop #2 lab (part 1): tester program
//
// File  main.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/

#include "Employee.h"
using namespace sdds;
int main() {
   if(load()) {
      display();
   }
   deallocateMemory();
   return 0;
}