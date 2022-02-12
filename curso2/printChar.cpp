#include<iostream>
#include "./interfaces/printChar.hpp"

void printChar(int tries){
    if(tries == 1) {
        std::cout << "  O  " << std::endl;
    }
    if(tries == 2) {
        std::cout << "  O  " << std::endl;
        std::cout << "  0  " << std::endl;
    }
    if(tries == 3){
        std::cout << "  O  " << std::endl;
        std::cout << "--0  " << std::endl;
        std::cout << "     " << std::endl;
    }
    if(tries == 4){
        std::cout << "  O  " << std::endl;
        std::cout << "--0--" << std::endl;
        std::cout << "     " << std::endl;
    }
    if(tries == 5){
        std::cout << "  O  " << std::endl;
        std::cout << "--0--" << std::endl;
        std::cout << " /   " << std::endl;
    }
    if(tries == 6){
        std::cout << "  O  " << std::endl;
        std::cout << "--0--" << std::endl;
        std::cout << " / \\ " << std::endl;
        std::cout << "Game over!" << std::endl;
    }
}