#include "catch/catch.hpp"
#include "../hashtable.hpp"
#include "../list.hpp"
#include "../vigenere.hpp"
#include <fstream>

TEST_CASE("Test Search Success") {
    HashTable hashtable(90000);
    std::string name, pass;
    hashtable.LoadTable();

    std::ifstream in("raw.txt");
    in >> name >> pass;

    std::string hash = hashtable.findHash("SMITH");
    CHECK((hash == Vigenere::Encrypt("jones", pass)));


    hashtable.checkMatch(name, pass, "jones");
}

TEST_CASE("Test Search Fail/No Match") {
    HashTable hashtable(90000);


    hashtable.LoadTable();

    std::string hash = hashtable.findHash("SMITT");
    CHECK((hash == "-1"));

    hashtable.checkMatch("SMITH", "fasdasdfd", "key");
}
