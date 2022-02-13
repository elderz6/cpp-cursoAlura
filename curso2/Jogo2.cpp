#include<iostream>
#include<string>
#include<map>
#include "./interfaces/readFile.hpp"
#include "./interfaces/printHeader.hpp"
#include "./interfaces/printMistakes.hpp"
#include "./interfaces/printLetters.hpp"
#include "./interfaces/getInput.hpp"
#include "./interfaces/containsLetter.hpp"
#include "./interfaces/continueGame.hpp"
#include "./interfaces/printChar.hpp"

int main(){
    static const std::string secretWord = readFile();;
    static std::map<char, bool> correctPositions;
    static std::map<char, bool> mistakes;
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
            std::cout << "Correct!" << std::endl;
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