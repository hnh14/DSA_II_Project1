#ifndef USER_H
#define USER_H
#include <string>

class User {
    private:
        std::string name, pass;
    public:
        User();
        User(std::string);

        std::string getUser();
        void setUser(std::string);
        std::string getPass();
        void setPass(std::string);
};

#endif