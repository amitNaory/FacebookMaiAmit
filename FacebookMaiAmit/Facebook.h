#ifndef  _FACEBOOK_H_
#define _FACEBOOK_H_
#include <iostream>
#include <fstream>
#include "Date.h"
#include "Status.h"
#include "BoardMessage.h"
#include "FanPage.h"
#include "Friend.h"
#include "Exceptions.h"

using namespace std;

class Facebook
{
private:
	vector<Friend*> friends;
	vector<FanPage*> fanPages;

public:
	Facebook() {}
	Facebook(vector<Friend*> friends_array, vector<FanPage*> fanPage_array) :
		friends(friends_array), fanPages(fanPage_array) {}
	void connect(Friend& f1, Friend& f2) noexcept(false);
	void connectFanPageAndFriend(Friend& f1, FanPage& fanPage);
	void showFanPagesOfFriend(const Friend& f) const;
	void addFriend(Friend& newFriend)noexcept(false);
	bool isFriendExsist(const Friend& f) const;
	void addFanPage(FanPage& newPage)noexcept(false);
	bool isFanPageExsist(const FanPage& f) const;
	void showAllFriends() const;
	void showAllFanPages() const;
	int getInd(Friend* f) const;
	int getInd(FanPage* p) const;
	void freeFriends();
	void freeFanPages();
	void printMenu() const;
	void start();
	void initial(ifstream& inFile) noexcept(false);
	void saveDataToFile(ofstream& outFile) const;

private:
	void option1() noexcept(false);
	void option2() noexcept(false);
	void option3() noexcept(false);
	void option4() noexcept(false);
	void option5() const noexcept(false);
	void option6() noexcept(false);
	void option7() noexcept(false);
	void option8() noexcept(false);
	void option9() noexcept(false);
	void option10() const;
	void option11() const noexcept(false);
	void isInRange(int index, int range) const noexcept(false);

public:
	~Facebook() { freeFanPages(); freeFriends(); }


};
#endif // ! _FACEBOOK_H_


