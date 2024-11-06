#include <iostream>
#include <string>
#include <fstream>
#include "header.h"

using namespace std;

// функция для вычисления хеш-значения строки
int Set::hash_function(const string& str) {
    int hash = 0; 
    for (char c : str) {
        hash += c;  // суммирование ASCII-кодов символов строки
    }
    return hash % size;  // чтобы не выйти заграницы
}

// конструктор класса Set
Set::Set(int initialSize) {
    size = initialSize;  // размер таблицы
    count = 0;  // счетчик элементов
    table = new NodeSet*[size];  // выделение памяти под массив указателей на узлы
    for (int i = 0; i < size; i++) {
        table[i] = nullptr;  // инициализация каждого указателя как nullptr
    }
}

// функция для вставки элемента в множество
// сложность: O(1) (в худшем случае, если возникают коллизии - O(n), где n - количество элементов в связанном списке)
void Set::insert(const string& key) {
    int index = hash_function(key);  // вычисление индекса для вставки
    NodeSet* current = table[index];  // получение текущего узла по индексу

    while (current != nullptr) {  // проход по связанному списку
        if (current->key == key) {  // если ключ уже существует
            return;  // выход из функции (элемент уже существует)
        }
        current = current->next;  // переход к следующему узлу
    }

    NodeSet* newNode = new NodeSet(key);  // создание нового узла
    newNode->next = table[index];  // новый узел указывает на текущий узел по индексу
    table[index] = newNode;  // новый узел становится текущим узлом по индексу
    count++;  // увеличение счетчика элементов
}

// функция для удаления элемента из множества
// сложность: O(1) (в худшем случае, если возникают коллизии - O(n), где n - количество элементов в связанном списке)
bool Set::remove(const string& key) {
    int index = hash_function(key);  // вычисление индекса для удаления
    NodeSet* current = table[index];  // получение текущего узла по индексу
    NodeSet* prev = nullptr;  // указатель на предыдущий узел

    while (current != nullptr) {  // проход по связанному списку
        if (current->key == key) {  // если ключ найден
            if (prev == nullptr) {  // если это первый узел в списке
                table[index] = current->next;  // следующий узел становится текущим
            } else {
                prev->next = current->next;  // предыдущий узел указывает на следующий узел
            }
            delete current;  // удаление текущего узла
            count--;  // уменьшение счетчика элементов
            return true;  // возврат true (элемент успешно удален)
        }
        prev = current;  // переход к следующему узлу
        current = current->next;
    }
    return false;  // возврат false (элемент не найден)
}

// функция для проверки наличия элемента в множестве
// сложность: O(1) (в худшем случае, если возникают коллизии - O(n), где n - количество элементов в связанном списке)
bool Set::contains(const string& key) {
    int index = hash_function(key);  // вычисление индекса для поиска
    NodeSet* current = table[index];  // получение текущего узла по индексу

    while (current != nullptr) {  // проход по связанному списку
        if (current->key == key) {  // если ключ найден
            return true;  // возврат true (элемент найден)
        }
        current = current->next;  // переход к следующему узлу
    }

    return false;  // возврат false (элемент не найден)
}

// функция для вывода всех элементов множества
// сложность: O(n), где n - общее количество элементов в множестве
void Set::display() {
    for (int i = 0; i < size; i++) {  // проход по всем индексам таблицы
        NodeSet* current = table[i];  // получение текущего узла по индексу
        while (current != nullptr) {  // проход по связанному списку
            cout << current->key << " ";  // вывод ключа
            current = current->next;  // переход к следующему узлу
        }
    }
    cout << endl;  // переход на новую строку после вывода всех элементов
}

// функция для сохранения элементов множества в файл
void Set::saveToFile(const string& filePath) {
    ofstream outputFile(filePath);  // открытие файла для записи
    if (outputFile.is_open()) {
        for (int i = 0; i < size; i++) {  // проход по всем индексам таблицы
            NodeSet* current = table[i];  // получение текущего узла по индексу
            while (current != nullptr) {  // проход по связанному списку
                outputFile << current->key << endl;  // запись ключа в файл
                current = current->next;  // переход к следующему узлу
            }
        }
        outputFile.close();  // закрытие файла
    } else {
        cout << "не удалось открыть файл для записи." << endl;
    }
}