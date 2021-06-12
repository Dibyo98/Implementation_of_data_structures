#include <iostream>

#include "Array.h"

void print_arr(const mdd::Array<int, 5>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " " << std::flush;

    std::cout << std::endl;
}

int main()
{
    mdd::Array<int, 5> arr;

    arr.fill(-2);

    print_arr(arr);

    for (int i = 0; i < arr.size(); i++)
        arr[i] = 10 + i;

    print_arr(arr);
    
	return 0;
}
