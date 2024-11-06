#include "header.h"
#include <iostream>

using namespace std;

// вставка узла в бинарное дерево поиска
// Сложность: O(h), где h - высота дерева
NodeBST* BST::insert(NodeBST* node, int key) {
    // если текущий узел пустой, создаем новый узел с переданным ключом
    if (node == nullptr) return new NodeBST(key);

    // если ключ меньше ключа текущего узла, рекурсивно вставляем в левое поддерево
    if (key < node->key)
        node->left = insert(node->left, key);
    // если ключ больше ключа текущего узла, рекурсивно вставляем в правое поддерево
    else if (key > node->key)
        node->right = insert(node->right, key);
    // если ключ уже существует, возвращаем текущий узел (дубликаты не допускаются)
    else
        return node;

    return node; // возвращаем корень поддерева
}

// Функция для вставки значения(ключа) в бинарное дерево поиска
// Сложность: O(h), где h - высота дерева
void BST::insert(int key) {
    root = insert(root, key);
}

// Функция для вычисления высоты дерева
// Сложность: O(n)
int BST::height(NodeBST* node) {
    if (node == nullptr) return 0; // Если узел пустой, высота равна 0
    return 1 + max(height(node->left), height(node->right)); // Иначе возвращаем максимальную высоту поддеревьев + 1
}