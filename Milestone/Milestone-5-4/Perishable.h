/*
Final Project Milestone 5 
Module: Perishable
Filename: Perishable.h
Version 1.0
Author
-----------------------------------------------------------
Date	  Reason
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

#ifndef PERISHABLE_H
#define PERISHABLE_H
#include "Item.h"
#include "Date.h"

namespace sdds {
	class Perishable : public Item {
		char* m_handling;
		Date m_expiry;
	public:
		Perishable();
		~Perishable();
		Perishable(const Perishable&);
		Perishable& operator=(const Perishable&);
		Date& expiry();
		int readSku(std::istream& istr);
		std::ofstream& save(std::ofstream& ofstr) const;
		std::ifstream& load(std::ifstream& ifstr);
		std::ostream& display(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};
}

#endif
