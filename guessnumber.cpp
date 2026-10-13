#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));             
    int number = rand() % 100 + 1; 
    int guess;

    cout << "Guess the number (1-100): ";

    while (true) {
        cin >> guess;
        if (guess < number)
            cout << "Too low! Try again: ";
        else if (guess > number)
            cout << "Too high! Try again: ";
        else {
            cout << "Correct! The number was " << number << endl;
            break;
        }
    }
    return 0;
}
