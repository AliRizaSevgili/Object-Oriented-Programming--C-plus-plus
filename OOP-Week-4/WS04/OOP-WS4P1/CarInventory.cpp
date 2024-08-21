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

#define _CRT_SECURE_NO_WARNINGS
#include "CarInventory.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

namespace sdds {
	CarInventory::CarInventory() {
		resetInfo();
	}


	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		resetInfo();
		if (!isValid()) {
			setInfo(type, brand, model, year, code, price);
		}
		else {
			resetInfo();
		}

	}

	CarInventory::~CarInventory() {
		delete[] m_type;
		m_type = nullptr;
		delete[] m_model;
		m_model = nullptr;
		delete[] m_brand;
		m_brand = nullptr;
	}

	void CarInventory::resetInfo() {
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0.0;
	}
	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {
		delete[] m_type;
		m_type = nullptr;
		delete[] m_model;
		m_model = nullptr;
		delete[] m_brand;
		m_brand = nullptr;

		m_type = new char[strlen(type) + 1];
		strcpy(m_type, type);

		m_brand = new char[strlen(brand) + 1];
		strcpy(m_brand, brand);

		m_model = new char[strlen(model) + 1];
		strcpy(m_model, model);

		m_year = year;
		m_code = code;
		m_price = price;


		return *this;
	}
	void CarInventory::printInfo() const {
		std::cout << "| " << std::setw(10) << std::left << m_type << " | "
			<< std::setw(16) << std::left << m_brand << " | "
			<< std::setw(16) << std::left << m_model << " | "
			<< std::setw(4) << std::right << m_year << " | "
			<< std::setw(4) << std::right << m_code << " | "
			<< std::setw(9) << std::fixed << std::setprecision(2) << std::right << m_price << " |" << std::endl;
	}

	bool CarInventory::isValid() const {
		return m_type != nullptr && m_brand != nullptr && m_model != nullptr && m_year >= 1990 && m_code >= 100 && m_code <= 999 && m_price > 0;

	}

	bool CarInventory::isSimilarTo(const CarInventory& car) const {
		if (m_type == nullptr || m_brand == nullptr || m_model == nullptr || car.m_type == nullptr || car.m_brand == nullptr || car.m_model == nullptr) {
			return false;
		}

		return (strcmp(m_type, car.m_type) == 0 && strcmp(m_brand, car.m_brand) == 0 && strcmp(m_model, car.m_model) == 0 && m_year == car.m_year);


	}

	int find_similar(CarInventory car[], const int num_cars) {
		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
				if ((car[i].isValid() && car[j].isValid()) && car[i].isSimilarTo(car[j])) {
					return i;
				}
			}
		}
		return -1;
	}
}