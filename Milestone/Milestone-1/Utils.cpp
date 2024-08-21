/***********************************************************************
// Final project Milestone 1
// Module: Utils
// File: Utils.cpp
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
//***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstring>
#include <limits>
#include "Utils.h"
using namespace std;
namespace sdds {
    Utils ut;
    void Utils::testMode(bool testmode) {
        m_testMode = testmode;
    }
    void Utils::alocpy(char*& destination, const char* source)
    {
        delete[] destination;
        destination = nullptr;

        if (source != nullptr) {
            destination = new char[strlen(source) + 1];
            strcpy(destination, source);
        }
    }

    int Utils::getint(const char* prompt) {
        int input;
        bool validInput = false;
        const char* retryMessage = "Invalid Integer, retry: ";

        // Display the prompt if provided
        if (prompt != nullptr) {
            std::cout << prompt;
        }

        // Keep prompting until a valid integer is entered
        while (!validInput) {
            if (!(std::cin >> input)) {
                // Input is not a valid integer, clear error flags and discard input
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << retryMessage;
            }
            else {
                validInput = true;
            }
        }

        return input;
    }

    int Utils::getint(int min, int max, const char* prompt, const char* errMes) {
        int input = 0;
        bool validInput = false;
        const char* errorMessage = ", retry: ";
        if (prompt != nullptr) {
            input = getint(prompt);
        }
        while (!validInput) {
            if (!(std::cin >> input) && input > min && input > max) {
                // Input is not a valid integer, clear error flags and discard input
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (errMes != nullptr) {
                    std::cout << errorMessage;
                }
                else {
                    std::cout << "Value out of range [" << min << "<=" << input << "<=" << max << "]: " << endl;
                }
            }
            else {
                validInput = true;
            }
        }
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

}