#include "Event.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>

int main()
{
    std::cout << "Hello" << std::endl;

    std::ifstream touchDriver;

    touchDriver.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    touchDriver.open("/dev/input/event1", std::ifstream::binary);

    Event event;
    InputEvent input;
    while (true) {
        while (touchDriver.peek() != EOF) {
            touchDriver.read(reinterpret_cast<char *>(&input), sizeof(input));
            //read
            while (input.value != 0) {
                event.inputs.push_back(input);
                touchDriver.read(reinterpret_cast<char *>(&input), sizeof(input));
            }
            //print
            std::cout << "Size: " << std::dec << event.inputs.size() << std::endl;
            for (size_t i = 0; i < event.inputs.size(); i++) {
                std::cout << std::hex << event.inputs[i].time.tv_usec << " ";
                std::cout << std::hex << event.inputs[i].code << " ";
                std::cout << std::hex << event.inputs[i].type << " ";
                std::cout << std::hex << event.inputs[i].value << " ";
                std::cout << std::endl;
            }
            event.inputs.clear();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return 0;
}
