#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"

Date::Date()
{
  day = 00;
  month = 00;
  year = 0000;
}
void Date::setDate(string date)
{
		std::string mon, dy, yr;
		mon = stringformat.substr(0, 2);
		dy = stringformat.substr(3, 2);
		yr = stringformat.substr(6, 4);
		setDate(stoi(mon), stoi(dy), stoi(yr));
}
	void Date::setDate(int dy, int mon, int yr)
	{
		day = dy;
		month = mon;
		year = yr;
	}
	bool Date::operator > (const Date &dateobj)
	{
		bool status;
		if (year < dateobj.year)
			status = true;
		else if (year > dateobj.year)
			status = false;
		else if (year == dateobj.year)
		{
			if (month < dateobj.month)
				status = true;
			else if (month > dateobj.month)
				status = false;
			else if (month == dateobj.month)
			{
				if (day < dateobj.day)
					status = true;
				else if (day >= dateobj.day)
					status = false;
			}
		}
		return status;
	}

	bool Date::operator ==(const Date &dateobj)
	{
		bool status;
		if (year == dateobj.year && month == dateobj.month && day == dateobj.day)
			status = true;
		else
			status = false;
		return status;
	}

	bool Date::operator <(const Date &dateobj)
	{
		bool status;
		if (year > dateobj.year)
			status = true;
		else if (year < dateobj.year)
			status = false;
		else if (year == dateobj.year)
		{
			if (month > dateobj.month)
				status = true;
			else if (month < dateobj.month)
				status = false;
			else if (month == dateobj.month)
			{
				if (day > dateobj.day)
					status = true;
				else if (day <= dateobj.day)
					status = false;
			}
		}
		return status;
	}

	istream operator >>(const Date &dateobj)
  {
  		//For inputting the Date from the file to the inventory
		//also for entering the Date manually
		string input;
		cin >> input;
		//For the sake of error handling:
		if (input.length() != 11)
			input = "00/00/0000";
		string tempMonth = input.substr(0, 2);
		string tempDay = input.substr(3, 2);
		string tempYear = input.substr(6, 4);
		dateobj.month = stoi(tempMonth);
		dateobj.day = stoi(tempDay);
		dateobj.year = stoi(tempYear);
		return cin;
  }
	ostream operator <<(const Date &dateobj)
  {
  	cout << dateobj.day << "/" << dateobj.month << "/" << dateobj.year;
    return cout; // <-what the hell is this again? Check the textbook...
  }

