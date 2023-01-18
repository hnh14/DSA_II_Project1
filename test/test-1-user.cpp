#include "catch/catch.hpp"
#include "../user.hpp"

TEST_CASE("Constructor test") 
{
    User user;
    CHECK((user.getUser() == "" && user.getPass() == ""));
}

TEST_CASE("Name test")
{
    User user("bill");
    CHECK((user.getUser() == "bill"));
}

TEST_CASE("Pass test")
{
    User user;
    user.setPass("xyzzy");
    CHECK((user.getPass() == "xyzzy"));
}