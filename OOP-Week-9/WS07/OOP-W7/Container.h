/***********************************************************************
// OOP244 Workshop #7 lab (part 1)
//
// File  Container.h
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
#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H
#include <iostream>

namespace sdds {
    class Container {
    private:
        char _contentType[51];
        double _capacity{};
        double _quantity{};
        bool _spilled{};
    public:
        Container();

        Container(const char* contentType, double capacity);
        Container(const char* contentType, double capacity, double quantity);
        double operator+=(double quantity);
        double operator-=(double quantity);
        void setEmtpy();

        const char* getContent() const;
        double getCapacity() const;
        double getQuantity() const;


        void clear(double newCapacity, const char* newContentType);
        virtual std::istream& read(std::istream& is);
        virtual std::ostream& print(std::ostream& os) const;
    };
    std::ostream& operator<<(std::ostream& os, const Container& container);
    std::istream& operator>>(std::istream& is, Container& container);
}

#endif
