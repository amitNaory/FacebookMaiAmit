#pragma once
using namespace std;
#include <string>

class NewMemberException : public exception
{
private:
	string m_str;
public:
	NewMemberException(string name)
	{
		m_str = name;
		m_str += " is already existing member";
	}
	const char* what() const
	{
		return m_str.c_str();
	}
};

class DateException : public exception
{
private:
	string m_str;
public:
	DateException() : m_str("Invalid date of birth!") {}
	const char* what() const
	{
		return m_str.c_str();
	}
};

class FanPageException : public exception
{
private:
	string m_str;
public:
	FanPageException(const string& name)
	{
		m_str = name;
		m_str += " is already existing fan page";
	}
	const char* what() const
	{
		return m_str.c_str();
	}
};

class InputException : public exception
{
private:
	string m_str;
public:
	InputException() : m_str("Invalid choice!") {}
	const char* what() const
	{
		return m_str.c_str();
	}
};

class ConnectFriendsException : public exception
{
private:
	string m_str;
public:
	ConnectFriendsException(const string& f1, const string& f2)
	{
		if (f1 != f2)
		{
			m_str = f1;
			m_str += " and ";
			m_str += f2;
			m_str += " are already friends";
		}
		else
		{
			m_str = "You can't connect friend to himself";
		}
	}

	virtual char const* what() const override
	{
		return m_str.c_str();
	}
};

