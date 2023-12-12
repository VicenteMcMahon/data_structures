#include <iostream>
#define NUMBER_OF_NUMBERS 6

int main() {
    int numbers[NUMBER_OF_NUMBERS];
    int total = 0;
    for (unsigned int i = 0; i < NUMBER_OF_NUMBERS; i++) {
        std::cout << "Number " << i+1 << ": ";
        std::cin >> numbers[i];
        total += numbers[i];
    }
    std::cout << "[";
    for (int i = NUMBER_OF_NUMBERS-1; i >= 0; i--) {
        std::cout << numbers[i];
        if (i != 0) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
    std::cout << "Total: " << total << " Average: " << total / NUMBER_OF_NUMBERS << std::endl;
    return 0;
}