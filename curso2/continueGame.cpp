#include<iostream>
#include "./interfaces/continueGame.hpp"
#include "./interfaces/addNewWord.hpp"

bool continueGame(const std::string& secretWord, const std::map<char, bool>& correctPositions){
    for(char letter : secretWord){
        if(correctPositions.find(letter) == correctPositions.end() 
		|| !correctPositions.at(letter)) return true;
    }
    std::cout << std::endl << "You Won!" << std::endl;
    std::cout << "The word was " << secretWord << std::endl;
    addNewWord();
    return false;
}