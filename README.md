Name Deng chol kon 
Roll Number 202511436
#include <iostream>
using namespace std;

// Function to calculate and display result
void calculateResult(int english, int math, int science)
{
    int total = english + math + science;
    float average = total / 3.0;

    cout << "\n------ Student Result ------" << endl;
    cout << "Student Name : Deng" << endl;
    cout << "English      : " << english << endl;
    cout << "Math         : " << math << endl;
    cout << "Science      : " << science << endl;
    cout << "Total Marks  : " << total << endl;
    cout << "Average      : " << average << endl;

    if (average >= 50)
    {
        cout << "Result       : Passed" << endl;
    }
    else
    {
        cout << "Result       : Failed" << endl;
    }
}

int main()
{
    int english, math, science;

    // Input marks
    cout << "Enter marks for English: ";
    cin >> english;

    cout << "Enter marks for Math: ";
    cin >> math;

    cout << "Enter marks for Science: ";
    cin >> science;

    // Function call
    calculateResult(english, math, science);

    return 0;
}
