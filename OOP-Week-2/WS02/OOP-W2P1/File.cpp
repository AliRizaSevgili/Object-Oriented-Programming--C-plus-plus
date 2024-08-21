/***********************************************************************
 Student Name     : Ali Riza Sevgili
   Student Number	: 135200228
   Student Email	: arsevgili@myseneca.ca
   Date			    : 09/23/2023
   > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// OOP244 Workshop #2 lab (part 1)
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }
    bool read(char* empName)
    {
        return fscanf(fptr, "%[^\n]\n", empName) == 1;
    }
    bool read(int& empNumber)
    {
        return fscanf(fptr, "%d,", &empNumber) == 1;
    }
    bool read(double& empSalary)
    {
        return fscanf(fptr, "%lf,", &empSalary) == 1;
    }
}