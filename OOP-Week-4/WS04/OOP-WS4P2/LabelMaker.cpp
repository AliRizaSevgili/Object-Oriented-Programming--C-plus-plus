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

#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "LabelMaker.h"

using namespace std;

namespace sdds {

    LabelMaker::LabelMaker(int noOfLabels)
    {
        if (noOfLabels > 0) {
            numLabels = noOfLabels;
            Labels = new Label[noOfLabels];
        }
        else {
            noOfLabels = 0;
        }
    }

    void LabelMaker::readLabels()
    {
        if (numLabels > 0) {
            cout << "Enter " << numLabels << " labels:" << endl;

            for (int i = 0; i < numLabels; i++) {
                cout << "Enter label number " << i + 1 << endl;
                Labels[i].readLabel();
            }
        }
    }

    void LabelMaker::printLabels()
    {
        for (int i = 0; i < numLabels; i++) {
            Labels[i].printLabel();
            cout << endl;
        }
    }

    LabelMaker::~LabelMaker()
    {

        delete[] Labels;
        Labels = nullptr;
    }

}