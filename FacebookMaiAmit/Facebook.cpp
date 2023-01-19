#include "Facebook.h"
#include "Exceptions.h"

#define MAX_NAME_LEN 20
#define MAX_TEXT_LEN 256
#include <iostream>
using namespace std;

//connect with two friends
void Facebook::connect(Friend& f1, Friend& f2)
{
	bool error = false;
	if (f1.getFriendName() == f2.getFriendName())
		error = true;
	if (!error)
		error = f1.isFriendsConnected(f2);

	if (!error)
	{
		f1 += f2;
		f2 += f1;
		cout << f1.getFriendName() << " and " << f2.getFriendName() << " are now connected as friends" << endl;
	}
	else
	{
		throw  ConnectFriendsException(f1.getName(), f2.getName());
	}

}

//connect fan page with friend
void Facebook::connectFanPageAndFriend(Friend& f1, FanPage& fanPage)
{
	bool b;
	b = f1.isFanPageAndFriendsConnected(fanPage);
	if (b == false) {
		f1.addFanPage(fanPage);
		fanPage += f1;
		cout << f1.getFriendName() << " is now a fan of " << fanPage.getName() << endl;
	}
	else
		cout << "This member is already a fan of this fan page" << endl;
}

//Add pointer to new friend to facebook
void Facebook::addFriend(Friend& newFriend) noexcept(false)
{
	if (isFriendExsist(newFriend) == true) { throw NewMemberException(newFriend.getName()); }
	friends.push_back(&newFriend);
	cout << "friend added succesfully" << endl;
}

//Returns true if the given member is already a member in facebook, else, returns false
bool Facebook::isFriendExsist(const Friend& f) const
{
	bool find = false;
	for (int i = 0; i < friends.size() && find == false; i++)
	{
		if (friends[i]->getFriendName() == f.getFriendName()) { find = true; }
	}
	return find;
}


//add pointer to new page to facebook
void Facebook::addFanPage(FanPage& newPage) noexcept(false)
{
	if (isFanPageExsist(newPage) == true) { throw FanPageException(newPage.getName()); }
	fanPages.push_back(&newPage);
	cout << "fan page added succesfully" << endl;
}


//Returns true if the given fan page is already a in facebook, else, returns false
bool Facebook::isFanPageExsist(const FanPage& f) const
{
	bool find = false;
	for (int i = 0; i < fanPages.size() && find == false; i++)
	{
		if (fanPages[i]->getName() == f.getName())
			find = true;
	}
	return find;
}

//free all pointers friends and friends array
void Facebook::freeFriends()
{
	for (int i = 0; i < friends.size(); i++)
	{
		delete friends[i];
	}

}

//free all pointers fanPages and fanPage array
void Facebook::freeFanPages()
{
	for (int i = 0; i < fanPages.size(); i++)
	{
		delete fanPages[i];
	}

}

//print all options in the menu
void Facebook::printMenu() const
{
	cout << "Please choose an option from the following menu: " << endl;
	cout << "1) add friend " << endl;
	cout << "2) add fan page" << endl;
	cout << "3) add status to a friend / fanpage board message" << endl;
	cout << "4) show all statuses of a friend / fan page" << endl;
	cout << "5) show recents statuses of all friends of some friend" << endl;
	cout << "6) connect two friends" << endl;
	cout << "7) delete connection with two friends" << endl;
	cout << "8) add new fan to page" << endl;
	cout << "9) remove fan from page" << endl;
	cout << "10) show all friends and fan pages on Facebook" << endl;
	cout << "11) show friends of friend / fan page" << endl;
	cout << "12) exit" << endl;
}

void Facebook::start()
{
	int input = 1;

	while (input != 12)
	{
		try {
			cout << endl;
			printMenu();
			cin >> input;
			cin.ignore();

			if (input == 1)
				option1();

			else if (input == 2)
				option2();

			else if (input == 3)
				option3();

			else if (input == 4)
				option4();

			else if (input == 5)
		        option5();

			else if (input == 6)
				option6();

			else if (input == 7)
				option7();

			else if (input == 8)
				option8();

			else if (input == 9)
				option9();

			else if (input == 10)
				option10();

			else if (input == 11)

				option11();
		}
		catch (const exception& e) { cout << endl << "Exception Thrown:" << endl << e.what() << endl; }
		catch (...) { cout << "Unknown Error" << endl; }
	}
}

//print all friends in facebook
void Facebook::showAllFriends() const
{
	for (int i = 0; i < friends.size(); i++)
	{
		cout << "friend num #" << i + 1 << " ";
		friends[i]->showName();
	}
}

//print all fan pages in facebook
void Facebook::showAllFanPages() const
{

	for (int i = 0; i < fanPages.size(); i++)
	{
		cout << "fan page num #" << i + 1 << " ";
		cout << fanPages[i]->getName() << endl;
	}

}

