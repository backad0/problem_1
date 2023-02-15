#include "IntDynamicArray.hpp"

IntDynamicArray::IntDynamicArray():size(10),arr(new long(10))
{}
IntDynamicArray::IntDynamicArray(int size):arr(new long(size)), size(size)
{}
IntDynamicArray::IntDynamicArray(int size, long n):arr(new long(size)), size(size)
{
    for (int i = 0; i<size; i++){
        arr[i] = n;
    }
}
IntDynamicArray::IntDynamicArray(IntDynamicArray &da):arr(new long(da.size)),size(da.size) {
    for (int i = 0; i<size; i++){
        IntDynamicArray::arr[i] = da.arr[i];
    }
}
IntDynamicArray::~IntDynamicArray() {
    delete this;
}

int IntDynamicArray::getSize() {
    return size;
}

long& IntDynamicArray::operator[](int index){
    return arr[index];
}

