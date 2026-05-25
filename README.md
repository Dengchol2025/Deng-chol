Name Deng chol kon 
Roll Number 202511436
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Structure definition
struct Student
{
    int id;
    string name;
    int age;
    string course;
};

// Global array and counter
Student students[100];
int countStudents = 0;

// Random names and courses
string randomNames[] = {"John", "Alice", "David", "Emma", "Brian"};
string randomCourses[] = {"Computer Science", "Mathematics", "Engineering", "Business", "Medicine"};

// Function to add student
void addStudent()
{
    int choice;

    cout << "\n1. Enter Student Manually";
    cout << "\n2. Generate Random Student";
    cout << "\nChoose option: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "\nEnter Student ID: ";
        cin >> students[countStudents].id;

        cin.ignore();

        cout << "Enter Student Name: ";
        getline(cin, students[countStudents].name);

        cout << "Enter Student Age: ";
        cin >> students[countStudents].age;

        cin.ignore();

        cout << "Enter Course: ";
        getline(cin, students[countStudents].course);
    }
    else
    {
        students[countStudents].id = rand() % 900 + 100;
        students[countStudents].name = randomNames[rand() % 5];
        students[countStudents].age = rand() % 10 + 18;
        students[countStudents].course = randomCourses[rand() % 5];

        cout << "\nRandom Student Generated Successfully.\n";
    }

    countStudents++;
}

// Function to display students
void displayStudents()
{
    if (countStudents == 0)
    {
        cout << "\nNo students found.\n";
        return;
    }

    cout << "\n===== STUDENT LIST =====\n";

    for (int i = 0; i < countStudents; i++)
    {
        cout << "\nStudent " << i + 1 << endl;
        cout << "ID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Course: " << students[i].course << endl;
    }
}

// Function to search student
void searchStudent()
{
    int id;
    bool found = false;

    cout << "\nEnter Student ID to search: ";
    cin >> id;

    for (int i = 0; i < countStudents; i++)
    {
        if (students[i].id == id)
        {
            cout << "\nStudent Found:\n";
            cout << "ID: " << students[i].id << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Course: " << students[i].course << endl;

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Student not found.\n";
    }
}

// Function to update student
void updateStudent()
{
    int id;
    bool found = false;

    cout << "\nEnter Student ID to update: ";
    cin >> id;

    for (int i = 0; i < countStudents; i++)
    {
        if (students[i].id == id)
        {
            cin.ignore();

            cout << "Enter New Name: ";
            getline(cin, students[i].name);

            cout << "Enter New Age: ";
            cin >> students[i].age;

            cin.ignore();

            cout << "Enter New Course: ";
            getline(cin, students[i].course);

            cout << "Student updated successfully.\n";

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Student not found.\n";
    }
}

// Function to delete student
void deleteStudent()
{
    int id;
    bool found = false;

    cout << "\nEnter Student ID to delete: ";
    cin >> id;

    for (int i = 0; i < countStudents; i++)
    {
        if (students[i].id == id)
        {
            for (int j = i; j < countStudents - 1; j++)
            {
                students[j] = students[j + 1];
            }

            countStudents--;

            cout << "Student deleted successfully.\n";

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Student not found.\n";
    }
}

// Main function
int main()
{
    srand(time(0));

    int choice;

    do
    {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "\nInvalid choice.";
                cout << "\nRandom Number: " << rand() % 100;
                cout << "\nRandom Name: " << randomNames[rand() % 5] << endl;
        }

    } while (choice != 6);

    return 0;
}
