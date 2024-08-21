/* Citation and Sources...
Final Project Milestone 4
Module: Date
Filename: Date.h
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
#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__

#include <iostream>
#include "Status.h"

namespace sdds
{
    // Define a constant for the maximum year value
    const int MAXIMUM_YEAR_VALUE = 2030;

    // Date class declaration
    class Date
    {
    private:
        int Year;               // Year component of the date
        int Month;              // Month component of the date
        int Day;                // Day component of the date
        Status status;          // Status object to represent the state of the date
        bool Format;            // Flag to indicate the date format (true for YYYY/MM/DD, false for YYYY/DD/MM)
        bool validate();        // Private member function to validate the date

    public:
        // Constructors
        Date();                 // Default constructor
        Date(int m_year, int m_month, int m_day); // Parameterized constructor

        // Public member functions
        int uniqueValue()const; // Function to calculate a unique value for the date
        const Status& state();  // Function to return the status object
        bool formatted(bool m_format); // Function to set the date format
        operator bool() const;  // Conversion operator to check if the date is valid

        // Input and output functions
        std::istream& read(std::istream& istr);    // Function to read a date from input stream
        std::ostream& write(std::ostream& ostr) const; // Function to write the date to output stream
    };

    // Comparison operators for Date objects
    bool operator==(const Date& one, const Date& two);
    bool operator!=(const Date& one, const Date& two);
    bool operator>=(const Date& one, const Date& two);
    bool operator<=(const Date& one, const Date& two);
    bool operator<(const Date& one, const Date& two);
    bool operator>(const Date& one, const Date& two);

    // Input and output operators for Date objects
    std::istream& operator>>(std::istream&, Date&);
    std::ostream& operator<<(std::ostream&, const Date&);
}

#endif

