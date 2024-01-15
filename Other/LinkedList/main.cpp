#include <iostream>

template<typename T>
struct Node {
    T data;
    Node* next;
};

template<typename T>
struct LinkedList {
    Node<T>* head;
    Node<T>* end;
    LinkedList(T item) {
        head = new(item, NULL);
        end = head;
    }
    ~LinkedList() {
        
    }
    void insert(T item) {

    }
};

int main() {
    LinkedList<int> test{1};
    Node<int> next{2, NULL};
    test.head.next = &next;
    std::cout << test.head.next->data << std::endl;
    return 0;
}