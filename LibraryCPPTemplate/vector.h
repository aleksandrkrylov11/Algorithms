#ifndef VECTOR_TEMPLATE_H
#define VECTOR_TEMPLATE_H

#include <cstddef>

template <typename Data> class Vector
{
public:
    // Creates vector
    Vector()
    {
        size_ =0;
        reserved=0;
        data_=nullptr;
    }

    // copy constructor
    Vector(const Vector &a)
    {
        copyvec(a);
    }

    // assignment operator
    Vector &operator=(const Vector &a)
    {
        if (this != &a) {
            delete[] data_;
            copyvec(a);
        }
        return *this;
    }

    // Deletes vector structure and internal data
    ~Vector()
    {
        delete[] data_;
    }

    // Retrieves vector element with the specified index
    Data get(size_t index) const
    {
        return data_[index];
    }

    // Sets vector element with the specified index
    void set(size_t index, Data value)
    {
        data_[index]= value;
    }

    // Retrieves current vector size
    size_t size() const
    {
        return size_;
    }

    // Changes the vector size (may increase or decrease)
    // Should be O(1) on average
    void resize(size_t size)
    {
        if (size>reserved) {
            size_t newReserved = reserved*2;
            if (newReserved<size) newReserved = size;
            Data* newData = new Data[newReserved];
            for (size_t i=0; i <size_; i++) newData[i]= data_[i];
            delete[] data_;
            data_ = newData;
            reserved = newReserved;
        }
        size_=size;
    }

private:
    void copyvec(const Vector &a) {
        size_=a.size_;
        reserved = a.reserved;
        data_=new Data[reserved];
        for (size_t i=0;i<size_;i++) data_[i] =a.data_[i];

    }
    Data* data_;
    size_t size_;
    size_t reserved;
    
};

#endif
