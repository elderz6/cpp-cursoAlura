#include<iostream>
#include "./interfaces/continueGame.hpp"
#include "./interfaces/addNewWord.hpp"

bool continueGame(std::string secretWord, std::map<char, bool> correctPositions){
    for(char letter : secretWord){
        if(!correctPositions[letter]) return true;
    }
    std::cout << std::endl << "You Won!" << std::endl;
    std::cout << "The word was " << secretWord << std::endl;
    addNewWord();
    return false;
}