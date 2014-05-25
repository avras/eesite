#include <iostream>

int main()
{
    int numElements, *numArray;
    std::cout << "Enter length of integer array: ";
    std::cin >> numElements;
    try
    {
        numArray = new int[numElements];
    }
    catch(std::bad_alloc)
    {
        std::cout << "Memory allocation failed." << std::endl;
        return 1;
    }
    delete[] numArray;
    return 0;
}
