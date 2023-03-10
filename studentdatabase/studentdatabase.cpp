#include <iostream>
#include "Student.h"
#include "menu.h"

using namespace std;

int main()
{
    Student s;
    menu m;
    int ID;
    string name;
    string lastName;
    int age;
    int option;

    while (true) {
        m.initmenu("dodaj studenta", "aktulalizuj studenta", "usun studenta");
        option = m.option();
        switch (option) {
        case 1:
            m.getinformation(name, lastName, age);
            break;
        case 2:
            cout << "gut";
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

