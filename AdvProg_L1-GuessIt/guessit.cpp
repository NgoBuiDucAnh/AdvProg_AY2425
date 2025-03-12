#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int generateRandomNumber() {
    return rand() % 100 + 1;
}

int getPlayerGuess() {
    int guess;
    cout << "Enter your guess (1-100): ";
    cin >> guess;
    while(guess < 1 || guess > 100) {
        cout << "The number you guessed is invalid." << "\n";
        cout << "Enter your guess (1-100): ";
        cin >> guess;
    }
    return guess;
}

string getAnswer(int number, int randomNumber) {
    if (number > randomNumber) 
        return "Your number is higher.";
     else if (number < randomNumber) 
        return "Your number is lower.";
    else 
        return "Congratulations! You win.";
}

bool checkSuccess(string answer) {
    return answer == "Congratulations! You win.";
}

bool checkContinuePlaying(char isContinued) {
    return isContinued == 'y' || isContinued == 'Y';
}

char getPlayerOpinion() {
    char isContinued;
    cout << "Do you want to play again? (y/n): ";
    cin >> isContinued;
    return isContinued;
}

void playGuessIt() {
    int randomNumber = generateRandomNumber();
    int number;
    string answer;
    
    do {
        number = getPlayerGuess();
        answer = getAnswer(number, randomNumber);
        cout << answer << endl;
    } while (!checkSuccess(answer));
}

int main() {
    srand(time(0));
    char isContinued;
    
    do {
        playGuessIt();
        isContinued = getPlayerOpinion();
    } 
    while (checkContinuePlaying(isContinued));
    
    cout << "Thanks for playing!" << endl;
    return 0;
}
