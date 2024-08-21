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
#include "Line.h"
using namespace std;
namespace sdds
{
    static int count = 0;
    void Line::draw(std::ostream& ostr) const
    {
        if (m_length > 0 && LblShape::label()) {
            ostr << LblShape::label();
            count++;
            if (count == 1) {
                ostr.width(m_length);
            }
            else if (count == 6) {
                ostr.width(m_length);
            }
            else if (count == 7) {
                ostr.width(m_length);
            }
            else {
                ostr.width(m_length);
            }
            cout << endl;
            ostr.fill('=');
            cout << "=";
        }
    }
    Line::Line(const char* _label, int _length) : LblShape(_label)
    {
        if (_length > 0)
            m_length = _length;
    }
    void Line::getSpecs(std::istream& istr)
    {
        int _length;
        bool _escape = false;
        do {
            LblShape::getSpecs(istr);
            istr >> _length;
                if (!istr) {
                    istr.clear();
                    istr.ignore(32767, '\n');
                }
                else {
                    istr.ignore();
                    m_length = _length;
                    _escape = true;
                }
            // if(_length < 0){
            // _escape = false;
            // }
        } while (!_escape);
    }
    // int Line::count = 0;
    // void Line::count(int count){
    // count = count;
    // }
    // void Line::count(){
    // count++;
    // }
}


/*#define _CRT_SECURE_NO_WARNINGS

#include "Line.h"
#include <cstring>
#include <iomanip>

namespace sdds {
    Line::Line() : LblShape(), m_length(0) {}

    Line::Line(const char* label, int length) : LblShape(label), m_length(length) {}

    void Line::draw(std::ostream& os) const {
        if (m_length > 0 && label() != nullptr) {
            os << label() << std::endl;
            os << std::setw(m_length) << std::setfill('=') << '=' << std::endl;
        }
    }

    void Line::getSpecs(std::istream& is) {
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(1000, '\n'); // ignores the rest of the line
    }
}*/
