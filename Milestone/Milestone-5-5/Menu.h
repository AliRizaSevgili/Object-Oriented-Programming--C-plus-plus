/*
Final Project Milestone 5 
Module: Menu
Filename: Menu.h
Version 1.0
Author
-----------------------------------------------------------
Date	  Reason
2023/
-----------------------------------------------------------
Student Name		: Ali Riza Sevgili
Student Number		: 135200228
Student Email		: arsevgili@myseneca.ca
Date				: 12 / 2 / 2023
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef MENU_H
#define MENU_H

namespace sdds {
	const int maxOptions = 15;
	class Menu {
		char* menuContent;
	public:
		Menu(const char* options = nullptr);
		~Menu();
		int run() const;
	};
}

#endif
