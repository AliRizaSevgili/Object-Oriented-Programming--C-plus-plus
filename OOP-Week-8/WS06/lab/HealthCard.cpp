// Workshop #6:
// Version: 1.0
// File name: HealthCard.cpp
// Date: 2023/11/05
// Author: Wail Mardini
// Description:
// This file tests the lab section of your workshop
/* Student Name : Ali Riza Sevgili
Student Number : 135200228
Student Email : arsevgili@myseneca.ca
 > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "HealthCard.h"


namespace sdds {



	bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[])const
	{
		return (name != nullptr && strlen(name) != 0 &&
			number > 999999999 && number < 9999999999 &&
			strlen(vCode) == 2 &&
			strlen(sNumber) == 9);
	}


	HealthCard::HealthCard() {
		m_name = nullptr;
		m_number = 0;
		m_vCode[0] = '\0';
		m_sNumber[0] = '\0';
	}

	void HealthCard::setEmpty() {
		delete[] m_name;
		m_name = nullptr;
		m_number = 0;
		m_vCode[0] = '\0';
		m_sNumber[0] = '\0';
	}
	void HealthCard::allocateAndCopy(const char* name) {
		delete[] m_name;
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
	}

	void HealthCard::extractChar(std::istream& istr, char ch) const {
		char next;
		next = istr.peek();
		if (next == ch) {
			istr.ignore();
		}
		else {
			istr.ignore(1000, ch);
			istr.setstate(std::ios::failbit);
		}
	}
	std::ostream& HealthCard::printIDInfo(std::ostream& ostr) const {
		ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
		return ostr;
	}





	void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]) {
		if (validID(name, number, vCode, sNumber)) {
			setEmpty();
			allocateAndCopy(name);
			m_number = number;
			strcpy(m_vCode, vCode);
			strcpy(m_sNumber, sNumber);
		}
		else {
			setEmpty();
		}

	}
	HealthCard::HealthCard(const char* name, const long long number, const char vCode[], const char sNumber[]) {
		set(name, number, vCode, sNumber);
	}
	HealthCard::HealthCard(const HealthCard& hc) {
		if (validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber)) {
			allocateAndCopy(hc.m_name);
			m_number = hc.m_number;
			strcpy(m_vCode, hc.m_vCode);
			strcpy(m_sNumber, hc.m_sNumber);
		}
	}



	HealthCard& HealthCard::operator=(const HealthCard& hc) {
		if (this == &hc) {
			return *this;
		}
		setEmpty();
		if (validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber)) {
			allocateAndCopy(hc.m_name);
			m_number = hc.m_number;
			strcpy(m_vCode, hc.m_vCode);
			strcpy(m_sNumber, hc.m_sNumber);
		}
		return *this;
	}

	HealthCard::~HealthCard() {
		delete[] m_name;
	}


	HealthCard::operator bool() const {
		return (m_name != nullptr);
	}




	std::ostream& HealthCard::print(std::ostream& ostr, bool toFile) const {
		if (validID(m_name, m_number, m_vCode, m_sNumber)) {
			if (toFile) {
				ostr << m_name << "," << m_number << "-" << m_vCode << ", " << m_sNumber << std::endl;
			}
			else {
				char pad = std::cout.fill('.');
				std::cout << std::left << std::setw(50) << m_name;
				std::cout.fill(pad);
				printIDInfo(std::cout);
			}
		}
		else  if (!toFile) {
			ostr << "Invalid Health Card Record";

		}
		return ostr;
	}


	std::istream& HealthCard::read(std::istream& istr) {
		char name[MaxNameLength]{ '\0' };
		long long number{ 0 };
		char vCode[3]{ 0 };
		char sNumber[10]{ 0 };
		istr.get(name, MaxNameLength, ',');
		extractChar(istr, ',');
		istr >> number;
		extractChar(istr, '-');
		istr.get(vCode, 3, ',');
		extractChar(istr, ',');
		istr.get(sNumber, 10);
		extractChar(istr, '\n');
		if (istr)
		{
			set(name, number, vCode, sNumber);
		}
		else
		{
			istr.clear();
			istr.ignore(1000, '\n');
		}
		return istr;
	}


	std::istream& operator>>(std::istream& istr, HealthCard& hc) {
		return hc.read(istr);
	}



	std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc) {
		return hc.print(ostr, false);
	}


}


