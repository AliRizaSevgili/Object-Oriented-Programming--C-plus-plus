/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program

// Student Name     : Ali Riza Sevgili
   Student Number	: 135200228
   Student Email	: arsevgili@myseneca.ca
   Date			    : 10/14/2023
   > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// File  Flight.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"


using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title, "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title, title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    //### type conversion operators
    double Flight::minFuelRequired() const {
        return m_passengers * 600.0;  
    }

    Flight :: operator bool() const {
        return m_passengers > 0 && m_fuel >= minFuelRequired();
    }

    Flight::operator int() const {
        return m_passengers;
    }


    Flight::operator double() const {
        return m_fuel;
    }

    Flight::operator const char* () const {
        return m_title;
    }

    

    //### Unary member operator
     bool Flight::operator~() const {
        return m_passengers == 0;
    }

     Flight& Flight::operator=(const Flight& other) {
         if (this != &other) {
             Flight temp(other);  
             this->swap(temp);   
         }
         return *this;
     }


     void Flight::swap(Flight& other) {
         std::swap(m_passengers, other.m_passengers);
         std::swap(m_fuel, other.m_fuel);

         char tempTitle[16];
         strcpy(tempTitle, m_title);
         strcpy(m_title, other.m_title);
         strcpy(other.m_title, tempTitle);
     }

     Flight& Flight::operator=(int passengerCount) {
         if (passengerCount > 0 && passengerCount <= Boen747Capacity) {
             m_passengers = passengerCount;
         }
         return *this;
     }

     Flight& Flight::operator=(double fuelAmount) {
         if (fuelAmount > 0 && fuelAmount <= FuelTankCapacity) {
             m_fuel = fuelAmount;
         }
         return *this;
     }
     
     Flight& Flight::operator+=(double fuelAmount) {
         if (fuelAmount > 0) { 
             m_fuel += fuelAmount; 
             if (m_fuel > FuelTankCapacity) { 
                 m_fuel = FuelTankCapacity;
             }
         }
         return *this;
     }

     Flight& Flight::operator+=(int passengerCount) {
         if (passengerCount > 0) { 
             m_passengers += passengerCount; 
             if (m_passengers > Boen747Capacity) { 
                 m_passengers = Boen747Capacity;
             }
         }
         return *this;
     }
    
     Flight& Flight::operator-=(double fuelAmount) {
         if (fuelAmount > 0) {  
             m_fuel -= fuelAmount;  
             if (m_fuel < 0) {     
                 m_fuel = 0;
             }
         }
         return *this;  
     }

     Flight& Flight::operator-=(int passengerCount) {
         if (passengerCount > 0) {  
             m_passengers -= passengerCount;  
             if (m_passengers < 0) {  
                 m_passengers = 0;
             }
         }
         return *this;  
     }


     Flight& Flight::operator<<(Flight& rhs) {
         if (this != &rhs && this->m_passengers > 0 && rhs.m_passengers > 0) {
             int totalPassengers = this->m_passengers + rhs.m_passengers;

             if (totalPassengers > Boen747Capacity) {
                 this->m_passengers = Boen747Capacity;
                 rhs.m_passengers = totalPassengers - Boen747Capacity;
             }
             else {
                 this->m_passengers = totalPassengers;
                 rhs.m_passengers = 0;
             }
         }

         return *this;

     }

     Flight& Flight::operator>>(Flight& rhs) {

         if (this != &rhs && this->m_passengers > 0 && rhs.m_passengers > 0) {
             int totalPassengers = this->m_passengers + rhs.m_passengers;

             if (totalPassengers <= Boen747Capacity) {
                 rhs.m_passengers = totalPassengers;
                 this->m_passengers = 0;
             }
             else {
                 int passengersToMove = this->m_passengers - (Boen747Capacity - rhs.m_passengers);
                 if (passengersToMove > 0) {
                     rhs.m_passengers = Boen747Capacity;
                     this->m_passengers -= passengersToMove;
                 }
                 else {
                     rhs.m_passengers += this->m_passengers;
                     this->m_passengers = 0;
                 }
             }

             return *this;
         }

         return *this; 
     }


     /*
     Flight:: operator bool() const {
         return m_passengers > 0;
     }
     */
         int Flight::operator+(const Flight& other) const {
             if (!(*this) || !other) {
                 return 0;
             }

             return this->m_passengers + other.m_passengers;
         }


         int operator+=(int& left, const Flight& right) {
             left += static_cast<int>(right);  
             return left;
         }



     };