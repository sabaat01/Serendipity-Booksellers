#define _CRT_SECURE_NO_WARNINGS
#include "InventoryModule.h"


InventoryModule::InventoryModule() : Module()
	{
		numBooks = 0;
		FileToArray();
		sortBytitle();

	}
InventoryModule::~InventoryModule()
	{
		ArrayToFile();
	}
void InventoryModule::driver()
	{
		int choice1, choice2, index;
		string searchValue;
		char findAnother;
		do{
			choice1 = displayInvenu();
			if (choice1 == 1){
				do{
					cout << "Do you want to look up the book by 1)Title or 2)ISBN? Enter your choice: ";
					cin >> choice2;
					cin.get();
					if (choice2 == 1){
						do{
							cout << "Please enter the book title: ";
							getline(cin, searchValue);
							index = searchByTitle(searchValue);
							if (index != -1)
								displayABook(index);
							else
								cout << "Book not found. Please search again.\n";
						} while (index == -1);
					}
					else if (choice2 == 2){
						do{
							cout << "Please enter the book ISBN: ";
							cin >> searchValue;
							sortByISBN();
							index = searchByISBN(searchValue); //<- enter isbn and search by author? WRONG!
							if (index != -1)
								displayABook(index);
							else
								cout << "Book not found. Please search again.\n";
						} while (index == -1);
					}
					else {
						cout << "Invalid entry. Please try again. Press enter.\n";
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
int InventoryModule::displayInvenu(){
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
void InventoryModule::FileToArray()
	{
		fstream bookList;
		string inputFileName;
		//need to skip the first line before readings(headings)
		int number = 0;
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
				double wholesale = 0.0, retail = 12.3456;
				Date date;
				for (int i = 0; i < arrsize && getline(bookList, title, '\t'); i++)
				{
					cout << "\nWe are reading eight values from the file!!\n"; //these read from file functions are creating issues!
					getline(bookList, author, '\t');
					getline(bookList, ISBN, '\t');
					bookList >> wholesale;
					bookList >> retail;
					bookList.ignore();
					bookList >> date;
					bookList >> quantity;
					bookList.ignore();

					inventory[i].setTitle(title);
					inventory[i].setAuthor(author);
					inventory[i].setISBN(ISBN);
					inventory[i].setWholesale(wholesale);
					inventory[i].setRetail(retail);
					inventory[i].setDate(date);
					inventory[i].setQuantity(quantity);
					numBooks++;
				} //OR: Until you hit '\t', read in a value(including spaces). Every eight set values will be one Book.
				//Then the next eight are the next book.
				cout << "\nWe have completed file read! Here is what is in the array: \n";
				displayBooks();
				number = 1;
				sortBytitle();
				displayBooks();
			}
			else
				cout << "\n\nFile Open Error! Please ensure the file is accessible, then try again.\n";
		} while (!number); //BY the time the if statement is complete, !bookList has turned to true. So, this repeats over and over again!
	}
void InventoryModule::ArrayToFile()
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
//void InventoryModule::sortBook(char type){} //-> Still working on it!!
void InventoryModule::sortBytitle() {
		int startScan, minIndex;
		Book minBook;
		for (startScan = 0; startScan < (numBooks - 1); startScan++)
		{
			minIndex = startScan;
			minBook = inventory[startScan];
			for (int index = startScan + 1; index < numBooks; index++)
			{
				if (inventory[index].getTitle() < minBook.getTitle())
				{
					minBook = inventory[index];
					minIndex = index;
				}
			}
			inventory[minIndex] = (inventory[startScan]);
			inventory[startScan] = (minBook);
		}
	}
void InventoryModule::sortByquantity() {
		int startScan, minIndex;
		Book minBook;
		for (startScan = 0; startScan < (numBooks - 1); startScan++)
		{
			minIndex = startScan;
			minBook = inventory[startScan];
			for (int index = startScan + 1; index < numBooks; index++)
			{
				if (inventory[index].getQuantity() < minBook.getQuantity())
				{
					minBook = inventory[index];
					minIndex = index;
				}
			}
			inventory[minIndex] = (inventory[startScan]);
			inventory[startScan] = minBook;
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
void InventoryModule::sortByRetailPrice() {
		int startScan, minIndex;
		Book minBook;
		for (startScan = 0; startScan < (numBooks - 1); startScan++)
		{
			minIndex = startScan;
			minBook = inventory[startScan];
			for (int index = startScan + 1; index < numBooks; index++)
			{
				if (inventory[index].getRetail() < minBook.getRetail())
				{
					minBook = inventory[index];
					minIndex = index;
				}
			}
			inventory[minIndex] = (inventory[startScan]);
			inventory[startScan] = (minBook);
		}
	}
void InventoryModule::sortByWholesalePrice() {
		int startScan, minIndex;
		Book minBook;
		for (startScan = 0; startScan < (numBooks - 1); startScan++)
		{
			minIndex = startScan;
			minBook = inventory[startScan];
			for (int index = startScan + 1; index < numBooks; index++)
			{
				if (inventory[index].getWholesale() < minBook.getWholesale())
				{
					minBook = inventory[index];
					minIndex = index;
				}
			}
			inventory[minIndex] = (inventory[startScan]);
			inventory[startScan] = (minBook);
		}
	}
void InventoryModule::sortByAuthor() {
		int startScan, minIndex;
		Book minBook;
		for (startScan = 0; startScan < (numBooks - 1); startScan++)
		{
			minIndex = startScan;
			minBook = inventory[startScan];
			for (int index = startScan + 1; index < numBooks; index++)
			{
				if (inventory[index].getAuthor() < minBook.getAuthor())
				{
					minBook = inventory[index];
					minIndex = index;
				}
			}
			inventory[minIndex] = (inventory[startScan]);
			inventory[startScan] = (minBook);
		}
	}
void InventoryModule::sortByISBN() {
		int startScan, minIndex;
		Book minBook;
		for (startScan = 0; startScan < (numBooks - 1); startScan++)
		{
			minIndex = startScan;
			minBook = inventory[startScan];
			for (int index = startScan + 1; index < numBooks; index++)
			{
				if (inventory[index].getISBN() < minBook.getISBN())
				{
					minBook = inventory[index];
					minIndex = index;
				}
			}
			inventory[minIndex] = (inventory[startScan]);
			inventory[startScan] = (minBook);
		}
	}
int InventoryModule::searchByTitle(string title)
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

int InventoryModule::searchByISBN(string isbn)
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
void InventoryModule::addBook()
	{

		string Title;
		string Author;
		string Publisher;
		double RetailPrice;
		double wholeSalePrice;
		cout << "Please enter the details of the Book you want to add\n";
		cout << "Enter Title\n";
		cin >> Title;
		int result = binarySearchbyName(bookObject, size, Title);
		if (result != -1)
		{
			bookObject[result].incrementQuantity();
		}
		else
		{
			size = size + 1;
			bookObject[size].setTitle(Title);
			
			cout << "Enter Author";
			cin >> Author;
			cout << "\n";
			bookObject[size].setAuthor(Author);
			cout << "Enter Publisher";
			cin >> Publisher;
			cout << "\n";
			bookObject[size].setPublisher(Publisher);
			cout << "Retail price";
			cin >> RetailPrice;
			cout << "\n";
			bookObject[size].setRetailPrice(RetailPrice);
			cout << "whole sale price";
			cin >> wholeSalePrice;
			cout << "\n";
			bookObject[size].setWholesale(wholeSalePrice);
			bookObject[size].setQuantity(1);
		}

	}
	
void InventoryModule::deleteBook()
	{
		
		string BookTitle;
		cout << "what book do you want Delete";
		cin >> BookTitle;
		int result = binarySearchbyName(bookObject, size, BookTitle);
		if (result != -1)
		{
			for (int i = result; i < size - 1; i++)
			{
				bookObject[i] = bookObject[i + 1];   //Moves the entire list up by one.
			}
			size = size - 1;
		}
		else
		{
			cout << "Book not found\n";
		}
	}
	
void InventoryModule::editBook()
	{
		string BookTitle;
		cout << "what book do you want edit: Enter Title ";
		cin >> BookTitle;
		int result = binarySearchbyName(bookObject, size, BookTitle);
		if (result != -1)
		{
			string res="";
			int entry;
			//int entry;
			cout << "\nPlease select entry to be edited\t";
			cout << "1:Title\n 2:Author\n 3:Publisher\n:4:Quantity \n 5:Retail price\n 6:whole sale\n ";
			cin >> entry;
			switch (entry)
			{
			case 1:
				cout << "Enter Title";
				cin >> res;
				bookObject[result].setTitle(res);
				break;
			case 2:
				cout << "Enter author ";
				cin >> res;
				bookObject[result].setAuthor(res);
				break;
			case 3:
				cout << "Enter publisher";
				cin >> res;
				bookObject[result].setPublisher(res);
				break;

			case 4:
				cout << "Quantity";
				int value;
				cin >> value;
				bookObject[result].setQuantity(value);
				break;

			case 5:

				cout << "Retail price";
				double value2;
				cin >> value2;
				bookObject[result].setRetailPrice(value2);
				break;
			case 6:

				cout << "whole sale";
				double value3;
				cin >> value3;
				bookObject[result].setWholesale(value3);
				break;
			default: cout << "Invalid menu choice. Please try again: ";
			}

		}
		else
		{
			cout << "Book not found\n";
		}
	}
void InventoryModule::displayABook(int index)
	{
		cout << "Entering Display A Book function....\n";
		cout << "\nTitle: " << inventory[index].getTitle()
			<< "\nAuthor: " << inventory[index].getAuthor()
			<< "\nISBN: " << inventory[index].getISBN()
			<< "\nWholesale Cost: " << inventory[index].getWholesale()
			<< "\nRetail Cost: " << inventory[index].getRetail()
			<< "\nDate Added to Inventory: ";
		inventory[index].getDate();
		cout << "\nQuantity: " << inventory[index].getQuantity();

	}
void InventoryModule::displayBooks()
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

