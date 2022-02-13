#include<iostream>
#include "./interfaces/printLetters.hpp"

void printLetters(const std::string& secretWord, const std::map<char, bool> correctPositions){
    for(char letter : secretWord){
        if(correctPositions.find(letter) != correctPositions.end()) std::cout << letter << " ";
        else std::cout << "_ ";
    }
    std::cout << std::endl;
}