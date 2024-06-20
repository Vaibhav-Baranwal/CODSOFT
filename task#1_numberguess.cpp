#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
    // Initialize random seed
    srand(static_cast<unsigned>(time(0)));

    // Generate random number between 1 and 100
    int randomNumber = 1 + rand() % 100;
    int userGuess;

    cout << "Guess the number between 1 and 100!" << endl;

    do
    {
        cout << "Enter your guess: ";
        cin >> userGuess;

        if (userGuess > randomNumber)
        {
            cout << "Too high!" << endl;
        }
        else if (userGuess < randomNumber)
        {
            cout << "Too low!" << endl;
        }

    } while (userGuess != randomNumber);

    cout << "Congratulations! You guessed the right number." << endl;

    return 0;
}