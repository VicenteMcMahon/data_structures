#include <iostream>
#include <strings.h>

template <typename T>
struct Node {
    T datum;
    int8_t next;
    constexpr Node() {}
    constexpr Node(T datum, int8_t next): datum(datum), next(next) {}
};

template <typename T, const size_t L>
struct ArrayLinkedList {
    // The head index.
    int head = -1;
    // To allow for the program to know where to put the item in the list.
    int next_free_item = 0;
    // The array.
    Node<T> array[L];
    // The function to get an item by traversing through the list.
    constexpr Node<T>* get(int index) {
        unsigned int i = 0;
        int next_item = head;
        while (next_item > 0 && i < index) {
            next_item = array[next_item].next;
            i++;
        }
        return array + next_item; // What about error?
    }
    constexpr void add_start(T item) {
        array[next_free_item] = Node<T>(item, head);
        head = next_free_item;
        next_free_item++;
    }
    constexpr void remove_start(void) {
        Node<T> last_head = array[head];
        if (head < 0) return;
        head = array[head].next;
        last_head.next = -1;
    }
    constexpr void add(T item, int index) {
        if (index <= 0) return add_start(item);
        Node<T>* current = get(index - 1);
        // if (current < 0) return;
        array[next_free_item] = Node<T>(item, current->next);
        current->next = next_free_item;
        next_free_item++;
    }
    constexpr void remove(int index) {
        if (index <= 0) return remove_start();
        Node<T>* current = get(index - 1);
        if (current->next < 0) return;
        int8_t old_next = current->next;
        current->next = array[current->next].next;
        array[old_next].next = -1;
    }
    constexpr void print() {
        int8_t next_item = head;
        while (next_item >= 0) {
            std::cout << array[next_item].datum << std::endl;
            next_item = array[next_item].next;
        }
    }
};


void menu() {
    printf("OPTIONS: 0 - help, 1 - print, 2 - add start, 3 - remove start, 4 - add, 5 - remove, 6 - exit, 7 - clear screen\n");
}

int main(void) {
    ArrayLinkedList<std::string, 12> list{};
    // Allows user to use list.
    unsigned int option;
    menu();
    while (true) {
        printf(">> ");
        std::cin >> option;
        if (option == 0) menu();
        else if (option == 1) list.print();
        else if (option == 2) {
            std::string item;
            std::cout << "Item Name: ";
            std::cin >> item;
            list.add_start(item);
        } else if (option == 3) list.remove_start();
        else if (option == 4) {
            std::string item;
            std::cout << "Item Name: ";
            std::cin >> item;
            unsigned int index;
            std::cout << "Index: ";
            std::cin >> index;
            list.add(item, index);
        } else if (option == 5) {
            unsigned int index;
            std::cout << "Index: ";
            std::cin >> index;
            list.remove(index);
        } else if (option == 6) return 0;
        else if (option == 7) system("clear");
    }
    return 0;
}