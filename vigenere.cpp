#include "vigenere.hpp"
#include <iostream>

std::string Vigenere::Encrypt(std::string key, std::string data) {
    std::string toSwap;
    for(int i = 0; i < data.size(); i++) {
        int map = (key[i % key.size()] - 97) + data[i];

        if(map > 122)
            map -= 26;

        data[i] = char(map);
    }
    
    return data;
}