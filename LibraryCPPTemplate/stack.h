#ifndef STACK_TEMPLATE_H
#define STACK_TEMPLATE_H
#include "vector.h"

template <typename Data> class Stack
{
public:
    // Creates empty stack
    Stack()
    {
    }

    // copy constructor
    Stack(const Stack &a)
    {
        data_ = a.data_;
    }

    // assignment operator
    Stack &operator=(const Stack &a)
    {
        if (this != &a) {
            data_= a.data_;
        }
        return *this;
    }

    // Deletes the stack
    ~Stack()
    {
    }

    // Pushes data on top of the stack
    // Should be O(1) on average
    void push(Data value)
    {
        data_.resize(data_.size()+1);
        data_.set(data_.size()-1, value);
    }

    // Retrieves the last element from the stack
    Data get() const
    {
        return data_.get(data_.size()-1);
    }

    // Removes the last element from the stack
    // Should be O(1)
    void pop()
    {
        data_.resize(data_.size()-1);
    }

    // Returns true if the stack is empty
    bool empty() const
    {
        return data_.size()==0;
    }

private:
    Vector<Data> data_;
};

#endif
