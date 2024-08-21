/* Citation and Sources...
Final Project Milestone 2
Module: AidMan
Filename: AidMan.cpp
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
Date				: 11 /15 / 2023
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include "AidMan.h"
#include <iostream>
#include "Utils.h"
#include <string.h>
#include "Date.h"
#include "Menu.h"


using namespace std;
namespace sdds {
    unsigned int AidMan::menu() const
    {
        cout << "Aid Management System" << endl;

        Date date;
        cout << "Date: " << date << endl;
        if (dataFile != nullptr) {
            cout << "Data file: " << dataFile << endl;
            cout << endl;
        }
        else {
            cout << "Data file: " << "No file" << endl;
            cout << endl;
        }

        return menuObj.run();
    }

    AidMan::AidMan(const char* filename) : dataFile(nullptr), menuObj("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database") {
        if (filename != nullptr) {
            dataFile = new char[strlen(filename) + 1];
            strcpy(dataFile, filename);
        }
    }

    AidMan::~AidMan()  // Destructor
    {
        delete[] dataFile;
        dataFile = nullptr;
    }
    void AidMan::run()
    {
        {
            unsigned int option;
            do {
                option = menu(); // Display the menu and get the user's choice

                switch (option) {
                case 1:
                    cout << "\n****List Items****\n\n";
                    // Implement the task logic for option 1
                    break;
                case 2:
                    cout << "\n****Add Item****\n\n";
                    // Implement the task logic for option 2
                    break;
                case 3:
                    cout << "\n****Remove Item****\n\n";
                    // Implement the task logic for option 3
                    break;
                case 4:
                    cout << "\n****Update Quantity****\n\n";
                    // Implement the task logic for option 4
                    break;
                case 5:
                    cout << "\n****Sort****\n\n";
                    // Implement the task logic for option 5
                    break;
                case 6:
                    cout << "\n****Ship Items****\n\n";
                    // Implement the task logic for option 6
                    break;
                case 7:
                    cout << "\n****New/Open Aid Database****\n\n";
                    // Implement the task logic for option 7
                    break;
                case 0:
                    cout << "Exiting Program!\n";
                    break;
                default:
                    cout << "Invalid option. Please try again.\n";
                }

            } while (option != 0);
        }
    }
}
