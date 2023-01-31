#include "hashtable.hpp"
#include "user.hpp"
#include "vigenere.hpp"
#include <iostream>
#include <fstream>
#include <functional>

// Constructor - Creates an array of linked lists
HashTable::HashTable(int numBuckets) {
    this->numBuckets = numBuckets;
    buckets = new List[numBuckets];
}

// Reads the "encrypted.txt" file and enters
// the user info into the hash table
void HashTable::LoadTable() {
    std::ifstream inputFile;
    inputFile.open("encrypted.txt");

    if(!inputFile.is_open()) {
        std::cout << "Could not open encrypted.txt" << std::endl;
        return;
    }

    std::string name, pass;
    User* temp;
    int hash;
    while(true) {
        inputFile >> name >> pass;
        temp = new User(name);
        temp->setPass(pass);

        hash = std::hash<std::string>{}(name) % numBuckets;

        if(inputFile.eof())
            break;

        buckets[hash].Push(temp);
    }
}

// Searches for a username in the hash table and returns the password
std::string HashTable::findHash(std::string name) {
    int hash = std::hash<std::string>{}(name) % numBuckets;
    
    return buckets[hash].findHash(name);
}

// Checks if the password given matches the password in the hash table
std::string HashTable::checkMatch(std::string name, std::string pass, std::string key) {
    std::string encryptedPass = Vigenere::Encrypt(key, pass);
    if(encryptedPass == findHash(name)) 
        return "match";
    else   
        return "no match";
}