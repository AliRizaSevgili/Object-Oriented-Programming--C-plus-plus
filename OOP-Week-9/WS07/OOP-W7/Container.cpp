/***********************************************************************
// OOP244 Workshop #7 lab (part 1)
//
// File  Container.cpp
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
#include <limits>
#include "Container.h"
using namespace std;
namespace sdds {
    Container::Container() {
        _contentType[0] = '\0';
        _capacity = 0.0;
        _quantity = 0.0;
        _spilled = false;
    }
    Container::Container(const char* contentType, double capacity) {
        std::strncpy(_contentType, contentType, 40);
        _contentType[40] = '\0';
        _capacity = capacity;
        _quantity = 0.0;
    }

    Container::Container(const char* contentType, double capacity, double quantity) {
        std::strncpy(_contentType, contentType, 40);
        _contentType[40] = '\0';
        _capacity = capacity;
        _quantity = quantity;
        _spilled = false;
    }


    void Container::setEmtpy()
    {
        _contentType[0] = '\0';
        _quantity = 0;
    }

    const char* Container::getContent() const {
        return _contentType;
    }

    double Container::getCapacity() const {
        return _capacity;
    }

    double Container::getQuantity() const {
        return _quantity;
    }

    double Container::operator+=(double quantity) {
        double added = 0.0;

        if (_quantity < _capacity) {
            added = quantity;
            _quantity += quantity;

            if (_quantity > _capacity) {
                added -= (_quantity - _capacity);
                _quantity = _capacity;
            }
        }

        _spilled = added > 0.0;
        return added;
    }

    double Container::operator-=(double quantity) {
        if (quantity < _quantity) {
            _quantity -= quantity;
            return quantity;
        }
        else {
            double removed = _quantity;
            _quantity = 0.0;
            return removed;
        }
    }
    void Container::clear(double newCapacity, const char* newContentType) {
        _capacity = newCapacity;
        std::strncpy(_contentType, newContentType, 40);
        _contentType[40] = '\0';
        _quantity = 0;
        _spilled = false;
    }





    std::ostream& Container::print(std::ostream& os) const {
        if (_contentType[0] == '\0' || _quantity > _capacity) {

            os << "****: (**cc/***)";
        }
        else {

            os << _contentType << ": (" << _quantity << "cc/" << _capacity << ")";
        }
        return os;
    }




    std::istream& Container::read(std::istream& is) {
        if (_contentType[0] == '\0' || _quantity > _capacity) {
            std::cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << endl;
            return is;
        }

        std::cout << "Add to " << *this << std::endl;
        std::cout << "> ";

        int amount;
        while (true) {
            if (is >> amount) {
                if (amount >= 1 && amount <= 220000) {
                    if (amount <= 999) {
                        int addedAmount = *this += amount;
                        std::cout << "Added " << addedAmount << " CCs" << std::endl;
                        return is;
                    }
                    else {
                        std::cout << "Value out of range [1<=val<=999]: ";
                    }
                }
                else {
                    std::cout << "Value out of range [1<=val<=220000]: ";
                }
            }
            else {
                std::cout << "Invalid Integer, retry: ";
                is.clear();
            }
        }
    }




    std::ostream& operator<<(std::ostream& os, const Container& container)
    {
        container.print(os);
        return os;
    }

    std::istream& operator>>(std::istream& is, Container& container)
    {
        container.read(is);
        return is;
    }


}
