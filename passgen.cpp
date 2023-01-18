#include "passgen.hpp"
#include <iostream>

void PassGen::writeRaw() {
    std::string data = "";
    std::string temp;
    std::ifstream inputFile;
    std::ofstream outputFile;

    inputFile.open("lastNames.txt");
    outputFile.open("raw.txt");

    while (true) {
        inputFile >> temp;
        inputFile.ignore(50, '\n');

        if(inputFile.eof())
            break;
            
        data += temp + "\n";
    }
    
    outputFile << data;

    inputFile.close();
    outputFile.close();
}

std::string PassGen::getRandomPass() {
    std::string pass = "";
    for(int i = 0; i < 9; i++) {
        pass += char(rand() % 25 + 97);
    }

    return pass;
}