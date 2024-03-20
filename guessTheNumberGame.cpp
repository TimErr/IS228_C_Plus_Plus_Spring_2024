#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Seed the random number generator using the current time from the local machine
    
    int secretNumber = rand() % 100 + 1; // Generate random number between 1 and 100
    int guess;
    int attempts = 0;
    const int maxAttempts = 10;
    bool gameover = false;

    cout << "Welcome to the Number Guessing Game!" << endl;

    // Game loop
    if (!gameover) {
        while (attempts < maxAttempts) {
            cout << "Enter your guess (between 1 and 100): ";
            cin >> guess;

            attempts++;
            
            if (guess < secretNumber) { //if guess is too low, guess again
                cout << "Too low! Try again." << endl;
            } else if (guess > secretNumber) { //if guess is too high, guess agian
                cout << "Too high! Try again." << endl;
            } else { //correct guess, display secret number and number of attempts
            cout << "Congratulations! You've guessed the number " << secretNumber << " in " << attempts << " attempts!" << endl;
            gameover = true;
            break; // Exit the loop
            }
            cout <<"You have " << maxAttempts - attempts << " attempts left." << endl;    
            
            if (attempts == maxAttempts)
                gameover = true;
            }
        }
    
    if(gameover) {
        cout << "Sorry, you've run out of attempts. The correct number was " << secretNumber << "." << endl;
    }
    return 0;
}
