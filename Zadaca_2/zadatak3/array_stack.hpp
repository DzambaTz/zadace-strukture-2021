#pragma once
#include "stack_interface.h"
#include <cstddef>
#include <iostream>

template <typename T>
class Array_stack : public stack_interface<T>
{
private:
    size_t capacity_;
    size_t top_index_;
    size_t size_;
    T *array;

public:
    //Constructors and assignment operators
    Array_stack() : capacity_(0), top_index_(0), size_(0), array(nullptr) {}
    Array_stack(const Array_stack &);
    Array_stack(Array_stack &&);
    Array_stack &operator=(const Array_stack &);
    Array_stack &operator=(Array_stack &&);
    ~Array_stack() { delete[] array; }

    //Methods
    void push(const T &val);
    void push(T &&val);
    T &top();
    const T &top() const;
    void pop();
    size_t size() const;
    bool empty() const;

    //Other operators
    template <typename Type>
    friend inline std::ostream &operator<<(std::ostream &, const Array_stack<Type> &);
    bool operator==(const Array_stack &);
    bool operator!=(const Array_stack &other) { return !operator==(other); };
    Array_stack operator+(const Array_stack &);
};

//Copy constructor
template <typename T>
Array_stack<T>::Array_stack(const Array_stack<T> &other)
    : capacity_(other.size_), top_index_(other.top_index_), size_(other.size_)
{
    array = new T[other.size_];
    for (size_t i = 0; i < other.size_; ++i)
    {
        array[i] = other.array[i];
    }
}

//Move constructor
template <typename T>
Array_stack<T>::Array_stack(Array_stack<T> &&other)
    : capacity_(other.size_), top_index_(other.top_index_), size_(other.size_)
{
    array = other.array;
    other.array = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
    other.top_index_ = 0;
}

//Copy assignment operator
template <typename T>
Array_stack<T> &Array_stack<T>::operator=(const Array_stack<T> &other)
{
    delete[] array;
    capacity_ = other.size_;
    top_index_ = other.top_index_;
    size_ = other.size_;

    array = new T[other.size_];
    for (size_t i = 0; i < other.size_; ++i)
    {
        array[i] = other.array[i];
    }

    return *this;
}

//Move assignment operator
template <typename T>
Array_stack<T> &Array_stack<T>::operator=(Array_stack<T> &&other)
{
    capacity_ = other.size_;
    top_index_ = other.top_index_;
    size_ = other.size_;

    std::swap(array, other.array);

    other.size_ = 0;
    other.capacity_ = 0;
    other.top_index_ = 0;

    return *this;
}

//Pushes (by copy) a value to the top of the stack
template <typename T>
void Array_stack<T>::push(const T &val)
{
    if (size_ < capacity_)
    {
        array[size_] = val;
        ++size_;
        ++top_index_;
    }
    else
    {
        T *new_array = new T[capacity_ + 1];
        if (!empty())
        {
            for (size_t i = 0; i < capacity_; ++i)
            {
                new_array[i] = array[i];
            }
        }
        new_array[capacity_] = val;

        delete[] array;
        array = new_array;

        ++capacity_;
        top_index_ = size_;
        ++size_;
    }
}

//Moves the specified value to the top of the stack
template <typename T>
void Array_stack<T>::push(T &&val)
{
    if (size_ < capacity_)
    {
        array[size_] = std::move(val);
        ++size_;
        ++top_index_;
    }
    else
    {
        T *new_array = new T[capacity_ + 1];
        if (!empty())
        {
            for (size_t i = 0; i < capacity_; ++i)
            {
                new_array[i] = array[i];
            }
        }
        new_array[capacity_] = std::move(val);

        delete[] array;
        array = new_array;

        ++capacity_;
        top_index_ = size_;
        ++size_;
    }
}

//Returns the top element of the stack
template <typename T>
T &Array_stack<T>::top()
{
    if (!empty())
    {
        return array[top_index_];
    }
    else
    {
        throw "Cannot read from empty stack!";
    }
}

//Same top method but for cases when the top object is const
template <typename T>
const T &Array_stack<T>::top() const
{
    if (!empty())
    {
        return array[top_index_];
    }
    else
    {
        throw "Cannot read from empty stack!";
    }
}

//Pops (removes) the top element (doesn't delete the top element just shrinks the readable range)
template <typename T>
void Array_stack<T>::pop()
{
    if (!empty())
    {
        --top_index_;
        --size_;
    }
}

//Returns the number of elements on the stack
template <typename T>
size_t Array_stack<T>::size() const
{
    return size_;
}

//Returns true if the stack is empty and vice versa
template <typename T>
bool Array_stack<T>::empty() const
{
    return size_ ? false : true;
}

//Overload for the << (left shift) operator so we can print the stack easier
template <typename T>
std::ostream &operator<<(std::ostream &s, const Array_stack<T> &stack)
{
    for (int i = stack.top_index_; i >= 0; --i)
    {
        s << stack.array[i] << " ";
    }
    return s;
}

//Operator == that compares two stacks, and returns true if they are
//equal in size and they have the same elements
template <typename T>
bool Array_stack<T>::operator==(const Array_stack<T> &other)
{
    if (size_ != other.size_)
    {
        return false;
    }

    for (size_t i = 0; i < size_; ++i)
    {
        if (array[i] != other.array[i])
        {
            return false;
        }
    }

    return true;
}

//Operator + that enables addition of the stacks.
//The two stacks (operands) get copied to a new (third) stack.
template <typename T>
Array_stack<T> Array_stack<T>::operator+(const Array_stack<T> &other)
{
    Array_stack<T> new_stack;
    for (size_t i = 0; i < size_; ++i)
    {
        new_stack.push(array[i]);
    }

    for (size_t i = 0; i < other.size_; ++i)
    {
        new_stack.push(other.array[i]);
    }

    //std::move(new_stack) is optional and shows no change in performance with -O2 enabled
    return new_stack;
}