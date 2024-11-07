// Обратная польская запись
#include <iostream>
#include <sstream>
#include <string>
#include "structure/header.h"

using namespace std;

// обратная польская запись
int evaluatePE(string entryPolish) {
    Stack stack;
    istringstream iss(entryPolish);
    string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) {
            // если токен - число, помещаем его в стек
            stack.push(token);
        } else {
            // если токен - оператор, извлекаем два операнда из стека
            if (stack.top == nullptr) {
                throw runtime_error("Недостаточно операндов для операции");
            }
            int operand2 = stoi(stack.peek());
            stack.pop();

            if (stack.top == nullptr) {
                throw runtime_error("Недостаточно операндов для операции");
            }
            int operand1 = stoi(stack.peek());
            stack.pop();

            // выполняем операцию и помещаем результат обратно в стек
            int result;
            if (token == "+") {
                result = operand1 + operand2;
            } else if (token == "-") {
                result = operand1 - operand2;
            } else if (token == "*") {
                result = operand1 * operand2;
            } else if (token == "/") {
                result = operand1 / operand2;
            } else {
                throw runtime_error("Неизвестный оператор: " + token);
            }
            stack.push(to_string(result));
        }
    }

    // результат должен быть единственным элементом в стеке
    if (stack.top == nullptr || stack.top->next != nullptr) {
        throw runtime_error("Некорректное выражение");
    }

    return stoi(stack.peek());
}

// вывод в инфиксной форме
string convertPEtoInfix(string entryPolish) {
    Stack stack;
    istringstream iss(entryPolish);
    string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) {
            stack.push(token);
        } else {
            string operand2 = stack.peek();
            stack.pop();

            string operand1 = stack.peek();
            stack.pop();

            // формируем инфиксное выражение и помещаем его обратно в стек
            string infixExpression = "(" + operand1 + " " + token + " " + operand2 + ")";
            stack.push(infixExpression);
        }
    }

    return stack.peek();
}

int main() {
    string entryPolish;
    cout << "Введите выражение в обратной польской записи: ";
    getline(cin, entryPolish);

    try {
        int result = evaluatePE(entryPolish);
        string entryInfix = convertPEtoInfix(entryPolish);
        cout << "Инфиксное выражение: " << entryInfix << endl;
        cout << "Результат: " << result << endl;
    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}