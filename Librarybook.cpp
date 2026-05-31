#include "LibraryBook.h"

// Initialize static constant
const double LibraryBook::FINE_PER_DAY = 0.50;

// Default constructor
LibraryBook::LibraryBook() {
    bookID = 0;
    title = "";
    author = "";
    borrowerName = "";
    daysBorrowed = 0;
    isBorrowed = false;
    cout << "Book object created (default constructor)" << endl;
}

// Parameterized constructor
LibraryBook::LibraryBook(int id, string t, string a) {
    bookID = id;
    title = t;
    author = a;
    borrowerName = "";
    daysBorrowed = 0;
    isBorrowed = false;
    cout << "Book object created (parameterized constructor) for: " << title << endl;
}

// Destructor
LibraryBook::~LibraryBook() {
    cout << "Book object destroyed: "" << title << "" (ID: " << bookID << ")" << endl;
}

// Getters
int LibraryBook::getBookID() const {
    return bookID;
}

string LibraryBook::getTitle() const {
    return title;
}

string LibraryBook::getAuthor() const {
    return author;
}

string LibraryBook::getBorrowerName() const {
    return borrowerName;
}

int LibraryBook::getDaysBorrowed() const {
    return daysBorrowed;
}

bool LibraryBook::getIsBorrowed() const {
    return isBorrowed;
}

// Setters
void LibraryBook::setBookID(int id) {
    bookID = id;
}

void LibraryBook::setTitle(string t) {
    title = t;
}

void LibraryBook::setAuthor(string a) {
    author = a;
}

void LibraryBook::setBorrowerName(string name) {
    borrowerName = name;
}

void LibraryBook::setDaysBorrowed(int days) {
    daysBorrowed = days;
}

void LibraryBook::setIsBorrowed(bool status) {
    isBorrowed = status;
}

// Borrow a book
void LibraryBook::borrowBook(string borrower) {
    if (!isBorrowed) {
        isBorrowed = true;
        borrowerName = borrower;
        daysBorrowed = 0;
        cout << "Book "" << title << "" borrowed by " << borrower << endl;
    } else {
        cout << "Book "" << title << "" is already borrowed!" << endl;
    }
}

// Return a book
void LibraryBook::returnBook() {
    if (isBorrowed) {
        cout << "Book "" << title << "" returned by " << borrowerName 
             << " after " << daysBorrowed << " days" << endl;
        isBorrowed = false;
        borrowerName = "";
        daysBorrowed = 0;
    } else {
        cout << "Book "" << title << "" was not borrowed!" << endl;
    }
}

// Calculate fine for overdue books
double LibraryBook::calculateFine() const {
    if (isBorrowed && isOverdue()) {
        return daysBorrowed * FINE_PER_DAY;
    }
    return 0.0;
}

// Check if book is overdue (assuming 14 days is the borrowing limit)
bool LibraryBook::isOverdue() const {
    return isBorrowed && (daysBorrowed > 14);
}

// Display book information
void LibraryBook::displayBook() const {
    cout << "========================================" << endl;
    cout << "Book ID: " << bookID << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Status: " << (isBorrowed ? "BORROWED" : "AVAILABLE") << endl;
    if (isBorrowed) {
        cout << "Borrower: " << borrowerName << endl;
        cout << "Days Borrowed: " << daysBorrowed << endl;
        if (isOverdue()) {
            cout << "OVERDUE! Fine: $" << calculateFine() << endl;
        }
    }
    cout << "========================================" << endl;
}
