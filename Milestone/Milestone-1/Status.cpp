/***********************************************************************
// Final project Milestone 1
// Module: Status
// File: Status.cpp
// Version 1.0
// Author  Fardad Soleimanloo
// Description

Student Name		: Ali Riza Sevgili
Student Number		: 135200228
Student Email		: arsevgili@myseneca.ca
Date				: 11 / 04 / 2023
> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
/***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <ctime>
#include <cstring>
#include <limits>
#include "Utils.h" 
#include "Status.h"
using namespace std;
namespace sdds {

    // Constructor that sets the status description and code.
    Status::Status(const char* description, int code) {
        // Clear any existing description before assigning new memory.
        if (this->description != nullptr) {
            delete[] this->description;
            this->description = nullptr;
        }
        // Allocate memory and copy the description, if provided.
        if (description != nullptr) {
            this->description = new char[strlen(description) + 1];
            strcpy(this->description, description);
        }

        // Set the status code.
        this->code = code;
    }

    // Copy constructor that initializes a new object as a copy of an existing one.
    Status::Status(const Status& s) {
        *this = s;
    }

    // Copy assignment operator that ensures deep copying of the object.
    Status& Status::operator=(const Status& s) {
        if (this != &s) {
            // Clear existing description before copying.
            if (description != nullptr) {
                delete[] description;
                description = nullptr;
            }
            // Allocate memory and copy the description.
            if (s.description != nullptr) {
                description = new char[strlen(s.description) + 1];
                strcpy(description, s.description);
            }
            // Copy the status code.
            code = s.code;
        }
        // Return a reference to the current object.
        return *this;
    }

    // Destructor that cleans up dynamically allocated memory.
    Status::~Status() {
        if (description != nullptr) {
            delete[] description;
            description = nullptr;
        }
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
        }
        description = new char[strlen(sDescription) + 1];
        strcpy(description, sDescription);
        return *this;
    }

    // Conversion operator to int to return the status code.
    Status::operator int() const {
        return this->code;
    }

    // Conversion operator to const char* to return the description.
    Status::operator const char* () const {
        return this->description;
    }

    // Conversion operator to bool to check if the description is set.
    Status::operator bool() const {
        return (this->description == nullptr);
    }

    // Clears the status description and code, resetting the object.
    Status& Status::clear() {
        if (description != nullptr) {
            delete[] description;
            description = nullptr;
        }
        code = 0;
        return *this;
    }

    // Overloaded ostream operator to print the status object.
    std::ostream& operator<<(std::ostream& os, const Status& status) {
        if (!status) {
            // If status is an error, print the error code.
            if (status.code != 0) {
                os << "ERR#" << status.code << ": ";
            }
            // Print the status description.
            os << status.description;
        }
        return os;
    }
} // namespace sdds
