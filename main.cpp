#include "EventCreator.h"
#include <iostream>

#include <chrono>
#include <thread>

void PrintEvent(Event event)
{
    if (event.type == eventType::Press) {
        std::cout << "New Press" << std::endl;
        std::cout << "X: " << event.x << " Y: " << event.y << std::endl;
    }
    if (event.type == eventType::Drag) {
        std::cout << "New Drag" << std::endl;
        std::cout << "X: " << event.x << " Y: " << event.y << std::endl;
    }
    if (event.type == eventType::Lift) {
        std::cout << "New Lift" << std::endl;
    }
}

int main()
{
    std::cout << "Hello" << std::endl;

    EventCreator evtCreator;
    while (true) {
        std::cout << "Checking.." << std::endl;
        //Check for input
        if (evtCreator.HasNewEvents()) {
            PrintEvent(evtCreator.GetEvent());
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }

    return 0;
}