/***********************************************************************
// Final project Milestone 1
// Module: Status
// File: Status.h
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


#ifndef SDDS_STATUS_H 
#define SDDS_STATUS_H
namespace sdds {

    class Status {
        char* description{}; // Pointer to dynamically allocated memory for the status message
        int code; // Numerical code representing the status (error code, success, etc.)

    public:
        // Constructors
        Status(const char* description = nullptr, int code = 0); // Default constructor with optional parameters
        Status(const Status& s); // Copy constructor

        // Assignment Operators
        Status& operator=(const Status& s); // Copy assignment operator
        Status& operator=(int sCode); // Assignment operator to set the status code
        Status& operator=(const char* sDescription); // Assignment operator to set the status message

        // Destructor
        ~Status();

        // Type Conversion Operators
        operator int() const; // Converts the status object to an integer type (status code)
        operator const char* () const; // Converts the status object to a C-string (status message)
        operator bool() const; // Converts the status object to a boolean (true if status is clear, false if error exists)

        // Member Functions
        Status& clear(); // Clears the status, resetting the message and code

        // Friend Functions
        friend std::ostream& operator<<(std::ostream& os, const Status& status); // Overloads the << operator for output
    };

}

#endif // !SDDS_STATUS_H
