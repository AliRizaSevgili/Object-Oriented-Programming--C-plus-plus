/* Citation and Sources...
Final Project Milestone 2
Module: Status
Filename: StatusTester.cpp
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
#include <iostream>
#include "Status.h"
using namespace std;
const int c_min{ 0 };
const int c_max{ 100 };

class Container {
    int m_val{};
    sdds::Status m_state;
    Container& set(int value) {
        if (value < c_min) {
            m_state = "value too low";
            m_state = -1;
        }
        else if (value > c_max) {
            m_state = "value too high";
            m_state = 1;
        }
        else {
            m_state.clear();
        }
        return *this;
    }
public:
    Container(int value = 0) {
        set(value);
    }
    istream& read(istream& istr = cin) {
        istr >> m_val;
        m_state.clear();
        if (istr) {
            set(m_val);
        }
        else {
            m_state = "Invalid Integer";
            istr.clear();
        }
        istr.ignore(1000, '\n');
        return istr;
    }
    ostream& write(ostream& ostr = cout)const {
        if (m_state) {
            ostr << m_val;
        }
        else {
            ostr << m_state;
        }
        return ostr;
    }
    Container& value(int val) {
        set(val);
        return *this;
    }
    int value()const {
        return m_val;
    }
    operator bool()const {
        return m_state;
    }
    const sdds::Status& state()const {
        return m_state;
    }
};
ostream& operator<<(ostream& ostr, const Container& I) {
    return I.write(ostr);
}
istream& operator>>(istream& istr, Container& I) {
    return I.read(istr);
}

void prnContainer(Container C) {
    cout << "Container: (" << C << ")" << endl;
    if (!C) {
        cout << "Error #: " << int(C.state()) << endl;
        cout << "Problem: " << (const char*)(C.state()) << endl;
    }
}

int main() {
    Container c;
    cout << "Enter following values :\nabc\n123\n-123\n12" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "> ";
        cin >> c;
        prnContainer(c);
    }
    return 0;
}