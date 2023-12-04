#include <iostream>

int main() {
    int numbers[6];
    for (uint i = 0; i < 6; i++) {
        std::cout << "Number " << i+1 << ": ";
        std::cin >> numbers[i];
    }
    std::cout << "[";
    for (uint i = 0; i < 6; i++) {
        std::cout << numbers[i];
        if (i != 5) std::cout << ", ";
    }
    std::cout << "]";
    std::cout << std::endl;
    return 0;
}