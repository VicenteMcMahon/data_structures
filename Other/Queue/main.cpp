#include <iostream> // Allows outputting to the terminal.

template<typename T, size_t S> // Allows the user to set a typename of T and a size of S for the array.
struct Queue {
    private:
        T* front = queueData; // The front pointer.
        T* rear = queueData - 1; // The rear pointer.
    public:
        size_t size = 0; // Size of the queue.
        T queueData[S] = {}; // The data of the queue.
        void enQueue(T value) {
            // If the array is full, don't add the item.
            if (isFull()) {
                std::cout << "Array is full" << std::endl;
                return;
            }
            rear++; // Increment the rear pointer.
            *rear = value; // Set value to the location of the rear pointer.
            size++; // Increment the size.
        }
        T* deQueue() {
            if (isEmpty()) return NULL; // Don't return anything if there is nothing in the list.
            front++; // Increment the front pointer.
            size--; // Decrement the size.
            return front - 1; // Return the pointer to the element at the original front value.
        }
        size_t isFull() {
            return rear >= queueData + S; // If rear memory adress is bigger than than the memory adress of the end of the list.
        }
        size_t isEmpty() {
            return size == 0;
        }
        void print() {
            for (T* i = front; i <= rear; i++) std::cout << *i << std::endl;
        }
};

int main() {
    Queue<const char*, 5> test{}; // Creates a queue.
    test.enQueue("Bob");
    test.enQueue("Dave");
    test.enQueue("Jane");
    test.deQueue();
    test.enQueue("Julie");
    test.deQueue();
    test.enQueue("Ned");
    test.enQueue("James");
    test.enQueue("No Name");
    test.print(); // Prints the list.
    return 0; // Exit the program with no error value.
}