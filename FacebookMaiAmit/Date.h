#ifndef _DATE_H
#define _DATE_H
#include <iostream>
#include "Exceptions.h"

using namespace std;

//This h file does not have source file beacuse all funcs are short and described in here

class Date {
private:
	const int day;
	const int month;
	const int year;
public:
	Date() :day(0), month(0), year(0) {}
	Date(int _day, int _month, int _year) noexcept(false) : day(_day), month(_month), year(_year)
	{
		if (this->day < 1 || this->day>31 || this->month < 1 || this->month>12 || this->year < 1)
		{
			throw DateException();
		}
	}

	int GetDay() const {
		return day;
	}
	int GetMonth() const {
		return month;
	}
	int GetYear() const {
		return year;
	}

	void show(ostream& file) const { file << day << " " << month << " " << year << endl; }

};

#endif

