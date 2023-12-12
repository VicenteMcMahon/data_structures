#include <iostream>
#define NUMBER_OF_NAMES 5

int main() {
    char* names[NUMBER_OF_NAMES] = {"Person1", "Person2", "Person3", "Person4", "Person5"};
    std::string search;
    std::cout << "Name of person: ";
    std::cin >> search;
    for (unsigned int i = 0; i < NUMBER_OF_NAMES; i++)
        if (names[i] == search) std::cout << "The record number for " << names[i] << " is " << i+1 << std::endl;
    return 0;
}