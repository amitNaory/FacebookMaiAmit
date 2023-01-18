#include "BoardMessage.h"

//print all statuses in board message
void BoardMessage::printAllStatus() const
{
	if (messages.size() == 0)
		cout << "This board messeage is empty - no statuses yet" << endl;
	else {
		cout << "all board messages: " << endl;
		for (int i = 0; i < messages.size(); i++) {
			cout << "#" << i << " " << endl;
			messages[i]->show();
		}
	}
}

//This function add new given status to the status array in board message
void BoardMessage::addStatus(const string text, const string visual)
{
	if (visual == "") {
		Status* newStatus = new Status(text);
		messages.push_back(newStatus);
	}
	else {
		Visual* newStatus = new Visual(text, visual);
		messages.push_back(newStatus);
	}
}

//show 10 recent status
void BoardMessage::show10RecentStatus() const
{
	if (messages.size() == 0)
	{
		cout << "This board messeage is empty - no statuses yet" << endl;
	}
	else
	{
		for (int i = 0; i < RECENT && i < messages.size(); i++)
			messages[i]->show();
	}
}
