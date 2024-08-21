/***********************************************************************
// OOP244 Workshop #8

// Student Name     : Ali Riza Sevgili
   Student Number	: 135200228
   Student Email	: arsevgili@myseneca.ca
   Date			    : 10/14/2023
   > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "LblShape.h"

using namespace std;
namespace sdds
{
	// constructor
	void LblShape::getSpecs(std::istream& istr)
	{
		string _label;
		getline(istr, _label, ',');
		delete[] m_label;
		m_label = new char[strlen(_label.c_str()) + 1];
		strcpy(m_label, _label.c_str());
	}
	
	LblShape::LblShape(const char* _label)
	{
		if (_label && _label[0] != '\0') {
			m_label = new char[strlen(_label) + 1];
			strcpy(m_label, _label);
		}
	}
	LblShape::~LblShape()
	{
		if (m_label) {
			delete[] m_label;
			m_label = nullptr;
		}
	}
	
	const char* LblShape::label() const
	{
		return m_label;
	}
}



