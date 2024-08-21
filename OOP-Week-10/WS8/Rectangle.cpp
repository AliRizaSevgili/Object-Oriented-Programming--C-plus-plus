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
#include <iostream>
#include <cstring>
#include "Rectangle.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace sdds
{
    void Rectangle::getSpecs(std::istream& istr)
    {
        int _width;
        int _height;
        char _comma;
        bool _escape = false;
        do {
            LblShape::getSpecs(istr);
            istr >> _width >> _comma >> _height;
            if (!istr) {
                istr.clear();
                istr.ignore(32767, '\n');
            }
            else {
                istr.ignore();
                m_width = _width;
                m_height = _height;
                _escape = true;
            }
        } while (!_escape);
    }
    void Rectangle::draw(std::ostream& ostr) const
    {
        if (m_width > 0 && m_height >> 0) {
            ostr << '+';
            ostr.width(m_width - 2);
            ostr.fill('-');
            ostr << '-' << '+' << endl;
            ostr << '|';
            ostr.width(m_width - 2);
            ostr.fill(' ');
            ostr << left << LblShape::label() << '|' << endl;
            for (unsigned int i = 0; i < (m_height - 3); i++) {
                ostr << '|';
                ostr.width(m_width - 2);
                ostr.fill(' ');
                ostr << ' ' << '|' << endl;
            }
            ostr << '+';
                ostr.width(m_width - 2);
            ostr.fill('-');
            ostr << '-' << '+';
        }
    }
    Rectangle::Rectangle(const char* _label, int _width, int _height) :
        LblShape(_label)
    {
        int _compareWidth = strlen(LblShape::label()) + 2;
        if (_width > _compareWidth && _height > 3) {
            m_width = _width;
            m_height = _height;
        }
    }
    // void Rectangle::getSpecs(std::istream &istr)
    // {
    // int _width;
    // int _height;
    // bool _escape = false;
    // do {
    // LblShape::getSpecs(istr);
    // istr >> _width;
    // if (!istr) {
    // istr.clear();
    // istr.ignore(32767, '\n');
    // }
    // else {
    // istr.ignore();
    // istr >> _height;
    // if (!istr) {
    // istr.clear();
    // istr.ignore(32767, '\n');
    // }
    // else {
    // istr.ignore();
    // m_width = _width;
    // m_height = _height;
    // _escape = true;
    // }
    // }
    // } while (!_escape);
    // }
}













/*#define _CRT_SECURE_NO_WARNINGS
#include <iomanip> 
#include <iostream>
#include <iomanip>
#include "Rectangle.h"

namespace sdds {
    Rectangle::Rectangle() : LblShape(), m_width(0), m_height(0) {}

    Rectangle::Rectangle(const char* label, int width, int height)
        : LblShape(label), m_width(width), m_height(height) {}

    void Rectangle::draw(std::ostream& os) const {
        if (m_height >= 3 && m_width >= static_cast<int>(std::strlen(label())) + 2) {
            // First line
            os << '+' << std::string(m_width - 2, '-') << '+' << '\n';

            // Second line with label
            os << '|' << std::left << std::setw(m_width - 2) << label() << '|' << '\n';

            // Middle empty lines
            for (int i = 0; i < m_height - 3; ++i) {
                os << '|' << std::string(m_width - 2, ' ') << '|' << '\n';
            }

            // Last line, same as the first line
            os << '+' << std::string(m_width - 2, '-') << '+' << '\n';
        }
    
    }

    void Rectangle::getSpecs(std::istream& is) {
        LblShape::getSpecs(is);
        is >> m_width;
        is.ignore();
        is >> m_height;
        is.ignore(1000, '\n');
        if (m_height < 3 || m_width < static_cast<int>(std::strlen(label())) + 2) {
            m_width = 0;
            m_height = 0;
        }
    }
}
*/