/* Citation and Sources...
Final Project Milestone 3
Module: iProduct
Filename: iProduct.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <fstream>
#include "iProduct.h"
using namespace std;
namespace sdds
{
    iProduct::~iProduct()
    {
    }

    int iProduct::readSku(std::istream& istr)
    {
        return 0;
    }

    int iProduct::operator-=(int qty)
    {
        return 0;
    }

    int iProduct::operator+=(int qty)
    {
        return 0;
    }

    iProduct::operator double() const
    {
        return 0;
    }

    iProduct::operator bool() const
    {
        return 0;
    }

    int iProduct::qtyNeeded() const
    {
        return 0;
    }

    int iProduct::qty() const
    {
        return 0;
    }

    void iProduct::linear(bool isLinear)
    {
        return;
    }

    std::ofstream& iProduct::save(std::ofstream& ofstr) const
    {
        return ofstr;
    }

    std::ifstream& iProduct::load(std::ifstream& ifstr)
    {
        return ifstr;
    }

    std::ostream& iProduct::display(std::ostream& ostr) const
    {
        return ostr;
    }

    std::istream& iProduct::read(std::istream& istr)
    {
        return istr;
    }

    bool iProduct::operator==(int sku) const
    {
        return true;
    }

    bool iProduct::operator==(const char* description) const
    {
        return true;
    }

    istream& operator>>(istream& in, iProduct& p)
    {
        return p.read(in);
    }

    ostream& operator<<(ostream& os, const iProduct& p)
    {
        return p.display(os);
    }

}