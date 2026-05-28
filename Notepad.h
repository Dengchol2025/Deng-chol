#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <string>
using namespace std;

void writeFile(const string& filename, const string& text);
void readFile(const string& filename);
void appendFile(const string& filename, const string& text);

#endif
