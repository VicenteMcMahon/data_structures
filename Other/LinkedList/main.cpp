#include <iostream>

template<typename T>
struct Node {
    T data;
    Node* next;
};

template<typename T>
struct LinkedList {
    Node<T> head;
};

int main() {
    LinkedList<int> test{Node<int>{1, NULL}};
    Node<int> next{2, NULL};
    test.head.next = &next;
    std::cout << test.head.next->data << std::endl;
    return 0;
}