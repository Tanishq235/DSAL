#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string FILENAME = "students.txt";

void addStudent() {
    ofstream file(FILENAME, ios::app);
    string roll, name, division, address;
    cout << "Enter Roll Number: "; cin >> roll;
    cout << "Enter Name: "; cin >> name;
    cout << "Enter Division: "; cin >> division;
    cout << "Enter Address: "; cin >> address;
    file << roll << " " << name << " " << division << " " << address << "\n";
    file.close();
    cout << "Student added successfully!\n";
}

void deleteStudent() {
    ifstream file(FILENAME);
    ofstream temp("temp.txt");
    string roll, name, division, address, rollToDelete;
    bool found = false;
    cout << "Enter Roll Number to delete: "; cin >> rollToDelete;
    while (file >> roll >> name >> division >> address) {
        if (roll != rollToDelete)
            temp << roll << " " << name << " " << division << " " << address << "\n";
        else
            found = true;
    }
    file.close();
    temp.close();
    remove(FILENAME.c_str());
    rename("temp.txt", FILENAME.c_str());
    cout << (found ? "Student deleted successfully!\n" : "Student not found!\n");
}

void displayStudent() {
    ifstream file(FILENAME);
    string roll, name, division, address, rollToFind;
    bool found = false;
    cout << "Enter Roll Number to search: "; cin >> rollToFind;
    while (file >> roll >> name >> division >> address) {
        if (roll == rollToFind) {
            cout << "Roll Number: " << roll << "\nName: " << name << "\nDivision: " << division << "\nAddress: " << address << "\n";
            found = true;
            break;
        }
    }
    file.close();
    if (!found) cout << "Student not found!\n";
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Student\n2. Delete Student\n3. Display Student\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: displayStudent(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);
    return 0;
}
