#include "list.hpp"
#include <iostream>

// Constructor - sets head to nullptr
List::List() {
    head = nullptr;
}

// Pushes User object to the head of the list
void List::Push(User* toPush) {
    if(head == nullptr) {
        head = toPush;
    }

    else {
        toPush->setNext(head);
        head = toPush;
    }
}

// Starts the recursive search at the head of the linked list
std::string List::findHash(std::string name) {
    if(head == nullptr)
        return "-1";

    if(name == head->getUser())
        return head->getPass();

    if(head->getNext() == nullptr)
        return "-1";
    
    return findHash(name, head->getNext());
}

// Continues the recursive search until User is found or end of list is reached
std::string List::findHash(std::string name, User* user) {
    if(name == user->getUser())
        return user->getPass();

    if(user->getNext() == nullptr)
        return "-1";
    
    return findHash(name, user->getNext());
}