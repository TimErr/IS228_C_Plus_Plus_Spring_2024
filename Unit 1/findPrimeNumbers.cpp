#include <iostream>

using namespace std;

int main() {
    int lowerLimit, upperLimit;
    cout << "Enter lower limit of range: ";
    cin >> lowerLimit;
    cout << "Enter upper limit of range: ";
    cin >> upperLimit;

    cout << "Prime numbers between "  << lowerLimit << " and " << upperLimit << " are: ";
    for (int num = lowerLimit; num <= upperLimit; ++num) {
        bool isPrime = true;

        // Check if num is prime
        for (int i = 2; i <= num / 2; ++i) {
            if (num % i == 0) {
                isPrime = false;
                break; // If num is divisible by any number other than 1 and itself, it's not prime
            }
        }

        // If num is prime, print it
        if (isPrime && num != 1) {
            cout << num << " ";
        }
    }

    cout << endl;

    return 0;
}