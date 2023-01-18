#include <iostream>
#include "Facebook.h"
using namespace std;

int main() {

	ifstream inFile("facebook.txt");
	ofstream outFile("outFacebook.txt");
	Facebook network;
	try
	{
		network.readDataFromFile(inFile);
		//network.initial(inFile);
		network.start();
		network.freeFriends();
		network.freeFanPages();
		network.saveDataToFile(outFile);
		inFile.close();
		outFile.close();
		cout << "Thank you for using Facebook!" << endl;
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}