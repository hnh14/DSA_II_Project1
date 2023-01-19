#include "user.hpp"
#include <iostream>

User::User() {
    name = "";
    pass = "";
    next = nullptr;
}

User::User(std::string name) {
    this->name = name;
    pass = "";
    next = nullptr;
}

std::string User::getUser() {
    return name;
}

void User::setUser(std::string name) {
    this->name = name;
}

std::string User::getPass() {
    return pass;
}

void User::setPass(std::string pass) {
    this->pass = pass;
}

void User::setNext(User* next) {
    this->next = next;
}

User* User::getNext() {
    return next;
}