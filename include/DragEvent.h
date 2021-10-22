#pragma once

#include "Event.h"

class DragEvent : public Event
{
  public:
    uint32_t x;
    uint32_t y;

    DragEvent();
    DragEvent(std::ifstream &stream);
    void UpdateActivity(Activity &activity) const;
};