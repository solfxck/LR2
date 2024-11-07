// Преобразование целого числа в римскую цифру
#include "structure/header.h"
#include <iostream>

using namespace std;

string intToRoman(int num) {
    // хеш-таблица для хранения соответствий между арабскими числами и римскими символами
    HashTable hashTable(13); // создание хеш-таблицы
    hashTable.insert("M", "1000");
    hashTable.insert("CM", "900");
    hashTable.insert("D", "500");
    hashTable.insert("CD", "400");
    hashTable.insert("C", "100");
    hashTable.insert("XC", "90");
    hashTable.insert("L", "50");
    hashTable.insert("XL", "40");
    hashTable.insert("X", "10");
    hashTable.insert("IX", "9");
    hashTable.insert("V", "5");
    hashTable.insert("IV", "4");
    hashTable.insert("I", "1");

    // массив для хранения пар (значение, римская цифра)
    Array romanValues;
    for (int i = 0; i < hashTable.size; ++i) {
        NodeHT* current = hashTable.table[i]; // берем текущий элемент из хеш-таблицы
        while (current != nullptr) { // пока есть элементы в списке
            romanValues.pushEnd(current->value + " " + current->key); // добавление пары значение-римская цифра в массив
            current = current->next; // переходим к следующему элементу списка
        }
    }

    // сортировка массива (по убыванию)
    for (int i = 0; i < romanValues.length(); ++i) { // внешний цикл для обхода массива
        for (int j = i + 1; j < romanValues.length(); ++j) { // внутренний цикл для сравнения элементов
            // преобразуем строку в целое значение
            int value1 = stoi(romanValues.get(i).substr(0, romanValues.get(i).find(' '))); // первое значение
            int value2 = stoi(romanValues.get(j).substr(0, romanValues.get(j).find(' '))); // второе значение
            if (value1 < value2) { // если первое значение меньше второго
                string temp = romanValues.get(i); // временное хранение первого элемента
                romanValues.replace(i, romanValues.get(j)); // замена первого элемента на второй
                romanValues.replace(j, temp); // замена второго элемента на временный
            }
        }
    }

    string result = ""; // строка для хранения итогового результата
    for (int i = 0; i < romanValues.length(); ++i) { // итерируемся по массиву римских значений
        int value = stoi(romanValues.get(i).substr(0, romanValues.get(i).find(' '))); // получаем значение
        string roman = romanValues.get(i).substr(romanValues.get(i).find(' ') + 1); // получаем римскую цифру
        while (num >= value) { // пока число больше или равно значению
            result += roman; // добавляем римскую цифру к результату
            num -= value; // уменьшаем число на значение
        }
    }

    return result; // возвращаем итоговую строку с римскими цифрами

    /*
    Ввод: 1987
    1. 1987 >= 1000: result = "M", num = 987
    2. 987 >= 900: result = "MCM", num = 87
    3. 87 >= 50: result = "MCML", num = 37
    4. 37 >= 10: result = "MCMLX", num = 27
    5. 32 >= 10: result = "MCMLXX", num = 17
    6. 17 >= 10: result = "MCMLXXX", num = 7
    7. 7 >= 5: result = "MCMLXXXV", num = 2
    8. 2 >= 1: result = "MCMLXXXVI", num = 1
    8. 1 >= 1: result = "MCMLXXXVII", num = 0 (остановка)
    Вывод: MCMLXXXVII
    */
}

int main() {
    int num;
    
    cout << "Введите число: ";
    cin >> num;
    cout << "Вывод: " << intToRoman(num) << endl;

    return 0;
}