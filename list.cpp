#include "list.hpp"
#include <iostream>

List::List() {
    head = nullptr;
}

void List::Push(User* toPush) {
    if(head == nullptr) {
        head = toPush;
    }

    else {
        toPush->setNext(head);
        head = toPush;
    }
}

std::string List::findHash(std::string name) {
    if(name == head->getUser())
        return head->getPass();

    if(head->getNext() == nullptr)
        return "-1";
    
    return findHash(name, head->getNext());
}

std::string List::findHash(std::string name, User* user) {
    if(name == user->getUser())
        return user->getPass();

    if(user->getNext() == nullptr)
        return "-1";
    
    return findHash(name, user->getNext());
}