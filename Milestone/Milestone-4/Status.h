/* Citation and Sources...
Final Project Milestone 4
Module: Status
Filename: Status.h
Version 1.0
Author	John Doe
Revision History
-----------------------------------------------------------
Date      Reason
2023/?/?  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
Student Name		: Ali Riza Sevgili
Student Number		: 135200228
Student Email		: arsevgili@myseneca.ca
Date				: 11 / 28 / 2023
-----------------------------------------------------------*/


#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H

#include <cstring>
#include <iostream>

using namespace std;

namespace sdds
{
    // Status class represents a status message with a description and a code.
    class Status
    {
    public:
        char* Description;  // Pointer to a character array for the description.
        int Code;          // Integer code representing the status.

        // Constructor with default values.
        Status(char* str = nullptr, int code = 0);

        // Copy constructor.
        Status(const Status& status);

        // Assignment operator overload for copying another Status object.
        Status& operator=(const Status& status);

        // Destructor to release dynamically allocated memory.
        ~Status();

        // Assignment operator overload to set the description using a string.
        Status& operator=(const char* str);

        // Assignment operator overload to set the code using an integer.
        Status& operator=(const int code);

        // Conversion operator to convert Status to bool for condition checking.
        operator bool() const;

        // Conversion operator to convert Status to int for retrieving the code.
        operator int() const;

        // Conversion operator to convert Status to char* for retrieving the description.
        operator char* () const;

        // Friend function to overload the << operator for printing Status objects.
        friend ostream& operator<<(ostream& os, const Status& status);

        // Function to clear the Status object by resetting description and code.
        Status& clear();
    };
}

#endif // !SDDS_STATUS_H
