#include "Student.h"
#include <iostream>

Student::Student()
{
    _id = 0;
    _name = "";
    _lastName = "";
    _age = 0;
}

Student::Student(int id, string name, string lastname, int age)
{
    _id = id;
    _name = name;
    _lastName = lastname;
    _age = age;
}

void Student::setStudent(int id, string name, string lastname, int age)
{
    _id = id;
    _name = name;
    _lastName = lastname;
    _age = age;
}

int Student::getID()
{
    return _id;
}

string Student::getName()
{
    return _name;
}

string Student::getLastName()
{
    return _lastName;
}

void Student::print()
{
    cout << "ID : " << _id << endl;
    cout << "Name : " << _name << endl;
    cout << "lastname : " << _lastName << endl;
    cout << "age : " << _lastName << endl;
}
