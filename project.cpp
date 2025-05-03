// ===========================================📚 Library Management System=========================
// ===========================================📚 Library Management System=========================
#include<iostream>
#include<string>
using namespace std;

struct Book {
    int bookID;
    string title;
    string author;
    int quantity;
};

// Function Declarations
void addBook(Book library[], int &count);
void displayBooks(const Book library[], int count);
void searchBook(const Book library[], int count);
void updateBook(Book library[], int count);
void deleteBook(Book library[], int &count);

int main() {
    const int maxBook = 100;
    Book library[maxBook];
    int count = 0;
    int choice;

    cout << "===== Welcome to Library Management System =====\n";

    do {
        cout << "\nMenu:\n";
        cout << "1. Add New Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Update Book Information\n";
        cout << "5. Delete Book\n";
        cout << "6. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(library, count); break;
            case 2: displayBooks(library, count); break;
            case 3: searchBook(library, count); break;
            case 4: updateBook(library, count); break;
            case 5: deleteBook(library, count); break;
            case 6: cout << "Exiting the system. Goodbye!\n"; break;
            default: cout << "Invalid choice. Please try again.\n"; break;
        }
    } while (choice != 6);

    return 0;
}

// Function to Add New Book
void addBook(Book library[], int &count) {
    cout << "Enter Book ID: ";
    cin >> library[count].bookID;
    cin.ignore(); // Clears newline after integer input

    cout << "Enter Book Title: ";
    getline(cin, library[count].title);

    cout << "Enter Author Name: ";
    getline(cin, library[count].author);

    cout << "Enter Quantity: ";
    cin >> library[count].quantity;

    cout << "Book Added Successfully!\n";
    count++;
}

// Function to Display All Books
void displayBooks(const Book library[], int count) {
    if (count == 0) {
        cout << "\nNo books available.\n";
        return;
    }

    cout << "\nList of Books:\n";
    for (int i = 0; i < count; i++) {
        cout << "-----------------------------\n";
        cout << "Book ID   : " << library[i].bookID << endl;
        cout << "Title     : " << library[i].title << endl;
        cout << "Author    : " << library[i].author << endl;
        cout << "Quantity  : " << library[i].quantity << endl;
    }
}

// Function to Search Book
void searchBook(const Book library[], int count) {
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (library[i].bookID == id) {
            cout << "Book Found!\n";
            cout << "Title    : " << library[i].title << endl;
            cout << "Author   : " << library[i].author << endl;
            cout << "Quantity : " << library[i].quantity << endl;
            return;
        }
    }

    cout << "Book not found.\n";
}

// Function to Update Book
void updateBook(Book library[], int count) {
    int id;
    cout << "Enter Book ID to update: ";
    cin >> id;
    cin.ignore();

    for (int i = 0; i < count; i++) {
        if (library[i].bookID == id) {
            cout << "Enter new Title: ";
            getline(cin, library[i].title);

            cout << "Enter new Author: ";
            getline(cin, library[i].author);

            cout << "Enter new Quantity: ";
            cin >> library[i].quantity;

            cout << "Book Information Updated Successfully!\n";
            return;
        }
    }

    cout << "Book not found.\n";
}

// Function to Delete Book
void deleteBook(Book library[], int &count) {
    int id;
    cout << "Enter Book ID to delete: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (library[i].bookID == id) {
            for (int j = i; j < count - 1; j++) {
                library[j] = library[j + 1];
            }
            count--;
            cout << "Book Deleted Successfully!\n";
            return;
        }
    }

    cout << "Book not found.\n";
}

