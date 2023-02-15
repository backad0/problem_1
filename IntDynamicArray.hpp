#include <istream>


class IntDynamicArray {
private:
    long *arr;
    int size;
public:
    IntDynamicArray();
    IntDynamicArray(int size);
    IntDynamicArray(int size, long n);
    IntDynamicArray(IntDynamicArray &da);
    ~IntDynamicArray();

    int getSize();
    long& operator[](int index);

};
