#include <iostream>
#include "structure/header.h"

using namespace std;

// проверка, является ли дерево сбалансированным
bool isBalanced(NodeBST* node) {
    if (node == nullptr) return true; // пустое дерево считается сбалансированным

    // вычисляем высоту левого и правого поддеревьев
    int leftHeight = BST::height(node->left);
    int rightHeight = BST::height(node->right);

    // если разница высот больше 1, дерево не сбалансировано
    if (abs(leftHeight - rightHeight) > 1) return false;

    // рекурсивно проверяем левое и правое поддеревья
    return isBalanced(node->left) && isBalanced(node->right);
}

int main() {
    BST tree;
    int value;

    cout << "Введите последовательность целых чисел, оканчивающуюся нулем:" << endl;
    while (cin >> value && value != 0) {
        tree.insert(value);
    }

    if (isBalanced(tree.root)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}