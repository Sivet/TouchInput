#pragma once

#include "Event.h"

class PressEvent : public Event
{
  public:
    uint32_t x = 0;
    uint32_t y = 0;

    PressEvent(std::ifstream &stream);
    void UpdateActivity(Activity &activity) const;
};
