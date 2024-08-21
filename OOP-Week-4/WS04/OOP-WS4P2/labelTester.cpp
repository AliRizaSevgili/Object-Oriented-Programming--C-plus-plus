/***********************************************************************
// OOP244 Workshop #4 DIY (part 2): tester program
// Student Name     : Ali Riza Sevgili
   Student Number	: 135200228
   Student Email	: arsevgili@myseneca.ca
   Date			    : 10/7/2023
   > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// File  main.cpp
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#include <iostream>
#include "Label.h"
using namespace std;
using namespace sdds;
int main() {
	Label title;
	Label L("AbCdEfGh");
	cout << ">";
	title.printLabel() << "<" << endl;
	title.text("Enter a label text!");
	title.printLabel() << endl << "> ";
	L.readLabel();
	L.printLabel();
	return 0;
}