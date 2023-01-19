#ifndef LIST_H
#define LIST_H
#include "user.hpp"
#include <iostream>

class List
{
private:
    User* head;
public:
    List();
    void Push(User*);
    std::string findHash(std::string);
    std::string findHash(std::string, User*);
};

#endif