//inital first data for facebook
void Facebook::initial(ifstream& inFile)
{
	string first_name, last_name, name;
	int d, m, y, size;
	inFile >> size;
	for (int i = 0; i < size; i++)
	{
		inFile >> first_name >> last_name;
		inFile >> d >> m >> y;
		name = first_name + " " + last_name;
		Friend* f = new Friend(name, d, m, y);
		friends.push_back(f);
	}
	char c;
	inFile >> size;
	for (int i = 0; i < size; i++)
	{
		getline(inFile, name);
		FanPage* p = new FanPage(name);
		fanPages.push_back(p);
	}


	friends[0]->addFriend(*friends[1]);
	friends[1]->addFriend(*friends[0]);

	friends[0]->addFriend(*friends[2]);
	friends[2]->addFriend(*friends[0]);

	fanPages[0]->addFriend(*friends[0]);
	friends[0]->addFanPage(*fanPages[0]);

	fanPages[0]->addFriend(*friends[1]);
	friends[1]->addFanPage(*fanPages[0]);

	fanPages[2]->addFriend(*friends[0]);
	friends[0]->addFanPage(*fanPages[2]);

	fanPages[1]->addFriend(*friends[2]);
	friends[2]->addFanPage(*fanPages[1]);

	fanPages[2]->addFriend(*friends[2]);
	friends[2]->addFanPage(*fanPages[2]);

	friends[0]->addStatus("please give us good grade", "");
	friends[1]->addStatus("we are good students", "");
	friends[2]->addStatus("give them good graders", "");
	friends[2]->addStatus("I love my new dress", "");
}

//add new friend to facebook
void Facebook::option1() noexcept(false)
{
	int day, month, year;
	string name;

	cout << "Please enter the new member name: " << endl;
	getline(cin, name);
	if (isNameExist(name))
		throw invalid_argument("name already exist in system");
	cout << "Please enter the new member date of birth. format:DD MM YYYY" << endl;
	cin >> day >> month >> year;
	Friend* newFriend = new Friend(name, day, month, year);
	addFriend(*newFriend);
}

//return true if name exist in facebook friends
bool Facebook::isNameExist(string name)
{
	for (int i = 0; i < friends.size(); i++)
	{
		if (friends[i]->getName() == name)
			return true;
	}
	return false;
}




//add new fanPage to facebook
void Facebook::option2() noexcept(false)
{
	string name;
	cout << "Please enter fan page name: " << endl;;
	getline(cin, name);
	FanPage* newFanPage = new FanPage(name);
	addFanPage(*newFanPage);
}


//add status to fan page or friend
void Facebook::option3() noexcept(false)
{
	char answer, visual;
	string text, Fname;
	int option;
	cout << "Please enter the new status" << endl;
	getline(cin, text);

	cout << "Do you want to add to this status a video or a image? Y/N" << endl;
	cin >> visual;
	if (visual != 'Y' && visual != 'N') { throw InputException(); }

	if (visual == 'Y')
	{
		cout << "Please enter the image/video name: " << endl;
		cin.ignore();
		getline(cin, Fname);
	}
	else //No visual added to status
		Fname = "";

	cout << "Do you want to add the status to a friend? Y/N (if choose N we will add to fan page)" << endl;
	cin >> answer;
	if (answer != 'Y' && answer != 'N') { throw InputException(); }

	if (answer == 'Y')
	{
		cout << "Please enter index of the friend you want to add status from the following friends" << endl;
		showAllFriends();
		cin >> option;
		isInRange(option, friends.size());
		friends[option - 1]->addStatus(text, Fname);
	}

	else //answer is N (add ststus to a fan page)
	{
		cout << "Please enter index of the fan page you want to add status from the following fan pages" << endl;
		showAllFanPages();
		cin >> option;
		isInRange(option, fanPages.size());
		fanPages[option - 1]->addStatus(text, Fname);
	}
}

//Show all statuses of a friend or a fan page 
void Facebook::option4() noexcept(false)
{
	char answer;
	int option;

	cout << "Do you want to see all statuses of a friend? Y/N (if choose N we will show all statuses of a fan page)" << endl;
	cin >> answer;
	if (answer != 'Y' && answer != 'N') { throw InputException(); }

	if (answer == 'Y')
	{
		cout << "Please enter index of the friend that you want to see his statuses from the following friends" << endl;
		showAllFriends();
		cin >> option;
		isInRange(option, friends.size());
		friends[option - 1]->showMboard();
	}

	else //answer is N (show all statuses of a fan page)
	{
		cout << "Please enter index of the fan page that you want to see it statuses from the following fan pages" << endl;
		showAllFanPages();
		cin >> option;
		isInRange(option, fanPages.size());
		fanPages[option - 1]->showAllStatuses();
	}
}

