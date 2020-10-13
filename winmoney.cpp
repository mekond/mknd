#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int moneyLost = 0;
    srand(time(nullptr));
    int number = rand() % 1000001;
    string choose;
    string stringValue;
    int guess = -1;

    cout << "Want to win a million dollars?\nIf so, guess the winning number (a number between 0 and 100000).\n";

    do {
        cout << "Insert $1.00 and enter your number or 'q' to quit:\n";
        cin >> stringValue;
        istringstream(stringValue) >> guess;
        cout << guess << "\n";
        if (stringValue == "q"){
            cout << "You lost $" << moneyLost << ". Thanks for playing. Come again!";
            return EXIT_SUCCESS;
        } else if (guess == 0){
            cout << "invalid input, exiting." << endl;
            return 0;
        }
        else {
        if (guess < number) {
            cout << "Sorry, good guess, but not quite right. Do you want me to give you a hint (y|n)?\n";
            cin >> choose;
            guess = 0;
            moneyLost += 1;
            if (choose == "y"){
                cout << "Your number is too low!\n";
                moneyLost += 2;
            } else if ( choose == "n"){}
            else{
                cout << "****WRONG INPUT EXITING****" << endl;
                return 0;
            }
        }
        else if (guess > number){
            cout << "Sorry, good guess, but not quite right. Do you want me to give you a hint (y|n)?\n";
            cin >> choose;
            moneyLost += 1;
            guess = 0;
            if (choose == "y"){
                cout << "Your number is too high!\n";
                moneyLost += 2;
            } else if ( choose == "n"){}
            else{
                cout << "****WRONG INPUT EXITING****" << endl;
                return 0;
            }
        }

        else{
            cout << "YOU WIN!" << endl;
        }
        }
        } while (number != guess);

    return EXIT_SUCCESS;
    }
