#include <stdio.h>

// This is required for pop as it can be null. T is a gneric type of the datum.
template <typename T>
struct CanBeNone {
    bool is_none;
    T datum;
};

// This contains a piece of datum and the previous pointer. This is used in a linked list.
template <typename T>
struct Node {
    T datum;
    Node<T> *previous;
    constexpr Node(T datum, Node<T> *previous): datum(datum), previous(previous) {}
};

// This is the data type that needs to be coded.
template <typename T>
struct Stack {
    Node<T> *top = NULL;
    ~Stack() {
        // This goes through the list and deletes all items. This is required to prevent memory leaks.
        traverse([](Node<T> *item) {
            delete item;
        });
    }
    // This method allows the caller to pass a callback function which will be ran on every element in the list.
    constexpr void traverse(void (*callback)(Node<T> *item)) {
        Node<T> *current = top;
        while (current != NULL) {
            Node<T> *previous = current->previous;
            callback(current);
            current = previous;
        }
    }
    constexpr bool is_empty(void) {
        return top == NULL;
    }
    constexpr void push(T item) {
        top = new Node<T>(item, top);
    }
    // Needs extra code because sometimes it cannot return a value. This occures when the list is empty. Also the node needs to be deleted in memory to save memory.
    constexpr CanBeNone<T> pop(void) {
        if (is_empty()) return CanBeNone<T>{true};
        T datum = top->datum;
        Node<T> *to_be_deleted = top;
        top = to_be_deleted->previous;
        to_be_deleted->previous = NULL;
        delete to_be_deleted;
        return CanBeNone<T>{false, datum};
    }
};

// Prints the help menu.
void print_help(void) {
    printf("Options: 0 - help, 1 - push, 2 - pop, 3 - is empty, 4 - print list, 5 - clear, 6 - exit and 7 - exit & clear.\n");
}

int main(void) {
    // Creates a stack.
    Stack<char> stack{};
    // Code for the menu.
    unsigned int option;
    char value;
    print_help();
    while (true) {
        printf(">> ");
        scanf("%d", &option);
        switch (option) {
            case 0:
                print_help();
                break;
            case 1:
                printf("Input value: ");
                scanf(" %c", &value);
                stack.push(value);
                break;
            case 2: {
                CanBeNone<char> returned_item = stack.pop();
                if (!returned_item.is_none) printf("Returned: %c\n", returned_item.datum);
                else printf("Cannot delete item; the list is empty.\n");
                break;
            }
            case 3:
                printf("%s\n", stack.is_empty() ? "true" : "false");
                break;
            case 4:
                printf("|HEAD| -> ");
                stack.traverse([](Node<char> *item) {
                    printf("%c\n", item->datum);
                    printf("          ");
                });
                printf("NULL\n");
                break;
            case 5:
                printf("\033[H\033[2J\033[3J");
                print_help();
                break;
            case 6:
                return 0;
            case 7:
                printf("\033[H\033[2J\033[3J");
                return 0;
            default:
                printf("Unknown Command.\n");
                print_help();
                break;
        }
    }
}