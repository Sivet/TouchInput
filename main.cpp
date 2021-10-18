#include "Event.h"
#include "LiftEvent.h"
#include "PressEvent.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <linux/input.h>
#include <thread>

int main()
{
    std::cout << "Hello" << std::endl;

    std::ifstream touchDriver;

    touchDriver.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    touchDriver.open("/dev/input/event1", std::ifstream::binary);

    InputEvent input;
    touchDriver.read(reinterpret_cast<char *>(&input), sizeof(input));

    //THOUGHT: Have list of "active" presses, clear them all on a lift

    if (input.code == EV_ABS && input.type == ABS_MT_TRACKING_ID && input.value == 0) {
        std::cout << "New Press" << std::endl;
        PressEvent press(touchDriver);
    }
    if (input.code == EV_ABS && input.type == ABS_MT_TRACKING_ID && input.value == 0xFFFFFFFF) {
        std::cout << "New Lift" << std::endl;
        LiftEvent lift(touchDriver);
    }

    /*Event event;
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
    }*/

    touchDriver.close();
    return 0;
}
void PrintEvent(Event &event)
{
}