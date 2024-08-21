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
#include "Graduate.h"

using namespace std;
namespace sdds
{
	Graduate::Graduate() {
		SVname = { nullptr };
		title = { nullptr };
	}

	Graduate::Graduate(const char* studentName, int studentAge, const char* thesisTitle, const char* supervisorName) : Student(studentName, studentAge) {
		SVname = new char[strlen(supervisorName) + 1];
		strcpy(SVname, supervisorName);
		title = new char[strlen(thesisTitle) + 1];
		strcpy(title, thesisTitle);
	}
	Graduate::Graduate(const Graduate& other) :Student(other), SVname(nullptr), title(nullptr)
	{
		SVname = new char[strlen(other.SVname) + 1];
		strcpy(SVname, other.SVname);
		title = new char[strlen(other.title) + 1];
		strcpy(title, other.title);
	}

	Graduate& Graduate::operator=(const Graduate& other) {
		if (this != &other) {
			Student::operator=(other);
			delete[]SVname;
			delete[]title;

			SVname = new char[strlen(other.SVname) + 1];
			strcpy(SVname, other.SVname);
			title = new char[strlen(other.title) + 1];
			strcpy(title, other.title);
		}
		return *this;
	}
	

	Graduate::~Graduate()
	{
		delete[] SVname;
		delete[] title;
	}

	void Graduate::display() const {
		Student::display();

		std::cout << "Thesis Title: " << title << std::endl;
		std::cout << "Supervisor: " << SVname << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}
}






