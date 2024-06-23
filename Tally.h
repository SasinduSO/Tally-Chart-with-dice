#ifndef TALLY_H
#define TALLY_H

#include<cstring>
#include<string>
class Tally {

private:
	
public:
	void runMenu();//task1
	void displayText(char fname[]);//task2
	void generateTable(int nodie, int rolls);//task4
	int getDiceValue(int min, int max);//task4
	void printResults(int results[], int min, int max);//task4
	void saveData();//task 5
	void createLists( char opt[]);//task3
	void loadData();//task6
};
#endif // TALLY_H
