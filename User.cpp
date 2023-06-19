#include"User.h"

User::User(const std::string& name, const std::string& login, const std::string& pass)
    : _name(name), _login(login), _pass(pass) {}

std::fstream& operator >>(std::fstream& is, User& obj) {
    is >> obj._name;
    is >> obj._login;
    is >> obj._pass;
    return is;
}

std::ostream& operator <<(std::ostream& os, const User& obj) {
    os << obj._name;
    os << ' ';
    os << obj._login;
    os << ' ';
    os << obj._pass;
    return os;
}