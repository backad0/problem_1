#include <iostream>
#include "IntDynamicArray.hpp"

int main() {
    IntDynamicArray arr(10, 5);
    /*for (int i = 0; i<arr.getSize(); i++){
        std::cin >> arr[i];
    }*/
    std::cin >> arr;
    std::cout << arr;
}
