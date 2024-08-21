/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.h
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#include <ostream>
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_


namespace sdds {

    class Portfolio {
        double m_value = 0;
        char m_stock[16];
        char m_type;

    public:
        
        Portfolio();
        void emptyPortfolio();
        std::ostream& display() const;
        Portfolio(double value, const char* stock, char type);
        void dispPortfolio() const;
        operator double() const;
        operator const char* () const;
        operator char() const;
        operator bool() const;

        Portfolio& operator+=(double value);
        Portfolio& operator-=(double value);

        bool operator~() const;
        
        Portfolio& operator<<(Portfolio& portfolio);
        Portfolio& operator>>(Portfolio& portfolio);

        friend double operator+(const Portfolio& left, const Portfolio& right);
        friend double operator+=(double& total, const Portfolio& portfolio);

    };
}
#endif // SDDS_Portfolio_H_
