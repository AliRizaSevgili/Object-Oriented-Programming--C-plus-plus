
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

#ifndef SDDS_Lblshape_H_
#define SDDS_Lblshape_H_
#include "Shape.h"
namespace sdds
{
	class LblShape : public Shape
	{
		char* m_label{ nullptr };
	protected:
		const char* label() const;
	public:
		LblShape() {} // default constructor
		LblShape(const char* _label); // one argument constructor
		virtual ~LblShape();
		LblShape(const LblShape& src) = delete;
		LblShape& operator=(const LblShape& src) = delete;
		void getSpecs(std::istream& istr);
	};
}
#endif
























//#ifndef SDDS_LBLSHAPE_H
//#define SDDS_LBLSHAPE_H
//
//
//
//
//
//#include "Shape.h"
//
//namespace sdds {
//    class LblShape :public Shape {
//        char* m_label;
//    protected:
//        const char* label() const;
//        void setLabel(const char* label);
//    public:
//        LblShape();
//        LblShape(const char* label);
//        ~LblShape();
//        LblShape(const LblShape& ls) = delete;
//        LblShape& operator=(const LblShape& ls) = delete;
//        void getSpecs(std::istream& is)override;
//    };
//}
//
//
//#endif
