/* Citation and Sources...
Final Project Milestone 3
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
Date				: 11 / 21 / 2023
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <ctime>
#include <cstring>
#include <limits>
//#include "Utils.h" 
#include "Status.h"
using namespace std;
namespace sdds {

    Status::Status(const char* description) {
        // Clear any existing description before assigning new memory.
        if (description != nullptr) {
            delete[] this->description; // Release any existing memory
            this->description = new char[strlen(description) + 1]; // Allocate new memory
            strcpy(this->description, description); // Copy the provided description
        }
        else {
            this->description = nullptr; // If no description is provided, set to nullptr
        }
        this->code = 0; // Initialize the code to 0 as in the first function
    }


    // Copy constructor that initializes a new object as a copy of an existing one.
    Status::Status(const Status& s) 
    {
        if (s.description != nullptr) {
            delete[] description;
            description = new char[strlen(s.description) + 1];
            strcpy(description, s.description);
            code = s.code;
        }
        else {
            description = nullptr;
        }   
    }


    // Copy assignment operator that ensures deep copying of the object.
    Status& Status::operator=(const Status& s) 
    {
        if (this != &s) {

                delete[] description;
                description = nullptr;
                description = new char[strlen(s.description) + 1];
                strcpy(description, s.description);
                code = s.code;
        }
        // Return a reference to the current object.
        return *this;
    }

    // Destructor that cleans up dynamically allocated memory.
    Status::~Status() {
         
            delete[] description;
            description = nullptr;
        }
    

    // Assignment operator that sets the status code.
    Status& Status::operator=(int sCode) {
        code = sCode;
        return *this;
    }

    // Assignment operator that sets the status description.
    Status& Status::operator=(const char* sDescription) {
        if (description != nullptr) {
            delete[] description;
            description = nullptr;
            description = new char[strlen(sDescription) + 1];
            strcpy(description, sDescription);
        }
        else {
            description = nullptr;
        }
        return *this;
    }

    // Conversion operator to int to return the status code.
    Status::operator int() const {
        return code;
    }

    // Conversion operator to const char* to return the description.
    Status::operator const char* () const {
        return description;
    }

    // Conversion operator to bool to check if the description is set.
    Status::operator bool() const {
        return description == nullptr;
    }

    // Clears the status description and code, resetting the object.
    Status& Status::clear() {
            delete[] description;
            description = nullptr;
            code = 0;
        return *this;
    }

    ostream& Status::display(ostream& os)const
    {
        if (code != 0) {

            os << "ERR#" << code << ": " << description;

        }
        else {

            os << description;

        }

        return os;
    }


    // Overloaded ostream operator to print the status object.
    std::ostream& operator<<(std::ostream& os, const Status& status) {
        if (status.operator bool() == false) {
            status.display(os);
        }
        return os;
    }
    
} // namespace sdds
