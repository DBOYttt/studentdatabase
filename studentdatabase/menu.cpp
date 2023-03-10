#include "menu.h"
#include <iostream>
using namespace std;

void menu::initmenu(string option1, string option2, string option3)
{
	    cout << "Wybierz opcjê: " << endl;
		cout << "1. " << option1 + " :" << endl;
		cout << "2. " << option2 + " :" << endl;
		cout << "3. " << option3 + " :" << endl;
		cout << "0. Wyjscie :" << endl;
}

int menu::option()
{
	int option;
	cin >> option;
	return option;
}

void menu::getinformation(string &inf1, string &inf2,int &inf3)
{
	
	cout << "Name :" << endl;
	cin >> inf1;
	cout << "LastName :" << endl;
	cin >> inf2;
	cout << "age :" << endl;
	cin >> inf3;



}


