#include "IntDynamicArray.hpp"
#include <exception>
#include "CannotBeCompared.hpp"

using namespace std;

IntDynamicArray::IntDynamicArray()
{
    arr = new long[10];
    size = 10;
}
IntDynamicArray::IntDynamicArray(int size)
{
    this->arr = new long[size];
    this->size = size;
}
IntDynamicArray::IntDynamicArray(int size, long n)
{
    this->arr = new long[size];
    this->size = size;
    for (int i = 0; i<size; i++){
        arr[i] = n;
    }
}
IntDynamicArray::IntDynamicArray(IntDynamicArray &da):arr(new long(da.size)),size(da.size) {
    for (int i = 0; i<size; i++){
        IntDynamicArray::arr[i] = da.arr[i];
    }
}

IntDynamicArray::IntDynamicArray(IntDynamicArray &&da) noexcept {
    size = da.size;
    arr = da.arr;
    da.arr = nullptr;
}

IntDynamicArray::~IntDynamicArray() {
    arr = nullptr;
}

int IntDynamicArray::getSize() const {
    return size;
}

long& IntDynamicArray::operator[](int index){
    return arr[index];
}

void IntDynamicArray::resize(int newSize) {
    long *arr1 = new long[newSize];
    for (int i = 0; i<this->size; i++){
        arr1[i] = this->arr[i];
    }
    if (newSize > this->size) {
        for (int i = this->size; i<newSize; i++){
            arr1[i] = 0;
        }
    }
    this->size = newSize;
    this->arr = arr1;
}

IntDynamicArray &IntDynamicArray::operator=(IntDynamicArray &&tmp) noexcept {
    delete this;
    size = tmp.size;
    arr = tmp.arr;
    tmp.arr = nullptr;
    return *this;
}

IntDynamicArray &IntDynamicArray::operator=(const IntDynamicArray &tmp) {
    delete this;
    size = tmp.size;
    arr = new long[size];
    for (int i = 0; i < size; i++){
        arr[i] = tmp.arr[i];
    }
    return *this;
}

bool IntDynamicArray::operator==(const IntDynamicArray &tmp) {
    if (size == tmp.size){
        for (int i = 0; i<size; i++){
            if (arr[i]!= tmp.arr[i]) return false;
        }
        return true;
    } else return false;
}

bool IntDynamicArray::operator!=(const IntDynamicArray &tmp) {
    if (size != tmp.size) return true;
    for (int i = 0; i<size; i++){
        if (arr[i] != tmp.arr[i]) return true;
    }
    return false;
}

bool IntDynamicArray::operator<(const IntDynamicArray &rhs) const {
    if(size != rhs.size) throw CannotBeCompared();
    int countComp = 0;
    bool isLes;
    for (int i = 0; i<size; i++){
        if (arr[i] != rhs.arr[i]){
            countComp++;
            isLes = arr[i] != rhs.arr[i];
        }
    }
    if (countComp >1) throw CannotBeCompared();
    if ((countComp ==1)&&(isLes)) {return true;} else return false;
}

bool IntDynamicArray::operator>(const IntDynamicArray &rhs) const {
    return rhs < *this;
}

bool IntDynamicArray::operator<=(const IntDynamicArray &rhs) const {
    return !(rhs < *this);
}

bool IntDynamicArray::operator>=(const IntDynamicArray &rhs) const {
    return !(*this < rhs);
}

IntDynamicArray &IntDynamicArray::operator+(IntDynamicArray &tmp) {
    IntDynamicArray sumA(size+tmp.size);
    long *tmpArr = new long[size+tmp.size];
    for(int i=0; i<size; i++){
        tmpArr[i] = arr[i];
    }
    for (int i = size; i<size+tmp.size; i++){
        tmpArr[i] = tmp.arr[i];
    }
    sumA.arr = tmpArr;
    return sumA;
}

std::ostream &operator<<(ostream &os, IntDynamicArray &arr) {
    os << "Size: " << arr.size << endl << "Array:" << endl;
    for (int i = 0; i<arr.size; i++){
        os << "[" << i << "] = " << arr[i] << endl;
    }
    return os;
}

std::istream &operator>>(istream &in, IntDynamicArray &arr) {
    for (int i = 0; i<arr.getSize(); i++){
        in >> arr[i];
    }
    return in;
}

