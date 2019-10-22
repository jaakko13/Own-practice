#include <iostream>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <iterator>
#include <fstream>
using namespace std;

void regular();
void bonus();
void adding();
void print();


int main() {
	char choice;
	bool running = true;

	while (running)
	{
		cout << "What do you want to do?" << endl;
		cout << "a = add a ticket, p = print the lottery numbers" << endl;
		cin >> choice;

		switch (choice) {
		case 'a':
			adding();
			break;
		case 'p':
			print();
			break;
		default:
			cout << "That is not a valid option." << endl;
			break;
		}
	}
}


void print() {
	
	regular();
	bonus();
}


void regular() {
	cout << "These are your regular numbers." << endl;
	int i = 0;
	vector<int> regs(7);
	srand(time(NULL));
	for (i = 0; i < 7; i++) {
		int x = rand() % 39 + 1;
		regs.push_back(x);
	}
	sort(regs.begin(), regs.end());
	reverse(regs.begin(), regs.end());
	for (int i = 0; i < 7; ++i) {
		cout << regs[i] << ' ';
	}
	
	cout << endl << endl;
}


void bonus() {
	cout << "These are your bonus numbers." << endl;
	int i = 0;
	vector<int> bonus(3);
	srand(time(NULL));
	for (i = 0; i < 3; i++) {
		int y = rand() % 39 + 1;
		bonus.push_back(y);
	}
	sort(bonus.begin(), bonus.end());
	reverse(bonus.begin(), bonus.end());
	for (int i = 0; i < 3; ++i) {
		cout << bonus[i] << ' ';
	}
	cout << endl;
}


void adding()
{
	int numbers[7];
	int i = 0;
	int x;
	cout << "What are your regular numbers?";
	for (i = 0; i < 7; i++) {
		cin >> x;
		if (x <= 39 && x >= 1) {
			cin >> numbers[i];
		}
		else if (x > 39 or x < 1) {
			cout << "That is not a valid number. Only numbers between 1 and 39 are valid. Try again.";
			cout << endl;
			adding();
		}
	}
	
	for (i = 0; i < 7; i++) {
		cout << numbers[i] << " ";
	}
	cout << endl;




}



