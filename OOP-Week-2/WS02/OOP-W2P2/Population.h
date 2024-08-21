/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):

// Student Name     : Ali Riza Sevgili
   Student Number	: 135200228
   Student Email	: arsevgili@myseneca.ca
   Date			    : 09/26/2023
   > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

 // File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {

	struct Population {
		char postalCode[4];
		int populationCount;
	};

	// returns true if the cstring starts with subString
	bool startsWith(const char* cString, const char* subString);

	// Gets postal code from user input
	bool getPostalCode(char* postal_code_prefix);

	// Sorts the population data
	void sortPopulation();

	// Loads population data from file with specified prefix
	bool load(const char* filename, const char* partial_postal_code_prefix);

	// Overloaded load function for loading all data
	bool load(const char* filename);

	// Displays the population data
	void display();

	// Deallocates the dynamically allocated memory
	void deallocateMemory();
}

#endif // SDDS_POPULATION_H_

