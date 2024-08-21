/* Citation and Sources...
Final Project Milestone 4
Module: Item
Filename: Item.h
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


#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include "iProduct.h"
#include "Status.h"
using namespace std;
namespace sdds
{
	class Item : public iProduct
	{
	private:
		double Price;
		int Quantity;
		int Quantity_Needed;
		char* Description;
	protected:
		bool Linear;
		Status state;
		int SKU;
		bool linear();
	public:
		Item();
		Item(const Item& item);
		Item& operator=(const Item& item);
		~Item();
		int qtyNeeded()const;
		int qty()const;
		operator double()const;
		operator bool()const;
		int operator-=(int qty);
		int operator+=(int qty);
		void linear(bool isLinear);
		void clear();
		bool operator==(int sku)const;
		bool operator==(const char* description)const;
		ofstream& save(ofstream& ofstr)const;
		ifstream& load(ifstream& ifstr);
		ostream& display(ostream& ostr)const;
		int readSku(istream& istr);
		istream& read(istream& istr);
	};
}

#endif // !SDDS_ITEM_H