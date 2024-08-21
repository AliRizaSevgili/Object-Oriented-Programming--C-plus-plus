/***********************************************************************
// OOP244 Workshop #7 lab (part 1)
//
// File  Pack.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
//* Student Name : Ali Riza Sevgili
//Student Number  : 135200228
//Student Email   : arsevgili@myseneca.ca
 //> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <limits>
#include "Pack.h"
#include "Container.h"

namespace sdds {
    Pack::Pack() : Container(), m_unitSize(330.0) {}

    Pack::Pack(const char* content, int size, double unitSize, int numUnits) : Container(content, size* unitSize, numUnits* unitSize), m_unitSize(unitSize) {
        if (unitSize <= 0) {
            setEmtpy();
        }
    }

    int Pack::operator+=(int units) {
        int unitsToAdd = units;
        if (unitsToAdd < 0) {
            unitsToAdd = 0;
        }

        int unitsAdded = Container::operator+=(unitsToAdd * m_unitSize) / m_unitSize;
        return unitsAdded;
    }

    int Pack::operator-=(int units) {
        int unitsToRemove = units;
        if (unitsToRemove < 0) {
            unitsToRemove = 0;
        }

        int unitsRemoved = Container::operator-=(unitsToRemove * m_unitSize) / m_unitSize;
        return unitsRemoved;
    }

    double Pack::unit() const {
        return m_unitSize;
    }

    int Pack::noOfUnits() const {
        return int(Container::getQuantity() / m_unitSize);
    }

    int Pack::size() const {
        return int(Container::getCapacity() / m_unitSize);
    }

    void Pack::clear(int size, double unitSize, const char* content) {
        Container::clear(size * unitSize, content);
        if (unitSize > 0) {
            m_unitSize = unitSize;
        }
        else {
            setEmtpy();
        }
    }


    std::ostream& Pack::print(std::ostream& os) const {
        Container::print(os); // Call the base class print function
        os << ", " << noOfUnits() << " in a pack of " << size();
        return os;
    }

    std::istream& Pack::read(std::istream& is) {
        if (noOfUnits() >= size()) {
            std::cout << "Pack is full!, Press <ENTER> to continue...." << std::endl;
            /*is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');*/
            return is;
        }

        std::cout << "Add to ";
        print(std::cout);
        std::cout << std::endl << "> ";

        int amount;
        while (true) {
            if (is >> amount) {
                if (amount >= 1 && amount <= (size() - noOfUnits())) {
                    int addedAmount = static_cast<int>(*this += amount);
                    std::cout << "Added " << addedAmount << std::endl;
                    return is;
                }
                else if (amount > 0) {
                    std::cout << "Value out of range [1<=val<=" << (size() - noOfUnits()) << "]: ";
                }
                else {
                    std::cout << "Invalid Integer, retry: ";
                }
            }
            else {
                std::cout << "Invalid Integer, retry: ";
                is.clear();
                /*is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');*/
            }
        }
    }



    std::ostream& operator<<(std::ostream& os, const Pack& pack) {
        return pack.print(os);
    }

    std::istream& operator>>(std::istream& is, Pack& pack) {
        return pack.read(is);
    }
}
