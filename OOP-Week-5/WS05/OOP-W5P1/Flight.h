/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program

// Student Name     : Ali Riza Sevgili
   Student Number	: 135200228
   Student Email	: arsevgili@myseneca.ca
   Date			    : 10/14/2023
   > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

   // File  Flight.h
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/

#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

    const int Boen747Capacity = 388;
    const int FuelTankCapacity = 238840;

    class Flight {

        mutable int m_passengers = 0;
        mutable double m_fuel = 0;
        mutable char m_title[16];
        void emptyPlane();

    public:
        Flight();
        Flight(int passengers, double fuel, const char* title);
        std::ostream& display()const;
        //operator bool() const;
        operator int() const;
        operator double() const;
        operator const char* ()const;
        double minFuelRequired() const;
        operator bool() const;
        bool operator~() const;
        Flight& operator=(const Flight& other);
        void swap(Flight& other);
        Flight& operator=(int passengerCount);
        Flight& operator=(double fuelAmount);
        Flight& operator+=(double fuelAmount);
        Flight& operator+=(int passengerCount);
        Flight& operator-=(double fuelAmount);
        Flight& operator-=(int passengerCount);
        Flight& operator<<(Flight& rhs);
        Flight& operator>>(Flight& rhs);
        int operator+(const Flight& other) const;
        
    };

    int operator+=(int& left, const Flight& right);
}
#endif // SDDS_FLIGHT_H

