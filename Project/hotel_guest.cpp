#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // to use std::remove_if
#include <sstream> // for std::istringstream
#include <cctype> // for std::toupper
#include <stdexcept>

using namespace std;

// Define a structure to represent a guest
struct Guest {
    string firstName;
    string lastName;
    int roomNumber;
};

//Define a structure to represent a room
struct Room {
    int number;
    bool occupied;
};

// Function prototypes
void displayMenu();
void checkInGuest(vector<Guest> &guestList, vector<Room> &roomList);
void displayGuests(const vector<Guest> &guestList);
void checkoutGuest(vector<Guest> &guessList, vector<Room> &roomList);
void viewRoomStatus(vector<Room> &roomList);

bool isNumber(const string& s);


int main() {
    vector<Guest> guestList; // Vector to store guests
    vector<Room> roomList; // Vector to store rooms

    //initialize rooms
    for (int i = 1001; i <= 1010; ++i) {
        roomList.push_back({i, false}); //initialze all rooms as vacant
    }

    //display menu and take user input to perform selected function
    string choice_str;
    int choice;
    do {
        displayMenu();
        cin >> choice_str;

        //checks that a number is entered, if letter(s) are entered gives user message
        if(!isNumber(choice_str)) {
            cout << " Invalid Input. Please enter a number.\n";
            continue;
        }

        choice = stoi(choice_str);
        switch (choice) {
            case 1:
                //add guests to the guessList
                checkInGuest(guestList, roomList);
                break;
            case 2:
                //display all guests and their room number
                displayGuests(guestList);
                break;
            case 3:
                //remove guest from GuestList
                checkoutGuest(guestList, roomList);
                break;
            case 4:
                // 
                viewRoomStatus(roomList);
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

//display "menu" for user to make selection
void displayMenu() {
    cout << "\nHotel Management System Menu\n";
    cout << "1. Check in guest\n";
    cout << "2. Display all guests\n";
    cout << "3. Check out guest\n";
    cout << "4. View room status\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

//checks guest in and adds to guestList
void checkInGuest(vector<Guest> &guestList, vector<Room> &roomList) {
   
        Guest newGuest;
        cout << "Enter first and last name of guest: ";
        cin >> newGuest.firstName >> newGuest.lastName;
        //convert user input for guest firstName and lastName to upper case
        transform(newGuest.lastName.begin(), newGuest.lastName.end(), newGuest.lastName.begin(), ::toupper);
        transform(newGuest.firstName.begin(), newGuest.firstName.end(), newGuest.firstName.begin(), ::toupper);

        //Display available rooms
        cout <<"Available rooms:\n";
        for( const auto &room : roomList) {
            if(!room.occupied) {
                cout << room.number << " ";
            }
        }
   
        cout << endl;

        bool roomFound = false;
        do {
            try {
                cout << "Enter room number: ";
                cin >> newGuest.roomNumber;

                // Check if the room number is within the valid range
                if (newGuest.roomNumber < 1001 || newGuest.roomNumber > 1010) {
                    throw out_of_range("Invalid room number. Room number should be between 1001 and 1010.");
                }

                // Check if room is available
                for (auto &room : roomList) {
                    if (room.number == newGuest.roomNumber && !room.occupied) {
                        room.occupied = true;
                        roomFound = true;
                        break;
                    }
                }

                if (!roomFound) {
                    cout << "Room " << newGuest.roomNumber << " is occupied. Please enter a vacant room number.\n";
                }
            } catch (const exception &e) {
            cerr << "Exception caught: " << e.what() << endl;
            continue;
            }
        } while (!roomFound);

    // Add the guest to the guestList
    guestList.push_back(newGuest);
    cout << newGuest.firstName << " " << newGuest.lastName << " checked in successfully to room number " << newGuest.roomNumber << ".\n";
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

//checkoutGuest from the guestList searching by firstName and lastName or by room number
void checkoutGuest(vector<Guest> &guestList, vector<Room> &roomList) {
    if(guestList.empty()) {
        cout << "No guests to remove.\n";
        return;
    }

    //ask user if they wish to check out guest by name or room number
    char choice;
    cout << "Do you want to check out guest by name (N) or by room number (R)? ";
    cin >> choice;
    
    if (choice == 'N' || choice == 'n') {
        string firstName, lastName;
        int roomNumber;
        cout <<"Enter firstname and lastname of the guest to check out: ";
        cin >> firstName >> lastName;
        
        transform(firstName.begin(), firstName.end(),firstName.begin(), ::toupper);
        transform(lastName.begin(), lastName.end(),lastName.begin(), ::toupper);

        auto it = remove_if(guestList.begin(), guestList.end(),[&](const Guest &guest) {
            return guest.firstName == firstName && guest.lastName == lastName, roomNumber = guest.roomNumber;
        });

    
        if (it != guestList.end()) {
            cout << "Guest found.\n";
            int roomNumber = it->roomNumber;
            // Mark the associated room as vacant
            for (auto &room : roomList) {
                if (room.number == roomNumber) {
                    cout << "Room number to vacate: " << roomNumber << endl;
                    room.occupied = false;
                    break;
                }
            }
            guestList.erase(it);
            cout << firstName << " " << lastName << " checked out Successfully.\n";
        } else {
            cout << "Guest not found.\n";
        }
    } else if (choice == 'R' || choice == 'r') {
        int roomNumber;
        cout << "Enter room number of the guest to check out: ";
        cin >> roomNumber;

        auto it = remove_if(guestList.begin(), guestList.end(), [&](const Guest &guest) {
            return guest.roomNumber == roomNumber;
        });

        if (it != guestList.end()) {
            // Mark the room as vacant
            for (auto &room : roomList) {
                if (room.number == roomNumber) {
                    room.occupied = false; // Mark the room as vacant
                    break;
                }
            }

            guestList.erase(it);
            cout <<"Room " << it->roomNumber <<" checked out successfully.\n";
        } else {
            cout << "No guest found in room " << roomNumber << ".\n";
        }
    } else {
        cout << "Invalid choice.\n";
    }    
}

//viewRoomStatus to view which rooms are occupied or vacant.
void viewRoomStatus(vector<Room> &roomList) {
    cout<<"Room Status:\n";
    for (const auto &room : roomList) {
        cout << "Room " << room.number << ": " << (room.occupied ? "Occupied" : "Vacant") << endl;
    }
}

//isNumber to check if user input for menu choice is of numeric value
bool isNumber(const string& s) {
    return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}   