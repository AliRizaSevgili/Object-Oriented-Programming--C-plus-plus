/***********************************************************************
// OOP244 Workshop #2 lab (part 1)

// Student Name     : Ali Riza Sevgili
   Student Number	: 135200228
   Student Email	: arsevgili@myseneca.ca
   Date			    : 09/23/2023 
   > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// File  Employee.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#include <iostream>
#include "Employee.h"
#include "File.h"
#include <cstring>
using namespace std;
namespace sdds {

    int noOfEmployees;
    Employee* employees;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
    bool load(Employee& emp)
    {
        bool ok = false;
        char name[128];


        if (read(emp.m_empNo) && read(emp.m_salary) && read(name))
        {
            emp.m_name = new char[strlen(name) + 1];
            strcpy(emp.m_name, name);
            ok = true;
        }
        return ok;
    }
    // TODO: Finish the implementation of the 0 arg load function 
    bool load() {
        bool ok = false;
        int i = 0;
        if (openFile(DATAFILE))
        {
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];

            for (int j = 0; j < noOfEmployees; j++)
            {

                i += load(employees[j]);
            }

            if (i != noOfEmployees)
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
            else
            {
                ok = true;
            }

            closeFile();
        }
        else
        {
            cout << "Could not open data file: " << DATAFILE << endl;
        }

        return ok;
    }

    // TODO: Implementation for the display functions go here
    void display(const Employee& emp)
    {
        cout << emp.m_empNo << ": " << emp.m_name << ", $" << emp.m_salary << endl;
    }
    void display()
    {
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;

        sort();

        for (int i = 0; i < noOfEmployees; i++)
        {
            cout << i + 1 << "- ";
            display(employees[i]);
        }
    }

    // TODO: Implementation for the deallocateMemory function goes here
    void deallocateMemory()
    {
        for (int i = 0; i < noOfEmployees; i++)
        {
            delete[] employees[i].m_name;
        }

        delete[] employees;
    }



}