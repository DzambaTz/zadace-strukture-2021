#pragma once
#include "stack_interface.h"
#include <cstddef>
#include <iostream>

template <typename T>
class List_stack : public stack_interface<T>
{
private:
    struct Node
    {
        friend List_stack;
        Node *next_;
        T data_;
        Node() : next_(nullptr) {}
        Node(const T &val, Node *const next) : next_(next), data_(val) {}
        Node(T &&val, Node *const next) : next_(next), data_(std::move(val)) {}
    };

    Node *top_;
    size_t size_;

public:
    //Konstruktori i operatori dodjeljivanja
    List_stack() : top_(nullptr), size_(0) {}
    List_stack(Node *top, size_t size) : top_(top), size_(size) {}
    List_stack(const List_stack &);
    List_stack(List_stack &&);
    List_stack &operator=(const List_stack &);
    List_stack &operator=(List_stack &&);
    ~List_stack();

    //Metode
    void push(const T &val);
    void push(T &&val);
    T &top();
    const T &top() const;
    void pop();
    inline size_t size() const { return size_; };
    inline bool empty() const { return size_ ? false : true; };

    //Ostali operatori
    template <typename Type>
    friend inline std::ostream &operator<<(std::ostream &s, const List_stack<Type> &stack)
    {
        Node *tmp = stack.top_;
        for (size_t i = 0; i < stack.size_; ++i)
        {
            s << tmp->data_ << " ";
            tmp = tmp->next_;
        }
        return s;
    }
    bool operator==(const List_stack &);
    bool operator!=(const List_stack &other) { return !operator==(other); };
    List_stack operator+(const List_stack &);
};

template <typename T>
List_stack<T>::List_stack(const List_stack<T> &other)
{
    Node *tmp1 = other.top_->next_;
    top_ = new Node(other.top_->data_, nullptr);
    Node *tmp2 = top_;

    for (size_t i = 0; i < other.size_ - 1; ++i)
    {
        tmp2->next_ = new Node(tmp1->data_, nullptr);
        tmp2 = tmp2->next_;
        tmp1 = tmp1->next_;
    }

    size_ = other.size_;
}

template <typename T>
List_stack<T>::List_stack(List_stack<T> &&other)
{
    top_ = other.top_;
    size_ = other.size_;
    other.top_ = nullptr;
    other.size_ = 0;
}

template <typename T>
List_stack<T> &List_stack<T>::operator=(const List_stack<T> &other)
{
    for (size_t i = 0; i < size_; ++i)
    {
        pop();
    }

    Node *tmp1 = other.top_->next_;
    top_ = new Node(other.top_->data_, nullptr);
    Node *tmp2 = top_;

    for (size_t i = 0; i < other.size_ - 1; ++i)
    {
        tmp2->next_ = new Node(tmp1->data_, nullptr);
        tmp2 = tmp2->next_;
        tmp1 = tmp1->next_;
    }

    size_ = other.size_;
    return *this;
}

template <typename T>
List_stack<T> &List_stack<T>::operator=(List_stack<T> &&other)
{
    for (size_t i = 0; i < size_; ++i)
    {
        pop();
    }
    top_ = other.top_;
    size_ = other.size_;
    other.top_ = nullptr;
    other.size_ = 0;
    return *this;
}

template <typename T>
List_stack<T>::~List_stack()
{
    for (size_t i = 0; i < size_; ++i)
    {
        pop();
    }
}

template <typename T>
void inline List_stack<T>::push(const T &val)
{
    top_ = new Node(val, top_);
    ++size_;
}

template <typename T>
void inline List_stack<T>::push(T &&val)
{
    top_ = new Node(std::move(val), top_);
    ++size_;
}

template <typename T>
T &List_stack<T>::top()
{
    if (!empty())
    {
        return top_->data_;
    }
    else
    {
        throw "Cannot read from empty stack!";
    }
}

template <typename T>
const T &List_stack<T>::top() const
{
    if (!empty())
    {
        return top_->data_;
    }
    else
    {
        throw "Cannot read from empty stack!";
    }
}

template <typename T>
void List_stack<T>::pop()
{
    Node *temp = top_;
    top_ = top_->next_;
    delete temp;
    --size_;
    if (empty())
    {
        top_ = nullptr;
    }
}

template <typename T>
bool List_stack<T>::operator==(const List_stack<T> &other)
{
    if (size_ != other.size_)
    {
        return false;
    }
    Node *top_tmp = top_;
    Node *other_top_tmp = other.top_;

    for (size_t i = 0; i < size_; ++i)
    {
        if (top_tmp->data_ != other_top_tmp->data_)
        {
            return false;
        }
        top_tmp = top_tmp->next_;
        other_top_tmp = other_top_tmp->next_;
    }

    return true;
}

template <typename T>
List_stack<T> List_stack<T>::operator+(const List_stack<T> &other)
{
    Node *new_top = new Node(top_->data_, nullptr);
    Node *tmp2 = new_top;
    Node *tmp1 = top_->next_;

    for (size_t i = 0; i < size_ - 1; ++i)
    {
        tmp2->next_ = new Node(tmp1->data_, nullptr);
        tmp2 = tmp2->next_;
        tmp1 = tmp1->next_;
    }

    tmp1 = top_;

    for (size_t i = 0; i < other.size_; ++i)
    {
        tmp2->next_ = new Node(tmp1->data_, nullptr);
        tmp2 = tmp2->next_;
        tmp1 = tmp1->next_;
    }

    return List_stack(new_top, size_ + other.size_);
}