//show 10 recent statuses of all of friend's friends
void Facebook::option5() const noexcept(false)
{
	int option;

	cout << "Please enter the index of the friend that you want to see the 10 recent statuses of his friends" << endl;
	showAllFriends();
	cin >> option;
	isInRange(option, friends.size());
	friends[option - 1]->showMyFriends10RecentStatuses();
}

//connect with two friends
void Facebook::option6() noexcept(false)
{
	int ind1, ind2;
	cout << "Please choose 2 friends from the following friends list that you want to connect friends as friends" << endl;
	showAllFriends();
	cout << "Please enter the index of #1 friend:" << endl;
	cin >> ind1;
	isInRange(ind1, friends.size());
	cout << "Please enter the index of #2 friend:" << endl;;
	cin >> ind2;
	isInRange(ind2, friends.size());

	connect(*friends[ind1 - 1], *friends[ind2 - 1]);
}

//cancel friendship with two friends
void Facebook::option7() noexcept(false)
{
	int ind1, ind2;
	cout << "Please choose a friend that you want to remove some friend from his friends list:" << endl;
	showAllFriends();
	cout << "Please enter the index of the friend that you have chosen:" << endl;
	cin >> ind1;
	isInRange(ind1, friends.size());

	cout << "please choose a friend that you want to remove from " << friends[ind1 - 1]->getFriendName() << " friends list:" << endl;
	friends[ind1 - 1]->showAllFriends();
	cout << "Please enter the index of the friend that you have chosen:" << endl;
	cin >> ind2;
	isInRange(ind2, friends[ind1 -1]->getFriendsSize());

	int If2 = getInd(friends[ind1 - 1]->getFriend(ind2 - 1));
	friends[If2]->removeFriend(friends[If2]->getFriendInd(friends[ind1 - 1]));
	friends[ind1 - 1]->removeFriend(ind2-1);
	cout << friends[ind1 - 1]->getFriendName() << " and " << friends[If2]->getFriendName() << " are no longer friends" << endl;
}


int Facebook::getInd(Friend* f) const
{
	auto it = find(friends.begin(), friends.end(), f);
	int ind = it - friends.begin();
	return ind;
}

int Facebook::getInd(FanPage* p) const
{
	auto it = find(fanPages.begin(), fanPages.end(), p);
	int ind = it - fanPages.begin();
	return ind;
}

//cheack if index is in range
void Facebook::isInRange(int index, int range) const noexcept(false)
{
	if (index < 1 || index> range)
		throw InputException();
}


//add a new fan to a fan page
void Facebook::option8() noexcept(false)
{
	int ind1, ind2;
	cout << "Please choose a friend from the following friends list that you want him to like a fan page:" << endl;
	showAllFriends();
	cout << "Please enter the index of the friend that you have chosen:" << endl;
	cin >> ind1;
	isInRange(ind1, friends.size());
	cout << "Please choose a fan page that you want" << friends[ind1 - 1]->getFriendName() << " to like:" << endl;
	showAllFanPages();
	cout << "Please enter the index of the fan page that you have chosen:" << endl;
	cin >> ind2;
	isInRange(ind2, fanPages.size());
	connectFanPageAndFriend(*friends[ind1 - 1], *fanPages[ind2 - 1]);
}


//remove a fan from a fan page
void Facebook::option9() noexcept(false)
{
	int ind1, ind2;

	cout << "Please choose a fan page that you want to remove a fan from his fans list:" << endl;
	showAllFanPages();
	cout << "Please enter the index of the fan page that you have chosen:" << endl;
	cin >> ind1;
	isInRange(ind1, fanPages.size());
	cout << "Please choose a friend that you want to remove from " << fanPages[ind1 - 1]->getName() << " fan page:" << endl;
	fanPages[ind1 - 1]->showFans();
	cout << "Please enter the index of the friend that you have chosen:" << endl;
	cin >> ind2;
	isInRange(ind2, fanPages[ind1-1]->getFansSize());

	int If = getInd(fanPages[ind1 - 1]->getFriend(ind2 - 1));
	fanPages[ind1 - 1]->removeFriend(ind2-1);
	friends[If]->removeFanPage(friends[If]->getPageInd(fanPages[ind1 - 1]));
}

//print all friends of facebook and fan pages
void Facebook::option10() const
{
	cout << endl;
	cout << "All friends of facebook:" << endl;
	showAllFriends();
	cout << endl << "All fan pages of facebook:" << endl;
	showAllFanPages();
	cout << endl;
}

