// Step 1: Header files and namespace
#include <iostream>
#include <string>
using namespace std;

// Step 2: Ticket class
class Ticket
{
public:
    int pnr;
    string passengerName;
    string source;
    string destination;
    int seatNumber;

    // Step 3: Input function (for data entry)
    void input()
    {
        cout << "Enter Passenger Name: ";
        getline(cin, passengerName);
        cout << "Enter Source Station: ";
        getline(cin, source);
        cout << "Enter Destination Station: ";
        getline(cin, destination);
        cout << "Enter Seat Number: ";
        cin >> seatNumber;
        cin.ignore(); // Clear input buffer
    }

    // Step 4: Display function
    void display()
    {
        cout << "PNR: " << pnr
             << "\nName: " << passengerName
             << "\nFrom: " << source
             << "\nTo: " << destination
             << "\nSeat Number: " << seatNumber << "\n\n";
    }
};

// Step 5: Main function
int main()
{
    const int MAX_TICKET = 5;
    Ticket ticket[MAX_TICKET];
    int count = 0;
    int pnr_counter = 1001;

    cout<<"\n===== Welcome to Railway Reservation System =====\n\n";
    // Step 6: Infinite loop for menu
    while (true)
    {
        cout << "1. Book Ticket\n2. Show Tickets\n3. Exit\nChoice: ";
        int choice;
        cin >> choice;
        cin.ignore(); // Important for getline()

        // Step 7: Booking option
        if (choice == 1)
        {
            if (count == MAX_TICKET)
            {
                cout << "Sorry, booking full!\n";
                continue;
            }
            ticket[count].pnr = pnr_counter++;
            ticket[count].input();
            cout << "Ticket booked successfully! Your PNR is " << ticket[count].pnr << "\n\n";
            count++;
        }

        // Step 8: Show tickets
        else if (choice == 2)
        {
            if (count == 0)
            {
                cout << "No tickets booked yet.\n\n";
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    ticket[i].display();
                }
            }
        }

        // Step 9: Exit
        else if (choice == 3)
        {
            cout << "Exiting...\n";
            break;
        }

        // Invalid choice
        else
        {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
