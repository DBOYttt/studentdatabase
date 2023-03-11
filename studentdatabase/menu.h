#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class menu
{
public:
	void initmenu(string option1, string option2, string option3);
	int option();
	void  getinformation(string &inf1, string &inf2,int &inf3);
	void  searchstudent(int& inf);
	void editmenu(string &option);
};

