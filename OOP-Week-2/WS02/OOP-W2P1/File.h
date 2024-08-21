/***********************************************************************
// OOP244 Workshop #2 lab (part 1)

// Student Name     : Ali Riza Sevgili
   Student Number	: 135200228
   Student Email	: arsevgili@myseneca.ca
   Date			    : 09/23/2023 
   > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// File  File.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	// TODO: Declare overloaded read function prototypes
	bool read(char* empName);


	bool read(int& empNumber);


	bool read(double& empSalary);

}

#endif // !SDDS_FILE_H_