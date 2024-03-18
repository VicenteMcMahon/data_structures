#include <iostream> // Imports functions that allow for outputting to the terminal in the 'std' namespace.

template<typename T> // Defines a generic type 'T'.
struct Node {
    public:
        T datum; // Makes a piece of datum called 'datum' that is of type 'T'.
        Node<T>* next; // This is the pointer tp the next node.
        constexpr Node(T datum, Node<T>* next): datum(datum), next(next) {} // The constructor method.
        ~Node(void) { // The destructor method to clear the memory which is stored on the heap.
            // std::cout << "DELETED" << std::endl;
            if (next != NULL) delete next; // Deletes the next node if not null. This calles the destructor of the next item and then clears it from memory.
        }
};

template<typename T> // Defines a generic type 'T'.
struct LinkedList {
    private:
        Node<T>* head; // Makes a private node pointer called 'head'.
    public:
        constexpr LinkedList(T item) { // The constructor method.
            head = new Node<T>(item, NULL); // Creates a new node on to the heap with a pointer to NULL and item as the piece of datum.
        }
        ~LinkedList(void) { // The destructor method.
            delete head; // Deletes the first item in the linked list. This calls its destructor method.
        }
        constexpr Node<T>* get(int index) {
            int i = 0; // The current item index, not the target index called 'index'.
            Node<T>* next_item = head;
            while (next_item != NULL && i < index) { // Goes until at end of list or 'i' is at the index.
                next_item = next_item->next; // Makes the value of 'next_item' the next item of the linked list.
                i++; // Increments 'i';
            }
            return i == index ? next_item : NULL; // Returns 'next_item' if at correct index, otherwise it returns a null pointer.
        }
        constexpr void add_start(T item) {
            head = new Node<T>(item, head); // Creates a new node to the heap which the head pointer is set to and the new node pointer is set to the old pointer.
        }
        constexpr void remove_start(void) {
            Node<T> *last_head = head; // Stores the location to the last head pointer.
            if (head == NULL) return; // Makes sure it isn't a null pointer.
            head = head->next;
            last_head->next = NULL;
            delete last_head; // Deletes the 'Node' to prevent memory leaks.
        }
        constexpr void add(T item, int index) {
            if (index <= 0) return add_start(item); // If index is 0, then it is the same as 'add_start'.
            Node<T>* current = get(index - 1);
            if (current == NULL) return;
            current->next = new Node<T>(item, current->next);
        }
        constexpr void remove(int index) {
            if (index <= 0) return remove_start(); // If index is 0, then it is the same as 'remove_start'.
            Node<T>* current = get(index - 1);
            if (current->next == NULL) return; // Makes sure it isn't removing a null pointer.
            Node<T>* old_next = current->next; // Saves the old next value for deletion.
            current->next = current->next->next; // Skips over the value to be deleted.
            old_next->next = NULL; // Makes 'old_next' next null because of deletion.
            delete old_next; // Clears up the memory.
        }
        constexpr void print(void) {
            Node<T>* next_item = head;
            while (next_item != NULL) {
                std::cout << next_item->datum << std::endl;
                next_item = next_item->next;
            }
        }
};

int main(void) {
    LinkedList<int> test{1};
    test.add(2, 0);
    test.print();
    return 0;
}