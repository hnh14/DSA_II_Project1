#include "hashtable.hpp"
#include "passgen.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

int main() {
    // Writes raw.txt and encrypted.txt files
    PassGen::writeRaw();
    PassGen::writeEncrypted("jones");

    // Creates hash table
    HashTable hashtable(90000);
    hashtable.LoadTable();

    // Tries to open raw.txt
    std::ifstream inputFile("raw.txt");
    if(!inputFile.is_open()) {
        std::cout << "Could not open raw.txt" << std::endl;
        return 0;
    }

    std::cout << "Legal:\n" << "UserID      " << "Password   " <<"Attempted" << "  Result" << std::endl;

    // Loops 5 times and checks if password from raw.txt matches the password in the table
    std::string name, pass;
    for(int i = 0; i < 5; i++) {
        inputFile >> name >> pass;
        std::cout << std::setw(12) << std::left << name << pass 
                  << "  " << pass << "  " << hashtable.checkMatch(name, pass, "jones") << std::endl;
    }

    std::cout << std::endl << "Illegal:\n" << "UserID      " << "Password   " <<"Attempted" << "  Result" << std::endl;

    // Loops 5 times and enters the wrong password to make sure the hash table recognizes it is not a match
    inputFile.clear();
    inputFile.seekg(0);
    for(int i = 0; i < 5; i++) {
        inputFile >> name >> pass;
        std::cout << std::setw(12) << std::left << name << pass;

        if(pass[0] != 'x')
            pass[0] = 'x';
        else
            pass[0] = 'y';

        std::cout << "  " << pass << "  " << hashtable.checkMatch(name, pass, "jones") << std::endl;
    }
}