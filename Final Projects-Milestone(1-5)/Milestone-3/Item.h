/* Citation and Sources...
Final Project Milestone 3
Module: Utils
Filename: Item.h
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
Date				: 11 / 21 / 2023
-----------------------------------------------------------*/


#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include <fstream>
#include "iProduct.h"
#include "Status.h"  

namespace sdds {

    // Item class, derived from iProduct interface
    class Item : public iProduct {
        double price;           // Price of the item
        int quantityOnHand;     // Quantity of item currently on hand
        int quantityNeeded;     // Quantity of item needed
        char* description;      // Description of the item
        bool isLinear;          // Flag for linear format display

    protected:
        Status itemStatus;      // Status of the item
        int sku{};                // Stock Keeping Unit number
        bool linear() const;  // Protected method to return the linear flag
   
    public:
        Item(); // Default constructor

        // Rule of Three
        Item(const Item& other);            // Copy constructor
        Item& operator=(const Item& other); // Assignment operator
        ~Item();                            // Destructor
        
        void clear();                       // Public modifier
        
        // Implementation of pure virtual functions from iProduct
        int readSku(std::istream& istr);         // Read SKU from input stream
        int operator-=(int qty);                 // Decrease quantity on hand
        int operator+=(int qty);                 // Increase quantity on hand
        operator double() const;                 // Convert to double (price)
        operator bool() const;                   // Convert to bool (check state)
        int qtyNeeded() const;                   // Get quantity needed
        int qty() const;                         // Get quantity on hand
        void linear(bool isLinear);              // Set linear format
        std::ofstream& save(std::ofstream& ofstr) const; // Save item to a file
        std::ifstream& load(std::ifstream& ifstr);       // Load item from a file
        std::ostream& display(std::ostream& ostr) const; // Display item on screen
        std::istream& read(std::istream& istr);           // Read item from input stream
        bool operator==(int sku) const;                   // Compare by SKU
        bool operator==(const char* description) const ;  // Compare by description
    };

}

#endif // SDDS_ITEM_H
