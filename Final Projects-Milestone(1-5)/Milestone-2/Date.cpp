/* Citation and Sources...
Final Project Milestone 2
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
Date				: 11 / 15 / 2023
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Utils.h"
#include "Status.h"
#include "Date.h"

using namespace std;

// Begin namespace sdds
namespace sdds {

	// Validates the date values for year, month, and day
	bool sdds::Date::validate()
	{
		int currentYear, currentMonth, currentDay;
		// Activating test mode, assuming 'ut' is a utility object
		ut.testMode(true);
		// Retrieves the current system date
		ut.getSystemDate(&currentYear, &currentMonth, &currentDay);

		// Check year validity
		if (year < currentYear || year > MAX_YEAR) {
			// Set status message
			this->status = "Invalid year in date";
			// Set status code
			this->status = 1;
			return false;
		}

		// Check month validity
		if (month < 1 || month > 12) {
			// Set status message
			this->status = "Invalid month in date";
			// Set status code
			this->status = 2;
			return false;
		}

		// Check day validity
		// Get the maximum days in the given month
		int maxDaysInMonth = ut.daysOfMon(month, year);
		if (day < 1 || day > maxDaysInMonth) {
			this->status = "Invalid day in date";
			// Set status code
			this->status = 3;
			return false;
		}

		// If all checks pass, clear the status
		this->status.clear();
		return true;

	}
	// Computes a unique integer value for the date
	int Date::uniqueDateValue(int year, int month, int day) const
	{
		// A formula to create a unique value for a date
		return ((year * 372) + (month * 31) + day);
	}


	// Default constructor
	Date::Date()
	{
		// Activate test mode
		ut.testMode(true);
		// Set the date to the current system date
		ut.getSystemDate(&year, &month, &day);
	}
	// Parameterized constructor
	Date::Date(int year, int month, int day)
	{
		this->year = year; // Set year
		this->month = month;// Set month
		this->day = day;// Set day
		this->validate();// Validate the date
	}

	// Overloaded comparison operators
	bool Date::operator==(const Date& other) const {
		return uniqueDateValue(year, month, day) == uniqueDateValue(other.year, other.month, other.day);
	}

	bool Date::operator!=(const Date& other) const {
		return !(*this == other);
	}

	bool Date::operator<(const Date& other) const {
		return uniqueDateValue(year, month, day) < uniqueDateValue(other.year, other.month, other.day);
	}

	bool Date::operator>(const Date& other) const {
		return uniqueDateValue(year, month, day) > uniqueDateValue(other.year, other.month, other.day);
	}

	bool Date::operator<=(const Date& other) const {
		return uniqueDateValue(year, month, day) <= uniqueDateValue(other.year, other.month, other.day);
	}

	bool Date::operator>=(const Date& other) const {
		return uniqueDateValue(year, month, day) >= uniqueDateValue(other.year, other.month, other.day);
	}
	// Returns the current status of the date object
	const Status& Date::state() const
	{
		return status;
	}
	// Setter to format the date output
	Date& Date::formatted(bool format)
	{
		this->formated = format;
		return *this;
	}

	// Conversion operator to check if the date has a valid status
	Date::operator bool() const {
		return (this->status);
	}

	// Writes the formatted date to an output stream
	std::ostream& Date::write(std::ostream& ostr) const {
		if (formated) {
			// Write in YYYY/MM/DD format
			ostr << std::setfill('0') << std::setw(4) << year << "/"
				<< std::setw(2) << month << "/"
				<< std::setw(2) << day;
		}
		// Write in YYMMDD format
		else {
			ostr << std::setfill('0') << std::setw(2) << (year % 100)
				<< std::setw(2) << month
				<< std::setw(2) << day;
		}
		return ostr;
	}

	// Reads the date from an input stream
	std::istream& Date::read(std::istream& istr) {
		int dateValue;

		if (!(istr >> dateValue)) {
			istr.setstate(std::ios::failbit);
			std::cerr << "Invalid date value";
			return istr;
		}


		int numDigits = 0;
		int temp = dateValue;
		while (temp > 0) {
			temp /= 10;
			numDigits++;
		}

		int currentYear, currentMonth, currentDay;
		ut.getSystemDate(&currentYear, &currentMonth, &currentDay);

		if (numDigits == 6) {
			// Assume YYMMDD format
			year = (dateValue / 10000) + 2000;
			dateValue %= 10000;
			month = dateValue / 100;
			day = dateValue % 100;
			if (!validate()) {
				istr.setstate(std::ios::failbit); // Invalid date format
				return istr;
			}
			return istr;
		}
		else if (numDigits == 4) {
			// Assume MMDD format
			year = currentYear;
			month = dateValue / 100;
			day = dateValue % 100;
			if (!validate()) {
				istr.setstate(std::ios::failbit); // Invalid date format
				return istr;
			}
			return istr;

		}
		else {
			year = currentYear;
			month = dateValue / 100;
			day = dateValue % 100;
			if (!validate()) {
				istr.setstate(std::ios::failbit); // Invalid date format
				return istr;
			}
			return istr;
		}

	}

	// Friend function to overload the insertion operator
	std::ostream& operator<<(std::ostream& os, const Date& date) {
		//os << std::setfill('0') << std::setw(4) << date.year << '-'
		//	<< std::setw(2) << date.month << '-' << std::setw(2) << date.day;
		date.write(os);
		return os;
	}

	// Friend function to overload the extraction operator
	std::istream& operator>>(std::istream& is, Date& date) {
		date.read(is);
		return is;
	}
}


