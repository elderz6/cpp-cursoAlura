#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;

void printHeader(){
    cout << "+++++ + +++++" << endl;
    cout << "   Game  2   " << endl;
    cout << "+++++ + +++++" << endl;
    cout << endl;
}

bool containsLetter(char letter, string secretWord){
    for(char contains : secretWord){
        if(contains == letter) return true;
    }
    return false;
}

void printLetters(string secretWord, map<char, bool> correctPositions){
    for(char letter : secretWord){
        if(correctPositions[letter]) cout << letter << " ";
        else cout << "_ ";
    }
    cout << endl;
}

void printMistakes(map<char, bool> mistakes){
    if(mistakes.empty()) return;
    else{
        cout << "Mistakes: ";
        for(auto item : mistakes){
            cout << item.first << " ";
        }
    }
    cout << endl;
}

void printChar(int tries){
    if(tries == 1) {
        cout << "  O  " << endl;
    }
    if(tries == 2) {
        cout << "  O  " << endl;
        cout << "  0  " << endl;
    }
    if(tries == 3){
        cout << "  O  " << endl;
        cout << "--0  " << endl;
        cout << "     " << endl;
    }
    if(tries == 4){
        cout << "  O  " << endl;
        cout << "--0--" << endl;
        cout << "     " << endl;
    }
    if(tries == 5){
        cout << "  O  " << endl;
        cout << "--0--" << endl;
        cout << " /   " << endl;
    }
    if(tries == 6){
        cout << "  O  " << endl;
        cout << "--0--" << endl;
        cout << " / \\ " << endl;
        cout << "Game over!" << endl;
    }
}

char getInput(){
    cout << "Guess a letter: ";
    char letterIn;
    cin >> letterIn;
    letterIn = toupper(letterIn);
    cout << endl;
    return letterIn;
}

string readFile(){
    ifstream file("./dict.txt");
    if(!file.is_open()){
        cout << "Error opening file" << endl;
        exit(0);
    }

    int len;
    file >> len;
    srand(time(0));
    int sort = rand() % len;
    string word;
    for(int i = 0; i < len; i++){
        string newWord;
        file >> newWord;
        if(i == sort){
            word = newWord;
            break;
        }
    }
    file.close();
    return word;
}

void addNewWord(){
    cout << "Do you want to add a new word? (Y/N)" << endl;
    
    char want;
    cin >> want;
    want = toupper(want);
    if(want != 'Y') exit(0);

    ofstream file("./dict.txt", ios::app);
    if(!file.is_open()){
        cout << "Error opening file" << endl;
        exit(0);
    }
    cout << "Enter a new word: ";
    string newWord;
    cin >> newWord;
    transform(newWord.begin(), newWord.end(), newWord.begin(), ::toupper);

    file << endl << newWord;
    file.close();
}

bool continueGame(string secretWord, map<char, bool> correctPositions){
    for(char letter : secretWord){
        if(!correctPositions[letter]) return true;
    }
    cout << endl << "You Won!" << endl;
    cout << "The word was " << secretWord << endl;
    addNewWord();
    return false;
}

int main(){
    string secretWord = readFile();;
    map<char, bool> correctPositions;
    map<char, bool> mistakes;
    bool notFullWord = true;
    bool notMaxTries = true;
    int tries = 0;

    printHeader();

    while(notFullWord && notMaxTries){
        printMistakes(mistakes);
        printLetters(secretWord, correctPositions);
        char letterIn = getInput();
       
        if(containsLetter(letterIn, secretWord)){
            correctPositions[letterIn] = true;
            cout << "Correct!" << endl;
            notFullWord = continueGame(secretWord, correctPositions);
        }
        else {
            mistakes[letterIn] = true;
            tries++;
            printChar(tries);
            if(tries == 6) notMaxTries = false;
        }
    }
}