#define _CRT_SECURE_NO_WARNINGS

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
	InventoryModule() : Module()
	{
		numBooks = 0;
		FileToArray();
		sortBytitle();

	}
	~InventoryModule()
	{
		ArrayToFile();
	}
	void driver()
	{
		int choice1, choice2, index;
		string searchValue;
		char findAnother;
		do{
			choice1 = displayInvenu();
			if (choice1 == 1){
				do{
					cout << "Do you want to look up the book by 1)Title or 2)ISBN? \nEnter your choice: ";
					cin >> choice2;
					if (choice2 == 1){
						cout << "Please enter the book title: ";
						getline(cin, searchValue);
						index = searchByTitle(searchValue);
						displayABook(index);
					}
					else if (choice2 == 2){
						cout << "Please enter the book ISBN: ";
						cin >> searchValue;
						sortByISBN();
						index = searchByISBN(searchValue); //<- enter isbn and search by author? WRONG!
						displayABook(index);
					}
					else {
						cout << "Invalid entry. Please try again.\n";
					}

					cout << "\n\nDo you wish to look up another book? y/n: ";
					cin >> findAnother;
				} while ((choice2 != 1 && choice2 != 2) || findAnother == 'y');
			}
			if (choice1 == 2)
				editBook();
			if (choice1 == 3)
				addBook();
			if (choice1 == 4)
				deleteBook();
		} while (choice1 != 5);
		cout << "\n\nLeaving Inventory Menu and returning to Main Menu...";
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
		//need to skip the first line before readings(headings)
		do
		{
			cout << "Please enter the path to the input text file: ";
			cin >> inputFileName;
			bookList.open(inputFileName);
			if (bookList)
			{
				cout << "File opened successfully!\n";
				string title, author, publisher, ISBN;
				int quantity;
				double wholesale, retail;
				string date;
				for (int i = 0; i < arrsize && getline(bookList, title, '\t'); i++)
				{
					cout << "We are reading eight values from the file!!\n"; //these read from file functions are creating issues!
					getline(bookList, author, '\t');							//They are accounting for '\t', but NOT '\n' 
																			//<- establish that '\n' marks the end of a book and by that point
																				//the next iteration should start to occur!
					getline(bookList, ISBN, '\t');
					bookList >> wholesale;
					bookList >> retail;
					getline(bookList, date, '\t');
					bookList >> quantity;

					inventory[i].setTitle(title);
					inventory[i].setAuthor(author);
					inventory[i].setISBN(ISBN);
					inventory[i].setWholesale(wholesale);
					inventory[i].setDate(date);
					inventory[i].setQuantity(quantity);
					numBooks++;
				} //OR: Until you hit '\t', read in a value(including spaces). Every eight set values will be one Book.
				//Then the next eight are the next book.
				cout << "We have completed file read! Here is what is in the array: \n";
				displayBooks();
			}
			else
				cout << "\n\nFile Open Error! Please ensure the file is accessible, then try again.\n";
		} while (!bookList); //BY the time the if statement is complete, !bookList has turned to true. So, this repeats over and over again!
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
			string title, author, publisher, ISBN;
			int quantity;
			double wholesale, retail;

			title = inventory[i].getTitle();
			author = inventory[i].getAuthor();
			ISBN = inventory[i].getISBN();
			quantity = inventory[i].getQuantity();
			wholesale = inventory[i].getWholesale();
			retail = inventory[i].getRetail();

			UpdatedBookList << title << "\t";
			UpdatedBookList << author << "\t";
			UpdatedBookList << ISBN << "\t";
			UpdatedBookList << wholesale << "\t";
			UpdatedBookList << retail << "\t";
			UpdatedBookList << quantity << "\t";


			//date = inventory[i].getDate << "\t\n"; //couts date(dd/mm/yyyy)
		}
	}
	void sortBook(char type){} //-> Still working on it!!
	void sortBytitle() {
		int startScan, minIndex;
		string minValue;
		for (startScan = 0; startScan < (numBooks - 1); startScan++) {
			minIndex = startScan;
			minValue = inventory[startScan].getTitle();
		}
		for (int index = startScan + 1; index < numBooks; index++) {
			if (inventory[index].getTitle() < minValue) {
				minValue = inventory[index].getTitle();
				minIndex = index;
			}
		}
		inventory[minIndex].setTitle(inventory[startScan].getTitle());
		inventory[startScan].setTitle(minValue);
	}
	void sortByquantity() {
		int startScan, minIndex;
		int minValue;
		for (startScan = 0; startScan < (numBooks - 1); startScan++) {
			minIndex = startScan;
			minValue = inventory[startScan].getQuantity();
			for (int index = startScan + 1; index < numBooks; index++) {
				if (inventory[index].getQuantity() < minValue) {
					minValue = inventory[index].getQuantity();
					minIndex = index;
				}
			}
			inventory[minIndex].setQuantity(inventory[startScan].getQuantity());
			inventory[startScan].setQuantity(minValue);
		}
	}
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
	void sortByRetailPrice() {
		int startScan, minIndex;
		double minValue;
		for (startScan = 0; startScan < (numBooks - 1); startScan++) {
			minIndex = startScan;
			minValue = inventory[startScan].getRetail();
			for (int index = startScan + 1; index < numBooks; index++) {
				if (inventory[index].getRetail() < minValue) {
					minValue = inventory[index].getRetail();
					minIndex = index;
				}
			}
			inventory[minIndex].setRetail(inventory[startScan].getRetail());
			inventory[startScan].setRetail(minValue);
		}
	}
	void sortByWholesalePrice() {
		int startScan, minIndex;
		double minValue;
		for (startScan = 0; startScan < (numBooks - 1); startScan++) {
			minIndex = startScan;
			minValue = inventory[startScan].getWholesale();
			for (int index = startScan + 1; index < numBooks; index++) {
				if (inventory[index].getWholesale() < minValue) {
					minValue = inventory[index].getWholesale();
					minIndex = index;
				}
			}
			inventory[minIndex].setWholesale(inventory[startScan].getWholesale());
			inventory[startScan].setWholesale(minValue);
		}
	}
	void sortByAuthor() {
		int startScan, minIndex;
		string minValue;
		for (startScan = 0; startScan < (numBooks-1); startScan++) {
			minIndex = startScan;
			minValue = inventory[startScan].getAuthor();
			for (int index = startScan + 1; index < numBooks; index++) {
				if (inventory[index].getAuthor() < minValue) {
					minValue = inventory[index].getAuthor();
					minIndex = index;
				}
			}
			inventory[minIndex].setAuthor(inventory[startScan].getAuthor());
			inventory[startScan].setAuthor(minValue);
		}
	}
	void sortByISBN() {
		int startScan, minIndex;
		string minValue;
		for (startScan = 0; startScan < (numBooks-1); startScan++) {
			minIndex = startScan;
			minValue = inventory[startScan].getISBN();
			for (int index = startScan + 1; index < numBooks; index++) {
				if (inventory[index].getISBN() < minValue) {
					minValue = inventory[index].getISBN();
					minIndex = index;
				}
			}
			inventory[minIndex].setISBN(inventory[startScan].getISBN());
			inventory[startScan].setISBN(minValue);
		}
	}
	int searchByTitle(string title)
	{
		int first = 0, last = numBooks - 1, middle, position = -1;
		bool found = false;
		while (!found && first <= last)
		{
			middle = (first + last) / 2;
			if (inventory[middle].getTitle() == title)
			{
				found = true;
				position = middle;
			}
			else if (inventory[middle].getTitle() > title)
				last = middle - 1;
			else first = middle + 1;
		}
		return position;
	}

	int searchByISBN(string isbn)
	{
		int first = 0, last = numBooks - 1, middle, position = -1;
		bool found = false;
		while (!found && first <= last)
		{
			middle = (first + last) / 2;
			if (inventory[middle].getISBN() == isbn)
			{
				found = true;
				position = middle;
			}
			else if (inventory[middle].getISBN() > isbn)
				last = middle - 1;
			else first = middle + 1;
		}
		return position;
	}
	/*
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
	void addBook()
	{
		cout << "You have entered the Add Book function. However, there is nothing here yet. Redirecting...\n";
	}
	void deleteBook()
	{
		cout << "You have entered the Delete Book function. However, there is nothing here yet. Redirecting...\n";
	}
	void editBook()
	{
		cout << "You have entered the Edit Book function. However, there is nothing here yet. Redirecting...\n";
	}
	void displayABook(int index)
	{
		cout << "Entering Display A Book function....\n";
		cout << "\nTitle: " << inventory[index].getTitle()
			<< "\nAuthor: " << inventory[index].getTitle()
			<< "\nISBN: " << inventory[index].getISBN()
			<< "\nWholesale Cost: " << inventory[index].getWholesale()
			<< "\nRetail Cost: " << inventory[index].getRetail()
			<< "\nDate Added to Inventory: ";
		inventory[index].getDate();
		cout << "\nQuantity: " << inventory[index].getQuantity();

	}
	void displayBooks()
	{
		cout << "\n\nEntering Display Book function....\n";
		for (int i = 0; i < numBooks; i++)
		{
			cout << "\nTitle: " << inventory[i].getTitle()
				<< "\nAuthor: " << inventory[i].getAuthor()
				<< "\nISBN: " << inventory[i].getISBN()
				<< "\nWholesale Cost: " << inventory[i].getWholesale()
				<< "\nRetail Cost: " << inventory[i].getRetail()
				<< "\nDate Added to Inventory: ";
			inventory[i].getDate();
			cout << "\nQuantity: " << inventory[i].getQuantity();
			cout << "\n\n\n\n";
		}
	}

};
#endif
