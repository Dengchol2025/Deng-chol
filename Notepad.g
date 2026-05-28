#include <iostream>
#include <fstream>
#include "notepad.h"

using namespace std;

void writeFile(const string& filename, const string& text) {
    ofstream file(filename);
    if (file.is_open()) {
        file << text << endl;
        file.close();
        cout << "File saved successfully.
";
    } else {
        cout << "Could not create file.
";
    }
}

void readFile(const string& filename) {
    ifstream file(filename);
    string line;

    if (file.is_open()) {
        cout << "
--- File Contents ---
";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Could not open file.
";
    }
}

void appendFile(const string& filename, const string& text) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << text << endl;
        file.close();
        cout << "Text appended successfully.
";
    } else {
        cout << "Could not open file.
";
    }
}
