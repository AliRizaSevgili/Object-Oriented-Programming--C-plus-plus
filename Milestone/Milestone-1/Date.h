/***********************************************************************
// Final project Milestone 1
// Module: Date
// File: Date.h
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

#include "Status.h"
#ifndef SDDS_DATE_H
#define SDDS_DATE_H
namespace sdds {
    // Constant for the maximum valid year.
    const int MAX_YEAR = 2030;

    // The Date class represents a specific calendar date.
    class Date {
        int year; // Holds the year part of the date.
        int month;// Holds the month part of the date.
        int day; // Holds the day part of the date.
        Status status;// Holds the status of the date, including error messages.
        bool formated = true; // Flag to determine if the date is formatted.

        bool validate(); // Private method to validate the date.
        // Computes a unique value for the date for comparison purposes.
        int uniqueDateValue(int year, int month, int day) const;
    public:
        // Default constructor that initializes the date to the system date.
        Date();
        // Constructor that initializes the date with provided values.
        Date(int year, int month, int day);
        // Comparison operators to compare two Date objects.
        bool operator==(const Date& other) const;
        bool operator!=(const Date& other) const;
        bool operator<(const Date& other) const;
        bool operator>(const Date& other) const;
        bool operator<=(const Date& other) const;
        bool operator>=(const Date& other) const;

        // Returns the status of the date, indicating whether it's valid and any error messages.
        const Status& state() const;
        // Sets whether the date should be formatted.
        Date& formatted(bool format);
        // Converts the Date object to a boolean value based on its validation status.
        operator bool() const;
        // Writes the date to an output stream in a formatted way.
        std::ostream& write(std::ostream& ostr) const;
        // Reads a date from an input stream and validates it.
        std::istream& read(std::istream& istr);
        // Friend functions to overload the insertion and extraction operators.
        friend std::ostream& operator<<(std::ostream& os, const Date& date);
        friend std::istream& operator>>(std::istream& is, Date& date);

    };

}

#endif // !SDDS_DATE_H