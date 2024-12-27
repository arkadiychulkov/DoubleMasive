#pragma once
#include<iostream>

template <typename T>
class DoubLinLst {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(T value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    DoubLinLst() : head(nullptr), tail(nullptr) {}

    ~DoubLinLst() {
        DeleteAll();
    }
    
    void AddInFrontOfHead(T value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            if (head == tail) {
                tail = newNode;
            }
        }
    }

    void AddAfterTail(T value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            if (head == tail) {
                tail = newNode;
            }
        }
    }

    void DeleteFromHead() {
        if (!head) return;

        if (head == tail) {
            head = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
    }

    void DeleteFromTail() {
        if (!tail) return;

        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
    }

    void DeleteAll() {
        while (head) {
            DeleteFromHead();
        }
    }

    void Show() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    DoubLinLst Clone() const {
        DoubLinLst cloneList;
        Node* current = head;
        while (current) {
            cloneList.AddAfterTail(current->data);
            current = current->next;
        }
        return cloneList;
    }

    DoubLinLst operator+(const DoubLinLst& other) const {
        DoubLinLst combinedList = this->Clone();
        Node* current = other.head;
        while (current) {
            combinedList.AddAfterTail(current->data);
            current = current->next;
        }
        return combinedList;
    }

    DoubLinLst operator*(const DoubLinLst& other) const {
        DoubLinLst intersectionList;
        Node* current = head;
        while (current) {
            Node* otherCurrent = other.head;
            while (otherCurrent) {
                if (current->data == otherCurrent->data) {
                    intersectionList.AddAfterTail(current->data);
                    break;
                }
                otherCurrent = otherCurrent->next;
            }
            current = current->next;
        }
        return intersectionList;
    }

};