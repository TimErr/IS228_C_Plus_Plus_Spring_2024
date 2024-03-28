#include <iostream>


/*originally had this function coded as just an int, but in playing with the program, 
trying to do a factorial on any number above 12 gave garbage data. changed to an 
unsigned long long int to adjust for this. now it can do factorial up to 20*/

// Function to calculate factorial
unsigned long long int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
        
}

int main() {
    int num;
    std::cout << "Enter a number to find its factorial 0 to 20 only: ";//ask for user to input a number to get factorial
    std::cin >> num;    
    std::cout << "Factorial of " << num << " is: " << factorial(num) << std::endl; //output message and call function in same line
    return 0;
}
