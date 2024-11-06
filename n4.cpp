#include <iostream>
#include <string>
#include <sstream>
#include "structure/header.h"

using namespace std;

// проверка, является ли символ заглавной буквой
bool isAccent(char c) {
    return isupper(c);
}

// приведения строки к нижнему регистру
string toLowerCase(const string& str) {
    string lowerStr = str;
    for (char &c : lowerStr) {
        c = tolower(c);
    }
    return lowerStr;
}

// проверка, является ли слово правильно ударенным
bool isCorrectAccent(const string& word, Array& dictionary) {
    string lowerWord = toLowerCase(word); // приводим слово к нижнему регистру для сравнения с словарем

    // проверяем, есть ли слово в словаре
    bool foundInDictionary = false; // найдено ли слово в словаре?
    for (int i = 0; i < dictionary.length(); ++i) {
        string dictWord = dictionary.get(i);
        if (lowerWord == toLowerCase(dictWord)) {
            foundInDictionary = true;
            // проверяем, совпадает ли ударение
            bool accentsMatch = true; // совпадают ли ударения в слове из текста и слове из словаря?
            for (size_t j = 0; j < word.size(); ++j) {
                if (isAccent(word[j]) != isAccent(dictWord[j])) {
                    accentsMatch = false;
                    break;
                }
            }
            if (accentsMatch) {
                return true;
            }
        }
    }

    // если слово не найдено в словаре, проверяем количество ударений
    int accentCount = 0;
    for (char c : word) {
        if (isAccent(c)) {
            accentCount++;
        }
    }

    // cлово считается правильным, если в нем ровно одно ударение
    if (!foundInDictionary) {
        return accentCount == 1;
    }

    // если слово найдено в словаре, но ударение не совпадает, возвращаем false
    return false;
}

int main() {
    int N;
    cout << "Введите количество слов в словаре: ";
    cin >> N;
    cin.ignore(); // игнорируем символ новой строки после ввода числа

    Array dictionary;
    cout << "Введите слова словаря с правильными ударениями:" << endl;
    for (int i = 0; i < N; ++i) {
        string word;
        getline(cin, word);
        dictionary.pushEnd(word);
    }

    string text;
    cout << "Введите текст, в котором Петя расставил ударения:" << endl;
    getline(cin, text);

    istringstream iss(text);
    string word;
    int errorCount = 0;

    while (iss >> word) {
        if (!isCorrectAccent(word, dictionary)) { // проверка, является ли слово правильно ударным
            errorCount++;
        }
    }

    cout << "Количество ошибок в тексте: " << errorCount << endl;

    return 0;
}