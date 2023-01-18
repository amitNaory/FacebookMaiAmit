#ifndef _STATUS_H
#define _STATUS_H
#include <iostream>
#include <ctime>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
#pragma warning(disable: 4996)

//This header file does not have source file beacuse all funcs are short and described in here

class Status
{

protected:
	string text;
	time_t time_posted;

public:
	Status(string post) :text(post), time_posted(time(0)) {}
	Status() : text(""), time_posted(time(0)) {}

	void set(string data, time_t time) {
		text = data;
		time_posted = time;
	}

	const string getText() const
	{
		return text;
	}

	const string getDate() const
	{
		return (const string)ctime(&time_posted);
	}

	virtual void show() const
	{
		cout << text << endl << "posted on date: " << ctime(&time_posted) << endl;
	}

	bool operator==(const Status& other)
	{
		if (text == other.text)
			return true;
		else
			return false;
	}

	bool operator!=(const Status& other)
	{
		return!(*this == other);
	}

	virtual ~Status(){};
};
#endif
