/***********************************************************************
// OOP244 Workshop #3 lab (part 1): tester program

// Student Name     : Ali Riza Sevgili
   Student Number	: 135200228
   Student Email	: arsevgili@myseneca.ca
   Date			    : 10/01/2023
   > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

   // File  Train.h
// Version 1.0
// Author   Cornel Barna, Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#ifndef _TRAIN_H
#define _TRAIN_H
#include <iostream>
#include <string>

#define MIN_TIME 700
#define MAX_TIME 2300
#define MAX_NO_OF_PASSENGERS 1000

namespace sdds {
	
	class Train {
		
		char* trName;
		int numPassenger; //store number of people on the train
		int departureTime; //store departure time;
		bool valid; // check validity
	
	public:
		
		Train();
		~Train();
		bool load(int& notBoarded);
		void initialize();
		bool validTime(int value)const;
		bool validNoOfPassengers(int value)const;
		void set(const char* name);
		void set(int noOfPassengers, int departure);
		void set(const char* name, int noOfPassengers, int departure);
		void finalize();
		bool isInvalid()const;
		int noOfPassengers() const;
		const char* getName() const;
		int getDepartureTime() const;
		void display() const;
		bool updateDepartureTime();
		bool transfer(const Train& from);
	};

	
};
#endif // TRAIN_H
