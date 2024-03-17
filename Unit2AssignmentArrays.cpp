#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

// Function to insert data into the array
void insertData(int arr[][COLS]) {
    cout << "Enter " << ROWS * COLS << " elements for the array:" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            // Prompting the user to enter each element of the array
            cout << "Enter element at position [" << i << "][" << j << "]: ";
            cin >> arr[i][j]; // Reading user input and storing it in the array
        }
    }
}

// Function to print the contents of the array
void printArray(int arr[][COLS]) {
    cout << "Array contents:" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            // Printing each element of the array
            cout << arr[i][j] << " ";
        }
        cout << endl; // Moving to the next line after printing each row
    }
}

int main() {
    int array[ROWS][COLS]; // Declaring a 3x3 array

    insertData(array); // Calling insertData function to populate the array
    printArray(array); // Calling printArray function to display the array

    return 0;
}
