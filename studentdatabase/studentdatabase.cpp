#include <iostream>
#include "Student.h"
#include "menu.h"
#include "database.h"
#include "database.cpp"

using namespace std;

int main()
{
    Student s;
    menu m;
    database d;
    int ID;
    string name;
    string lastName;
    int age;
    int option;
    string option_edit;
    string newvalue;
    Record record;

    while (true) {
        m.initmenu("dodaj studenta", "aktulalizuj studenta", "usun studenta");
        option = m.option();
        switch (option) {
        case 1:
            ID = d.lastid();
            m.getinformation(name, lastName, age);
            d.saveinformation(++ID, name, lastName, age);
            break;
        case 2:
            m.searchstudent(ID);
            d.findstudent(ID);
            d._Record(ID);
            break;
        case 3:
            cout << "gut";
            break;
        case 0:
            std::cout << "Wybrano wyjscie." << std::endl;
            return 0;
        default:
            std::cout << "Nieprawidlowa opcja." << std::endl;
            break;
        }
        std::cout << "Nacisnij Enter, aby wrócić do menu wyboru." << std::endl;
        std::cin.ignore();
        std::cin.get();
    }
    return 0;
}

