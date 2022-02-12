#include<iostream>
#include "./interfaces/printLetters.hpp"

void printLetters(std::string secretWord, std::map<char, bool> correctPositions){
    for(char letter : secretWord){
        if(correctPositions[letter]) std::cout << letter << " ";
        else std::cout << "_ ";
    }
    std::cout << std::endl;
}