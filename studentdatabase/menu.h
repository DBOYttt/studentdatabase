#pragma once
#include <string>
#include <vector>

using namespace std;
class menu
{
public:
	void initmenu(string option1, string option2, string option3);
	int option();
	void  getinformation(string &inf1, string &inf2,int &inf3);
};

