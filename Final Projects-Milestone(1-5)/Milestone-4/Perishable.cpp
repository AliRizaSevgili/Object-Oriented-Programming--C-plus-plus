/* Citation and Sources...
Final Project Milestone 4
Module: Perishable
Filename: Perishable.cpp
Version 1.0
Author	John Doe
Revision History
-----------------------------------------------------------
Date      Reason
2023/?/?  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
Student Name		: Ali Riza Sevgili
Student Number		: 135200228
Student Email		: arsevgili@myseneca.ca
Date				: 11 / 28 / 2023
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iomanip>
#include <iostream>
#include "Perishable.h"
#include "Item.h"
#include "Utils.h"
using namespace std;
namespace sdds {

    Perishable::Perishable() : Item::Item()
    {
        // Initialize the Instructions pointer to nullptr.
        Instructions = nullptr;

        // Set the Expiry to be formatted as true.
        Expiry.formatted(true);
    }


    Perishable::Perishable(const Perishable& perishable) : Item::Item(perishable)
    {
        // Copy the Expiry from the source Perishable object to this object.
        Expiry = perishable.Expiry;

        // Check if the source Perishable object is valid.
        if (perishable)
        {
            // If valid, allocate memory for the Instructions and copy the content.
            Instructions = new char[strlen(perishable.Instructions) + 1];
            strcpy(Instructions, perishable.Instructions);
        }
        else
        {
            // If not valid, set the Instructions pointer to nullptr.
            Instructions = nullptr;
        }
    }


    Perishable& Perishable::operator=(const Perishable& perishable)
    {
        // Deallocate memory for Instructions and set it to nullptr.
        delete[] Instructions;
        Instructions = nullptr;

        // Copy the Expiry from the source Perishable object to this object.
        Expiry = perishable.Expiry;

        // Check if the source Perishable object is valid.
        if (perishable)
        {
            // Call the base class's operator= to copy its members.
            Item::operator=(perishable);

            // Allocate memory for the Instructions and copy the content.
            Instructions = new char[strlen(perishable.Instructions) + 1];
            strcpy(Instructions, perishable.Instructions);
        }
        else
        {
            // If not valid, set the Instructions pointer to nullptr.
            Instructions = nullptr;
        }

        // Return a reference to this object.
        return *this;
    }


    Perishable::~Perishable()
    {
        delete[] Instructions;
        Instructions = nullptr;
        Expiry.formatted(false);
    }

    const Date& Perishable::expiry() const
    {
        // Return a reference to the Expiry member, which is of type Date.
        return Expiry;
    }

    int Perishable::readSku(std::istream& istr)
    {
        Utils a;

        // Prompt the user for the SKU
        cout << "SKU: ";

        // Read and validate the SKU using the Utils object
        // Ensures SKU is within the specified range (10000 to 39999)
        SKU = a.checking_num(istr, 10000, 39999);

        // Return -1 (function seems to be designed to always return -1)
        return -1;
    }


    std::ofstream& Perishable::save(std::ofstream& ofstr) const
    {
        if (state)
        {
            // Call the save function of the base class (Item) to save common data
            Item::save(ofstr);

            // Add a tab character
            ofstr << "\t";

            // Check if Instructions is not nullptr, then save it followed by a tab character
            if (Instructions != nullptr) {
                ofstr << Instructions << "\t";
            }

            // Save the uniqueValue of Expiry (assuming it's a Date object)
            ofstr << Expiry.uniqueValue();
        }
        return ofstr;
    }


    std::ifstream& Perishable::load(std::ifstream& ifstr) {
        // Call the load function of the base class (Item) to load common data
        Item::load(ifstr);

        // Delete existing Instructions and set it to nullptr
        delete[] Instructions;
        Instructions = nullptr;

        if (ifstr)
        {
            // Ignore characters up to the next tab character
            ifstr.ignore(1000, '\t');

            // Allocate memory for Instructions and read it up to the next tab character
            Instructions = new char[1000];
            ifstr.getline(Instructions, 1000, '\t');

            // Read Expiry (assuming it's a Date object)
            ifstr >> Expiry;

            // Ignore characters up to the end of the line
            ifstr.ignore(1000, '\n');
        }

        return ifstr;
    }


    std::ostream& Perishable::display(std::ostream& ostr) const {
        if (Linear) {
            // Display the item information in a linear format
            ostr << setfill(' ');
            Item::display(ostr);
            if (Instructions != nullptr && strlen(Instructions) != 0)
            {
                ostr << "*"; // Display '*' if there are instructions
            }
            else
            {
                ostr << " "; // Display a space if there are no instructions
            }
            ostr << Expiry; // Display the expiry date
        }
        else
        {
            // Display the item information with additional details
            ostr << std::setfill(' ');
            ostr << "Perishable ";
            Item::display(ostr); // Display common item information
            ostr << "Expiry date: " << Expiry << endl; // Display the expiry date
            if (Instructions != nullptr && strlen(Instructions) != 0)
            {
                ostr << "Handling Instructions: " << Instructions << endl; // Display handling instructions
            }
        }
        return ostr;
    }

    std::istream& Perishable::read(std::istream& istr) {
        Item::read(istr); // Read common item information

        delete[] Instructions;
        Instructions = nullptr;
        Instructions = new char[1000];

        cout << "Expiry date (YYMMDD): ";
        istr >> Expiry; // Read the expiry date in YYMMDD format
        istr.ignore(1000, '\n');

        cout << "Handling Instructions, ENTER to skip: ";
        istr.getline(Instructions, 1000); // Read handling instructions

        if (Instructions[0] == '\n')
        {
            Instructions = nullptr;
        }

        state = true;

        return istr;
    }

}

