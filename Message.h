#pragma once

#include <string>
#include <fstream>

class Message {
    std::string _text;
    std::string _sender;
    std::string _receiver;

public:
    Message()=default;
    Message(const std::string& text, const std::string& sender, const std::string& receiver);

    friend std::fstream& operator >>(std::fstream& is, Message& obj);
    friend std::ostream& operator <<(std::ostream& os, const Message& obj);
};