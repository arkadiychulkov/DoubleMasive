#pragma once
#include <iostream>
#include <stdexcept>

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
        try {
            Node* newNode = new Node(value);
            if (!head) {
                head = tail = newNode;
            }
            else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }
        catch (const std::bad_alloc&) {
            throw std::runtime_error("Memory failed");
        }
    }

    void AddAfterTail(T value) {
        try {
            Node* newNode = new Node(value);
            if (!tail) {
                head = tail = newNode;
            }
            else {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
        }
        catch (const std::bad_alloc&) {
            throw std::runtime_error("Memory failed");
        }
    }

    void DeleteFromHead() {
        if (!head) {
            throw std::runtime_error("Cannot delete");
        }

        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void DeleteFromTail() {
        if (!tail) {
            throw std::runtime_error("Cannot delete");
        }

        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void DeleteAll() {
        while (head) {
            DeleteFromHead();
        }
    }

    void Show() {
        if (!head) {
            throw std::runtime_error("Cannot show");
        }

        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    DoubLinLst Clone() {
        DoubLinLst cloneList;
        Node* current = head;
        try {
            while (current) {
                cloneList.AddAfterTail(current->data);
                current = current->next;
            }
        }
        catch (const std::runtime_error& e) {
            throw std::runtime_error("Error clon lst: " + std::string(e.what()));
        }
        return cloneList;
    }

    DoubLinLst operator+(const DoubLinLst& other) {
        DoubLinLst combinedList;
        try {
            Node* current = head;
            while (current) {
                combinedList.AddAfterTail(current->data);
                current = current->next;
            }

            current = other.head;
            while (current) {
                combinedList.AddAfterTail(current->data);
                current = current->next;
            }
        }
        catch (const std::runtime_error& e) {
            throw std::runtime_error("Error comb: " + std::string(e.what()));
        }
        return combinedList;
    }

    DoubLinLst operator*(const DoubLinLst& other) const {
        DoubLinLst intersectionList;
        try {
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
        }
        catch (const std::runtime_error& e) {
            throw std::runtime_error("Error: " + std::string(e.what()));
        }
        return intersectionList;
    }
};
