/* Student Name     : Ali Riza Sevgili
   Student Number	: 135200228
   Student Email	: arsevgili@myseneca.ca
   Date			    : 09/16/2023 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Word.h"
#include "cStrTools.h"
using namespace sdds;
using namespace std;
int main() {
	char filename[256];
	programTitle();
	cout << "Enter filename: ";
	cin >> filename;
	wordStats(filename);
	return 0;
}
