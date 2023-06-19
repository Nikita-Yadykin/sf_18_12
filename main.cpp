#include <fstream>
#include <iostream>
#include <filesystem>

#include "User.h"
#include "Message.h"

namespace fs = std::filesystem;

void setFilePermissions(const std::string& filePath) // Устанавливаем разрешение на чтение и запись только для владельца
{
    fs::permissions(filePath,
        fs::perms::owner_read | fs::perms::owner_write,
        fs::perm_options::replace);
}

int main() {
    std::fstream user_file("users.txt", std::ios::in | std::ios::out);
    if (!user_file) {
        // Создаем файл, если его не существует
        user_file.open("users.txt", std::ios::in | std::ios::out | std::ios::trunc);
    }

    std::fstream message_file("messages.txt", std::ios::in | std::ios::out);
    if (!message_file) {
        // Создаем файл, если его не существует
        message_file.open("messages.txt", std::ios::in | std::ios::out | std::ios::trunc);
    }

    if (user_file && message_file) {
        User user("Alex", "qwerty", "12345");
        Message message("Hello", "Alex", "Bob");


        // Устанавливаем права доступа только для текущего пользователя
        setFilePermissions("users.txt");
        setFilePermissions("messages.txt");


        // Записываем данные пользвателя в файл
        user_file << user << std::endl;

        // Записываем данные сообщения в файл
        message_file << message << std::endl;

        // Устанавливаем позицию перед чтением в начало файлов
        user_file.seekg(0, std::ios_base::beg);
        message_file.seekg(0, std::ios_base::beg);

        // Считываем данные пользвателя
        User readUser;
        user_file >> readUser;
        std::cout << "User: " << readUser << std::endl;

        // Считываем данные сообщения
        Message readMessage;
        message_file >> readMessage;
        std::cout << "Message: " << readMessage << std::endl;

        user_file.close();
        message_file.close();
    }
    else {
        std::cout << "Could not open files!" << std::endl;
    }

    return 0;
}