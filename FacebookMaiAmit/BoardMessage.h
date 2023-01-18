#ifndef _BOARDMESSAGE_H_
#define _BOARDMESSAGE_H_
#include <iostream>
#include "Visual.h"
#define RECENT 10

using namespace std;
class Status;
#include <vector>

class BoardMessage
{
private:
	vector<Status*> messages;

public:
	BoardMessage() {}
	void addStatus(const string text, const string visual);
	void printAllStatus() const;
	void show10RecentStatus()const;

};
#endif // !_BOARDMESSAGE_

