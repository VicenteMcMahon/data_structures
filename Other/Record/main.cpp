#include <iostream>

struct Record {
    void* elements;
    Record(void* elements): elements(elements) {}
};

int main() {
    int numbers[3] = {1,2,3};
    Record test{&numbers};
    for (unsigned int i = 0; i < 3; i++) std::cout << *((int*)(test.elements)+i) << std::endl;
    return 0;
}