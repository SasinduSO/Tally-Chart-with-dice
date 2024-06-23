#include "Tally.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#include <array>
#include <vector>
#include <cstdlib>
using namespace std;



//task 2
void Tally::displayText(char fname[])
{
	fstream tfile(fname, ios::in); //object tfile is assigned to fname(tally about) ,ios::in is used to read the file
	string words;
	if (tfile.is_open()) //checking if file is open
	{
		getline(tfile, words); //assigning first line of tallyabout to words
		while (tfile)
		{
			cout << words << endl; //looping until all the lines inside tallyabout has been displayed
			getline(tfile, words);

		}

		tfile.close(); //closing file
	}
	else
	{
		cout << "ERROR FILE NOT READ!" << endl;
	}
	cout << fname << endl;


}

//task2 end

void Tally::runMenu() {
	//creating a heading

	int count = 0;
	while (count <= 40) {

		cout << "~";
		count++; //increasing count.. count=count+1
	};
	cout << endl;
	cout << "    " << "The Tally HO Probability Generator (sth)" << endl;
	//make count 0 to run again
	count = 0;
	while (count <= 40) {

		cout << "~";
		count++; //increasing count.. count=count+1
	};

	cout << endl;
	//end of heading and start of menu
	cout << "[1] End Testing the Program" << endl;
	cout << "[2] Display " << "About" << "information" << endl;
	cout << "[3] Read And Store Data From Files" << endl;
	cout << "[4] Generate a Dice Tally Table" << endl;
	cout << "[5] Save Tally Statistics to a file" << endl;
	cout << "[6] Load Tally Statistics from a file" << endl;

	//end of menu
	count = 0;
	while (count <= 40) {

		cout << "~";
		count++; //increasing count.. count=count+1
	};

	cout << endl;
	cout << "which option would you like (1-6) : " << endl;

	int opt; //declaring user option
	cin >> opt;

	//validating user input

	if (opt > 0 and opt < 7)
	{
		switch (opt)
		{
		default:cout << "You have selected :" << opt << endl;
			break;
		case 1:cout << "Program has ended" << endl;
			break;
		case 2: {
			cout << "2 will happen" << endl;

			char name[] = "TallyAbout.txt";
			displayText(name);
		}
			  break;
		case 3:
		{
			
			cout << "Which file do you want to open?" << endl;
			cout << "file name should be entered in the form ~filename.txt~" << endl;
			char option[20];
			cin >> option;
			cout << "Data loading from " << option << endl;
			fstream file;
			file.open(option);
			if(file.fail())
			{
				cout << "File Not found." << endl;
			}
			else
			{
				createLists(option);
				cout << "Data stored into tallyData collection (vector)" << endl;
			}

		}
			break;
		case 4: 
		{
		
			cout << "4 will happen" << endl;
			cout << endl;

			cout << "How many dice to roll (1-2):" << endl;
			int nodie;
			cin >> nodie;
			cout << "How many rolls required (1-10)" << endl;
			int rolls;
			cin >> rolls;
			cout << endl;
			generateTable(nodie , rolls);
			

		}
			break;
		case 5: 
		{

			cout << "5 will happen" << endl;
			cout << endl;
			saveData();
		}
			break;
		case 6:
		{
			cout << "6 will happen" << endl;
			cout << endl;
			loadData();
		
		}
		break;
		}
	}
	else
	{
		cout << "invalid option" << endl;
	}

	//end running programs

}

