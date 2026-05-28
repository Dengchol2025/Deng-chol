#include <iostream>
#include "notepad.h"

using namespace std;

int main() {
    int choice;
    string filename;
    string text;

    do {
        cout << "
===== Simple Notepad Application =====
";
        cout << "1. Create/Write a text file
";
        cout << "2. Read/Display file contents
";
        cout << "3. Append new text to a file
";
        cout << "4. Exit
";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter file name: ";
                getline(cin, filename);
                cout << "Enter text to write: ";
                getline(cin, text);
                writeFile(filename, text);
                break;

            case 2:
                cout << "Enter file name: ";
                getline(cin, filename);
                readFile(filename);
                break;

            case 3:
                cout << "Enter file name: ";
                getline(cin, filename);
                cout << "Enter text to append: ";
                getline(cin, text);
                appendFile(filename, text);
                break;

            case 4:
                cout << "Exiting program...
";
                break;

            default:
                cout << "Invalid choice. Try again.
";
        }
    } while (choice != 4);

    return 0;
}
