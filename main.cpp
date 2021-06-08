#include <iostream>

#include "array.hpp"

int main()
{
    mdd::Array<int, 5> arr;

    for (int i = 0; i < arr.len(); i++)
    {
        arr.put(i, 10+i);
    }

    std::cout << arr.at(2) << std::endl;

    return 0;
}