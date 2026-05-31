#include "Functions.h"

// Global array of books and count
LibraryBook library[100];
int bookCount = 0;

// Initialize library with some books
void initializeLibrary() {
    bookCount = 0;
    // Add some sample books
    library[bookCount++] = LibraryBook(101, "C++ Programming", "Bjarne Stroustrup");
    library[bookCount++] = LibraryBook(102, "Data Structures", "Mark Allen Weiss");
    library[bookCount++] = LibraryBook(103, "Algorithms", "Thomas Cormen");
    library[bookCount++] = LibraryBook(104, "Operating Systems", "Abraham Silberschatz");
    library[bookCount++] = LibraryBook(105, "Database Systems", "Ramaswamy");
    cout << "Library initialized with 5 sample books." << endl;
}

// Add a new book
void addBook() {
    if (bookCount >= 100) {
        cout << "Library is full! Cannot add more books." << endl;
        return;
    }
    
    int id;
    string title, author;
    
    cout << "
--- Add New Book ---" << endl;
    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Book Title: ";
    getline(cin, title);
    cout << "Enter Author Name: ";
    getline(cin, author);
    
    library[bookCount++] = LibraryBook(id, title, author);
    cout << "Book added successfully!" << endl;
}

// Display all books
void displayBooks() {
    cout << "
--- All Books in Library ---" << endl;
    if (bookCount == 0) {
        cout << "No books in the library." << endl;
        return;
    }
    
    for (int i = 0; i < bookCount; i++) {
        library[i].displayBook();
    }
}

// Search book by ID
void searchBook() {
    int id;
    cout << "
--- Search Book by ID ---" << endl;
    cout << "Enter Book ID: ";
    cin >> id;
    
    for (int i = 0; i < bookCount; i++) {
        if (library[i].getBookID() == id) {
            cout << "
Book found!" << endl;
            library[i].displayBook();
            return;
        }
    }
    
    cout << "Book with ID " << id << " not found!" << endl;
}

// Borrow book menu
void borrowBookMenu() {
    int id;
    string borrower;
    
    cout << "
--- Borrow Book ---" << endl;
    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Borrower Name: ";
    getline(cin, borrower);
    
    for (int i = 0; i < bookCount; i++) {
        if (library[i].getBookID() == id) {
            library[i].borrowBook(borrower);
            return;
        }
    }
    
    cout << "Book with ID " << id << " not found!" << endl;
}

// Return book menu
void returnBookMenu() {
    int id;
    int days;
    
    cout << "
--- Return Book ---" << endl;
    cout << "Enter Book ID: ";
    cin >> id;
    
    for (int i = 0; i < bookCount; i++) {
        if (library[i].getBookID() == id) {
            if (library[i].getIsBorrowed()) {
                cout << "Enter number of days borrowed: ";
                cin >> days;
                library[i].setDaysBorrowed(days);
                library[i].returnBook();
                
                if (library[i].isOverdue()) {
                    cout << "This book is OVERDUE! Fine: $" << library[i].calculateFine() << endl;
                }
            } else {
                cout << "This book was not borrowed!" << endl;
            }
            return;
        }
    }
    
    cout << "Book with ID " << id << " not found!" << endl;
}

// Display overdue books
void displayOverdueBooks() {
    cout << "
--- Overdue Books ---" << endl;
    bool found = false;
    
    for (int i = 0; i < bookCount; i++) {
        if (library[i].isOverdue()) {
            library[i].displayBook();
            found = true;
        }
    }
    
    if (!found) {
        cout << "No overdue books found." << endl;
    }
}

// Calculate total fines
void calculateTotalFines() {
    double totalFine = 0.0;
    int overdueCount = 0;
    
    cout << "
--- Total Fines Calculation ---" << endl;
    
    for (int i = 0; i < bookCount; i++) {
        if (library[i].isOverdue()) {
            totalFine += library[i].calculateFine();
            overdueCount++;
            cout << """ << library[i].getTitle() << "" (ID: " 
                 << library[i].getBookID() << "): $" << library[i].calculateFine() << endl;
        }
    }
    
    cout << "
Total Overdue Books: " << overdueCount << endl;
    cout << "Total Fines: $" << totalFine << endl;
}
