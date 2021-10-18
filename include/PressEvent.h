#pragma once

#include "Event.h"

class PressEvent : public Event
{
  public:
    uint16_t x;
    uint16_t y;

    PressEvent(std::ifstream &stream);
    ~PressEvent();
};
