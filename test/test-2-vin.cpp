#include "catch/catch.hpp"
#include "../vigenere.hpp"

TEST_CASE("Test Encryption")
{
    CHECK((Vigenere::Encrypt("jones", "data") == "moge"));
}

TEST_CASE("Test Encryption 2")
{
    CHECK((Vigenere::Encrypt("charlie", "foxtrot") == "hvxkcwx"));
}