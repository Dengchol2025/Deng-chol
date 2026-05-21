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

#include <iostream>
using namespace std;

// Functions
bool login();
void menu();
void deposit(double &balance);
void withdraw(double &balance);
void checkBalance(double balance);

int main()
{
    double balance = 1000;
    int choice;

    if (!login())
    {
        cout << "Too many attempts!";
        return 0;
    }

    do
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            checkBalance(balance);
            break;

        case 2:
            deposit(balance);
            break;

        case 3:
            withdraw(balance);
            break;

        case 4:
            cout << "Thank you!\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}

// Login Function
bool login()
{
    int pin = 1234, input, attempts = 0;

    while (attempts < 3)
    {
        cout << "Enter PIN: ";
        cin >> input;

        if (input == pin)
        {
            return true;
        }

        attempts++;
        cout << "Wrong PIN\n";
    }

    return false;
}

// Menu Function
void menu()
{
    cout << "\n--- ATM MENU ---\n";
    cout << "1. Check Balance\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Exit\n";
    cout << "Choose: ";
}

// Check Balance
void checkBalance(double balance)
{
    cout << "Balance: $" << balance << endl;
}

// Deposit Function
void deposit(double &balance)
{
    double amount;

    cout << "Enter amount: ";
    cin >> amount;

    balance += amount;

    cout << "Deposit Successful\n";
}

// Withdraw Function
void withdraw(double &balance)
{
    double amount;

    cout << "Enter amount: ";
    cin >> amount;

    if (amount <= balance)
    {
        balance -= amount;
        cout << "Withdrawal Successful\n";
    }
    else
    {
        cout << "Insufficient Balance\n";
    }
}
