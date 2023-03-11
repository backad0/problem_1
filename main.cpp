#include <iostream>
#include "IntDynamicArray.hpp"
using namespace std;

int main() {
    IntDynamicArray arr(10, 5);
    IntDynamicArray arr1(10, 5);
    IntDynamicArray arr6(10, 6);
    //cout << arr<< endl << arr1;
    IntDynamicArray arr2(move(arr));
    IntDynamicArray arr3(arr1);
    cout << endl << arr1 << endl << arr2;
    arr2.resize(15);
    //cout << arr2;
    //cout << endl << arr2[9] << endl;
    cout << (arr1 == arr2) << endl << (arr1 != arr2) << endl;
    arr3[0] = 6;
    //cout << (arr3>arr1) << endl;
    //IntDynamicArray arr4 = arr1 + arr2;
    //cout << arr4.getSize();
    //cout << arr1<< endl << arr2;
    IntDynamicArray arr5(4);
    //cin >> arr5;
    //cout << arr5;

    return 0;
}
