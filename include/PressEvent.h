#pragma once

#include "Event.h"

class PressEvent : public Event
{
  public:
    uint32_t x;
    uint32_t y;

    PressEvent(std::ifstream &stream);
    void UpdateActivity(Activity &activity) const;
};
