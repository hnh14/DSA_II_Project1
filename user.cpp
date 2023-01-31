#include "user.hpp"
#include <iostream>

// Default Constructor
User::User() {
    name = "";
    pass = "";
    next = nullptr;
}

// Constructor - sets name
User::User(std::string name) {
    this->name = name;
    pass = "";
    next = nullptr;
}

// Get function for name
std::string User::getUser() {
    return name;
}

// Set function for name
void User::setUser(std::string name) {
    this->name = name;
}

// Get function for password
std::string User::getPass() {
    return pass;
}

// Set function for password
void User::setPass(std::string pass) {
    this->pass = pass;
}

// Set function for next User pointer
void User::setNext(User* next) {
    this->next = next;
}

// Get function for next User pointer
User* User::getNext() {
    return next;
}