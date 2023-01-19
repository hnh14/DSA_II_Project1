#include "catch/catch.hpp"
#include "../list.hpp"
#include "../user.hpp"

TEST_CASE("Test Search Success") {
    List list;
    User* dummy = new User("Dummy");
    dummy->setPass("checkmate");

    list.Push(dummy);
    list.Push(new User("Dan"));
    list.Push(new User("Steve"));
    list.Push(new User("Joe"));
    list.Push(new User("Leo"));
    list.Push(new User("Don"));

    std::string hash = list.findHash("Dummy");
    CHECK((hash == "checkmate"));

}

TEST_CASE("Test Search Fail") {
    List list;
    
    list.Push(new User("Dan"));
    list.Push(new User("Steve"));
    list.Push(new User("Joe"));
    list.Push(new User("Leo"));
    list.Push(new User("Don"));

    std::string hash = list.findHash("Dummy");
    CHECK((hash == "-1"));

}
