#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
using namespace std;

int main() {
    srand(time(0));               // seed the random number generator
    int number = rand() % 100 + 1; // random number between 1 and 100
    int guess;
    
    cout << "Guess the number between 1 and 100!\n";

    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess == number) {
            cout << "Congratulations! You guessed the number.\n";
            break;  // exit the loop if correct
        } 
        else if (guess < number) {
            cout << "Too low! Try again.\n";
        } 
        else {
            cout << "Too high! Try again.\n";
        }
    }

    return 0;
}
