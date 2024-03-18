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
    constexpr Node<T>* get_index(int index) {
        // Checking value.
        unsigned int i = 0;
        // Next pointer.
        int next_item = head;
        // Loop while next the pointer has a value and the checking index is smaller than the target index.
        while (next_item > 0 && i < index) {
            // Goes to next item.
            next_item = array[next_item].next;
            // Increments the checking value.
            i++;
        }
        // This adds the offset of next pointer to the array pointer which is a pointer to the item the user wants in the array.
        return array + next_item;
    }
    constexpr Node<T>* get_previous_value(T value) {
        // Next pointer.
        int next_index = head;
        // Loop while next the pointer has a value and the checking index is smaller than the target index.
        while (next_index > 0 && array[next_index].next > 0 && array[array[next_index].next].datum != value) {
            // Goes to next item.
            next_index = array[next_index].next;
        }
        // This adds the offset of next pointer to the array pointer which is a pointer to the item the user wants in the array.
        return array + next_index;
    }
    constexpr Node<T>* get_value(T value) {
        return array + array[get_previous_value(value)->next].next;
    }
    constexpr void add_start(T item) {
        // Sets the next free space in the array to the new node.
        array[next_free_item] = Node<T>(item, head);
        // Sets head pointer to the next free space.
        head = next_free_item;
        // Increments the next free space.
        next_free_item++;
    }
    constexpr void remove_start(void) {
        // The original head pointer.
        Node<T> original_head = array[head];
        // If it's smaller than zero, then the pointer is null.
        if (head < 0) return;
        // Sets the head pointer to the next.
        head = array[head].next;
        original_head.next = -2;
        // Decrements the next free item.
        next_free_item--;
    }
    constexpr void add_index(T item, int index) {
        // If the index is zero, then it is the same as 'add_start'.
        if (index <= 0) return add_start(item);
        // Gets the current value.
        Node<T>* current = get_index(index - 1);
        // if (current < 0) return;
        array[next_free_item] = Node<T>(item, current->next);
        current->next = next_free_item;
        next_free_item++;
    }
    constexpr void remove_index(int index) {
        if (index <= 0) return remove_start();
        Node<T>* current = get_index(index - 1);
        if (current->next < 0) return;
        int8_t old_next = current->next;
        current->next = array[current->next].next;
        array[old_next].next = -2;
    }
    constexpr void add_value(T value) {
        Node<T>* current = get_previous_value(value);
        array[next_free_item] = Node<T>(item, current->next);
        current->next = next_free_item;
        next_free_item++;
    }
    constexpr void remove_value(T value) {
        Node<T>* current = get_previous_value(value);
        if (current->next < 0) return;
        int8_t old_next = current->next;
        current->next = array[current->next].next;
        array[old_next].next = -2;
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
    printf("OPTIONS: 0 - help, 1 - print, 2 - add start, 3 - remove start, 4 - add index, 5 - remove index, 6 - exit, 7 - clear screen, 8 - get index, 9 - get value, 10 - add value, 11 - remove value\n");
}

#define INPUT_ITEM(n)\
    std::string item##n;\
    std::cout << "Item Name: ";\
    std::cin >> item##n;

#define INPUT_INDEX(n)\
    unsigned int index##n;\
    std::cout << "Index: ";\
    std::cin >> index##n;

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
            INPUT_ITEM()
            list.add_start(item);
        } else if (option == 3) list.remove_start();
        else if (option == 4) {
            INPUT_ITEM()
            INPUT_INDEX()
            list.add_index(item, index);
        } else if (option == 5) {
            INPUT_INDEX()
            list.remove_index(index);
        } else if (option == 6) return 0;
        else if (option == 7) system("clear");
        else if (option == 8) {
            INPUT_INDEX()
            std::cout << list.get_index(index)->datum << std::endl;
        } else if (option == 9) {
            INPUT_ITEM()
            std::cout << list.get_value(item)->datum << std::endl;
        } else if (option == 10) {
            INPUT_ITEM(1)
            INPUT_ITEM(2)
            // list.add_value(item1)
            //TODO FIX ADD VALUE
        }
    }
    return 0;
}