#include <stdio.h>

template <typename T>
struct CanBeNone {
    bool is_none;
    T datum;
};

template <typename T>
struct Node {
    T datum;
    Node<T>* previous;
    constexpr Node(T datum, Node<T>* previous): datum(datum), previous(previous) {}
};

template <typename T>
struct Stack {
    Node<T>* top = NULL;
    ~Stack() {
        traverse([](Node<T>* item) {
            delete item;
        });
    }
    void traverse(void (*callback)(Node<T>* item)) {
        Node<T>* current = top;
        while (current != NULL) {
            Node<T>* previous = current->previous;
            callback(current);
            current = previous;
        }
    }
    bool is_empty(void) {
        return top == NULL;
    }
    void push(T item) {
        top = new Node<T>(item, top);
    }
    CanBeNone<T> pop(void) {
        if (is_empty()) return CanBeNone<T>{true};
        T datum = top->datum;
        Node<T>* to_be_deleted = top;
        top = to_be_deleted->previous;
        to_be_deleted->previous = NULL;
        delete to_be_deleted;
        return CanBeNone<T>{false, datum};
    }
};

void print_help(void) {
    printf("Options: 0 - help, 1 - push, 2 - pop, 3 - is empty, 4 - print list, 5 - clear, 6 - exit.\n");
}

int main(void) {
    Stack<char> stack{};
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
                printf("%d\n", stack.is_empty());
                break;
            case 4:
                stack.traverse([](Node<char>* item) {
                    printf("%c -> ", item->datum);
                });
                printf("NULL\n");
                break;
            case 5:
                printf("\033[H\033[2J\033[3J");
                print_help();
                break;
            case 6:
                return 0;
            default:
                break;
        }
    }
}