//print all friends of page or friend
void Facebook::option11() const noexcept(false)
{
	int option;
	char answer;
	cout << "Do you want to see the members connected to a friend? Y/N (if choose N we will show members conected to a fan page)" << endl;
	cin >> answer;
	if (answer != 'Y' && answer != 'N') { throw InputException(); }
	if (answer == 'Y')
	{
		cout << "Please enter index of the friend you want to see his friends list:" << endl;
		showAllFriends();
		cin >> option;
		isInRange(option, friends.size());
		friends[option - 1]->showAllFriends();
	}
	else //answer is N (add status to a fan page)
	{
		cout << "Please enter index of the fan page you want to see his fans list:" << endl;
		showAllFanPages();
		cin >> option;
		isInRange(option, fanPages.size());
		fanPages[option - 1]->showFans();
	}
}


//print all the pages that the given friend like
void Facebook::showFanPagesOfFriend(const Friend& f) const
{
	f.showFanPages();
}

void Facebook::saveDataToFile(ofstream& outFile) const
{
	//all friends data
	outFile << friends.size()<<endl;
	for (int i = 0; i < friends.size(); i++)
	{
		friends[i]->saveDataToFile(outFile);
	}
	//all fan pages data
	outFile << fanPages.size() << endl;
	for (int i = 0; i < fanPages.size(); i++)
	{
		outFile << fanPages[i]->getName() << endl;
	}

	//friends and pages list of eatch friend
	for (int i = 0; i < friends.size(); i++)
	{
		friends[i]->saveFriendsToFile(outFile);
		friends[i]->savePagesToFile(outFile);
	}

	//fans list of eatch fan page
	for (int i = 0; i < fanPages.size(); i++)
	{
		fanPages[i]->saveFansToFile(outFile);
	}
}

//return the friend pointer with input name
Friend* Facebook::findFriendbyName(string name) const
{
	for (int i = 0; i < friends.size(); i++)
	{
		if (friends[i]->getFriendName() == name)
			return friends[i];
		
	}
	return nullptr;
}

//return the fan page pointer with input name
FanPage* Facebook::findFanPagebyName(string name) const
{
	for (int i = 0; i < friends.size(); i++)
	{
		if (fanPages[i]->getName() == name)
			return fanPages[i];

	}
	return nullptr;
}

void Facebook::readDataFromFile(ifstream& inFile)
{
	int sizeFriends, sizeFanPage;

	string first_name, last_name, name;
	int d, m, y, size;
	//all friends data
	inFile >> sizeFriends;
	for (int i = 0; i < sizeFriends; i++)
	{
		inFile >> first_name >> last_name;
		inFile >> d >> m >> y;
		name = first_name + " " + last_name;
		Friend* f = new Friend(name, d, m, y);
		friends.push_back(f);
	}
	char c;
	inFile >> sizeFanPage;
	for (int i = 0; i < sizeFanPage; i++)
	{
		getline(inFile, name);
		FanPage* p = new FanPage(name);
		fanPages.push_back(p);
	}


	//friends and pages list of eatch friend
	for (int i = 0; i < friends.size(); i++)
	{

		readFriendsToFile(inFile, *friends[i]);
		readFanPageToFile(inFile, *friends[i]);
	}

	//fans list of eatch fan page
	for (int i = 0; i < fanPages.size(); i++)
	{
		readFriendsToFile(inFile, *fanPages[i]);
	}
}

//read friends of friend f from file
void Facebook::readFriendsToFile(ifstream& file, Friend& f)
{
	int size;
	string name;
	Friend* newfriend;
	file >> size;
	string first_name, last_name;
	for (int i = 0; i < size; i++)
	{

		file >> first_name >> last_name;
		name = first_name + " " + last_name;
		if (isNameExist(name))
		{
			newfriend = findFriendbyName(name);
			f.addFriend(*newfriend);
		}
		else
			throw invalid_argument("Name of friend doesn't exist");

	}
}

//read fans of p from file
void Facebook::readFriendsToFile(ifstream& file, FanPage& p)
{
	int size;
	string name;
	Friend* newfriend;
	file >> size;
	string first_name, last_name;
	for (int i = 0; i < size; i++)
	{
		file >> first_name >> last_name;
		name = first_name + " " + last_name;
		if (isNameExist(name))
		{
			newfriend = findFriendbyName(name);
			p.addFriend(*newfriend);
		}
		else
			throw invalid_argument("Name of friend doesn't exist");

	}
	
}

//read fan pages friend f likes from file
void Facebook::readFanPageToFile(ifstream& file, Friend& f)
{
	int size;
	string name;
	FanPage* newfanPage;
	file >> size;
	string first_name, last_name;
	for (int i = 0; i < size; i++)
	{
		getline(file, name);
		newfanPage = findFanPagebyName(name);
		if (newfanPage != nullptr)
		{
			f.addFanPage(*newfanPage);
		}
		else
			throw invalid_argument("Name of fan page doesn't exist");

	}

}

void Facebook::updateReadFile(ifstream& inFile, ofstream& outFile) const
{
	string line;
	while (getline(inFile, line)) 
	{
		outFile << line << "\n";
	}
}