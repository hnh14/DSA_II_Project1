#include "user.hpp"
#include <iostream>

User::User() {
    name = "";
    pass = "";
}

User::User(std::string name) {
    this->name = name;
    pass = "";
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