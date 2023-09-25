//============================================================================
// Name        : Guessing-Number.cpp
// Author      : Dev Chugh
// Description : This is task 1 of my C++ Programming Internship at InternPe
//               for building a user input number guessing game
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    cout << "Welcome to the Number Guessing Game!" << endl;

	begin:                                      //GOTO statement to restart the game
    // Seed the random number generator with the current time
    srand((unsigned int)(time(NULL)));

    // Define the range of numbers
    int minNumber = 1;
    int maxNumber = 100;
    int targetNumber = rand() % (maxNumber - minNumber + 1) + minNumber;

    int guess;
    int attempts = 0;
    int reset = 0;

    cout << "I've selected a number between " << minNumber << " and " << maxNumber << ". Try to guess it." << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < minNumber || guess > maxNumber) {
            cout << "Please enter a valid number between " << minNumber << " and " << maxNumber << "." << endl;
        } else if (guess < targetNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > targetNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number " << targetNumber << " in " << attempts << " attempts." << endl;
        }
    } while (guess != targetNumber);

    cout <<"Would you like to reset the number and try again (Enter 1 to reset): ";
    cin >> reset;
    cout << endl << endl;

    if (reset == 1) {
    	goto begin;
    }
    else {
    	cout << "Exiting the Game." << endl << "Thank you for Playing";
    	exit(0);
    }

    return 0;
}

