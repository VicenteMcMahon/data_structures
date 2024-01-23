#include <iostream> // Allows outputting to the terminal.

template<typename T, size_t S> // Allows the user to set a typename of T and a size of S for the array.
struct Queue { // Defines a data structure called 'Queue'.
    private: // Where the private properties and methods are defined.
        T queueData[S] = {}; // The data of the queue.
        T* front = queueData; // The front pointer.
        T* rear = queueData - 1; // The rear pointer.
        size_t size = 0; // Size of the queue.
    public: // Where the public properties and methods are defined.
        void enQueue(T value) { // Defines a procedure called 'enQueue' that takes in a value of type 'T'.
            if (isFull()) { // If the array is full, don't add the item.
                std::cout << "Array Is Full" << std::endl; // Outputs 'Array is full' to the console.
                return; // Exits the function.
            } // End of the if statement.
            rear++; // Increment the rear pointer to point to the next item in the array.
            if (rear >= queueData + S) rear = queueData; // If the rear pointer has gone beyond the array, set the pointer to the start of the array.
            *rear = value; // Set value to the location of the rear pointer.
            size++; // Increment the size.
        } // End of the procedure 'enQueue'.
        T* deQueue() { // Defines a function called 'deQueue' that returns a value of type 'T' which is the item that got deleted.
            if (isEmpty()) return NULL; // Don't return anything if there is nothing in the array.
            front++; // Increment the front pointer to point to the next item in the array.
            if (front >= queueData + S) front = queueData; // If the front pointer has gone beyond the array, set the pointer to the start of the array.
            size--; // Decrement the size.
            return front - 1; // Return the pointer to the element at the original front value.
        } // End of the function 'deQueue'.
        bool isFull() { // Defines a function called 'isFull' that returns a value of type 'bool'.
            return size >= S; // Returns 'true' if the size is bigger than or equal to the maximum, it is full.
        } // End of function called 'isFull'.
        bool isEmpty() { // Defines a function called 'isEmpty' that returns a value of type 'bool'.
            return size == 0; // Returns 'true' if the size is equal to zero.
        } // End of function called 'isEmpty'.
        void print() { // Defines a procedure called 'print'.
            for (T* i = queueData; i < queueData+S; i++) // Goes through the list. i is a pointer that is set at the start of the list, and it gets incremented by one to point to the next item in the list until it reaches the end.
                std::cout << *i << (((i < front && rear > front) || (i > rear && i < front && rear < front)) ? " DELETED" : "") << "\n"; // Checks if item has or has not been deleted using the postion of the rear and front pointers. It then prints out each item to the screen and if it has been deleted it would add 'DELETED' to the end.
        } // End of procedure called 'isEmpty'.
}; // End of struct called 'Queue'.

int main() { // Defines a function called 'main' that returns the type 'int'.
    Queue<const char*, 5> test{}; // Creates a queue.
    test.enQueue("Bob"); // Adds 'Bob' to the queue.
    test.enQueue("Dave I"); // Adds 'Dave I' to the queue.
    test.enQueue("Jane"); // Adds 'Jane' to the queue.
    test.deQueue(); // Removes the front item('Bob') from the queue.
    test.enQueue("Julie"); // Adds 'Julie' to the queue.
    test.deQueue(); // Removes the front item('Dave I') from the queue.
    test.enQueue("Ned"); // Adds 'Ned' to the queue.
    test.enQueue("James"); // Adds 'James' to the queue.
    test.enQueue("Alfed"); // Adds 'Alfred' to the queue.
    test.deQueue(); // Removes the front item('Jane') from the queue.
    test.enQueue("Dave II"); // Adds 'Dave II' to the queue.
    test.enQueue("Not Added To Queue"); // Cannot add anything else to the queue because it is full.
    test.deQueue(); // Removes the front item('Julie') from the queue.
    test.enQueue("Added To Queue"); // Adds 'Added To Queue' to the queue.
    test.print(); // Prints the array.
    return 0; // Exit the program with no error value.
} // End of function 'main'.