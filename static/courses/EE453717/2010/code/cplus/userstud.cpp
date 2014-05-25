#include <iostream>
#include <string>
#include "clstud.h"


int main()
{
    double SPI[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    CStudent boy("Adam", SPI, 8);

    std::cout << "Name:" << boy.getName() << std::endl;
    std::cout << boy.getName() << "'s CPI:" << boy.getCPI() << std::endl;

    {
        CStudent boy_clone = boy;
        
        std::cout << "Name:" << boy_clone.getName() << std::endl;
        std::cout << boy_clone.getName() << "'s CPI:" << boy_clone.getCPI() << std::endl;
    }
        
    std::cout << "Changing SPI..." << std::endl;
    boy.setSPI(0, 9);

    return 0;
}
