#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    double totalFee;
    double paidFee;
};

// Global vector to store all student data
vector<Student> students;

// Step 2: Print Menu Header
void printHeader() {
    cout << "\n================================\n";
    cout << "     Fee Inquiry Management     ";
    cout << "\n================================\n";
}

// Step 3: Add Student Function
void addStudent() {
    Student s;
    cout << "\n--- Add New Student ---\n";
    cout << "Enter student ID: ";
    cin >> s.id;
    cout << "Enter student name: ";
    cin.ignore(); // clear input buffer
    getline(cin, s.name);
    cout << "Enter total fee amount: ";
    cin >> s.totalFee;
    s.paidFee = 0;
    students.push_back(s);
    cout << ">>> Student added successfully!\n";
}

// Step 4: Pay Fee Function
void payFee() {
    int id;
    cout << "\n--- Pay Fee ---\n";
    cout << "Enter student ID: ";
    cin >> id;

    bool found = false;
    for (auto &s : students) {
        if (s.id == id) {
            found = true;
            double amount;
            cout << "Enter amount to pay: ";
            cin >> amount;
            if (amount + s.paidFee > s.totalFee) {
                cout << "Error: Amount exceeds total fee.\n";
            } else {
                s.paidFee += amount;
                cout << ">>> Payment successful! Total paid: " << s.paidFee << " ₹\n";
            }
            break;
        }
    }
    if (!found) {
        cout << "Student ID not found.\n";
    }
}

// step 5
void showStatus() {
    cout << "\n--- Fee Status Report ---\n";
    cout << left << setw(5) << "ID"
         << setw(15) << "Name"
         << setw(15) << "Total Fee"
         << setw(10) << "Paid"
         << setw(10) << "Due"
         << setw(10) << "Status" << "\n";

    cout << string(65, '-') << "\n";

    for (const auto &s : students) {
        double due = s.totalFee - s.paidFee;
        cout << left << setw(5) << s.id
             << setw(15) << s.name
             << setw(13) << fixed << setprecision(2) << s.totalFee << " ₹"
             << setw(9) << fixed << setprecision(2) << s.paidFee << " ₹"
             << setw(9) << fixed << setprecision(2) << due << " ₹"
             << setw(10) << (due == 0 ? "Paid" : "Unpaid") << "\n";
    }

    cout << string(65, '-') << "\n";
}


// Step 6: Main Menu Loop
int main() {
    int choice;
    while (true) {
        printHeader();
        cout << "\n1. Add Student\n2. Pay Fee\n3. Show Fee Status\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            addStudent();
        } else if (choice == 2) {
            payFee();
        } else if (choice == 3) {
            showStatus();
        } else if (choice == 4) {
            cout << "\nThank you for using Fee Inquiry Management System!\nGoodbye!\n";
            break;
        } else {
            cout << "Invalid choice, try again.\n";
        }
    }
    return 0;
}
