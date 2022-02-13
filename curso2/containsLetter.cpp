#include<string>
#include "./interfaces/containsLetter.hpp"
bool containsLetter(char& letter, const std::string& secretWord){
    for(char contains : secretWord){
        if(contains == letter) return true;
    }
    return false;
}
