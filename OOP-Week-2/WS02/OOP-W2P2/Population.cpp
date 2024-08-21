
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

#define _CRT_SECURE_NO_WARNINGS
#define DATAFILE "PCpopulations.csv"
#if defined(_WIN32) || defined(_WIN64)
#include <cstring> 
#define strcasecmp _stricmp
#else
#include <strings.h>
#endif
#include <algorithm>
#include <cstring>
#include <string.h>
#include <iostream>
#include <cstdio>
#include "File.h"
#include "Population.h"



using namespace std;


namespace sdds {
	extern FILE* fptr;
	char code[4]{};

	Population* populations = nullptr; 
	int popCount = 0; 
	char g_postalPrefix[4] = "";


	bool startsWith(const char* cstring, const char* subString) {
		return std::strstr(cstring, subString) == cstring;
	}

	// Getting postal code from user input
	bool getPostalCode(char* postal_code_prefix) {
		printf("Population Report\n-----------------\n");
		printf("Enter postal code:\n> ");
		scanf("%3s", postal_code_prefix); // updating to use parameter
		return (strcmp(postal_code_prefix, "!") != 0);
	}


	// Sorting populations array
	// Using standard sort function to sort populations based on count and postal code
	void sortPopulation() {
		std::sort(populations, populations + popCount,
			[](const Population& a, const Population& b) {
				if (a.populationCount != b.populationCount) {
					return a.populationCount < b.populationCount;
				}
				return strcasecmp(a.postalCode, b.postalCode) < 0;
			});
	}

	// Loading population data from file
	bool load(const char* filename, const char* partial_postal_code_prefix) {
		popCount = 0;

		if (!openFile(filename)) {
			cout << "Failed to open the file." << endl;
			return false;
		}

		char postal[4];
		int pop;
		int count = 0;
		int prefixLength = strlen(partial_postal_code_prefix);

		auto matchesPrefix = [&](const char* postal) {
			return strncmp(postal, partial_postal_code_prefix, prefixLength) == 0 ||
				strcmp(partial_postal_code_prefix, "all") == 0;
			};

		while (fscanf(fptr, "%3[^,],%d\n", postal, &pop) == 2) {
			if (matchesPrefix(postal)) {
				count++;
			}
		}
		
		// Allocating memory for population records
		populations = new Population[count];
		rewind(fptr);

		// Loading population data into the allocated memory
		int index = 0;
		while (fscanf(fptr, "%3[^,],%d\n", postal, &pop) == 2) {
			if (matchesPrefix(postal)) {
				strcpy(populations[index].postalCode, postal);  // Noted your change in variable name, please correct if necessary
				populations[index].populationCount = pop;      // Same here for population_count
				index++;
			}
		}

		// Closing the file after reading the data
		closeFile();
		popCount = count;

		return true;
	}


	// Overloaded load function for loading all data
	bool load(const char* filename) {
		return load(filename, "all");
	}


	// Displaying the population data
	void display() {
		

		if (true) {


			sortPopulation();

			cout << "Postal Code: population" << endl;
			cout << "-------------------------" << endl;

			int totalPopulation = 0;
			for (int i = 0; i < popCount; i++) {
				cout << i + 1 << "- " << populations[i].postalCode << ":  " << populations[i].populationCount << endl;
				totalPopulation += populations[i].populationCount;
			}

			cout << "-------------------------" << endl;
			cout << "Population of the listed areas: " << totalPopulation << endl << endl;
		}
		else {
			
			cout << "No data found for the provided postal code prefix." << endl << endl;
		}


	}

	// Deallocating the dynamically allocated memory
	void deallocateMemory() {
		delete[] populations;
		populations = nullptr;
	}
}