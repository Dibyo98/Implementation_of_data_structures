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
    mdd::Array<int, 5> arrt = { 1, 2, 3, 4, 5 };

    arr.fill(-2);

    mdd::Array<int, 5> arr2 = arr;
    mdd::Array<int, 5> arr3;

    arr3 = arrt;

    print_arr(arr);
    print_arr(arr2);
    print_arr(arr3);
    print_arr(arrt);

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = 10 + i;
        arr2[i] = 20 + i;
        arr3[i] = 30 + i;
    }

    print_arr(arr);
    print_arr(arr2);
    print_arr(arr3);
    print_arr(arrt);
    
	return 0;
}
