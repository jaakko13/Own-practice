#include <iostream>
//#include <list>
#include <fstream>
#include <algorithm>
using namespace std;

void adding();
void print();
void end();


int main()
{
	char choice;
	bool running = true;

	while (running)
	{
		cout << "What do you want to do?" << endl;
		cout << "a = add a student, p = print the student list, e = exit function" << endl;
		cin >> choice;

		switch (choice) {
		case 'a':
			adding();
			break;
		case 'p':
			print();
			break;
		case 'e':
			end();
			break;
		default:
			cout << "That is not a valid option." << endl;
			break;
		}
	}
}

void adding()
{
	ofstream outFS;
	outFS.open("myoutfile.txt", fstream::app);
	int i = 0;
	string name[100]; int amount[100]; int grades[100];
	for (i = 0; i < 1; i++) {
		cout << "What is the name of the student?";
		cin >> name[i];

		outFS << name[0] << ' ';

		cout << "How many weekly exercises did the student complete?";
		cin >> amount[i];

		outFS << amount[0] << ' ';

		cout << "What was the students grade in the final assignment?";
		cin >> grades[i];

		outFS << grades[0] << ' ';
	}
	outFS.close();
}

void print()
{

	ifstream inFS;
	inFS.open("myoutfile.txt");

	string name;
	double amount;
	double grades;
	double weekgrade;
	double weekly = 0.4;
	double final = 0.6;


	cout << "Is 40 percent for weekly exercises and 60 percent for final assignment okay?" << endl;
	cout << "y = yes, n = no" << endl;
	char choice;
	cin >> choice;

	switch (choice) {
	case 'y':
		while (inFS >> name >> amount >> grades)
		{
			if (amount < 20) {
				weekgrade = 0;
			}else if (19 < amount && amount < 24) {
				weekgrade = 1;
			}else if (23 < amount && amount < 28) {
				weekgrade = 2;
			}else if (27 < amount && amount < 33) {
				weekgrade = 3;
			}else if (32 < amount && amount < 37) {
				weekgrade = 4;
			}else if (36 < amount && amount < 41) {
				weekgrade = 5;
			}
			double precise = ((weekgrade * weekly) + (grades * final));
			double rounded = round((weekgrade * weekly) + (grades * final));
			cout << "Name:" << name << " Amount of weekly exercises completed:" << amount << " Precise grade:" << precise << " Rounded grade:" << rounded << endl;
		}
		break;
	case 'n':

		cout << "What percent would you like weekly exercises to be worth?";
		cin >> weekly;
		weekly = weekly / 100;

		cout << "What percent would you like the final assignment to be worth?";
		cin >> final;
		final = final / 100;

		while (inFS >> name >> amount >> grades)
		{
			
			if (amount < 20){
				weekgrade = 0;
			}
			else if (19 < amount && amount < 24) {
				weekgrade = 1;
			}
			else if (23 < amount && amount < 28) {
				weekgrade = 2;
			}
			else if (27 < amount && amount < 33) {
				weekgrade = 3;
			}
			else if (32 < amount && amount < 37) {
				weekgrade = 4;
			}
			else if (36 < amount && amount < 41) {
				weekgrade = 5;
			}
			double precise = (weekgrade * weekly + grades * final);
			double rounded = round(weekgrade * weekly + grades * final);
			cout << "Name:" << name << " Amount of weekly exercises completed:" << amount << " Precise grade:" << precise << " Rounded grade:" << rounded << endl;
		}
	}
		inFS.close();
}

void end()
{
	exit(0);
}