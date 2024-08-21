/* Citation and Sources...
Final Project Milestone 4
Module: Item
Filename: Item.cpp
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
Date				: 11 /28 / 2023
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iomanip>
#include <iostream>
#include "Item.h"
#include "Utils.h"
using namespace std;
namespace sdds

{
    // Default Constructor for Item class
    Item::Item()
    {

        Price = 0;   // Set initial price to zero
        Quantity = 0;  // Initialize quantity on hand to zero
        Quantity_Needed = 0; // Set initial quantity needed to zero
        SKU = 0;  // Initialize SKU (Stock Keeping Unit) to zero
        Linear = false; // Set display format to non-linear by default
        state = false; // Initialize item's state to false (not ready/valid)
        Description = nullptr; // Set description pointer to null (no description)
    }

   
    

    // Copy Constructor for Item class
    Item::Item(const Item& item)
    {
        // Check if the source item is valid
        if (item)
        {
            // Copy basic attributes from the source item
            Price = item.Price;               // Copy the price
            Quantity = item.Quantity;         // Copy the current quantity
            Quantity_Needed = item.Quantity_Needed; // Copy the quantity needed
            SKU = item.SKU;                   // Copy the Stock Keeping Unit number

            Linear = item.Linear;             // Copy the display format flag
            state = item.state;               // Copy the state of the item

            // Allocate memory for Description and copy the content
            Description = new char[strlen(item.Description) + 1];
            strcpy(Description, item.Description);
        }
        else
        {
            // Set Description to nullptr if source item is invalid
            Description = nullptr;
        }
    }



    // Assignment Operator for Item class
    Item& Item::operator=(const Item& item)
    {
        // First, delete the existing description to avoid memory leak
        delete[] Description;

        // Copy simple attributes from the source item
        Price = item.Price;                    // Copy the price
        Quantity = item.Quantity;              // Copy the current quantity
        Quantity_Needed = item.Quantity_Needed; // Copy the quantity needed
        SKU = item.SKU;                        // Copy the Stock Keeping Unit number

        Linear = item.Linear;                  // Copy the display format flag
        state = item.state;                    // Copy the state of the item

        // Check if the source item is valid
        if (item)
        {
            // Allocate new memory for Description and copy the content
            Description = new char[strlen(item.Description) + 1];
            strcpy(Description, item.Description);
        }
        else
        {
            // Set Description to nullptr if source item is invalid
            Description = nullptr;
        }

        // Return a reference to this object
        return *this;
    }


    Item::~Item()
    {
        Price = 0;
        Quantity = 0;
        Quantity_Needed = 0;
        SKU = 0;

        Linear = false;
        state = false;

        delete[] Description;
        Description = nullptr;
    }

    // Get the quantity needed for the item
    int Item::qtyNeeded() const
    {
        // Returns the value of Quantity_Needed
        return Quantity_Needed;
    }

    // Get the current quantity of the item
    int Item::qty() const
    {
        // Returns the value of Quantity
        return Quantity;
    }

    // Convert the Item object to its price value
    Item::operator double() const
    {
        // Implicitly returns the Price as a double
        return Price;
    }

    // Evaluate the item's state as a boolean value
    Item::operator bool() const
    {
        // Returns true if the state is true, otherwise returns false
        if (state)
        {
            return true;
        }
        return false;
    }


    // Decrements the item's quantity by a specified amount
    int Item::operator-=(int qty)
    {
        // Subtract 'qty' from 'Quantity' and return the new value
        return Quantity -= qty; // Note: The second return statement is unreachable and will not be executed
        return Quantity;
    }

    // Increments the item's quantity by a specified amount
    int Item::operator+=(int qty)
    {
        // Add 'qty' to 'Quantity' and return the new value
        return Quantity += qty; // Note: The second return statement is unreachable and will not be executed
        return Quantity;
    }

    // Sets the display mode of the item to linear or non-linear
    void Item::linear(bool isLinear)
    {
        // If 'isLinear' is true, set 'Linear' to true, otherwise set it to false
        if (isLinear)
        {
            Linear = true;
        }
        else
        {
            Linear = false;
        }
    }


    void Item::clear()
    {
        Price = 0;
        Quantity = 0;
        Quantity_Needed = 0;
        SKU = 0;

        delete[] Description;
        Description = nullptr;

        Linear = false;
        state = false;
    }

    // Overloaded equality operator to compare Item's SKU with an integer
    bool Item::operator==(int sku) const
    {
        // Initialize the result as false
        bool value = false;

        // If the Item's SKU matches the provided sku, set the result to true
        if (SKU == sku)
        {
            value = true;
        }

        // Return the comparison result
        return value;
    }

    // Overloaded equality operator to compare Item's description with a C-string
    bool Item::operator==(const char* description) const
    {
        // If the Item's Description contains the provided description string, return true
        if (strstr(Description, description))
            return true;

        // Otherwise, return false
        return false;
    }


    // Saves the current state of the Item object to a file stream
    std::ofstream& Item::save(std::ofstream& ofstr) const
    {
        // Check if the item's state is valid for saving
        if (state)
        {
            // Write item details to the file stream, separated by tabs
            ofstr << SKU << "\t";             // Write the Stock Keeping Unit
            ofstr << Description << "\t";     // Write the item's description
            ofstr << Quantity << "\t"         // Write the current quantity
                << Quantity_Needed << "\t"  // Write the quantity needed
                << Price;                   // Write the price of the item
        }

        // Return the file stream
        return ofstr;
    }


    // Loads item data from a file stream
    std::ifstream& Item::load(std::ifstream& ifstr)
    {
        // First, deallocate any existing memory for Description
        delete[] Description;

        // Allocate new memory for Description
        Description = new char[1000];

        // Check if the file stream is in a good state
        if (ifstr)
        {
            // Read data from the file stream into the item's attributes
            ifstr >> SKU; // Read the Stock Keeping Unit
            ifstr.ignore(1000, '\t'); // Ignore characters until a tab is encountered
            ifstr.getline(Description, 1000, '\t'); // Read the description up to 1000 characters or until a tab
            ifstr >> Quantity; // Read the quantity
            ifstr >> Quantity_Needed; // Read the quantity needed
            ifstr >> Price; // Read the price

            // Set the item's state as valid and in a good state
            state.clear(); // Clear any existing state message
            state = "This object is in a good state!"; // Set a new state message
            state = true; // Set the state flag to true
        }

        // Return the file stream
        return ifstr;
    }


    // Displays the item information to the output stream
    std::ostream& Item::display(std::ostream& ostr) const
    {
        // Check if the linear format is set for displaying
        if (Linear == true)
        {
            // Display in linear format
            ostr << SKU << " | "; // Output the SKU followed by a separator
            char des[36]; // Buffer for truncated description

            strncpy(des, Description, 35); // Copy first 35 characters of description
            des[35] = '\0'; // Ensure null termination
            ostr << left << setw(35) << des; // Output the truncated description with left alignment
            ostr << " | ";
            ostr << right << setw(4) << Quantity << " | " // Output the quantity with right alignment
                << right << setw(4) << Quantity_Needed << " | " // Output the quantity needed with right alignment
                << right << setw(7) << Price << " |"; // Output the price with right alignment
        }
        else
        {
            // Display in detailed format
            ostr << "AMA Item:" << endl; // Output a header
            ostr << SKU << ": " << Description << endl; // Output the SKU and full description
            ostr << "Quantity Needed: " << Quantity_Needed << endl; // Output the quantity needed
            ostr << "Quantity Available: " << Quantity << endl; // Output the available quantity
            ostr.setf(ios::fixed);
            ostr.precision(2); // Set precision for price display
            ostr << "Unit Price: $" << Price << endl; // Output the unit price
            ostr.setf(ios::fixed);
            ostr.precision(2); // Ensure precision is set for the next price display
            ostr << "Needed Purchase Fund: $"; // Output the label for needed purchase fund
            ostr << Price * (Quantity_Needed - Quantity) << endl; // Output the calculated needed purchase fund
        }
        return ostr; // Return the output stream
    }


    // Reads item details from an input stream
    std::istream& Item::read(std::istream& istr)
    {
        Utils a; // Util object for validation

        // Deallocate any existing memory for Description
        delete[] Description;
        Description = nullptr; // Set to nullptr to ensure safe reallocation
        Description = new char[1000]; // Allocate new memory for Description

        // Prompt user for input
        cout << "AMA Item:\n";
        cout << "SKU: ";
        cout << SKU << endl; // Display current SKU
        cout << "Description: ";

        // Read the description from input
        istr.ignore(1000, '\n'); // Ignore characters until newline
        istr.getline(Description, 1000); // Read the description

        // Check for invalid input
        if (Description == nullptr)
        {
            cout << "Console entry failed!";
        }

        // Prompt for quantity needed and validate input
        cout << "Quantity Needed: ";
        Quantity_Needed = a.checking_num(istr, 1, 9999); // Use Utils to check the input number

        // Check for invalid input
        if (Quantity_Needed < 1 || Quantity_Needed > 9999)
        {
            cout << "Console entry failed!";
        }

        // Prompt for quantity on hand and validate input
        cout << "Quantity On Hand: ";
        Quantity = a.checking_num(istr, 0, 22); // Use Utils to check the input number

        // Check for invalid input
        if (Quantity < 0 || Quantity > Quantity_Needed)
        {
            cout << "Console entry failed!";
        }

        // Prompt for unit price and validate input
        cout << "Unit Price: $";
        Price = a.checking_float(istr, 0, 9999); // Use Utils to check the input float

        // Check for invalid input
        if (Price < 0.0 || Price > 9999.0)
        {
            cout << "Console entry failed!";
        }

        // Set the state of the item to indicate it's in a good state
        state.clear(); // Clear existing state message
        state = "This object is in a good state!"; // Set a new state message
        state = true; // Set the state flag to true

        return istr; // Return the input stream
    }


    // Reads the SKU (Stock Keeping Unit) from an input stream
    int Item::readSku(std::istream& istr)
    {
        Utils a; // Util object for input validation

        // Prompt the user for the SKU
        cout << "SKU: ";
        // Read and validate the SKU using the Utils object
        // Ensures SKU is within the specified range (40000 to 99999)
        SKU = a.checking_num(istr, 40000, 99999);

        // Return -1 (function seems to be designed to always return -1)
        return -1;
    }

}
