#include <iostream>
#include "clstud.h"

template <class T>
T GetMax( T a, T b)
{
    return (a>b?a:b);
}

int main()
{
    int i = 1, j = 2, k;

    k = GetMax <int> (i,j);
    std::cout << "Max of " << i << " and " << j << " is " << k << std::endl;

    double di = 3.0, dj = 4.0, dk;
    dk = GetMax <double> (di,dj);
    std::cout << "Max of " << di << " and " << dj << " is " << dk << std::endl;


    double SPIboy[2] = {7, 8};
    double SPIgirl[2] = {8, 9};
    CStudent boy("Adam",SPIboy, 2);
    CStudent girl("Eve",SPIgirl, 2);

    CStudent topper = GetMax <CStudent>(boy, girl);
    std::cout << "The topper is " << topper.getName() << std::endl;

    return 0;
}
