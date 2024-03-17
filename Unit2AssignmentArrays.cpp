#include <iostream>
using namespace std;

//constants for number of Rows and Cols
const int ROWS = 3;
const int COLS = 3;

// inserts data into the array
void insertData(int arr[][COLS]) {
    cout << "Enter " << ROWS * COLS << " elements for the array:" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            // Prompt the user to enter each element of the array
            cout << "Enter element at position [" << i << "][" << j << "]: ";
            cin >> arr[i][j]; // Read user input and store it in the array
        }
    }
}

// print the contents of the array
void printArray(int arr[][COLS]) {
    cout << "Array contents:" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            // Print each element of the array
            cout << arr[i][j] << " ";
        }
        cout << endl; // Moving to the next line after printing each row
    }
}

int main() {
    int array[ROWS][COLS]; // Declaring a 3x3 array

    insertData(array); // Call insertData function to populate the array
    printArray(array); // Call printArray function to display the array

    return 0;
}
