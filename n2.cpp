#include <iostream>
#include <string>
#include <fstream>
#include "structure/header.h"

using namespace std;

void processCommand(Set& set, const string& command, const string& key, const string& filePath) {
    if (command == "SETADD") {
        set.insert(key);
        cout << "Элемент добавлен: " << key << endl;
    } else if (command == "SETDEL") {
        if (!set.remove(key)) {
            cout << "Данного элемента нет в множестве!" << endl;
        } else {
            cout << "Элемент удален: " << key << endl;
        }
    } else if (command == "SET_AT") {
        if (set.contains(key)) {
            cout << "Элемент найден: " << key << endl;
        } else {
            cout << "Элемент не найден: " << key << endl;
        }
    } else if (command == "SETPRINT") {
        set.display();
    } else {
        cout << "Неверная команда." << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cout << "Использование: " << argv[0] << " --file <путь до файла> --query <запрос> " << endl;
        return 1;
    }

    string filePath = argv[2];
    string query = argv[4];
    string key = (argc > 5) ? argv[5] : "";

    Set set;

    ifstream inputFile(filePath);
    if (inputFile.is_open()) {
        string key;
        while (inputFile >> key) {
            set.insert(key);
        }
        inputFile.close();
    } else {
        cout << "Не удалось открыть файл." << endl;
        return 1;
    }

    processCommand(set, query, key, filePath);

    // Сохранение данных в файл
    set.saveToFile(filePath);

    return 0;
}