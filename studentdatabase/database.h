#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
using namespace std;


class database
{
public:
	struct Record;
	void printRecord(Record record);
	void saveinformation(int &inf, string &inf2, string &inf3, int &inf4);
	int lastid();
	int findstudent(int &inf);
	vector<Record> readRecords(string filename);
	void editRecord(int id, string filename);
	void _Record(int ID);
};

