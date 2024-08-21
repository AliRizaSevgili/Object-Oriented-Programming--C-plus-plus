/* Citation and Sources...
Final Project Milestone 4
Module: Utils
Filename: Utils.cpp
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


// Disable warnings for potentially unsafe C library functions (specific to Visual Studio)
#define _CRT_SECURE_NO_WARNINGS

// Include the standard input/output stream library for using cin, cout, etc.
#include <iostream>

// Include the standard C library for time-related functions and structures
#include <ctime>

// Include the header file for the Utils class, defining its interface and utilities
#include "Utils.h"

// Include the standard string class library for using std::string
#include <string>

using namespace std;

namespace sdds
{
    Utils ut; // External instance of the Utils class.

    // Function to set the test mode flag, which determines whether the application is in test mode.
    void Utils::testMode(bool testmode)
    {
        m_testMode = testmode;
    }

    // Function to get the current system date.
    void Utils::getSystemDate(int* year, int* mon, int* day)
    {
        if (m_testMode)
        {
            // If in test mode, use predefined test date values.
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
        }
        else
        {
            // If not in test mode, obtain the current system date.
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }

    // Function to calculate the number of days in a given month of a specific year.
    int Utils::daysOfMon(int month, int year) const
    {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + ((mon == 1) && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)));
    }

    // Function to read an integer from the input stream 'istr' and validate it within the range [x, y].
    int Utils::checking_num(std::istream& istr, int x, int y)
    {
        string choice; // Variable to store user input as a string
        int flag = 0;  // Flag to indicate the validity of the input (0 for valid, 1 for invalid)
        int num;       // Variable to store the converted integer value of the input

        while (1) // Infinite loop to keep asking for input until a valid integer is entered
        {
            flag = 0;           // Reset flag to 0 at the beginning of each iteration
            cin >> choice;      // Read user input into the 'choice' string

            for (char c : choice) // Iterate through each character in the input string
            {
                if (isdigit(c)) // Check if the character is a digit
                {
                    continue;   // Continue to next character if it is a digit
                }
                flag = 1;      // Set flag to 1 if a non-digit character is found
                break;         // Break the loop as soon as a non-digit is found
            }

            if (flag == 1) // Check if the input string contains any non-digit characters
            {
                cout << "Invalid Integer, retry: "; // Prompt user to enter a valid integer
            }
            else // If the input string is a valid integer
            {
                num = stoi(choice); // Convert the string to an integer
                if (num >= x && num <= y) // Check if the integer is within the specified range [x, y]
                {
                    return num; // Return the integer if it is within the range
                }
                else
                {
                    cout << "Value out of range [" << x << "<=val<=" << y << "]: "; // Inform user if the value is out of range
                }
            }
        }
        return -1; // Return -1 if a valid integer within the range is not entered
    }


    // Function to read a floating-point number from the input stream 'istr' and validate it within the range [x, y].
    double Utils::checking_float(std::istream& istr, double x, double y)
    {
        string choice;  // Variable to store user input as a string
        int flag = 0;   // Flag to indicate the validity of the input (0 for valid, 1 for invalid)
        double num;     // Variable to store the converted floating-point value of the input
        int dec = 0;    // Counter for the number of decimal points in the input

        while (1)  // Infinite loop to keep asking for input until a valid number is entered
        {
            flag = 0;   // Reset flag to 0 at the beginning of each iteration
            cin >> choice;  // Read user input into the 'choice' string

            for (char c : choice)  // Iterate through each character in the input string
            {
                if (isdigit(c)) // Check if the character is a digit
                {
                    continue;   // Continue to next character if it is a digit
                }
                else if (c == '.' && dec == 0) // Check for a single decimal point
                {
                    dec++;  // Increment the decimal point counter
                    continue;  // Continue to next character
                }
                else
                {
                    flag = 1;  // Set flag to 1 if a non-valid character is found
                    break;  // Break the loop as soon as a non-valid character is found
                }
            }

            if (flag == 1)  // Check if the input string contains any non-valid characters
            {
                cout << "Invalid number, retry: "; // Prompt user to enter a valid number
            }
            else  // If the input string is a valid number
            {
                num = stod(choice); // Convert the string to a floating-point number
                if (num >= x && num <= y)  // Check if the number is within the specified range [x, y]
                {
                    return num;  // Return the number if it is within the range
                }
                else
                {
                    cout.setf(ios::fixed);  // Set cout to use fixed-point notation
                    cout.precision(2);  // Set the precision of the output to 2 decimal places
                    cout << "Value out of range [" << x << "<=val<=" << y << "]: ";  // Inform user if the value is out of range
                }
            }
        }
        return -1;  // Return -1 if a valid number within the range is not entered
    }

}
