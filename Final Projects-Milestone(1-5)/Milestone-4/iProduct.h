/* Citation and Sources...
Final Project Milestone 3
Module: iProduct
Filename: iProduct.h
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

#ifndef SDDS_iPRODUCT_H
#define SDDS_iPRODUCT_H

#include <fstream>
#include <iostream>
using namespace std;

namespace sdds
{
    // The iProduct class is a base class for product-related operations.
    class iProduct
    {
    public:
        virtual ~iProduct(); // Virtual destructor for proper cleanup in derived classes.

        // Virtual functions for various product-related operations.
        virtual int readSku(std::istream& istr);
        virtual int operator-=(int qty);
        virtual int operator+=(int qty);
        virtual operator double() const;
        virtual operator bool() const;
        virtual int qtyNeeded() const;
        virtual int qty() const;
        virtual void linear(bool isLinear);
        virtual ofstream& save(ofstream& ofstr) const;
        virtual ifstream& load(ifstream& ifstr);
        virtual ostream& display(ostream& ostr) const;
        virtual istream& read(istream& istr);
        virtual bool operator==(int sku) const;
        virtual bool operator==(const char* description) const;
    };

    // Overloaded input and output operators for iProduct objects.
    istream& operator>>(istream&, iProduct&);
    ostream& operator<<(ostream&, const iProduct&);
}

#endif // !SDDS_iPRODUCT_H
