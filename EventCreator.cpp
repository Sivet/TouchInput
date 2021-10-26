#include "EventCreator.h"

#include <linux/input.h>

EventCreator::EventCreator()
{
    touchDriver.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    touchDriver.open("/dev/input/event1", std::ifstream::binary);
}

EventCreator::~EventCreator()
{
    touchDriver.close();
}

bool EventCreator::HasNewEvents()
{
    if (touchDriver.peek() == EOF) {
        return false;
    }
    return true;
}

Event EventCreator::GetEvent()
{
    Event newEvent;

    ReadType(newEvent);
    ReadBody(newEvent);

    return newEvent;
}

void EventCreator::ReadType(Event &event)
{
    touchDriver.read(reinterpret_cast<char *>(&eventInput), sizeof(eventInput));
    if (eventInput.type == EV_ABS && eventInput.code == ABS_MT_TRACKING_ID && eventInput.value == 0xFFFFFFFF) {
        event.type = eventType::Lift;
    } else if (eventInput.type == EV_ABS && eventInput.code == ABS_MT_TRACKING_ID) {
        event.type = eventType::Press;
    } else if (eventInput.type == EV_ABS &&
               (eventInput.code == ABS_MT_POSITION_X || eventInput.code == ABS_MT_POSITION_Y)) {
        event.type = eventType::Drag;
    }
}

void EventCreator::ReadBody(Event &event)
{
    while (eventInput.type != 0 || eventInput.value != 0) {
        if (eventInput.type == EV_ABS && eventInput.code == ABS_X) {
            event.x = eventInput.value;
        }
        if (eventInput.type == EV_ABS && eventInput.code == ABS_Y) {
            event.y = eventInput.value;
        }
        touchDriver.read(reinterpret_cast<char *>(&eventInput), sizeof(eventInput));
    }
}