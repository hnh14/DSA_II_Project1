#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include "list.hpp"

class HashTable {
private:
    int numBuckets;
    List* buckets;
public:
    HashTable(int);
    void LoadTable();
    std::string findHash(std::string);
    std::string checkMatch(std::string, std::string, std::string);
};

#endif