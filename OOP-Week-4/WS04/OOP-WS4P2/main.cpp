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
#include <iostream>
#include "Label.h"
#include "LabelMaker.h"

using namespace sdds;
using namespace std;
int main() {
    int noOfLabels;
    // Create a lable for the program title:
    Label
        theProgram("/-\\|/-\\|"),
        test1,
        test2("ABCDEFGH");
    test1.printLabel();
    test2.printLabel();
    theProgram.printLabel();
    test1.text("Testing one, two, three");
    test1.printLabel() << endl;
    theProgram.text("Professor's Label Maker Program Tester");
    theProgram.printLabel() << endl << endl;
    // ask for number of labels to get created
    cout << "Number of labels to create: ";
    cin >> noOfLabels;
    cin.ignore(10000, '\n');
    // Create a LabelMaker for the number of 
    // the labels requested
    LabelMaker lblMkr(noOfLabels);
    // Ask for the label texts
    lblMkr.readLabels();
    // Print the labels
    lblMkr.printLabels();
    return 0;
}