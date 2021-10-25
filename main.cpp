#include "Activity.h"
#include <iostream>

int main()
{
    std::cout << "Hello" << std::endl;

    Activity activity("/dev/input/event1");

    return 0;
}