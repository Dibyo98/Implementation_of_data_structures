#pragma once

#include <iostream>
#include <stdexcept>

namespace mdd {
template <class _T, std::size_t _N>
class Array {
private:
    _T _data[_N];

public:
    Array() { }
    Array(const Array& arr);
    ~Array() { }

    Array& operator=(const Array& arr);
};

template <class _T, std::size_t _N>
Array<_T, _N>::Array(const Array& arr)
{
    std::copy(arr._data, arr._data + arr._N, _data);
}

template <class _T, std::size_t _N>
Array<_T, _N>& Array<_T, _N>::operator=(const Array& arr)
{
    std::copy(arr._data, arr._data + arr._N, _data);
    return *this;
}
}

/* namespace mdd_bak {
template <class T, std::size_t N>
class Array {
private:
    std::size_t size = N;
    T* pointer;

public:
    T* iterator;

public:
    Array()
    {
        if (size == 0)
            pointer = NULL;
        else
            pointer = new T[size];
    }

    ~Array()
    {
        delete[] pointer;
    }

    T at(std::size_t i)
    {
        if (i < size)
            return *(pointer + i);
        else
            throw std::out_of_range("Array out of bounds exception");
    }

    void put(std::size_t i, T data)
    {
        if (i < size) {
            *(pointer + i) = data;
        } else
            throw std::out_of_range("Array out of bounds exception");
    }

    std::size_t len() { return size; }

    T* begin() { return pointer; }

    T* end() { return (pointer + N); }
};
} // namespace mdd */
