Name Deng chol kon
Roll Number 202511436
#include <iostream>
using namespace std;

// Functions
void mainMenu();
void history();
void concepts();

int main()
{
    int choice;

    do
    {
        mainMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            history();
            break;

        case 2:
            concepts();
            break;

        case 3:
            cout << "Program Ended\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 3);

    return 0;
}

// Main Menu
void mainMenu()
{
    cout << "\n--- C++ BOOK SYSTEM ---\n";
    cout << "1. History of C++\n";
    cout << "2. Learn C++ Concepts\n";
    cout << "3. Exit\n";
    cout << "Choose: ";
}

// History Function
void history()
{
    cout << "\nC++ was developed by Bjarne Stroustrup.\n";
    cout << "It was created as an extension of C.\n";
}

// Concepts Function
void concepts()
{
    cout << "\nC++ Concepts:\n";
    cout << "- Data Types\n";
    cout << "- Control Flow\n";
    cout << "- Loops\n";
    cout << "- Arrays\n";
    cout << "- File Stream\n";
}
