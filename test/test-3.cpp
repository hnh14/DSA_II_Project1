#include "catch/catch.hpp"
#include "../passgen.hpp"

TEST_CASE("Test Password Generator") {
    std::string test = PassGen::getRandomPass();
    CHECK((test.length() == 9));
}

