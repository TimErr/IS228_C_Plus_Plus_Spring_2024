#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class GuessingGame {
private:
    int secretNumber;
    int attemptsLeft;

public:
    GuessingGame() {
        srand(time(0)); // Seed the random number generator using the current time from the local machine
        resetGame();
    }

    //resetGame is used to reset attempts left and start with a new secret number
    void resetGame() { 
        secretNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
        attemptsLeft = 5; // Player has 5 attempts by default
    }

    //play is the processing of the game
    void play() {
        cout << "Welcome to the Guessing Game!" << endl;
        cout << "Try to guess a number between 1 and 100." << endl;
        
        int attempts = 0;
        int guess;

        //Game Loop
         
        while (attemptsLeft > 0) {
            cout << "Attempts left: " << attemptsLeft << endl;
            cout << "Enter your guess: ";
            attempts++;
            cin >> guess;

            if (guess < secretNumber) { //if guess is too low, guess again
                 cout << "Too low! Try again." << endl;
            } else if (guess > secretNumber) { //if guess is too high, guess agian
                cout << "Too high! Try again." << endl;
            } else { //correct guess, display secret number and number of attempts
                cout << "Congratulations! You've guessed the number " << secretNumber << " in " << attempts << " attempts!" << endl;
                return;
            }
            attemptsLeft--;
            }

        if (attemptsLeft == 0) //all attempts used, let user know the secretNumber
            cout << "Sorry, you've run out of attempts.The correct number was " << secretNumber <<"."<<endl;
         
    }

    //playAgain allows user to decide to play another round
    bool playAgain() {
        char choice;
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        return (choice == 'y' || choice == 'Y');
    }
    
};

int main() {
    GuessingGame game; //create a game using constructor
    //do while loop to continue playing game as long as playAgain is true
    do {
        game.play();
        game.resetGame();
    } while (game.playAgain());
    return 0;
}
