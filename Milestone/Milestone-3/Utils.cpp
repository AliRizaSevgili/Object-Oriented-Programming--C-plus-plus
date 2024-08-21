/* Citation and Sources...
Final Project Milestone 3
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
Date				: 11 / 21 / 2023
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstring>
#include<iomanip>
#include <limits>
#include "Utils.h"
using namespace std;
namespace sdds 

{
    Utils ut;
    void Utils::testMode(bool testmode) {
        m_testMode = testmode;
    }

    
    void Utils::alocpy(char*& destination, const char* source)
    {
        delete[] destination;

        if (source != nullptr) {
            destination = new char[strlen(source) + 1];
            strcpy(destination, source);
        }
    }
    

    int Utils::getint(const char* prompt) {
        int input;
        bool validInput = false;
        char buffer;

        // Display the prompt if provided
        if (prompt != nullptr) {
            cout << prompt;
        }

        do {
            cin >> input;
            if (!cin) {
                cout << "Invalid Integer, retry: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else {
                cin.get(buffer);
                if (buffer != '\n') {
                    cout << "Enter only an integer, try again: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                else {
                    validInput = true;
                }
            }
        } while (!validInput);
        return input;

        return input;
    }

    int Utils::getint(int min, int max, const char* prompt, const char* errMes) {
        int input = 0;
        bool validInput = false;
        char buffer;
        if (prompt) {
            cout << prompt;
        }
        do {
            cin >> input;
            if (!cin) {
                cout << "Invalid Integer, retry: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else {
                cin.get(buffer);
                if (buffer != '\n') {
                    cout << "Enter only an integer, try again: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                else if (input < min || input > max) {
                    if (errMes) {
                        cout << errMes << ", retry: ";
                    }
                    else {
                        cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
                    }
                }
                else {
                    validInput = true;
                }
            }
        } while (!validInput);
        return input;
    }

    double Utils::getdouble(double min, double max, const char* prompt, const char* errMes)
    {
        double input;
        char buffer;
        bool flag = false;
        if (prompt) {
            cout << prompt;
        }
        do {
            cin >> input;
            if (!cin) {
                cout << "Invalid number, retry: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else {
                cin.get(buffer);
                if (buffer != '\n') {
                    cout << "Enter only a double, try again: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                else if (input < min || input > max) {
                    if (errMes) {
                        cout << errMes << ", retry: ";
                    }
                    else {
                        cout << "Value out of range [" << fixed << setprecision(2) << min << "<=val<=" << max << "]: ";
                    }
                }
                else {
                    flag = true;
                }
            }
        } while (!flag);
        return input;
    }

    void Utils::getSystemDate(int* year, int* mon, int* day) {
        if (m_testMode) {
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
        }
        else {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }
    int Utils::daysOfMon(int month, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }

   /* int Utils::countOptions(const char* text)
    {
        int count = 0;
        for (int i = 0; text[i]; i++) {
            if (text[i] == '\t') {
                count++;
            }
        }
        return count + 1; // Add 1 to count the last option after the last tab.
    }
    */
}