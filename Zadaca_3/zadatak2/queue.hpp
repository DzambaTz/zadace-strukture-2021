#pragma once
#include <iostream>
#include <cstddef>

template <typename T>
class Queue
{
    size_t capacity_;
    size_t head_ = 0;
    size_t tail_ = 0;
    bool full_ = false;

    T *buffer_;

public:
    //Constructors
    Queue() : capacity_(100), buffer_(new T[capacity_]) {}
    Queue(size_t capacity) : capacity_(capacity), buffer_(new T[capacity_]) {}
    Queue(const Queue &other);
    Queue(Queue &&other);
    ~Queue() { delete[] buffer_; }

    //Methods
    template <typename U>
    void push(U &&value);
    T pop();
    size_t size();
    size_t capacity() { return capacity_; };
    bool empty() { return size() == 0; };
    T &top() { return buffer_[tail_]; };
    const T &top() const { return buffer_[tail_]; };
};

template <typename T>
Queue<T>::Queue(const Queue &other) : capacity_(other.capacity_), head_(other.head_), tail_(other.tail_), full_(other.full_), buffer_(new T[capacity_])
{
    for (size_t i = 0; i < capacity_; ++i)
    {
        buffer_[i] = other.buffer_[i];
    }
}

template <typename T>
Queue<T>::Queue(Queue &&other) : capacity_(other.capacity_), head_(other.head_), tail_(other.tail_), full_(other.full_), buffer_(other.buffer_)
{
    other.buffer_ = buffer_;
    other.capacity_ = 0;
    other.head_ = 0;
    other.tail_ = 0;
}

template <typename T>
template <typename U>
void Queue<T>::push(U &&value)
{
    buffer_[head_] = std::forward<U>(value);
    if (full_)
    {
        tail_ = (tail_ + 1) % capacity_;
    }
    head_ = (head_ + 1) % capacity_;
    full_ = head_ == tail_;
}

template <typename T>
T Queue<T>::pop()
{
    if (empty())
    {
        throw std::underflow_error("The accessed queue is empty!");
    }

    T value = buffer_[tail_];
    tail_ = (tail_ + 1) % capacity_;
    full_ = false;

    return value;
}

template <typename T>
size_t Queue<T>::size()
{
    if (full_)
    {
        return capacity_;
    }

    if (head_ >= tail_)
    {
        return head_ - tail_;
    }
    else
    {
        return capacity_ - tail_ + head_;
    }
}