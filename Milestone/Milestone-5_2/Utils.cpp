/*
Final Project Milestone 5 
Module: Utils
Filename: Utils.cpp
Version 1.0
Author
-----------------------------------------------------------
Date	  Reason
2023/
-----------------------------------------------------------
Student Name		: Ali Riza Sevgili
Student Number		: 135200228
Student Email		: arsevgili@myseneca.ca
Date				: 12 / 2 / 2023
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
// Include the standard input/output stream library for using cin, cout, etc.
#include <iostream>
#include <cstring>
//Include the standard C library for time - related functions and structures
#include <ctime>

// Include the header file for the Utils class, defining its interface and utilities
#include "Utils.h"

using namespace std;
namespace sdds {
    Utils ut;  // External instance of the Utils class.

    // Function to set the test mode flag, which determines whether the application is in test mode.
    void Utils::testMode(bool testmode) {
        m_testMode = testmode;
    }

    // Function to get the current system date.
    void Utils::getSystemDate(int* year, int* mon, int* day) {
        if (m_testMode) {
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
        }
        else {
            // If not in test mode, obtain the current system date.
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }
    // Function to calculate the number of days in a given month of a specific year.
    int Utils::daysOfMon(int month, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }

    void Utils::alocpy(char*& destination, const char* source) {
        if (destination != nullptr) {
            delete[] destination;
            destination = nullptr;
        }
        if (source != nullptr) {
            destination = new char[strlen(source) + 1];
            strcpy(destination, source);
        }
    }

    int Utils::getint(const char* prompt) {
        int num;
        bool valid = false;

        if (prompt != nullptr) {
            cout << prompt;
        }
        while (!valid) {
            cin.clear();
            cin >> num;
            if (cin.fail())
            {
                cout << "Invalid Integer, retry: ";
                cin.clear();
                cin.ignore(2000, '\n');
            }
            else
            {
                valid = true;
            }
        }
        return num;
    }

    int Utils::getint(int min, int max, const char* prompt, const char* errMes) {
        int num;

        do {
            num = getint(prompt);
            if (num < min || num > max) {
                if (errMes != nullptr) {
                    cout << errMes << ", retry: ";
                }
                else {
                    cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
                }
                prompt = nullptr;
            }
        } while (num < min || num > max);
        return num;
    }
}
