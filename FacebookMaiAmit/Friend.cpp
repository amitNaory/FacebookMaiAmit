#include <iostream>
using namespace std;

#include "FanPage.h"
#include "Friend.h"


//This function add to friends pointers array a pointer to a new friend
void Friend::addFriend(Friend& newFriend)
{
	friends.push_back(&newFriend);
}

//cheack if friends already connected
bool Friend::isFriendsConnected(Friend& newFriend) const
{
	bool flag = false;

	for (int i = 0; i < friends.size() && !flag; i++)
	{
		if (friends[i] == &newFriend)
			flag = true;
	}

	return flag;
}

//This function add to fanpage pointers array a pointer to a new friend
void Friend::addFanPage(FanPage& newFanPage)
{
	pages.push_back(&newFanPage);
}

//cheack if fan page already connected
bool Friend::isFanPageAndFriendsConnected(FanPage& newFanPage) const
{
	bool flag = false;
	for (int i = 0; i < pages.size() && !flag; i++)
	{
		if (pages[i] == &newFanPage)
			flag = true;
	}

	return flag;
}

//Erase given friend from friends list
void Friend::removeFriend(int ind)
{
	friends.erase(friends.begin()+ind);
}

//Returns the index in friends array of the given friend
int Friend:: getFriendInd(Friend* f) const
{
	auto it = find(friends.begin(), friends.end(), f);
	int ind = it - friends.begin();
	return ind;
}

//Erase given page from pages list
void Friend::removeFanPage(int ind)
{
	pages.erase(pages.begin() + ind);
}


//Returns the index in pages array of the given page
int Friend::getPageInd(FanPage* p) const
{
	auto it = find(pages.begin(), pages.end(), p);
	int ind = it - pages.begin();
	return ind;
}

Friend* Friend::getFriend(int ind) const
{
	return friends[ind];
}

//Print friend's name
void Friend::showName() const
{
	cout << name << endl;
}

//Returns friend's name
string Friend::getName() const
{
	return name;
}

//Returns number of friends
int Friend::getFriendsSize() const
{
	return friends.size();
}

//show 10 recent status of a friend
void Friend::show10Status() const
{
	Mboard.show10RecentStatus();
}

//This function Print's all the statuses of the friend
void Friend::showMboard() const
{
	Mboard.printAllStatus();
}


//This function show's the recent statuses of all friends of the friend
void Friend::showMyFriends10RecentStatuses() const
{
	if (friends.size() == 0)
		cout << getFriendName() << " has no friends yet" << endl;
	else {
		for (int i = 0; i < friends.size(); i++)
		{
			cout << "Recent statuses of: ";
			friends[i]->showName();
			cout << endl;
			friends[i]->show10Status();
		}
	}
}

//Print's all friends in friends list
void Friend::showAllFriends() const
{
	if (friends.size() == 0)
		cout << getFriendName() << " has no friends yet" << endl;
	else {
		cout << getFriendName() << " friends list is: " << endl;
		for (int i = 0; i < friends.size(); i++)
		{
			cout << "friend num #" << i + 1 << " ";
			friends[i]->showName();
		}
	}
}

void Friend::showFanPages() const
{
	cout << "List of fan pages:" << endl;
	for (int i = 0; i < pages.size(); i++)
	{
		cout << i << ". ";
		cout << pages[i]->getName() << endl;
	}
}

void Friend:: saveDataToFile(ostream& file) const
{
	file << name << endl;
	date.show(file);
}

void Friend::saveFriendsToFile(ostream& file) const
{
	file << friends.size() << endl;
	for (int i = 0; i < friends.size(); i++)
	{
		file << friends[i]->getName() << endl;
    }
}

void Friend::savePagesToFile(ostream& file) const
{
	file << pages.size() << endl;
	for (int i = 0; i < pages.size(); i++)
	{
		file << pages[i]->getName() << endl;
	}
}