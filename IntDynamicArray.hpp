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

    IntDynamicArray(IntDynamicArray &&da) noexcept;

    ~IntDynamicArray();

    [[nodiscard]] int getSize() const;

    void resize(int newSize);

    long &operator[](int index);

    bool operator==(const IntDynamicArray &tmp);

    bool operator!=(const IntDynamicArray &tmp);

    bool operator<(const IntDynamicArray &rhs) const;

    bool operator>(const IntDynamicArray &rhs) const;

    bool operator<=(const IntDynamicArray &rhs) const;

    bool operator>=(const IntDynamicArray &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, IntDynamicArray &arr);

    friend std::istream &operator>>(std::istream &in, IntDynamicArray &arr);

    IntDynamicArray operator+(IntDynamicArray &tmp);

    IntDynamicArray &operator=(IntDynamicArray &&tmp) noexcept;

    IntDynamicArray &operator=(const IntDynamicArray &tmp);
};
