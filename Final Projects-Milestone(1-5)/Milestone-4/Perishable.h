/* Citation and Sources...
Final Project Milestone 4
Module: Perishable 
Filename: Perishable .h
Version 1.0
Author	John Doe
Revision History
-----------------------------------------------------------
Date      Reason
2023/?/?  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
Student Name		: Ali Riza Sevgili
Student Number		: 135200228
Student Email		: arsevgili@myseneca.ca
Date				: 11 / 28 / 2023
-----------------------------------------------------------*/
#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include <iostream>
#include "Item.h"
#include "Date.h"
namespace sdds
{
	class Perishable : public Item
	{
	private:
		Date Expiry;
		char* Instructions; // headline 
	public:
		Perishable();

		Perishable(const Perishable& perishable);
		Perishable& operator=(const Perishable& perishable);
		~Perishable();

		const Date& expiry()const;

		ofstream& save(ofstream& ofstr)const;
		ifstream& load(ifstream& ifstr);
		ostream& display(ostream& ostr)const;
		int readSku(istream& istr);
		istream& read(istream& istr);
	};
}

#endif // !SDDS_PERISHABLE_H

