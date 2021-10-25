#include "Activity.h"
#include "DragEvent.h"
#include "LiftEvent.h"
#include "PressEvent.h"

#include <chrono>
#include <linux/input.h>
#include <thread>

Activity::Activity(std::string path)
{
    touchDriver.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    touchDriver.open(path, std::ifstream::binary);

    InputEvent initInput;

    while (true) {
        std::cout << "Checking.." << std::endl;
        //Read
        if (touchDriver.peek() != EOF) {
            touchDriver.read(reinterpret_cast<char *>(&initInput), sizeof(initInput));
            if (initInput.type == EV_ABS && initInput.code == ABS_MT_TRACKING_ID && initInput.value == 0xFFFFFFFF) {
                std::cout << "New Lift" << std::endl;
                Handle(LiftEvent(touchDriver));
            } else if (initInput.type == EV_ABS && initInput.code == ABS_MT_TRACKING_ID) {
                std::cout << "New Press" << std::endl;
                Handle(PressEvent(touchDriver));
            } else if (initInput.type == EV_ABS &&
                       (initInput.code == ABS_MT_POSITION_X || initInput.code == ABS_MT_POSITION_Y)) {
                std::cout << "New Drag" << std::endl;
                Handle(DragEvent(touchDriver));
            }

        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }
}
Activity::~Activity()
{
    touchDriver.close();
}
void Activity::Handle(const Event &event)
{
    event.UpdateActivity(*this);
}

void Activity::SetCoords(uint32_t x, uint32_t y)
{
    std::cout << "X: " << x << " Y:" << y << std::endl;
    coords[0] = x;
    coords[1] = y;
}

std::array<uint32_t, 2> Activity::GetCoords()
{
    if (pressed) {
        return coords;
    } else {
        //Should just throw
        return std::array<uint32_t, 2>{0, 0};
    }
}

void Activity::setPressed(bool isPressed)
{
    if (isPressed) {
        std::cout << "Press" << std::endl;
    } else {
        std::cout << "Lift" << std::endl;
    }
    pressed = isPressed;
}

bool Activity::IsPressed()
{
    return pressed;
}