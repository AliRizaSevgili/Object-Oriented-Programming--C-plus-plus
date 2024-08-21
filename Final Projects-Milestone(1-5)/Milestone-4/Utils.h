/* Citation and Sources...
Final Project Milestone 4
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
Date				: 11 / 28 / 2023
-----------------------------------------------------------*/
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds {
    const int sdds_testYear = 2023;
    const int sdds_testMon = 12;
    const int sdds_testDay = 9;
   
    // Utils class provides utility functions for various tasks.
    class Utils
    {
        bool m_testMode = false; // Flag to indicate whether the application is in test mode.

    public:
        // Function to retrieve the current system date.
        // Parameters 'year', 'mon', and 'day' are optional and can be used to store the date components.
        void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);

        // Function to get the number of days in a given month of a specific year.
        int daysOfMon(int mon, int year) const;

        // Function to set the test mode flag.
        void testMode(bool testmode = true);

        // Function to read an integer from the input stream 'istr' and validate it within the range [x, y].
        int checking_num(std::istream& istr, int x, int y);

        // Function to read a floating-point number from the input stream 'istr' and validate it within the range [x, y].
        double checking_float(std::istream& istr, double x, double y);
    };

    extern Utils ut; // External instance of the Utils class.

} // namespace sdds

#endif // !SDDS_UTILS_H
