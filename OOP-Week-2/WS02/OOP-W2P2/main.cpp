/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):

// Student Name     : Ali Riza Sevgili
   Student Number	: 135200228
   Student Email	: arsevgili@myseneca.ca
   Date			    : 09/26/2023
   > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

 // File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/

#include <iostream>
#include "Population.h"

using namespace sdds;

int main() {
    char code[4]{};
    while (getPostalCode(code)) {
        if (load("PCpopulationsComplete.csv", code)) {
            display();
        }
        deallocateMemory();
    }
    return 0;
}
