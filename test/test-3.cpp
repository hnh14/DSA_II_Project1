#include "catch/catch.hpp"
#include "../passgen.hpp"

TEST_CASE("Test Password Generator") {
    std::string test = PassGen::getRandomPass(4);
    CHECK((test.length() == 9));
}


TEST_CASE("Test write raw.txt") {
    PassGen::writeRaw();
}

TEST_CASE("Test write encrypted.txt") {
    PassGen::writeEncrypted("jones");
}
