/*
Final Project Milestone 5 
Module: iProduct
Filename: iProduct.h
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

#ifndef IPRODUCT_H
#define IPRODUCT_H

namespace sdds {

	// The iProduct class is a base class for product-related operations.
	class iProduct {
	public:
		virtual ~iProduct();  // Virtual destructor for proper cleanup in derived classes.
		
		// Virtual functions for various product-related operations.
		virtual int readSku(std::istream& istr) = 0;
		virtual int operator-=(int qty) = 0;
		virtual int operator+=(int qty) = 0;
		virtual operator double()const = 0;
		virtual operator bool()const = 0;
		virtual int qtyNeeded()const = 0;
		virtual int qty()const = 0;
		virtual void linear(bool isLinear) = 0;
		virtual std::ofstream& save(std::ofstream& ofstr)const = 0;
		virtual std::ifstream& load(std::ifstream& ifstr) = 0;
		virtual std::ostream& display(std::ostream& ostr)const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual bool operator==(int sku)const = 0;
		virtual bool operator==(const char* description)const = 0;
	};

	// Overloaded input and output operators for iProduct objects.
	std::ostream& operator<<(std::ostream& ostr, const iProduct& obj);
	std::istream& operator>>(std::istream& istr, iProduct& obj);
}

#endif
