Name Deng chol kon
Roll Number 202511436


#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the average of numbers in a vector
double calculateAverage(const vector<int>& numbers) {
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    return numbers.empty() ? 0 : static_cast<double>(sum) / numbers.size();
}

int main() {
    // Variables and data types
    string name;
    int choice;
    vector<int> scores;

    // Input
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "How many scores do you want to enter? ";
    int n;
    cin >> n;

    // Loop to collect scores
    for (int i = 0; i < n; i++) {
        int score;
        cout << "Enter score " << i + 1 << ": ";
        cin >> score;
        scores.push_back(score);
    }

    // Basic calculations
    double average = calculateAverage(scores);

    // Conditional statement
    if (average >= 50) {
        cout << name << ", you passed with an average of " << average << endl;
    } else {
        cout << name << ", you failed with an average of " << average << endl;
    }

    // Switch statement
    cout << "Choose a subject:
";
    cout << "1. Math
2. English
3. Science
";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "You selected Math." << endl;
            break;
        case 2:
            cout << "You selected English." << endl;
            break;
        case 3:
            cout << "You selected Science." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}
