/* Citation and Sources...
Final Project Milestone 2
Module: AidMan
Filename: AidMan.h
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

#include "Menu.h"
#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
namespace sdds {

	class AidMan {
		char* dataFile;
		Menu menuObj;
		unsigned int menu() const;
		AidMan(const AidMan& other);  // Declare copy constructor as private without implementation
		AidMan& operator=(const AidMan& other);  // Declare copy assignment operator as private without implementation

	public:
		AidMan(const char* filename);
		~AidMan();
		void run();
	};
};
#endif

