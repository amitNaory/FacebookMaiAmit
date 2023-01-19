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
		
		network.saveDataToFile(outFile);
		network.freeFriends();
		network.freeFanPages();
		cout << "Thank you for using Facebook!" << endl;
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	inFile.close();
	outFile.close();

	ofstream readFile("facebook.txt");
	ifstream writeFile("outFacebook.txt");
	
	network.updateReadFile(writeFile, readFile);
	
	readFile.close();
	writeFile.close();


	return 0;
}