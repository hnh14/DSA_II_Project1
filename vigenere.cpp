#include "vigenere.hpp"
#include <iostream>

// Uses Vigenere Chiper algorithm to encrypt data using a key
std::string Vigenere::Encrypt(std::string key, std::string data) {
    for(int i = 0; i < data.size(); i++) {
        int map = (key[i % key.size()] - 97) + data[i];

        if(map > 122)
            map -= 26;

        data[i] = char(map);
    }
    
    return data;
}