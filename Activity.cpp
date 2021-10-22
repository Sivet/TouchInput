#include "Activity.h"
#include "Event.h"

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