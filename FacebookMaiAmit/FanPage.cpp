#include <iostream>
using namespace std;

#include "FanPage.h"
#include "Friend.h"

//return fan page name
string FanPage::getName()const { return name; }

//This function add to fans pointers array a pointer to a new fan
void FanPage::addFriend(Friend& newFriend)
{
	fans.push_back(&newFriend);
}

//This function removes the given friend from the fans list
void FanPage::removeFriend(int ind)
{
	fans.erase(fans.begin() + ind);
}


//Returns the index in fans array of the given friend
int FanPage::getFanInd(Friend* f)
{
	auto it = find(fans.begin(), fans.end(), f);
	int ind = it - fans.begin();
	return ind;
}

Friend* FanPage:: getFriend(int ind) const
{
	return fans[ind];
}

//Print all fans of fan page
void FanPage::showFans()const
{
	if (fans.size() == 0)
		cout << getName() << " has no fans yet" << endl;
	else {
		for (int i = 0; i < fans.size(); i++)
		{
			cout << i + 1 << ":";
			fans[i]->showName();
			cout << endl;
		}
	}
}

//This function Print's all the statuses of the fan page
void FanPage::showAllStatuses()const
{
	board.printAllStatus();
}

//Return the number of fans
int FanPage::getFansSize() const
{
	return fans.size();
}


void FanPage::saveFansToFile(ostream& file) const
{
	file << fans.size() << endl;
	for (int i = 0; i < fans.size(); i++)
	{
		file << fans[i]->getName() << endl;
	}
}

void FanPage::readFansToFile(ostream& file) const
{
	int size;
	string name;
	file >> size >> endl;
	for (int i = 0; i < size; i++)
	{
		file >> name >> endl;
	}
}
