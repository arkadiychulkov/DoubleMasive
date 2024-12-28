#include <iostream>

template<typename T>
class Array {
private:
    struct Node {
        T data;
        bool isEmpty;
        Node* prev;
        Node* next;

        Node() : data(T()), isEmpty(true), prev(nullptr), next(nullptr) {}
        Node(T& value) : data(value), isEmpty(false), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;
    int count;
    int grow;

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
        count = 0;
    }

    Node* getNodeAt(int index) {
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    }

    void addEmptyNodes(int num) {
        for (int i = 0; i < num; i++) {
            Node* newNode = new Node();
            if (!head) {
                head = tail = newNode;
            }
            else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            size++;
        }
    }

public:
    Array() : head(nullptr), tail(nullptr), size(0), count(0), grow(1) {}

    ~Array() {
        clear();
    }

    int GetSize() const {
        return size;
    }

    void SetSize(int newSize, int growStep = 1) {
        this->grow = growStep;

        if (newSize > size) {
            addEmptyNodes(newSize - size);
        }
        else if (newSize < size) {
            Node* current = getNodeAt(newSize);
            while (current) {
                Node* temp = current;
                current = current->next;
                delete temp;
                size--;
                if (count > size)
                    count--;
            }
        }
    }

    int GetUpperBound() {
        if (count > 0)
            return count - 1;
        else
            return 0;
    }

    bool IsEmpty() {
        return count == 0;
    }

    void FreeExtra() {
        if (size > count) {
            Node* current = getNodeAt(count);
            while (current) {
                Node* temp = current;
                current = current->next;
                delete temp;
                size--;
            }
        }
    }

    void RemoveAll() {
        clear();
    }

    T GetAt(int index) const {
        Node* node = getNodeAt(index);
        return node->data;
    }

    void SetAt(int index, const T& value) {
        Node* node = getNodeAt(index);
        node->data = value;
        if (node->isEmpty) {
            node->isEmpty = false;
            count++;
        }
    }

    T& operator[](int index) {
        return getNodeAt(index)->data;
    }

    void Add(const T& value) {
        if (count == size) {
            addEmptyNodes(grow);
        }

        Node* current = getNodeAt(count);
        current->data = value;
        current->isEmpty = false;
        ++count;
    }

    void Append(Array<T>& other) {
        Node* current = other.head;
        while (current) {
            if (!current->isEmpty) {
                Add(current->data);
            }
            current = current->next;
        }
    }

    Array<T>& operator=(Array<T>& other) {
        clear();
        Node* current = other.head;
        while (current) {
            if (!current->isEmpty) {
                Add(current->data);
            }
            else {
                addEmptyNodes(1);
            }
            current = current->next;
        }
        return *this;
    }

    T* GetData() {
        if (IsEmpty())
            return nullptr;
        T* dataArray = new T[count];
        Node* current = head;
        for (int i = 0; i < count; i++) {
            while (current->isEmpty) {
                current = current->next;
            }
            dataArray[i] = current->data;
            current = current->next;
        }
        return dataArray;
    }

    void InsertAt(int index, const T& value) {
        Node* newNode = new Node(value);

        if (index == 0) {
            if (head) {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            else {
                head = tail = newNode;
            }
        }
        else if (index == size) {
            Add(value);
        }
        else {
            Node* current = getNodeAt(index);
            newNode->next = current;
            newNode->prev = current->prev;
            if (current->prev) 
                current->prev->next = newNode;
            current->prev = newNode;
        }

        size++;
        count++;
    }

    void RemoveAt(int index) {
        Node* toRemove = getNodeAt(index);

        if (toRemove->prev) {
            toRemove->prev->next = toRemove->next;
        }
        else {
            head = toRemove->next;
        }

        if (toRemove->next) {
            toRemove->next->prev = toRemove->prev;
        }
        else {
            tail = toRemove->prev;
        }

        if (!toRemove->isEmpty) {
            count--;
        }

        delete toRemove;
        size--;
    }
};
