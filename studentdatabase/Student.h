#pragma once

#include <string>

using namespace std;

class Student
{
private:
	
	int _id;
	int _age;
	
	string _name;
	string _lastName;

public:
	Student();
	Student(int id, string name, string lastname, int age);
	void setStudent(int id, string name, string lastname, int age);
	int getID();
	string getName();
	string getLastName();
	void print();
};

