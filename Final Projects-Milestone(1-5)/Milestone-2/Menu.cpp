/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <iostream>
#include "Utils.h"
#include <limits>
#include <string.h>


using namespace std;
namespace sdds {

	Menu::Menu(const char* content)
	{
		if (content != nullptr && ut.countOptions(content) <= 15) {
			this->menuContent = new char[strlen(content) + 1];
			strcpy(this->menuContent, content);
			validMenu = true;
		}
		else {
			this->menuContent = nullptr;
			validMenu = false;
		}
	}
	Menu::~Menu()
	{
		if (menuContent != nullptr) {
			delete[] menuContent;
			menuContent = nullptr;
		}
	}

	unsigned int Menu::run() const
	{
		int number;

		if (validMenu == false) {
			cout << "Invalid Menu!" << endl;
			number = 0;
			return number;
		}

		char* menuCopy = new char[strlen(menuContent) + 1];
		strcpy(menuCopy, menuContent);
		char* words = strtok(menuCopy, "\t");
		int i = 1;

		while (words != nullptr) {
			cout << i << "- " << words << endl;
			words = strtok(nullptr, "\t");
			i++;
		}
		cout << "---------------------------------" << endl;
		cout << "0- Exit" << endl;
		cout << "> ";


		bool valid = false;
		int options = ut.countOptions(menuContent);
		while (!valid) {
			if (cin >> number) {
				if (number >= 0 && number <= options) {
					valid = true;
				}
				else {
					cout << "Value out of range [0<=val<=" << options << "]: ";
				}
			}
			else {
				cout << "Invalid Integer, retry: ";
				cin.clear();  // Clear the error flags
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}

		delete[] menuCopy;
		menuCopy = nullptr;
		return number;
	}
}

