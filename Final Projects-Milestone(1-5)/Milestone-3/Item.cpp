/* Citation and Sources...
Final Project Milestone 3
Module: Utils
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
Date				: 11 / 21 / 2023
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<iomanip>
#include <string>
#include<sstream>
#include"Utils.h"
#include"Item.h"
using namespace std;
namespace sdds {

    bool Item::linear() const
    {
        return isLinear;
    }

    // Default Constructor - Initializes all attributes to default values
    Item::Item()
    {
        price=0.0;
        quantityOnHand=0;
        quantityNeeded = 0;
        description = nullptr;
        isLinear = false;
    }
    // Copy Constructor - Performs deep copy
    Item::Item(const Item& other) {
        operator=(other);
    }

    // Assignment Operator - Handles self-assignment and performs deep copy
    Item& Item::operator=(const Item& other) {
        if (this != &other) {
            // Copy simple attributes
            price = other.price;
            quantityOnHand = other.quantityOnHand;
            quantityNeeded = other.quantityNeeded;
            description = new char[strlen(other.description) + 1];
            strcpy(description, other.description);
            itemStatus = other.itemStatus;
            sku = other.sku;
        }
        return *this;
    }

    // Destructor - Releases dynamically allocated memory
    Item::~Item() {
        delete[] description;
    }

    // Returns the quantity needed
    int Item::qtyNeeded() const {
        return quantityNeeded;
    }

    // Returns the quantity on hand
    int Item::qty() const {
        return quantityOnHand;
    }

    // Conversion to double (price)
    Item::operator double() const {
        return price;
    }

    // Conversion to bool (checks if the state is good)
    Item::operator bool() const {
        return itemStatus;
    }

    // Reduces the quantity on hand by the received value
    int Item::operator-=(int qty) {
        quantityOnHand -= qty;
        return quantityOnHand;
    }

    // Increases the quantity on hand by the received value
    int Item::operator+=(int qty) {
        quantityOnHand += qty;
        return quantityOnHand;
    }

    // Sets the linear flag attribute to true or false
    void Item::linear(bool isLinearFlag) {
        isLinear = isLinearFlag;
    }


    // Clears the status of the Item object
    void Item::clear() {
        price = 0.0;
        quantityOnHand = 0;
        quantityNeeded = 0;
        delete[] description;
        description = nullptr;
        isLinear = false;
        itemStatus = nullptr;
        sku = 0;
    }

    // Integer comparison: returns true if the SKU attribute matches the received value
    bool Item::operator==(int skuValue) const {
        return sku == skuValue;
    }

    // Constant character pointer comparison: returns true if the description contains the received C-string
    bool Item::operator==(const char* descriptionValue) const {
        
        return strstr(description, descriptionValue);
    }

    // Save method: Writes Item details to a file if the state is good
    std::ofstream& Item::save(std::ofstream& ofstr) const {
        if (static_cast<bool>(itemStatus)) {  // Checking if the state is good
            ofstr << sku << '\t'
                << description << '\t'
                << quantityOnHand << '\t'
                << quantityNeeded << '\t'
                << std::fixed << std::setprecision(2) << price;
            // Note: No new line is added
        }
        return ofstr;  // Returning the reference of ofstream
    }

    // Load method: Reads Item details from a file
    std::ifstream& Item::load(std::ifstream& ifstr) {
        delete[] description;  // Deallocating the current description
        description = nullptr;
        string tempDesc;
        ifstr >> sku;
        ifstr.ignore(10000, '\t');
        getline(ifstr, tempDesc, '\t');  // Reading description up to tab
        ifstr.ignore(10000, '\t');
        ifstr >> quantityNeeded;
        ifstr.ignore(10000, '\t');
        ifstr >> price;
        ifstr.ignore();
        if (ifstr.bad()) {
            itemStatus = "Input file stream read failed!";
        }
        ut.alocpy(description, tempDesc.c_str());
        return ifstr;  // Returning the reference of ifstream
    }


    // Display method: Prints the details of the Item based on its state
    std::ostream& Item::display(std::ostream& ostr) const {
        // Check if the state is bad, then print only the state
        if (!itemStatus) {
            ostr << itemStatus;
        }
        else {
            // If the state is good, print the details based on the format
            if (isLinear) {
                ostr.width(5);
                ostr << sku << " | ";
                int i;
                for (i = 0; i < 35; i++) {

                    if (description[i] == '\0') {
                        break;
                    }
                    else {
                        cout << description[i];
                    }
                }
                while (i < 35) {
                    cout << " ";
                    i++;
                }

                ostr << " | ";
                ostr.setf(ios::right);
                ostr.width(4);
                ostr << quantityOnHand << " | ";
                ostr.unsetf(ios::right);
                ostr.setf(ios::right);
                ostr.width(4);
                ostr << quantityNeeded << " | ";
                ostr.unsetf(ios::right);
                ostr.setf(ios::right);
                ostr.width(7);
                ostr << fixed << setprecision(2) << price << " |";
            }
            else {
                ostr << "AMA Item:" << endl;
                ostr << sku << ": " << description << endl;
                ostr << "Quantity Needed: " << quantityNeeded << endl;
                ostr << "Quantity Available: " << quantityOnHand << endl;
                ostr << "Unit Price: $" << price << endl;
                ostr << "Needed Purchase Fund: $" << price * (quantityNeeded - quantityOnHand) << endl;
            }
        }
        return ostr;
    }

    // Read the rest of the Item information from the console
    std::istream& Item::read(std::istream& istr) {
     
        string tempDesc;
        cout << "AMA Item:" << endl;
        cout << "SKU: " << sku << endl;
        cout << "Description: ";
        istr >> tempDesc;
        quantityNeeded = ut.getint(1, 9999, "Quantity Needed: ");
        quantityOnHand = ut.getint(0, quantityNeeded, "Quantity On Hand: ");
        price = ut.getdouble(0.00, 9999.00, "Unit Price: $");
    
        if (!istr) {
            itemStatus = "Console entry failed!";
        }
        ut.alocpy(description, tempDesc.c_str());
        return istr;
    }

    // Read SKU number from the input stream
    int Item::readSku(std::istream& istr) {
        int Sku;
        Sku = ut.getint(40000, 99999, "SKU: ");
        sku = Sku;
        return Sku;
    }
}