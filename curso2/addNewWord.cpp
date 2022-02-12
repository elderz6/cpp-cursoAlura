#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include "./interfaces/addNewWord.hpp"

void addNewWord(){
    std::cout << "Do you want to add a new word? (Y/N)" << std::endl;
    
    char want;
    std::cin >> want;
    want = toupper(want);
    if(want != 'Y') exit(0);

    std::ofstream file("./dict.txt", std::ios::app);
    if(!file.is_open()){
        std::cout << "Error opening file" << std::endl;
        exit(0);
    }
    std::cout << "Enter a new word: ";
    std::string newWord;
    std::cin >> newWord;
    transform(newWord.begin(), newWord.end(), newWord.begin(), ::toupper);

    file << std::endl << newWord;
    file.close();
}