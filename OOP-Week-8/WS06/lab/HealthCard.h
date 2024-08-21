// Workshop #6:
// Version: 1.0
// File name: HealthCard.h
// Date: 2023/11/05
// Author: Wail Mardini
// Description:
// This file tests the lab section of your workshop
/* Student Name : Ali Riza Sevgili
Student Number : 135200228
Student Email : arsevgili@myseneca.ca
> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//////////////////////////////////////////////////*/

#ifndef SDDS_HEALTHCARD_H 
#define SDDS_HEALTHCARD_H
#include <iostream>

namespace sdds { 

    const int MaxNameLength = 55; // Constant for the maximum length of the name

    class HealthCard { // Declaration of the HealthCard class
        char* m_name{}; // Pointer to dynamically allocated memory for storing the name
        long long m_number; // Variable to store the health card number
        char m_vCode[3]; // Array to store the version code, fixed size of 3 to include null terminator
        char m_sNumber[10]; // Array to store the service number, fixed size of 10 to include null terminator

        // Private member functions
        void allocateAndCopy(const char* name); // Allocates memory and copies the name into m_name
        void extractChar(std::istream& istr, char ch) const; // Extracts a character from the input stream

        std::ostream& printIDInfo(std::ostream& ostr) const; // Prints the ID information to an output stream

        // Validates the HealthCard information
        bool validID(const char* name, long long number, const char vCode[], const char sNumber[]) const;
        void setEmpty(); // Sets the HealthCard to a safe empty state

    public:
        // Public constructors and destructor
        HealthCard(); // Default constructor
        HealthCard(const HealthCard& hc); // Copy constructor
        HealthCard& operator=(const HealthCard& hc); // Copy assignment operator
        ~HealthCard(); // Destructor

        // Type conversion operator
        operator bool() const; // Converts the HealthCard object to a boolean value based on its validity

        // Member functions for printing and reading HealthCard information
        std::ostream& print(std::ostream& ostr, bool toFile = true) const; // Prints the HealthCard information
        std::istream& read(std::istream& istr); // Reads the HealthCard information from an input stream
        void set(const char* name, long long number, const char vCode[], const char sNumber[]); // Sets the HealthCard data

        // Parameterized constructor
        HealthCard(const char* name, const long long number, const char vCode[], const char sNumber[]); // Parameterized constructor to initialize a HealthCard

    };

    // Non-member operator overloads
    std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc); // Overload of the insertion operator for output
    std::istream& operator>>(std::istream& istr, HealthCard& hc); // Overload of the extraction operator for input

}

#endif // SDDS_HEALTHCARD_H // End of include guard

