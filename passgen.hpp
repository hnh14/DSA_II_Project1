#ifndef PASSGEN_H
#define PASSGEN_H
#include "vigenere.hpp"
#include <string>
#include <fstream>

class PassGen {
    public:
        static void writeRaw();
        static void writeEncrypted();

        static std::string getRandomPass();
};

#endif