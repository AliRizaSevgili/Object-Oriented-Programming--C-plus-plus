/***********************************************************************
// OOP244 Workshop #8 

// Student Name     : Ali Riza Sevgili
   Student Number	: 135200228
   Student Email	: arsevgili@myseneca.ca
   Date			    : 10/14/2023
   > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H

#include <iostream>

namespace sdds {
    class Shape {
    public:
        virtual void draw(std::ostream& os) const = 0;
        virtual void getSpecs(std::istream& is) = 0;
        virtual ~Shape() = default;
    };

    std::ostream& operator<<(std::ostream& os, const Shape& s);
    std::istream& operator>>(std::istream& is, Shape& s);
}

#endif
