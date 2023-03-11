#include "database.h"



void database::saveinformation(int &inf, string &inf2, string &inf3, int &inf4)
{
    if (inf == 0) {
        inf = 1;
    }

    ofstream file_obj;
    file_obj.open("Input.txt", ios::app);

    file_obj << inf << ";" << inf2 << ";" << inf3 << ";" << inf4 << "\n";

    file_obj.close();
}

int database::lastid()
{

		int last_id = 0;
		string line;
		ifstream file("Input.txt");

		if (file.is_open())
		{
			while (getline(file, line))
			{
				// dzielimy wiersz na pola, korzystaj¹c z separatora ";"
				string id_str = line.substr(0, line.find(';'));
				int id = stoi(id_str);
				// jeœli ID jest wiêksze ni¿ poprzednie, to aktualizujemy wartoœæ last_id
				if (id > last_id)
				{
					last_id = id;
				}
				else
				{
					last_id = 0;
				}
			}
			file.close();

			return last_id;
		}
	
}

int database::findstudent(int &inf)
{
    std::ifstream inputFile("Input.txt"); // otwieramy plik wejœciowy
    std::string line;
    while (std::getline(inputFile, line)) { // czytamy plik linia po linii
        int id;
        std::string name, lastname;
        int age;
        char delimiter;
        std::istringstream iss(line);
        iss >> id >> delimiter; // odczytujemy ID i separator
        std::getline(iss, name, ';'); // odczytujemy name do pierwszego œrednika
        std::getline(iss, lastname, ';'); // odczytujemy lastname do drugiego œrednika
        iss >> age; // odczytujemy age
        if (id == inf) { // jeœli ID jest równe 5, to wypisujemy poszczególne pola z odpowiednimi etykietami
            std::cout << "ID: " << id << std::endl;
            std::cout << "Name: " << name << std::endl;
            std::cout << "Lastname: " << lastname << std::endl;
            std::cout << "Age: " << age << std::endl;
            break; // przerywamy pêtlê, bo ju¿ znaleŸliœmy szukan¹ linijkê
        }
    }
    inputFile.close(); // zamykamy plik wejœciowy
    return 0;
}

struct Record {
    int id;
    string name;
    string lastname;
    int age;
};

vector<Record> readRecords(string filename)
{
    vector<Record> records;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string field;
            Record record;
            getline(ss, field, ';');
            record.id = stoi(field);
            getline(ss, field, ';');
            record.name = field;
            getline(ss, field, ';');
            record.lastname = field;
            getline(ss, field);
            record.age = stoi(field);
            records.push_back(record);
        }
        file.close();
    }
    else {
        cout << "Unable to open file: " << filename << endl;
    }
    return records;
}

void editRecord(int id, string filename)
{
    ifstream fileIn(filename);
    ofstream fileOut("temp.txt");

    if (fileIn.is_open() && fileOut.is_open()) {
        string line;
        while (getline(fileIn, line)) {
            stringstream ss(line);
            string field;
            Record record;
            getline(ss, field, ';');
            record.id = stoi(field);
            getline(ss, field, ';');
            record.name = field;
            getline(ss, field, ';');
            record.lastname = field;
            getline(ss, field);
            record.age = stoi(field);
            if (record.id == id) {
                string name, lastname, age;
                cout << "Enter new name: ";
                getline(cin, name);
                cout << "Enter new lastname: ";
                getline(cin, lastname);
                cout << "Enter new age: ";
                getline(cin, age);
                record.name = name;
                record.lastname = lastname;
                record.age = stoi(age);
                fileOut << record.id << ";" << record.name << ";" << record.lastname << ";" << record.age << endl;
            }
            else {
                fileOut << line << endl;
            }
        }
        fileIn.close();
        fileOut.close();

        // Renaming temp.txt to filename
        if (remove(filename.c_str()) != 0) {
            cout << "Error deleting file: " << filename << endl;
        }
        if (rename("temp.txt", filename.c_str()) != 0) {
            cout << "Error renaming file: " << "temp.txt" << " to " << filename << endl;
        }
    }
    else {
        cout << "Unable to open file: " << filename << endl;
    }
}

void printRecord(Record record) {
    cout << "ID: " << record.id << endl;
    cout << "Name: " << record.name << endl;
    cout << "Lastname: " << record.lastname << endl;
    cout << "Age: " << record.age << endl;
}

void _Record(int ID)
{
    vector<Record> records = readRecords("Input.txt");
    for (Record record : records) {
        if (record.id == ID) {
            printRecord(record);
            editRecord(record.id, "Input.txt");
            break;
        }
    }
}
