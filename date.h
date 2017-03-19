#define _CRT_SECURE_NO_WARNINGS
#ifndef DATE_H
#define DATE_H

class Date
{
private:
	int day, month, year;
public:
	Date();
	void setDate(string date);
	void setDate(int dy, int mon, int yr);
	bool operator > (const Date &dateobj);
	bool operator ==(const Date &dateobj);
	bool operator <(const Date &dateobj);
	void errorLoop(); //<- this will be checking day, month, and year bounds
	istream operator >>(const Date &dateobj);
	ostream operator <<(const Date &dateobj);
	


};
