#include <iostream>
#define LENGTH(x) sizeof(x) / sizeof(x[0])

int main(void) {
    // Creates the list.
    int list1[3] = {1, 128, 256};
    int list2[6] = {-1, 6, 9, 10, 15, 19};
    // Creates the merged list variable.
    int mergedList[LENGTH(list1)+LENGTH(list2)];
    // The index of the merged list.
    unsigned int index = 0;
    // The index of the first list.
    unsigned int i = 0;
    // The index of the second list.
    unsigned int j = 0;
    // Loops through until all items of merged list are added.
    while (index < LENGTH(list1)+LENGTH(list2)) {
        // If list1 item > list2 item and some checks to make sure that the index is in range.
        if (i >= LENGTH(list1) || (j <  LENGTH(list2) && list1[i] > list2[j])) {
            mergedList[index] = list2[j];
            // Increments the second list number.
            j++;
        } else {
            mergedList[index] = list1[i];
            // Increments the first list number.
            i++;
        }
        index++;
    }
    // Outputs the list.
    for (int& a : mergedList) {
        std::cout << a << "\n";
    }
}