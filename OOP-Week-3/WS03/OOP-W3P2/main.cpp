/***********************************************************************
// OOP244 Workshop #3 DIY (part 2): tester program

// Student Name     : Ali Riza Sevgili
   Student Number	: 135200228
   Student Email	: arsevgili@myseneca.ca
   Date			    : 10/01/2023
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

#include <iostream>
#include "Train.h"
using namespace std;
using namespace sdds;
void transfer(Train& to, const Train& from);
int main() {
	int i{};
	int notBoarded;
	Train A, B, C, D;
	A.initialize();
	B.initialize();
	C.initialize();
	D.initialize();
	A.set("Seneca Express A", 500, 300);
	B.set("Seneca Express B", 600, 1455);
	C.set("Seneca Express C", 450, 2255);
	D.set("Seneca Express D", 560, 1022);
	cout << "----------------------------------------" << endl;
	cout << "1. Testing the load function." << endl;
	cout << "----------------------------------------" << endl;
	for (i = 0; i < 2; i++) {
		if (B.load(notBoarded)) {
			cout << "Boarding Complete..." << endl;
		}
		else {
			cout << "Train is full, " << notBoarded << " passengers could not be boarded." << endl;
		}
	}
	cout << "----------------------------------------" << endl;
	cout << "2. Testing the updateDepartureTime function." << endl;
	cout << "----------------------------------------" << endl;
	cout << "Departure time is " << B.getDepartureTime() << endl;
	do {
		if (!B.updateDepartureTime()) {
			cout << "Invalid departure time, valid times are between " << MIN_TIME << " and " << MAX_TIME << "!" << endl;
		}
	} while (B.isInvalid());
	cout << "New departure time is " << B.getDepartureTime() << endl;
	cout << "----------------------------------------" << endl;
	cout << "3. Testing the transfer function." << endl;
	cout << "----------------------------------------" << endl;
	transfer(C, A);
	transfer(A, C);
	A.set(50, 2200);
	transfer(C, A);
	transfer(D, C);
	A.finalize();
	B.finalize();
	C.finalize();
	D.finalize();
	return 0;
}
void transfer(Train& to, const Train& from) {

	cout << "TRANSFERING\n   FROM: " << endl;
	from.display();
	cout << "   TO:" << endl;
	to.display();
	cout << "---->" << endl;
	if (!to.transfer(from)) {
		cout << "Transfer Failed!" << endl << endl;
	}
	else {
		cout << "Transfer Complete:" << endl;
		to.display();
		cout << endl;
	}
}