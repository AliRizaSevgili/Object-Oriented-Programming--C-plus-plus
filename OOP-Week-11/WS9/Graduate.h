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


/***********************************************************************
// OOP244 Workshop # 9: tester program
//
// File: Graduate.h
// Version 1.1
// Date: 11/20/2022
// Author: Razi Iqbal
// Description: This program demonstrates the concept of Polymorphism
// using an example of Student and Graduate.
//
// Revision History
// -----------------------------------------------------------
// Name  Manjot Kaur  Date            Reason
// Fardad          2023-11-02       review
// Fardad          2023-11-21       added namespace sdds
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef GRADUATE_H
#define GRADUATE_H
#include <iostream>

using namespace std;
namespace sdds {
	class Graduate : public Student {
		char* SVname;
		char* title;

	public:
		Graduate();
		Graduate(const char* studentName, int studentAge, const char* supervisorName, const char* thesisTitle);
		Graduate(const Graduate& other); 
		Graduate& operator=(const Graduate& other);
		~Graduate();
		void display() const;

	};
}





#endif
