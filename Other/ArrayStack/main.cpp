#include <stdio.h>
#include <stdint.h>

template <typename T, size_t S>
struct Stack {
    private:
        T array[S] = {};
        T* top = array - 1;
    public:
        bool is_full(void) {
            return top == array + S - 1;
        }
        bool is_empty(void) {
            return top < array;
        }
        void push(T item) {
            if (is_full()) printf("Error!\n");
            top++;
            *top = item;
        }
        T* pop(void) {
            if (is_empty()) return NULL;
            return top--;
        }
};

int main(void) {
    Stack<uint8_t, 5> stack{};
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    uint8_t* item = NULL;
    do {
        item = stack.pop();
        if (item != NULL) printf("%u\n", *item);
    } while (item != NULL);
    
    // printf("%d\n", *stack.pop());
    return 0;
}