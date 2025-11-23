#include <iostream>
#include <fstream>
#include <string>

int main() {
    int vr; // Для выбора действия: регистрация или вход
    std::cout << "1. ЗАРЕГИСТРИРОВАТЬСЯ или 2. ВОЙТИ? ";
    std::cin >> vr; // Считываем выбор пользователя

    if (vr == 1) { // Регистрация
        std::string log, pass;
        std::cout << "Введите логин (не более 50 символов): ";
        std::cin >> log;
        std::cout << "Введите пароль (не более 50 символов): ";
        std::cin >> pass;

        // Сохраняем логин и пароль в файл
        std::ofstream outputFile("LGPT.txt", std::ios::app); // Открываем файл для добавления
        if (!outputFile) { // Проверка на успешное открытие файла
            std::cerr << "Ошибка открытия файла!" << std::endl;
            return 1;
        }
        outputFile << log << std::endl; // Записываем логин
        outputFile << pass << std::endl; // Записываем пароль
        outputFile.close(); // Закрываем файл
        std::cout << "Регистрация окончена.\n";

        // Проверка логина и пароля после регистрации
        std::string inputLogin, inputPassword, storedLogin, storedPassword;
        bool success = false;

        // Открываем файл для чтения
        std::ifstream inputFile("LGPT.txt");
        if (!inputFile) { // Проверка на успешное открытие файла
            std::cerr << "Ошибка открытия файла!" << std::endl;
            return 1;
        }

        // Считываем логины и пароли из файла
        while (std::getline(inputFile, storedLogin) && std::getline(inputFile, storedPassword)) {
            // Проверяем введенные логин и пароль
            std::cout << "Введите логин для входа: ";
            std::cin >> inputLogin;
            std::cout << "Введите пароль для входа: ";
            std::cin >> inputPassword;

            // Проверяем логин и пароль
            if (inputLogin == storedLogin && inputPassword == storedPassword) {
                success = true;
                break; // Выходим из цикла, если вход успешен
            }
        }

        inputFile.close(); // Закрываем файл

        if (success) {
            std::cout << "Вход успешно выполнен.\n";
            // Здесь можно начать игру или другую логику
        }
        else {
            std::cout << "Неправильный логин или пароль. Попробуйте снова.\n";
        }

    }
    else if (vr == 2) { // Вход
        std::string inputLogin, inputPassword, storedLogin, storedPassword;
        bool success = false;

        // Открываем файл для чтения
        std::ifstream inputFile("LGPT.txt");
        if (!inputFile) { // Проверка на успешное открытие файла
            std::cerr << "Ошибка открытия файла!" << std::endl;
            return 1;
        }

        // Считываем логины и пароли из файла
        while (std::getline(inputFile, storedLogin) && std::getline(inputFile, storedPassword)) {
            std::cout << "Введите логин: ";
            std::cin >> inputLogin;
            std::cout << "Введите пароль: ";
            std::cin >> inputPassword;

            // Проверяем логин и пароль
            if (inputLogin == storedLogin && inputPassword == storedPassword) {
                success = true;
                break; // Выходим из цикла, если вход успешен
            }
        }

        inputFile.close(); // Закрываем файл

        if (success) {
            std::cout << "Вход успешно выполнен.\n";
            // Здесь можно начать игру или другую логику
        }
        else {
            std::cout << "Неправильный логин или пароль. Попробуйте снова.\n";
        }

    }
    else {
        std::cout << "Некорректный выбор. Пожалуйста, попробуйте снова.\n";
    }
    //начало игры

    return 0;
} 