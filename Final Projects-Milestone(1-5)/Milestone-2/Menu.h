/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.h
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
Date				: 11 / 15 / 2023
-----------------------------------------------------------*/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds {

    class Menu {
        // Private member variables
        bool validMenu = false; // Flag to indicate if the menu is valid
        char* menuContent; // Dynamically allocated array to store the menu content

        // Private copy constructor and assignment operator to prevent copying
        Menu(const Menu& other); // Copy constructor (not implemented, prevents copying)
        Menu& operator=(const Menu& other); // Assignment operator (not implemented, prevents assignment)

    public:
        // Public constructor and destructor
        Menu(const char* content); // Constructor that takes a C-string for menu content
        ~Menu(); // Destructor to deallocate dynamic memory

        // Public method
        unsigned int run() const; // Method to display the menu and get user's choice

    };
};

#endif // SDDS_MENU_H
