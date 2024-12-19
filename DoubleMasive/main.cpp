#include <iostream>

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
};

int main() {
    DoubLinLst<int> list;

    list.AddInFrontOfHead(1);
    list.AddAfterTail(2);
    list.AddAfterTail(3);
    list.Show();

    list.DeleteFromHead();
    list.Show();

    list.DeleteFromTail();
    list.Show();

    list.DeleteAll();
    list.Show();

    return 0;
}
