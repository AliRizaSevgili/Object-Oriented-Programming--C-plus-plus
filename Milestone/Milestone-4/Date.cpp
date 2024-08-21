/* Citation and Sources...
Final Project Milestone 4
Module: Date
Filename: Date.cpp
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

#define _CRT_SECURE_NO_WARNINGS // Disables certain warnings for cross-platform compatibility
#include <iomanip> // For output formatting
#include <iostream> // For standard input/output streams
#include <ctime> // For handling date and time functions
#include "Date.h" // Include the Date class header
#include "Utils.h" // Include the Utils class for utility functions
#include "Status.h" // Include the Status class for status handling
#include <string> // For string operations
using namespace std; // Use the standard namespace

namespace sdds { // Start of namespace sdds

    // Validate method to check the integrity of the date
    bool Date::validate() {
        Utils a; // Create a Utils object for utility operations
        Status b; // Create a Status object for status handling

        // Check if the month is within the valid range
        if (Month < 1 || Month > 12) {
            status.Description = new char[22]; // Allocate memory for error message
            strcpy(status.Description, "Invalid month in date"); // Copy error message
            status.Code = 2; // Set error code
            return false; // Return false indicating invalid date
        }
        // Check if the year is within the valid range
        else if (Year < sdds_testYear || Year > MAXIMUM_YEAR_VALUE) {
            status.Description = new char[21]; // Allocate memory for error message
            strcpy(status.Description, "Invalid year in date"); // Copy error message
            status.Code = 1; // Set error code
            return false; // Return false indicating invalid date
        }
        // Check if the day is within the valid range for the given month and year
        else if (Day < 1 || Day > a.daysOfMon(Month, Year)) {
            status.Description = new char[20]; // Allocate memory for error message
            strcpy(status.Description, "Invalid day in date"); // Copy error message
            status.Code = 3; // Set error code
            return false; // Return false indicating invalid date
        }
        else {
            b.clear(); // Clear the status object
            return true; // Return true indicating valid date
        }
    }

    // Method to calculate a unique value representing the date
    int Date::uniqueValue() const {
        return (Year - 2000) * 10000 + Month * 100 + Day; // Calculate unique value
    }

    // Method to return the current status of the Date object
    const Status& Date::state() {
        return status; // Return the status
    }

    // Method to set the date format
    bool Date::formatted(bool m_format) {
        Format = m_format; // Set format to either full year or short year
        return *this; // Enable chaining by returning the current object
    }

    // Conversion operator to boolean, currently not implemented with logic
    Date::operator bool() const {
        return 0; // Placeholder return value
    }

    // Default constructor initializing the date to a test date
    Date::Date() {
        Year = sdds_testYear; // Set year to test year
        Month = sdds_testMon; // Set month to test month
        Day = sdds_testDay; // Set day to test day
        formatted(true); // Use full year format by default
    }

    // Parameterized constructor initializing Date object with specific values
    Date::Date(int m_year, int m_month, int m_day) {
        Year = m_year; // Set year
        Month = m_month; // Set month
        Day = m_day; // Set day
        formatted(true); // Use full year format
        validate(); // Validate the date
    }

    // Comparison operators for Date objects, based on their unique value
    bool operator==(const Date& one, const Date& two) { return one.uniqueValue() == two.uniqueValue(); }
    bool operator!=(const Date& one, const Date& two) { return one.uniqueValue() != two.uniqueValue(); }
    bool operator>=(const Date& one, const Date& two) { return one.uniqueValue() >= two.uniqueValue(); }
    bool operator<=(const Date& one, const Date& two) { return one.uniqueValue() <= two.uniqueValue(); }
    bool operator<(const Date& one, const Date& two) { return one.uniqueValue() < two.uniqueValue(); }
    bool operator>(const Date& one, const Date& two) { return one.uniqueValue() > two.uniqueValue(); }

    // Method to read date from an input stream
    std::istream& Date::read(std::istream& istr) {
        int value = 0; // Variable to store the read value

        // Read value from the input stream
        istr >> value;
        if (istr.fail()) { // Check for input failure
            cout << "Invalid date value"; // Output error message
            cin.setstate(ios::badbit); // Set the state of the stream to bad
            return istr; // Return the stream
        }

        // Process the input value based on its length
        if (to_string(value).length() == 4 || to_string(value).length() == 3) {
            // Process as MMDD format
            Year = sdds_testYear;
            Day = value % 100;
            Month = value / 100;
        }
        else if (to_string(value).length() == 6 || to_string(value).length() == 5) {
            // Process as YYYYMMDD format
            Day = value % 100;
            value = value / 100;
            Month = value % 100;
            Year = value / 100 + 2000;
        }
        else {
            // Invalid format, set date to zero
            Month = 0;
            Day = 0;
            Year = 0;
        }
        if (!validate()) { // Validate the date
            cin.setstate(ios::badbit); // Set the stream state to bad if invalid
        }
        return istr; // Return the stream
    }

    // Method to write date to an output stream
    std::ostream& sdds::Date::write(std::ostream& ostr) const {
        if (Format == true) {
            // Write date in full year format
            ostr << Year << '/' << setw(2) << setfill('0') << Month << '/' << setw(2) << setfill('0') << Day;
        }
        else {
            // Write date in short year format
            ostr << Year % 100 << setw(2) << setfill('0') << Month << setw(2) << setfill('0') << Day;
        }
        return ostr; // Return the stream
    }

    // Stream insertion operator to write Date object to an output stream
    std::ostream& operator<<(std::ostream& ostr, const Date& D) {
        D.write(ostr); // Use the write method
        return ostr; // Return the stream
    }

    // Stream extraction operator to read Date object from an input stream
    std::istream& operator>>(std::istream& istr, Date& D) {
        D.read(istr); // Use the read method
        return istr; // Return the stream
    }

} // End of namespace sdds
