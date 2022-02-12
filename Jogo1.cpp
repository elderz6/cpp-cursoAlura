#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main () {
    srand(time(0));
    const int secretNumber = rand() % 100;
    int tries = 0;
    double score = 1000.0;

    cout << "+++++ + +++++" << endl;
    cout << "   Game  1   " << endl;
    cout << "+++++ + +++++" << endl;

    cout << "Select a difficulty level: (H)ard (M)edium (E)asy" << endl;
    char level;
    cin >> level;

    int maxTries;
    if(level == 'M') maxTries = 10;
    else if(level == 'E') maxTries = 20;
    else maxTries = 5;

    for(tries = 1; tries <= maxTries; tries++){
        int numberIn;
        cout << "Guess a number" << endl;
        cin >> numberIn;

        double penalty = abs(numberIn - secretNumber)/2.0;
        score = score - penalty;
        cout << "You guessed: " << numberIn << endl;

        if(numberIn == secretNumber) {
            cout << "Game Over" << endl;
            cout.precision(2);
            cout << fixed;
            cout << "Score: " << score << endl;
            cout << "Guessed correctly in " << tries << " tries" << endl;
            break;
        }
        else if(numberIn > secretNumber) cout << "Your number is greater than the secret" << endl;
        else if(numberIn < secretNumber) cout << "Your number is smaller than the secret" << endl;
        if(tries == maxTries) {
            cout << "You lost!" << endl;
            cout << "The secret number was " << secretNumber << endl;
        }
    }
}