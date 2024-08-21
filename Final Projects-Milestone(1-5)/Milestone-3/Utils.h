/* Citation and Sources...
Final Project Milestone 3
Module: Utils
Filename: Utils.h
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
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
namespace sdds {
    const int sdds_testYear = 2023;
    const int sdds_testMon = 12;
    const int sdds_testDay = 9;
    class Utils {
        bool m_testMode = false;
    public:
        void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
        int daysOfMon(int mon, int year)const;
        void testMode(bool testmode = true);
        void alocpy(char*& destination, const char* source);
        int getint(const char* prompt = nullptr);
        int getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr);
        //int countOptions(const char* text);
        double getdouble(double min, double max, const char* prompt = nullptr, const char* errMes = nullptr);
    };
    extern Utils ut;
}

#endif // !SDDS_UTILS_H
