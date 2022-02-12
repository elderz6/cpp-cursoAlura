#include<iostream>
#include<fstream>
#include "./interfaces/readFile.hpp"

std::string readFile(){
    std::ifstream file("./dict.txt");
    if(!file.is_open()){
        std::cout << "Error opening file" << std::endl;
        exit(0);
    }

    int len;
    file >> len;
    srand(time(0));
    int sort = rand() % len;
    std::string word;
    for(int i = 0; i < len; i++){
        std::string newWord;
        file >> newWord;
        if(i == sort){
            word = newWord;
            break;
        }
    }
    file.close();
    return word;
}