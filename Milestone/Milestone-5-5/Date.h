/*
Final Project Milestone 5 
Module: Date
Filename: Date.h
Version 1.0
Author
-----------------------------------------------------------
Date      Reason
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

#ifndef DATE_H
#define DATE_H
#include "Status.h"

namespace sdds {
	// Define a constant for the maximum year value
	const int maxYear = 2030;
	// Date class declaration
	class Date {
		int year;			// Year component of the date
		int month;			// Month component of the date
		int day;			// Day component of the date
		Status m_state;		// Status object to represent the state of the date
		bool format;		// Flag to indicate the date format (true for YYYY/MM/DD, false for YYYY/DD/MM)
		bool validate();	// Private member function to validate the date
		int unique() const;
		int stringToInt(char* str);
		bool validDigit(char* str);
	public:
		// Constructors
		Date();				// Default constructor
		Date(int newYear, int newMonth, int newDay);   // Parameterized constructor
		~Date();
		Date(const Date&);
		Date& operator=(const Date&);

		// Comparison operators for Date objects
		bool operator==(const Date& obj) const;
		bool operator!=(const Date& obj) const;
		bool operator<(const Date& obj) const;
		bool operator>(const Date& obj) const;
		bool operator<=(const Date& obj) const;
		bool operator>=(const Date& obj) const;
		Status& state();
		Date& formatted(bool format);  // Function to set the date format
		// Conversion operator to check if the date
		operator bool() const;
		// Input and output functions
		std::ostream& write(std::ostream& os) const;  // Function to write the date to output stream
		std::istream& read(std::istream& is);   // Function to read a date from input stream
	};
	// Input and output operators for Date objects
	std::ostream& operator<<(std::ostream& os, const Date& obj);
	std::istream& operator>>(std::istream& is, Date& obj);
};

#endif
