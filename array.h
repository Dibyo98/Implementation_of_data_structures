#pragma once

#include <iostream>
#include <stdexcept>

namespace mdd
{
    template <class T, std::size_t N>
    class array
    {
    private:
        std::size_t size = N;
        T *pointer;

    public:
        array()
        {
            if (size == 0)
                pointer = NULL;
            else
                pointer = new T[size];
        }

        ~array()
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
            if (i < size)
            {
                *(pointer + i) = data;
            }
            else
                throw std::out_of_range("Array out of bounds exception");
        }

        std::size_t len()
        {
            return size;
        }
    };
}