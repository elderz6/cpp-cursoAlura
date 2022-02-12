#include<iostream>
#include "./interfaces/getInput.hpp"

char getInput(){
    std::cout << "Guess a letter: ";
    char letterIn;
    std::cin >> letterIn;
    letterIn = toupper(letterIn);
    std::cout << std::endl;
    return letterIn;
}