/***********************************************************************
// OOP244 Workshop #4 DIY (part 2): tester program
// Student Name     : Ali Riza Sevgili
   Student Number	: 135200228
   Student Email	: arsevgili@myseneca.ca
   Date			    : 10/7/2023
   > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// File  main.cpp
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/


#ifndef SDDS_LABEL_H_
#define SDDS_LABEL_H_

#include <iostream>

namespace sdds {
    const char defaultFrame[9] = "+-+|+-+|";

    class Label
    {
    private://private members
        char frame[9];
        char* onelineText;

    public:

        Label();
        Label(const char* frameArg);
        Label(const char* frameArg, const char* content);
        ~Label();

        std::istream& readLabel();
        std::ostream& printLabel() const;
        Label& text(const char* content);
    };
}
#endif