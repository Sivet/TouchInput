#include "EventCreator.h"
#include "Rect.h"

#include <chrono>
#include <iostream>
#include <thread>

using namespace rsp::graphics;

static Rect rect(Point(200, 10), Point(400, 750));

bool isHitSimple(const Point &aPoint, const Rect &aRect)
{
    // Only works with non-rotated rectangles
    if (aPoint.GetX() > aRect.GetTopLeft().GetX() and
        aPoint.GetX() < aRect.GetBottomRight().GetX() and
        aPoint.GetY() > aRect.GetTopLeft().GetY() and
        aPoint.GetY() < aRect.GetBottomRight().GetY())
        return true;

    return false;
}

void PrintEvent(Event event)
{
    if (event.type == EventType::Press) {
        std::cout << "New Press" << std::endl;
        std::cout << "X: " << event.x << " Y: " << event.y << std::endl;
        bool hit = isHitSimple(Point(event.x, event.y), rect);
        std::cout << "Hit is: " << hit << std::endl;
    }
    if (event.type == EventType::Drag) {
        std::cout << "New Drag" << std::endl;
        std::cout << "X: " << event.x << " Y: " << event.y << std::endl;
    }
    if (event.type == EventType::Lift) {
        std::cout << "New Lift" << std::endl;
    }
}

int main()
{
    std::cout << "Hello" << std::endl;

    EventCreator evtCreator;
    while (true) {
        std::cout << "Checking.." << std::endl;
        // Check for input
        if (evtCreator.HasNewEvents()) {
            PrintEvent(evtCreator.GetEvent());
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }

    return 0;
}