/***********************************************************************
// OOP244 Workshop #3 lab (part 1): tester program

// Student Name     : Ali Riza Sevgili
   Student Number	: 135200228
   Student Email	: arsevgili@myseneca.ca
   Date			    : 09/30/2023
   > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

   // File  main.cpp
// Version 1.0
// Author   Cornel Barna, Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include "Train.h"


namespace sdds {
	Train::Train() {
		trName = nullptr;
		numPassenger = 0;
		departureTime = 0;
	}

	Train::~Train() {
		delete[] trName;
	}
	void Train::initialize() {
		trName = nullptr;
		numPassenger = -1;
		departureTime = -1;
	};

	bool Train::validTime(int value)const {
		return (value >= MIN_TIME && value <= MAX_TIME && value % 100 <= 59);
	};


	bool Train::validNoOfPassengers(int value)const {
		return (value > 0 && value <= MAX_NO_OF_PASSENGERS);
	};

	void Train::set(const char* name) {
		finalize();
		if (name && name[0] != '\0') {
			trName = new char[strlen(name) + 1];
			strcpy(trName, name);
		}
		else {
			name = nullptr;
		}

	};
	void Train::set(int noOfPassengers, int departure) {
		if (validNoOfPassengers(noOfPassengers) && validTime(departure)) {
			numPassenger = noOfPassengers;
			departureTime = departure;
		}
		else {
			numPassenger = -1;
			departureTime = -1;
		}
	};
	void Train::set(const char* name, int noOfPassengers, int departure) {
		if (name && name[0] != '\0') {
			delete[] trName;
			trName = new char[strlen(name) + 1];
			strcpy(trName, name);
		}
		else {
			trName = nullptr;
		}

		if (departure >= MIN_TIME && departure <= MAX_TIME) {
			departureTime = departure;
		}
		else {
			departureTime = -1;
		}
		if (noOfPassengers <= MAX_NO_OF_PASSENGERS && noOfPassengers > 0) {
			numPassenger = noOfPassengers;
		}
		else {
			numPassenger = -1;
		}
	};

	bool Train::isInvalid()const {
		if (trName == nullptr || numPassenger == -1 || departureTime == -1) {
			return true;
		}
		else {
			return false;
		}
	};
	int Train::noOfPassengers() const {
		return numPassenger;
	};
	const char* Train::getName() const {
		return trName;
	};
	int Train::getDepartureTime() const {
		return departureTime;
	};
	void Train::display() const {
		if (!isInvalid()) {
			std::cout << "NAME OF THE TRAIN:    " << getName() << std::endl;
			std::cout << "NUMBER OF PASSENGERS: " << noOfPassengers() << std::endl;
			std::cout << "DEPARTURE TIME:       " << getDepartureTime() << std::endl;
		}
		else {
			std::cout << "Train in an invalid State!" << std::endl;
		}

	};

	void Train::finalize() {
		delete[] trName;
		trName = nullptr;
	};
}
