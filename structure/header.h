#include <iostream>
#pragma once

using namespace std;

// определение структуры Node1 (спиок, очередь, стек)
struct Node1 {
    string data; // данные узла
    Node1* next; // указатель на следующий узел

    // конструктор для узла
    Node1(const string& value) : data(value), next(nullptr) {}
};

// структура NodeHT представляет узел в хеш-таблице
struct NodeHT {
    string key; // ключ, по которому хранится значение
    string value; // значение, связанное с ключом
    NodeHT* next; // указатель на следующий узел в связанном списке (для решения коллизий)

    // конструктор для создания нового узла хеш-таблицы
    // принимает ключ и значение
    NodeHT(const string& k, const string& v) : key(k), value(v), next(nullptr) {}
};

// Node для бинарного дерева поиска
struct NodeBST {
    int key; // ключ
    NodeBST* left; // указатель на левое поддерево
    NodeBST* right; // указатель на правое поддерево

    // конструктор для создания нового узла бинарного дерева поиска
    // принимает ключ и инициализирует указатели на левое и правое поддеревья
    NodeBST(int key) : key(key), left(nullptr), right(nullptr) {}
};

struct NodeSet {
    string key; // ключ = значению
    NodeSet* next; // указатель на следующий узел в связанном списке

    // конструктор для создания нового узла
    NodeSet(const string& k) : key(k), next(nullptr) {}
};

// объявление структуры Stack
struct Stack {
    Node1* top;
    Stack();
    void push(string value);
    void pop();
    string peek();
    void display();
};

// объявление структуры Array
struct Array {
    string* data;
    int size;
    int capacity;

    Array();
    void pushEnd(string value);
    void push(int index, string value);
    string get(int index);
    void pop(int index);
    void replace(int index, string value);
    int length();
    void display();
};

// объявление структуры List
struct List {
    Node1* head;
    Node1* tail;
    int size;

    List();
    void pushHead(string value);
    void pushTail(string value);
    void popHead();
    void popTail();
    bool popValue(string value);
    bool search(string value);
    void display();
};

// объявление структуры HashTable
struct HashTable {
    NodeHT** table; // массив указателей на узлы хеш-таблицы
    int size; // размер хеш-таблицы
    int count; // количество элементов в хеш-таблице

    HashTable(int initialSize = 10);
    int hash_function(const string& str);
    void insert(const string& key, const string& value);
    string get(const string& key);
    void remove(const string& key);
    void display();
};

// объявление структуры BST
struct BST {
    NodeBST* root;

    BST() : root(nullptr) {}
    NodeBST* insert(NodeBST* node, int key);
    void insert(int key);
    static int height(NodeBST* node);
};

// cтруктура множества
struct Set {
    NodeSet** table; // массив указателей на узлы
    int size;
    int count;

    Set(int initialSize = 10);
    int hash_function(const string& str);
    void insert(const string& key);
    bool remove(const string& key);
    bool contains(const string& key);
    void display();
    void saveToFile(const string& filePath);
};

void processCommand(Set& set, const string& command, const string& key, const string& filePath);