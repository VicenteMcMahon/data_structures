#include <iostream>
#define NUMBER_OF_OUTLETS 50

int main() {
    int outletSales[NUMBER_OF_OUTLETS][4] = {};
    int quaterSales[4] = {0, 0, 0, 0};
    for (unsigned int i = 0; i < NUMBER_OF_OUTLETS; i++) {
        int sales[4] = {0, 0, 0, 0};
        *outletSales[i] = *sales;
    }
    outletSales[1][1] = 1;
    outletSales[2][1] = 1;
    outletSales[49][2] = 3;
    for (unsigned int i = 0; i < NUMBER_OF_OUTLETS; i++) for (unsigned int j = 0; j < 4; j++) quaterSales[j] += outletSales[i][j];
    std::cout << quaterSales[0] << " " << quaterSales[1] << " " << quaterSales[2] << " " << quaterSales[3] << std::endl;
    return 0;
}