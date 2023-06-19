#pragma once

#include <string>
#include <fstream>

class User {
    std::string _name;
    std::string _login;
    std::string _pass;

public:
    User()=default;
    User(const std::string& name, const std::string& login, const std::string& pass);

    friend std::fstream& operator >>(std::fstream& is, User& obj);
    friend std::ostream& operator <<(std::ostream& os, const User& obj);
};