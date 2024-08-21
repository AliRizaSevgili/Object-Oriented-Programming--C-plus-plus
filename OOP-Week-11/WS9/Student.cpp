/***********************************************************************
// OOP244 Workshop #9

// Student Name     : Ali Riza Sevgili
   Student Number	: 135200228
   Student Email	: arsevgili@myseneca.ca
   Date			    : 11/25/2023
   > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;
namespace sdds {
	Student::Student() {
		m_name = {nullptr};
		m_age = 0;
	}

	Student::Student(const char* studentName, int studentAge) {
		m_name = new char[strlen(studentName) + 1];
		strcpy(m_name, studentName);
		m_age = studentAge;
	}

	Student::Student(const Student& other) {
		m_name = new char[strlen(other.m_name) + 1];
		strcpy(m_name, other.m_name);
		m_age = other.m_age;
	}

	Student& Student::operator=(const Student& other) 
	{
		if (this != &other) {
			delete[] m_name;
			m_name = new char[strlen(other.m_name) + 1];
			strcpy(m_name, other.m_name);
			m_age = other.m_age;
		}
		return *this;
	
	}

	Student::~Student()
	{
		delete[] m_name;
	}
	
	void Student::display() const
	{
		cout << "Name: " << m_name << endl <<"Age: " << m_age << endl;
	}


}