
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

#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_
#include "LblShape.h"
namespace sdds
{
    class Rectangle : public LblShape
    {
        unsigned int m_width{ 0 };
        unsigned int m_height{ 0 };
    public:
        Rectangle() {}
        Rectangle(const char* _label, int _width, int _height);
        virtual ~Rectangle() {}
        void getSpecs(std::istream& istr);
        void draw(std::ostream& ostr) const;
    };
}
#endif

