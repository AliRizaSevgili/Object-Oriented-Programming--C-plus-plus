/*
Final Project Milestone 5 
Module: iProduct
Filename: iProduct.cpp
Version 1.0
Author
-----------------------------------------------------------
Date      Reason
2023/
-----------------------------------------------------------
Student Name		: Ali Riza Sevgili
Student Number		: 135200228
Student Email		: arsevgili@myseneca.ca
Date				: 12 / 2 / 2023
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "iProduct.h"

using namespace std;
namespace sdds {
	iProduct::~iProduct() {
	}

	std::ostream& operator<<(std::ostream& ostr, const iProduct& obj) {
		obj.display(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, iProduct& obj) {
		obj.read(istr);
		return istr;
	}
}
