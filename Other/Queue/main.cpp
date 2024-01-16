#include <iostream> // Allows outputting to the terminal.

template<typename T, size_t S> // Allows the user to set a typename of T and a size of S for the array.
struct Queue {
    private:
        T* front = queueData; // The front pointer.
        T* rear = queueData - 1; // The rear pointer.
        size_t size = 0; // Size of the queue.
    public:
        T queueData[S] = {}; // The data of the queue.
        void enQueue(T value) {
            // If the array is full, don't add the item.
            if (isFull()) {
                std::cout << "Array is full" << std::endl;
                return;
            }
            rear++;
            if (rear >= queueData + S) rear = queueData;
            *rear = value; // Set value to the location of the rear pointer.
            size++; // Increment the size.
        }
        T* deQueue() {
            if (isEmpty()) return NULL; // Don't return anything if there is nothing in the list.
            front++;
            if (front >= queueData + S) front = queueData;
            size--; // Decrement the size.
            return front - 1; // Return the pointer to the element at the original front value.
        }
        bool isFull() {
            // return rear >= queueData + S; // If rear memory adress is bigger than than the memory adress of the end of the list.
            return size >= S;
        }
        bool isEmpty() {
            return size == 0;
        }
        void print() {
            for (T* i = queueData; i < queueData+S; i++) {
                std::cout << *i << (((i < front && rear > front) || (i > rear && i < front && rear < front)) ? " DELETED" : "") << std::endl;
            }
        }
};

int main() {
    // Queue<unsigned long long int, 32768> test{};
    // for (unsigned long long int i = 0; i < 32768; i++) test.enQueue(i);
    Queue<const char*, 5> test{}; // Creates a queue.
    test.enQueue("Bob");
    test.enQueue("Dave");
    test.enQueue("Jane");
    test.deQueue();
    test.enQueue("Julie");
    test.deQueue();
    test.enQueue("Ned");
    test.enQueue("James");
    test.deQueue();
    test.print(); // Prints the list.
    return 0; // Exit the program with no error value.
}