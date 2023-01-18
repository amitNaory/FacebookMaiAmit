#ifndef _FANPAGE_H_
#define _FANPAGE_H_
#include "Date.h"
#include "BoardMessage.h"

using namespace std;
class Friend;
#include <vector>

class FanPage
{
private:
	const string name;
	BoardMessage board;
	vector<Friend*> fans;

public:
	FanPage() {}
	FanPage(const string Name) :name(Name) {}

	string getName() const;
	void addFriend(Friend& newFriend);
	void removeFriend(int ind);
	int getFanInd(Friend* f);
	Friend* getFriend(int ind) const;
	void showFans()const;
	void addStatus(const string text, const string visual) { board.addStatus(text, visual); }
	void showAllStatuses() const;
	int getFansSize() const;
	void saveFansToFile(ostream& file) const;
	void readFansToFile(ostream& file);

	FanPage& operator+=(Friend& newFriend)
	{
		addFriend(newFriend);
		return *this;
	}

	bool operator<(const FanPage& other)
	{
		if (fans.size() < other.fans.size())
			return true;
		else
			return false;
	}
};
#endif // _FRIEDN_H_

