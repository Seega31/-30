#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

bool overwrite(const std::string& filePath, const std::string& content) {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        return false;
    }
    file << content;
    file.close();
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");

    //Задача 1.
    std::string filename = "data.txt";
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Ошибка открытия файла для записи!" << std::endl;
        return 1;
    }
    std::cout << "Введите строки (для завершения введите 'end'):" << std::endl;
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        if (input == "end") {
            break;
        }
        outFile << input << std::endl;
    }
    outFile.close();
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Ошибка открытия файла для чтения!" << std::endl;
        return 1;
    }
    std::cout << "Содержимое файла:" << std::endl;
    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }
    inFile.close();
    if (std::remove(filename.c_str()) != 0) {
        std::cerr << "Ошибка удаления файла!" << std::endl;
        return 1;
    }


    //Задача 2.
    std::string filePath = "example.txt";
    std::string newContent = "Новое содержимое файла";
    if (overwrite(filePath, newContent)) {
        std::cout << "Замена прошла успешно." << std::endl;
    }
    else {
        std::cout << "Файл не существует или не удалось открыть." << std::endl;
    }

    return 0;
}
