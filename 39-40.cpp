#include <iostream>
#include <string>

#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); system("color E"); } }_;
using namespace std;

/*
Задание 3 (Двусвязный список)
Реализовать шаблонный класс "Очередь с приоритетами" на основе двусвязного списка.
*/


template<typename T>
class PriorityQueue {
private:
    struct Node {
        T data;
        int priority;
        Node* next;
        Node* prev;

        Node(const T& value, int p) : data(value), priority(p), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    PriorityQueue() : head(nullptr), tail(nullptr) {}

    void enqueue(const T& value, int priority) {
        Node* newNode = new Node(value, priority);

        if (!head) {
            head = tail = newNode;
        }
        else {
            Node* current = head;
            while (current && current->priority >= priority) {
                current = current->next;
            }

            if (!current) {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            else if (!current->prev) {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            else {
                newNode->prev = current->prev;
                newNode->next = current;
                current->prev->next = newNode;
                current->prev = newNode;
            }
        }
    }

    T dequeue() {

        T value = tail->data;

        if (head == tail) {
            delete tail;
            head = tail = nullptr;
        }
        else {
            Node* prevTail = tail->prev;
            prevTail->next = nullptr;
            delete tail;
            tail = prevTail;
        }

        return value;
    }

    bool isEmpty() const {
        return !tail;
    }
};

int main() {
    PriorityQueue<string> priorityQueue;

    priorityQueue.enqueue("Task 1", 2);
    priorityQueue.enqueue("Task 2", 1);
    priorityQueue.enqueue("Task 3", 3);
    priorityQueue.enqueue("Task 4", 1);

    while (!priorityQueue.isEmpty()) {
        cout << "Dequeued: " << priorityQueue.dequeue() << endl;
    }

    return 0;
}















