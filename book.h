#define _CRT_SECURE_NO_WARNINGS
#ifndef BOOK_H
#define BOOK_H
#include "Date.h"
#include <string>

using namespace std;

class Book
{
private: //member variables
	Date dateAdded;
	string title;
	string author;
	string publisher;
	string ISBN;
	int quantity;
	double wholesale;
	double retail;

public: //member functions
	//Setters
	Book()
	{
		retail = 0;
		dateAdded.setDate(0, 0, 0);
	}
	void setTitle(string s)
	{
		title = s;
	}
	void setAuthor(string a)
	{
		author = a;
	}
	void setISBN(string isbn)
	{
		ISBN = isbn;
	}
	void setPublisher(string p)
	{
		publisher = p;
	}
	void setWholesale(double whole)
	{
		wholesale = whole;
	}
	void setRetail(double ret)
	{
		retail = ret;
	}
	void setDate(int month, int day, int year)
	{
		dateAdded.setDate(day, month, year);
	}
	void setDate(string date)
	{
		dateAdded.setDate(date);
	}
	void setQuantity(int q)
	{
		quantity = q;
	}

	//Getters
	string getTitle()
	{
		return title;
	}
	string getAuthor()
	{
		return author;
	}
	string getISBN()
	{
		return ISBN;
	}
	string getPublisher()
	{
		return publisher;
	}
	double getWholesale()
	{
		return wholesale;
	}
	double getRetail()
	{
		return retail; 
	}
	void getDate()
	{
		cout << dateAdded;//dateAdded.getDate();
	}
	int getQuantity()
	{
		return quantity;
	}
};

#endif
