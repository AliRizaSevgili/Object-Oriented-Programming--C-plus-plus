/*
Final Project Milestone 5 
Module: Item
Filename: Item.h
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

#ifndef ITEM_H
#define ITEM_H
#include "Status.h"
#include "iProduct.h"

namespace sdds {
	class Item : public iProduct {
	public:
		double m_price;
		int m_qty;
		int m_qtyNeeded;
		char* m_description;
		bool m_linear;
	protected:
		Status m_state;
		int m_sku;
		bool isLinear();
	public:
		Item();
		~Item();
		Item(const Item&);
		Item& operator=(const Item&);
		operator double()const;
		operator bool()const;
		int qtyNeeded()const;
		int qty()const;
		int operator-=(int qty);
		int operator+=(int qty);
		void linear(bool isLinear);
		void clear();
		bool operator==(int sku)const;
		bool operator==(const char* description)const;
		std::ofstream& save(std::ofstream& ofstr)const;
		std::ifstream& load(std::ifstream& ifstr);
		std::ostream& display(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
		int readSku(std::istream& istr);
	};
}

#endif
