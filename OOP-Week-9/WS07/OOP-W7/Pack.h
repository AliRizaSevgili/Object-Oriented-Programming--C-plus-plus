/***********************************************************************
// OOP244 Workshop #7 lab (part 1)
//
// File  Pack.h
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
// > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//***********************************************************************/

#ifndef SDDS_PACK_H
#define SDDS_PACK_H
#include "Container.h"

namespace sdds {
    class Pack : public Container {

        double m_unitSize{};

    public:
        Pack();
        Pack(const char* contentType, int size, double unitSize = 330.0, int noOfUnits = 0);
        /* ~Pack();*/
        int operator+=(int units);
        int operator-=(int units);

        double unit() const;
        int noOfUnits() const;
        int size() const;

        void clear(int size, double unitSize, const char* content);


        std::ostream& print(std::ostream& os) const;

        std::istream& read(std::istream& is);
    };
    std::ostream& operator<<(std::ostream& os, const Pack& pack);
    std::istream& operator>>(std::istream& is, Pack& pack);

}

#endif
