/* Citation and Sources...
Final Project Milestone 4
Module: Status
Filename: Status.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
#include "Status.h"
using namespace std;

namespace sdds
{
    // Constructor with parameters to initialize the Status object.
    Status::Status(char* str, int code)
    {
        Code = code;

        // Dynamically allocate memory for the description if 'str' is not null.
        if (str != NULL)
        {
            Description = new char[strlen(str) + 1];
            strcpy(Description, str);
        }
        else
        {
            Description = NULL;
        }
    }

    // Copy constructor to create a copy of a Status object.
    Status::Status(const Status& status)
    {
        Code = status.Code;

        // Copy the description if the source Status object is not empty.
        if (!status)
        {
            Description = new char[strlen(status.Description) + 1];
            strcpy(Description, status.Description);
        }
        else
        {
            Description = NULL;
        }
    }

    // Assignment operator overload to copy another Status object.
    Status& Status::operator=(const Status& status)
    {
        // Release the memory of the current Description to avoid memory leaks.
        delete[] Description;
        Description = nullptr;

        Code = status.Code;

        // Copy the description if the source Status object is not empty.
        if (status)
        {
            Description = new char[strlen(status.Description) + 1];
            strcpy(Description, status.Description);
        }
        else
        {
            Description = NULL;
        }

        return *this;
    }

    // Destructor to release dynamically allocated memory.
    Status::~Status()
    {
        delete[] Description;
        Description = nullptr;
    }

    // Assignment operator overload to set the description using a string.
    Status& Status::operator=(const char* str)
    {
        // Release the memory of the current Description to avoid memory leaks.
        delete[] Description;
        Description = nullptr;

        // If the input string is nullptr, return the object as is.
        if (str == nullptr) return *this;

        // Allocate memory and copy the input string.
        Description = new char[strlen(str) + 1];
        strcpy(Description, str);
        return *this;
    }

    // Assignment operator overload to set the code using an integer.
    Status& Status::operator=(const int code)
    {
        Code = code;
        return *this;
    }

    // Conversion operator to convert Status to bool for condition checking.
    Status::operator bool() const
    {
        // Returns 'true' if Description is not null (i.e., Status is not empty).
        if (Description != nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Conversion operator to convert Status to int for retrieving the code.
    Status::operator int() const
    {
        return Code;
    }

    // Conversion operator to convert Status to char* for retrieving the description.
    Status::operator char* () const
    {
        return Description;
    }

    // Friend function to overload the << operator for printing Status objects.
    ostream& operator<<(ostream& os, const Status& status)
    {
        // Print an error message (if code is non-zero) and the description.
        if (!status)
        {
            if (status.Code != 0)
                os << "ERR#" << status.Code << ": ";
            os << status.Description;
        }
        return os;
    }

    // Function to clear the Status object by resetting description and code.
    Status& Status::clear()
    {
        // Release the memory of the current Description and reset the code.
        delete[] Description;
        Description = nullptr;
        Code = 0;
        return *this;
    }
}
