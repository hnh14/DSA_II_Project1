#include "passgen.hpp"
#include <iostream>

std::string PassGen::getRandomPass() {
    std::string pass = "";
    for(int i = 0; i < 9; i++) {
        pass += char(rand() % 25 + 97);
    }

    return pass;
}