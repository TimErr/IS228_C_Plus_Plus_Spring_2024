#include <iostream>
using namespace std;


// inserts data into the array
void insertData(int* arr, int rows, int cols) {
    cout << "Enter " << rows * cols << " elements for the array:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Prompt the user to enter each element of the array
            cout << "Enter element at position [" << i << "][" << j << "]: ";
            cin >> *(arr + i * cols +j); // Read user input and store it in the array
        }
    }
}

// print the contents of the array
void printArray(int* arr, int rows, int cols) {
    cout << "Array contents:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Print each element of the array
            cout << *(arr + i * cols + j) << " ";
        }
        cout << endl; // Moving to the next line after printing each row
    }
}

int main() {
    const int ROWS = 3, COLS =3;
    int array[ROWS][COLS]; // Declaring a 3x3 array

    insertData(&array[0][0], ROWS,COLS); // Call insertData function to populate the array
    printArray(&array[0][0], ROWS, COLS); // Call printArray function to display the array

    return 0;
}
