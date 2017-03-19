#define _CRT_SECURE_NO_WARNINGS

#ifndef Inventory_H
#define Inventory_H
#include "Book.h"
#include <fstream>
#include <iostream>

using namespace std;
class Inventory
{
private:
	int arrsize = 100;
	Book inventory[arrsize];
	int numBooks;
public:
	InventoryModule()
	{
		numBooks = 0;
		FileToArray();
		
	}
	~InventoryModule()
	{
		ArrayToFile();
	}
	void inventoryDriver()
	{
		int choice1, choice2, searchValue, index;
		char findAnother;
		do{
			choice1 = displayInvenu();
			if(choice1 == 1){
				do{
				cout << "Do you want to look up the book by 1)Title or 2)ISBN? \nEnter your choice: ";
				cin >> choice2;
				if (choice2 == 1){
					cout << "Please enter the book title: ";
					cin >> searchValue;
					index = searchByTitle(searchValue);
					displayABook(index);
				}
				else if (choice2 == 2){
					cout << "Please enter the book ISBN: ";
					cin >> searchValue;
					index = searchByAuthor(searchValue); //<- enter isbn and search by author? WRONG!
					displayABook(index);
				}
				else {
					cout << "Invalid entry. Please try again.\n"; }
					
				cout << "\n\nDo you wish to look up another book? y/n: ";
				cin >> findAnother;
				} while((choice2 != 1 && choice2 != 2) || findAnother == 'y');
			}
			if (choice == 2)
				editBook();
			if (choice == 3)
				addBook();
			if (choice == 4)
				deleteBook();		
		}while(choice != 5);
		cout << "\n\nLeaving Inventory Menu and returning to Main Menu..."
	}
	int displayInvenu(){
		int entry;
		cout << "\n\n\n\nInventory Database Menu:\n";
		cout << "1) Look up a book\n";
		cout << "2) Edit a book\n";
		cout << "3) Add a book\n";
		cout << "4) Delete a book\n";
		cout << "5) Return to Main Menu\n";
		cout << "Enter your choice: ";
		cin >> entry;
		return entry;
	}
	void FileToArray()
	{
		fstream bookList;
		string inputFileName;
		cout << "Please enter the path to the input text file: ";
		cin >> inputFileName;
		bookList.open(inputFileName);
		//need to skip the first line before readings(headings)
		for (int i = 0; i < arrsize; i++)
		{
			getline(Booklist, inventory[i].setTitle, '\t') ; //test prototype- check by the book
			bookList >> inventory[i].setAuthor;
			bookList >> inventory[i].setPublisher;
			bookList >> inventory[i].setISBN;
			bookList >> inventory[i].setQuantity;
			bookList >> inventory[i].setWholesale;
			bookList >> inventory[i].setRetail;
			bookList >> inventory[i].setDate;
			numBooks++
		} //OR: Until you hit '\t', read in a value(including spaces). Every eight set values will be one Book.
			//Then the next eight are the next book.
	}
	void ArrayToFile()
	{
		fstream UpdatedBookList;
		cout << "What file would you like to save your book list into?";
		string fileName;
		cin >> fileName;
		UpdatedBookList.open(fileName);
		for (int i = 0; i < 100; i++)
		{
			UpdatedBookList << inventory[i].getTitle << "\t";
			UpdatedBookList << inventory[i].getAuthor << "\t";
			UpdatedBookList << inventory[i].getPublisher << "\t";
			UpdatedBookList << inventory[i].getISBN << "\t";
			UpdatedBookList << inventory[i].getQuantity << "\t";
			UpdatedBookList << inventory[i].getWholesale << "\t";
			UpdatedBookList << inventory[i].getRetail << "\t";
			UpdatedBookList << inventory[i].getDate << "\t\n"; //couts date(dd/mm/yyyy)
		}
	}
	void sortBook(char type){} //-> Still working on it!!
	void sortBytitle () {
		int startScan, minIndex;
		string minValue;
		for (startScan = 0; startScan < (size − 1); startScan++) {
			minIndex = startScan;
			minValue = book[startScan].getTitle;
		}
		for(int index = startScan + 1; index < size; index++) {
			if (book[index].getTitle < minValue) {
				minValue = array[index].getTitle;
				minIndex = index; }
		}
		Book[minIndex].getTitle = array[startScan].getTitle;
		array[startScan].getTitle = minValue;
	}
void sortByquantity () {
    int startScan, minIndex;
    int minValue;
    for (startScan = 0; startScan < (size − 1); startScan++) {
        minIndex = startScan;
        minValue = book[startScan].getQuantity;
        for(int index = startScan + 1; index < size; index++) {
            if (book[index].getQuantity < minValue) {
                minValue = array[index].getQuantity;
                minIndex = index; }
        }
        Book[minIndex].getQuantity = array[startScan].getQuantity;
        array[startScan].getQuantity = minValue;
    } 
}
void sortByAge () {
    int startScan, minIndex;
    Date minValue;
    for (startScan = 0; startScan < (size − 1); startScan++) {
        minIndex = startScan;
        minValue = book[startScan].getDate;
        for(int index = startScan + 1; index < size; index++) {
            if (book[index].getDate < minValue) {    //////////////////////////	OVERLOADED CONSTRUCTOR OF "<" FOR DATE DATA TYPE!!!
                minValue = array[index].getDate;
                minIndex = index; }
        }
        Book[minIndex].getDate = array[startScan].getDate;
        array[startScan].getDate = minValue;
    }
}
void sortByRetailPrice () {
    int startScan, minIndex;
    double minValue;
    for (startScan = 0; startScan < (size − 1); startScan++) {
        minIndex = startScan;
        minValue = book[startScan].getRetailprice;
        for(int index = startScan + 1; index < size; index++) {
            if (book[index].getRetailprice < minValue) {
                minValue = array[index].getRetailprice;
                minIndex = index; }
        }
        Book[minIndex].getRetailprice = array[startScan].getRetailprice;
        array[startScan].getRetailprice = minValue;
    } 
}
void sortByWholesalePrice () {
    int startScan, minIndex;
    double minValue;
    for (startScan = 0; startScan < (size − 1); startScan++) {
        minIndex = startScan;
        minValue = book[startScan].getWholesaleprice;
        for(int index = startScan + 1; index < size; index++) {
            if (book[index].getWholesaleprice < minValue) {
                minValue = array[index].getWholesaleprice;
                minIndex = index; }
        }
        Book[minIndex].getWholesaleprice = array[startScan].getWholesaleprice;
        array[startScan].getWholesaleprice = minValue;
    } 
}
void sortByAuthor () {
    int startScan, minIndex;
    string minValue;
    for (startScan = 0; startScan < (size − 1); startScan++) {
        minIndex = startScan;
        minValue = book[startScan].getAuthor;
        for(int index = startScan + 1; index < size; index++) {
            if (book[index].getAuthor < minValue) {
                minValue = array[index].getAuthor;
                minIndex = index; }
        }
        Book[minIndex].getAuthor = array[startScan].getAuthor;
        array[startScan].getAuthor = minValue;
    } 
}
void sortByISBN () {
    int startScan, minIndex;
    unsigned long long int minValue;
    for (startScan = 0; startScan < (size − 1); startScan++) {
        minIndex = startScan;
        minValue = book[startScan].getISBN;
        for(int index = startScan + 1; index < size; index++) {
            if (book[index].getISBN < minValue) {
                minValue = array[index].getISBN;
                minIndex = index; }
        }
        Book[minIndex].getISBN = array[startScan].getISBN;
        array[startScan].getISBN = minValue;
    } 
}
	int searchByTitle(string title)
	{
	int first = 0, last = numBooks - 1, middle, position = -1;
	bool found = false;
	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (inventory[middle].title == title)
		{
			found = true;
			position = middle;
		}
		else if (inventory[middle].title > value)
			last = middle - 1;
		else first = middle + 1;
	}
	return position;
	}
	
	int searchByISBN(unsigned long long int isbn)
	{
	int first = 0, last = numBooks - 1, middle, position = -1;
	bool found = false;
	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (inventory[middle].ISBN == isbn)
		{
			found = true;
			position = middle;
		}
		else if (inventory[middle].ISBN > isbn)
			last = middle - 1;
		else first = middle + 1;
	}
	return position;
	}
	
	 void Addbook();
	 void Deletebook();
	 void EditBook();

};
#endif