//task 4
void Tally::generateTable(int nodie, int rolls) 
{

	int noOfDice = nodie;
	int noOfTurns = rolls;

	Tally t1;

	int min, max = 0;
	switch (noOfDice) { // validating minimum and maximum outputs
	case 1: {
		min = 1;
		max = 6;
		break; }
	case 2: {
		min = 2;
		max = 12;
		break; }
	default: {
		cout << "error";
		break; }
	}
	fstream tempfile;
	tempfile.open("tallyResults.txt", ios::out); //collection variable is a external file.txt
		tempfile.close();
	tempfile.open("tallyResults.txt",ios::app);
	tempfile << "You rolled " << noOfDice<< " dice " <<noOfTurns*10<<" times \n"; //printing inside file
	cout << "You rolled " << noOfDice << " dice " << noOfTurns * 10 << " times." << endl;
	int count3 = 0;
	while (count3 <= 30) {
		tempfile << "~";
		cout << "~";
		count3++; //increasing count.. count=count+1
	};
	cout << endl;
	tempfile << "\n";
	tempfile.close();
	int* counts = new int[max + 1]; //creating array
	for (int i = 0; i < max + 1; i++) {	//INITIALISING array
		counts[i] = 0;
	}
	srand(time(NULL)); //to variate the random result
	for (int i = 0; i < noOfTurns * 10; i++) {
		int currentValue = t1.getDiceValue(min, max); //getting a returned value(eg: from 2 to 12)
		counts[currentValue] += 1; //incrementing the value at the position where current value depicts
	}//counts[12]={2,4,8,4,7,.....,9} 12 numbers are stored with sum equal to 100

	t1.printResults(counts, min, max);//passing parameters into print results
}

int Tally::getDiceValue(int min, int max) {

	// return a random number beteween min & max

	int result = rand() % max + 1; // generating random number between maximum value
	if (result >= min and result <= max)//validating so that generated value is between range
	{
		return result;
	}
	else
	{
		int getDiceValue(int min, int max);// looping if generated value is outside range
	}
}

void Tally::printResults(int results[], int min, int max) {
	// print the results array
	fstream tempfile;
	tempfile.open("tallyResults.txt", ios::app);
	for (int i = min; i <= max; i++) {
		int starno = results[i];

		cout << i << ": ";

		tempfile << i << ": ";

		int count4 = 0;

		while (count4 < starno) {
			cout << "*";
			tempfile << "*";
			count4++;
		}
		tempfile << "\n";
		cout << endl;

	}
	tempfile.close();
}


//end of task 4

//starting task 5
void Tally::saveData()
{
	
	fstream tempfile("tallyResults.txt", ios::in); //object tempfile is used with "in" read mode 

	string savewords;
	fstream savefile;
//opening the file to save temporary dice table
	if (tempfile.is_open())
	{
		getline(tempfile, savewords); //displaying last generated dice table line by line
		while (tempfile)
		{
			cout << savewords << endl;
			getline(tempfile, savewords);

		}
		cout << endl;
		tempfile.close();
		cout << "Would you like to save this data? (y/n): ";
		char choice;
		cin >> choice;
		cout << endl;
		if (choice == 'y')
		{
			string words;
			savefile.open("SavedTallyData.txt", ios::app);
			fstream tempfile("tallyResults.txt", ios::in);
			getline(tempfile, words); //getting line by line from tempfile to save in savedtallydata.txt
			while (tempfile) //running tallyresults file until it is read from top to bottom
			{
				savefile << words << "\n"; //saving in savedtallydata.txt
				getline(tempfile, words);
			}
			savefile << "\n";
			cout << "These statistics are now saved" << endl;
		}
		else
		{
			cout << "No Data saved" << endl;
		}
			

		savefile.close();
		tempfile.close();
	}
	else
	{
		cout << "No Saved Data" << endl;
	}

}
//end of task 5

//starting task3

void Tally::createLists(char opt[])
{
	vector <string> tallyData; 
	string words;
	fstream loadf;
	

	loadf.open(opt);
	getline(loadf, words);
			while (loadf)
			{
				 tallyData.push_back(words);
				getline(loadf, words);

			}
	
		/*	for (int i = 0; i< tallyData.size(); i++)
			{
				cout << tallyData[i] << endl;
			}
		*/
}

//end of task 3 

//task 6

void Tally::loadData()
{
	char filename[] = "SavedTallyData.txt";
	vector <string> tallyData;
	string words;
	fstream loadf;


	loadf.open(filename);
	getline(loadf, words);
	while (loadf)
	{
		tallyData.push_back(words);
		getline(loadf, words);

	}

		for (int i = 0; i< tallyData.size(); i++)
		{
			cout << tallyData[i] << endl;
		}

}

//end of task 6
