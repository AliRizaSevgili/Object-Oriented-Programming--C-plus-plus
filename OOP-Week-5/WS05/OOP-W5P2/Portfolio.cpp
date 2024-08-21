/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "Portfolio.h"
#include <iostream>
#include <ostream>
#include <cstring>

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
        emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const {
        cout << " ";
        cout.width(10);
        cout << (const char*)(*this);
        cout << " | ";
        cout << "Value: ";
        cout.width(10);
        cout << double(*this);
        cout << " | ";
        cout << " Type: ";
        cout << char(*this);
    }

    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    Portfolio::operator double() const //overloaded operator that returns the value of the portfolio
    {
        return this->m_value;
    }


    Portfolio::operator const char* () const //overloaded operator that returns the name of the stock of a given portfolio
    {
        return this->m_stock;
    }


    Portfolio::operator char() const //overloaded operator that returns the type of the stock
    {
        return this->m_type;
    }


    Portfolio::operator bool() const //overloaded operator that will return true only if the portfolio.m_type is equal to G, V or I. thus returning a valid portfolio
    {
        return (this->m_type == 'G' || this->m_type == 'V' || this->m_type == 'I');
    }


    Portfolio& Portfolio::operator+=(double value) // overloaded operator that will increase the value of the portfolio by the double amount parameter.
    {
        if (*this && value > 0) { //call operator bool() function and checks if value is not negative and portfolio is valid
            this->m_value += value;
            return *this; //returns a reference to the same object. updated
        }
        return *this;//returns a reference to the same object

    }


    Portfolio& Portfolio::operator-=(double value) //overloaded operator that will decrease the value of the portfolio based on the double parameter
    {
        if (*this && value > 0) { //call operator bool() function and checks if *this is a valid portfolio and if value is not negative
            this->m_value -= value; //decreases the portfolio value by the double value
            return *this; //returns a reference to this object. updated
        }
        return *this;//returns a reference to the same object
    }


    bool Portfolio::operator~() const //overloaded operator that checks if the m_value is negative. returns true if negative
    {
        return (this->m_value < 0);
    }


    Portfolio& Portfolio::operator<<(Portfolio& portfolio)// overloaded << operator that will transfer value from the right portfolio to the left portfolio.
    {
        if (this != &portfolio) { //checks if its not self assigning
            if (*this && portfolio) { //call operator bool() function and checks if both portfolios are valid
                this->m_value += portfolio.m_value; //adds the value of the right portfolio to the left one.
                portfolio.emptyPortfolio(); //sets the right portfolio to a safe empty state
                return *this; //returns an updated reference to this portfolio with the operation complete.
            }
        }
        return *this; // if doesnt meet the conditions returns the same object unchanged.
    }


    Portfolio& Portfolio::operator>>(Portfolio& portfolio) // overloaded << operator that will transfer value from the left portfolio to the right portfolio.
    {
        if (this != &portfolio) { //checks if its not self assigning
            if (*this && portfolio) { //call operator bool() function and checks if both portfolios are valid
                portfolio.m_value += this->m_value; //adds the value of the left portfolio to the right one.
                this->emptyPortfolio(); //sets the left portfolio to a safe empty state
                return *this; //returns an updated reference to this portfolio with the operation complete.
            }
        }
        return *this; // if doesnt meet the conditions returns the same object unchanged.
    }
    

    double operator+(const Portfolio& left, const Portfolio& right) // friend function that takes 2 portfolios as parameters and then adds the values of the m.value variable from each one.
    {
        if (left && right) { //call operator bool() function and checks if both portfolios are valid
            return left.m_value + right.m_value; //returns the sum of both values
        }
        return 0.0;// return 0.0 if any of the portfolios are invalid
    }


    double operator+=(double& total, const Portfolio& portfolio) // friend special operator function that allows to update the global variable by a reference as parameter
        // and takes a portfolio as a parameter from which it will take the m_value to be added.
    {
        return total += portfolio.m_value; // updates the global variable by perfoming an addition of the parameters.
    }

}