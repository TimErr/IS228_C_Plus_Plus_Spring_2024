#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a structure to represent a guest
struct Guest {
    string firstName;
    string lastName;
    int roomNumber;
};

// Function prototypes
void displayMenu();
void addGuest(vector<Guest> &guestList);
void displayGuests(const vector<Guest> &guestList);

int main() {
    vector<Guest> guestList; // Vector to store guests

    //display menu and take user input to perform selected function
    char choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case '1':
                //add guests to the guessList
                addGuest(guestList);
                break;
            case '2':
                //display all guests and their room number
                displayGuests(guestList);
                break;
            case '3':
                // Option to remove guest (to be implemented later)
                cout << "Option to remove guest will be implemented later.\n";
                break;
            case '4':
                // Option to manage rooms (to be implemented later)
                cout << "Option to manage rooms will be implemented later.\n";
                break;
            case '5':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '5');

    return 0;
}

//display "menu" for user to make selection
void displayMenu() {
    cout << "\nHotel Management System Menu\n";
    cout << "1. Add a guest\n";
    cout << "2. Display all guests\n";
    cout << "3. Remove a guest (to be implemented)\n";
    cout << "4. Manage rooms (to be implemented)\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

//adds guest to guestList
void addGuest(vector<Guest> &guestList) {
    Guest newGuest;
    cout << "Enter guest First Name: ";
    cin >> newGuest.firstName;
    cout << "Enter guest Last Name: ";
    cin >> newGuest.lastName;
    cout << "Enter room number: ";
    cin >> newGuest.roomNumber;

    guestList.push_back(newGuest);
    cout << "Guest added successfully.\n";
}

//reads and prints out each guest with their corresponding room number
void displayGuests(const vector<Guest> &guestList) {
    //if guestList is empty, alert user the list is empty
    if (guestList.empty()) {
        cout << "No guests to display.\n";
        return;
    }

    //iterate through guestList and print our each guest with thier room number
    cout << "List of guests:\n";
    for (const auto &guest : guestList) {
        cout << "Name: " << guest.firstName + " " + guest.lastName << ", Room Number: " << guest.roomNumber << endl;
    }
}