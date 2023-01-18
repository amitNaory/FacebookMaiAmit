#ifndef _FRIEND_H
#define _FRIEND_H
#include "Date.h"
#include "BoardMessage.h"
#define RECENT 10

using namespace std;
class FanPage;

class Friend
{
private:
	const string name;
	Date date;
	vector<Friend*> friends;
	BoardMessage Mboard;
	vector<FanPage*> pages;
	
public:
	Friend() {}
	Friend(const string Name, int day, int month, int year)
		: name(Name), date(day, month, year) {}

	bool isFanPageAndFriendsConnected(FanPage& newFanPage) const;
	bool isFriendsConnected(Friend& newFriend) const;
	const string getFriendName() const { return name; }
	void addFriend(Friend& newFriend);
	void removeFriend(int ind);
	int getFriendInd(Friend* f) const;
	void addFanPage(FanPage& newFanPage);
	void removeFanPage(int ind);
	int getPageInd(FanPage* p) const;
	void showName() const;
	string getName() const;
	int getFriendsSize() const;
	Friend* getFriend(int ind) const;
	void show10Status() const;
	void showFanPages() const;
	void showMboard() const;
	void addStatus(const string text, const string visual) { Mboard.addStatus(text, visual); }
	void showMyFriends10RecentStatuses() const;
	void showAllFriends() const;
	void saveDataToFile(ostream& file) const;
	void saveFriendsToFile(ostream& file) const;
	void savePagesToFile(ostream& file) const;

	Friend& operator+=(Friend& newFriend)
	{
		addFriend(newFriend);
		return *this;
	}

	bool operator<(const Friend& other) const
	{
		if (friends.size() < other.friends.size())
			return true;
		else
			return false;
	}
};
#endif

