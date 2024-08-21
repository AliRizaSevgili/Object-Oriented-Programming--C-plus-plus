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
#define _crt_secure_no_warnings

#include "Shape.h"

namespace sdds {
	std::ostream& operator<<(std::ostream& os, const Shape& s) {
		s.draw(os);
		return os;
	}
	std::istream& operator>>(std::istream& is, Shape& s) {
		s.getSpecs(is);
		return is;
	}
}