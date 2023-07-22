/*
Домашнее задание
Урок: Бинарное дерево.

Задание 1
Создать класс для работы с бинарным деревом, содержащим англо-русский словарь.
Каждый узел содержит счетчик обращений к слову в данном узле.
В процессе эксплуатации словаря при каждом вызове слова в счетчик обращений добавляется единица.
Написать программу, которая:
- обеспечивает начальный ввод словаря с конкретными значениями счетчика обращений (если кол-во обращений не указано должно присваиваться 0);
- отобразить весь список слов в словаре;
- позволяет найти перевод указанного пользователем слова;


Вывод программы:
Список всех слов библиотеки сразу после ввода:
Aple - Яблоко (кол-во использований: 7)
Hello - Привет (кол-во использований: 0)
Home - Дом (кол-во использований: 0)
Tree - Дерево (кол-во использований: 10)

поиск слова: Tree
Tree - Дерево (кол-во использований: 11)

поиск слова: Tree
Tree - Дерево (кол-во использований: 12)
*/

#include <iostream>
#include <string>

#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); system("color E"); } }_;
using namespace std;


class BinaryTreeDictionary {
private:
    struct Node {
        std::string word;
        std::string translation;
        int counter;
        Node* left;
        Node* right;

        Node(const std::string& w, const std::string& t, int cnt) : word(w), translation(t), counter(cnt), left(nullptr), right(nullptr) {}
    };

    Node* root;

public:
    BinaryTreeDictionary() : root(nullptr) {}

    void insert(const std::string& word, const std::string& translation, int counter = 0) {
        root = insertRecursive(root, word, translation, counter);
    }

    void printDictionary() const {
        printInOrder(root);
    }

    bool findTranslation(const std::string& word) {
        return findTranslationRecursive(root, word);
    }

private:
    Node* insertRecursive(Node* currentNode, const std::string& word, const std::string& translation, int counter) {
        if (!currentNode) {
            return new Node(word, translation, counter);
        }

        if (word < currentNode->word) {
            currentNode->left = insertRecursive(currentNode->left, word, translation, counter);
        }
        else if (word > currentNode->word) {
            currentNode->right = insertRecursive(currentNode->right, word, translation, counter);
        }
        else {
            currentNode->translation = translation;
            currentNode->counter = counter;
        }

        return currentNode;
    }

    void printInOrder(Node* currentNode) const {
        if (currentNode) {
            printInOrder(currentNode->left);
            std::cout << currentNode->word << " - " << currentNode->translation << " (кол-во использований: " << currentNode->counter << ")" << std::endl;
            printInOrder(currentNode->right);
        }
    }

    bool findTranslationRecursive(Node* currentNode, const std::string& word) {
        if (!currentNode) {
            return false;
        }

        if (word < currentNode->word) {
            return findTranslationRecursive(currentNode->left, word);
        }
        else if (word > currentNode->word) {
            return findTranslationRecursive(currentNode->right, word);
        }
        else {
            currentNode->counter++;
            return true;
        }
    }
};

int main() {
    setlocale(LC_ALL, "RU");

    BinaryTreeDictionary dictionary;

    dictionary.insert("Aple", "Яблоко", 7);
    dictionary.insert("Hello", "Привет");
    dictionary.insert("Home", "Дом");
    dictionary.insert("Tree", "Дерево", 10);

    cout << "Список всех слов библиотеки сразу после ввода:" << endl;
    dictionary.printDictionary();
    cout << endl;

    string wordToFind;
    cout << "поиск слова: ";
    cin >> wordToFind;

    if (dictionary.findTranslation(wordToFind)) {
        cout << wordToFind << " - ";
        dictionary.printDictionary(); 
    }
    else {
        cout << "Слово не найдено в словаре." << endl;
    }

    return 0;
}
