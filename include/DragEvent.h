#pragma once

#include "Event.h"

class DragEvent : public Event
{
  public:
    uint32_t x = 0;
    uint32_t y = 0;

    DragEvent();
    DragEvent(std::ifstream &stream);
    void UpdateActivity(Activity &activity) const;
};