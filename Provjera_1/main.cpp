#include <iostream>

std::ostream &operator<<(std::ostream &s, const Array &arr)
{
    for (int i = 0; i < arr.size_; ++i)
    {
        s << *(arr.data_ + i) << " ";
    }
    return s;
}

template <typename T>
Array &operator+=(Array &a, Array &b)
{
    int new_size = a.size_ + b.size_;
    T *temp = new T[new_size];
    int i = 0;
    while (i < a.size_)
    {
        temp[i] = *(a.data_ + i);
        ++i;
    }
    int j = 0;
    while (j < b.size_)
    {
        temp[i + j] = *(b.data_ + j);
        ++j;
    }
    delete[] a.data_;
    delete[] b.data_;

    a.data_ = temp;
}