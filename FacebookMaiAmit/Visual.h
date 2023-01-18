#pragma once
#include <iostream>
using namespace std;
#include "Status.h"
#include <string>

class Visual : public Status
{
private:
	string Fname;
public:
	Visual() {};
	Visual(string text, string visual) : Status(text), Fname(visual) {}

	virtual void show() const
	{
		Status::show();
		string command = "start ";
		command += Fname;
		system(command.c_str());
	}
};
