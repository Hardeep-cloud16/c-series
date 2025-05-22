#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Step 2: Product Class
class product {
public:
    int id;
    string name;
    float price;
    int quantity;

    // Step 3: Input Function
    void input() {
        cout << "\n- - - Add New Product - - -\n";
        cout << "Enter Product ID        : ";
        cin >> id;
        cout << "Enter Product Name      : ";
        cin >> name;
        cout << "Enter Product Price     : ";
        cin >> price;
        cout << "Enter Product Quantity  : ";
        cin >> quantity;
    }

    // Step 4: Display Function
    void display() {
        cout << left << setw(10) << id
             << setw(15) << name
             << setw(10) << price
             << setw(10) << quantity
             << setw(10) << price * quantity << endl;
    }

    // Step 5: Get Total
    float getTotal() {
        return price * quantity;
    }
};

// Step 6: Main Function
int main() {
    product p[50];
    int count = 0, choice;

    do {
        cout << "\n=================================\n";
        cout << "Welcome to Grocery Store Management\n";
        cout << "=================================\n";
        cout << "1. Add Product\n";
        cout << "2. Show Bill\n";
        cout << "3. Exit\n";
        cout << "Enter Your Choice : ";
        cin >> choice;

        // Step 7: Add Product
        if (choice == 1) {
            p[count].input();
            count++;
            cout << "Product Added Successfully!\n";
        }

        // Step 8: Show Bill
        else if (choice == 2) {
            if (count == 0) {
                cout << "No product to display.\n";
            } else {
                float totalbill = 0;
                cout << left << setw(10) << "ID"
                     << setw(15) << "Name"
                     << setw(10) << "Price"
                     << setw(10) << "Qty"
                     << setw(10) << "Total" << endl;

                cout << "------------------------------------------------------------\n";

                for (int i = 0; i < count; i++) {
                    p[i].display();
                    totalbill += p[i].getTotal();
                }

                cout << "------------------------------------------------------------\n";
                cout << right << setw(40) << "Total Bill: $ " << totalbill << endl;
            }
        }

        // Step 9: Exit
        else if (choice == 3) {
            cout << "Thanks for shopping with us!\n";
        } else {
            cout << "Invalid Choice! Try again\n";
        }

    } while (choice != 3);

    return 0;
}
