#include "passgen.hpp"
#include "vigenere.hpp"
#include <iostream>
#include <time.h>
#include <functional>

// Reads lastNames.txt and writes Usernames and random passwords to raw.txt
void PassGen::writeRaw() {
    std::string data = "";
    std::string temp;
    std::ifstream inputFile;
    std::ofstream outputFile;

    inputFile.open("lastNames.txt");

    if(!inputFile.is_open()) {
        std::cout << "Could not open lastNames.txt" << std::endl;
        return;
    }

    outputFile.open("raw.txt");

    while (true) {
        inputFile >> temp;
        inputFile.ignore(50, '\n');
        
        if(inputFile.eof())
            break;

        temp += ' ' + getRandomPass(std::hash<std::string>{}(temp));
        data += temp + "\n";
    }
    
    outputFile << data;

    inputFile.close();
    outputFile.close();
}

// Reads raw.txt and writes Usernames and encrypted passwords to encrypted.txt
void PassGen::writeEncrypted(std::string key) {
    std::string data = "";
    std::string user, pass;
    std::ifstream inputFile;
    std::ofstream outputFile;

    inputFile.open("raw.txt");

    if(!inputFile.is_open()) {
        std::cout << "Could not open raw.txt" << std::endl;
        return;
    }

    outputFile.open("encrypted.txt");

    while (true) {
        inputFile >> user;
        inputFile >> pass;
        pass = Vigenere::Encrypt(key, pass);
        inputFile.ignore(50, '\n');

        if(inputFile.eof())
            break;

        data += user + ' ' + pass + "\n";
    }
    
    outputFile << data;

    inputFile.close();
    outputFile.close();
}

// Accepts seed and generates random 9 character password
std::string PassGen::getRandomPass(int seed) {
    std::string pass = "";
    srand(time(NULL) * seed);
    for(int i = 0; i < 9; i++) {
        pass += char(rand() % 25 + 97);
    }

    return pass;
}