
#include <iostream>
#include "Tally.h"
#include <fstream>
#include <string>
using namespace std;

int main()
{

	//create objects to access Tally class
	Tally T1;
	T1.runMenu();

	cout << "Do you want to select again?" << endl;
	cout << "~press Y for yes and any key for no..~" << endl;
	char ch;
	cin >> ch;
	if (ch == 'y')  //looping to use program as often as they want
	{
		main();
	}
}

