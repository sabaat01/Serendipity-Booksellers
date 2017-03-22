#ifndef INVENTORYMODULE_H
#define INVENTORYMODULE_H
#include "Module.h"
#include "Book.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;
class InventoryModule : public Module
{
private:
	const int arrsize = 100;
	Book inventory[100];
	int numBooks;
public:
	InventoryModule();
	~InventoryModule();
	void driver();
	int displayInvenu();
	void FileToArray();
	void ArrayToFile();
	/*
	void sortByAge() {
	int startScan, minIndex;
	string minValue;
	for (startScan = 0; startScan < (numBooks - 1); startScan++) {
	minIndex = startScan;
	minValue = inventory[startScan].getDate;
	for (int index = startScan + 1; index < numBooks; index++) {
	if (inventory[index].getDate < minValue) {    //////////////////////////	OVERLOADED CONSTRUCTOR OF "<" FOR DATE DATA TYPE!!!
	minValue = inventory[index].getDate;
	minIndex = index;
	}
	}
	inventory[minIndex].setDate(inventory[startScan].getDate);
	inventory[startScan].setDate(minValue);
	}
	}
	*/
	void sortBytitle();
	void sortByquantity();
	void sortByRetailPrice();
	void sortByWholesalePrice();
	void sortByAuthor();
	void sortByISBN();
	int searchByTitle(string title);
	int searchByISBN(string isbn);
	
	void addBook();
	void deleteBook();
	void editBook();
	void displayABook(int index);
	void displayBooks();
};
#endif

/*
void sortBook(char type); //-> Still working on it!!

void selectionSort() {
//selection sort code
}

void sortByTitle() {
setSearchParam('s');
selectionSort();
}

void sortByISN() {
setSearchParam('f');
selectionSort();
}
bool operator >(const Book &obj) {
if (searchParam = 's') return this->getAuthor() > obj.getAuthor();
else if (searchParam == 'f') return this->getISBN() > obj.getISBN();
//...
}
*/
