/*
Final Project Milestone 5 
Module: Status
Filename: Status.h
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

#ifndef STATUS_H
#define STATUS_H

namespace sdds {
	// Status class represents a status message with a description and a code.
	class Status {
		char* objStatus;  // Pointer to a character array for the description.
		int statusCode;  // Integer code representing the status.
	public:
		Status();
		~Status();
		// Constructor with default values.
		Status(const char* obj);
		// Assignment operator overload for copying another Status object.
		Status& operator=(const Status&);
		// Assignment operator overload to set the code using an integer.
		Status& operator=(int newValue);
		// Assignment operator overload to set the description using a string.
		Status& operator=(const char* newStatus);
		// Conversion operator to convert Status to int for retrieving the code.
		operator int() const;
		// Conversion operator to convert Status to char* for retrieving the description.
		operator const char* () const;
		// Conversion operator to convert Status to bool for condition checking.
		operator bool() const;
		// Function to clear the Status object by resetting description and code.
		Status& clear();
	};
	// Friend function to overload the << operator for printing Status objects.
	std::ostream& operator<<(std::ostream& os, const Status& obj);
};

#endif
