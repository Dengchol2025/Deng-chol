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
