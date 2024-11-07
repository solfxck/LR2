// Инопланетный геном
#include <iostream>
#include <string>
#include "structure/header.h"

using namespace std;

int main() {
    string genome1, genome2;
    cout << "Первый геном: ";
    cin >> genome1;
    cout << "Второй геном: ";
    cin >> genome2;

    // создаем множество для хранения пар соседних оснований из второго генома
    Set pairsSet(100);

    // заполняем множество парами соседних оснований из второго генома
    for (size_t i = 0; i < genome2.length() - 1; ++i) {
        string pair;
        pair += genome2[i];
        pair += genome2[i + 1];
        pairsSet.insert(pair);
    }

    // считаем степень близости
    int closenessDegree = 0;
    for (size_t i = 0; i < genome1.length() - 1; ++i) {
        string pair;
        pair += genome1[i];
        pair += genome1[i + 1];
        if (pairsSet.contains(pair)) {
            closenessDegree++;
        }
    }

    // Выводим результат
    cout << closenessDegree << endl;

    return 0;
}