#include <iostream>

int main() {
    /*
    An array is a list of a type of a fixed size.
    */
    char* names[5] = {"Person1", "Person2", "Person3", "Person4", "Person5"};
    for (unsigned int i = 0; i < 5; i++) std::cout << names[i] << std::endl;
    return 0;
}