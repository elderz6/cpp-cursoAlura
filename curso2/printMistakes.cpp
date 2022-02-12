#include<iostream>
#include "./interfaces/printMistakes.hpp"

void printMistakes(std::map<char, bool> mistakes){
    if(mistakes.empty()) return;
    else{
        std::cout << "Mistakes: ";
        for(auto item : mistakes){
            std::cout << item.first << " ";
        }
    }
    std::cout << std::endl;
}