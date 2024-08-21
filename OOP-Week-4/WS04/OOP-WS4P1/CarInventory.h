/***********************************************************************
// OOP244 Workshop #4 lab (part 1)

// Student Name     : Ali Riza Sevgili
   Student Number	: 135200228
   Student Email	: arsevgili@myseneca.ca
   Date			    : 10/7/2023
   > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

   // File  main.cpp
// Version 1.0
// Author   Asad Norouzi, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/

// CarInventory.h
#ifndef _CAR_INVENTORY_H
#define _CAR_INVENTORY_H
#include <iostream>
#include <iomanip>
#include <string>

namespace sdds {

	class CarInventory {
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;
	public:
		CarInventory();
		~CarInventory();
		CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1.0);
		void resetInfo();
		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
		void printInfo() const;
		bool isValid() const;
		bool isSimilarTo(const CarInventory& car) const;
	};
	int find_similar(CarInventory car[], const int num_cars);
}
#endif