//#include "Event.h"
#include "DragEvent.h"
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

    Activity activity;
    InputEvent initInput;

    while (true) {
        std::cout << "Checking.." << std::endl;
        //Read
        if (touchDriver.peek() != EOF) {
            touchDriver.read(reinterpret_cast<char *>(&initInput), sizeof(initInput));
            if (initInput.type == EV_ABS && initInput.code == ABS_MT_TRACKING_ID && initInput.value == 0xFFFFFFFF) {
                std::cout << "New Lift" << std::endl;
                activity.Handle(LiftEvent(touchDriver));
            } else if (initInput.type == EV_ABS && initInput.code == ABS_MT_TRACKING_ID) {
                std::cout << "New Press" << std::endl;
                activity.Handle(PressEvent(touchDriver));
            } else if (initInput.type == EV_ABS &&
                       (initInput.code == ABS_MT_POSITION_X || initInput.code == ABS_MT_POSITION_Y)) {
                std::cout << "New Drag" << std::endl;
                activity.Handle(DragEvent(touchDriver));
            }

        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }
    touchDriver.close();
    return 0;
}