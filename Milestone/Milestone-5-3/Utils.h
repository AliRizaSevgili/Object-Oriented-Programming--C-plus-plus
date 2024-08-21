/*
Final Project Milestone 5 
Module: Utils
Filename: Utils.h
Version 1.0
Author  Angeline Nicole Faina
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

#ifndef UTILS_H
#define UTILS_H

namespace sdds {
    const int sdds_testYear = 2023;
    const int sdds_testMon = 12;
    const int sdds_testDay = 9;

    // Utils class provides utility functions for various tasks.
    class Utils {
        bool m_testMode = false;  // Flag to indicate whether the application is in test mode.
    public:
        // Function to retrieve the current system date.
        // Parameters 'year', 'mon', and 'day' are optional and can be used to store the date components.
        void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
        int daysOfMon(int mon, int year)const;
        void testMode(bool testmode = true);
        void alocpy(char*& destination, const char* source);
        int getint(const char* prompt = nullptr);
        int getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr);
    };
    extern Utils ut;  // External instance of the Utils class.
}

#endif 
