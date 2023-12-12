#include <iostream>

int main() {
    int outlet1Sales[4] = {10, 12, 15, 10};
    int outlet2Sales[4] = {5, 8, 3, 6};
    int outlet3Sales[4] = {10, 12, 15, 10};
    std::cout << "Total for quarter 1 " << (outlet1Sales[0]+outlet2Sales[0]+outlet3Sales[0])*1000 << std::endl;
    std::cout << "Total for quarter 2 " << (outlet1Sales[1]+outlet2Sales[1]+outlet3Sales[1])*1000 << std::endl;
    std::cout << "Total for quarter 3 " << (outlet1Sales[2]+outlet2Sales[2]+outlet3Sales[2])*1000 << std::endl;
    std::cout << "Total for quarter 4 " << (outlet1Sales[3]+outlet2Sales[3]+outlet3Sales[3])*1000 << std::endl;
    return 0;
}