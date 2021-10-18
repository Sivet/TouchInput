#pragma once

#include "Event.h"

class LiftEvent : public Event
{
  public:
    LiftEvent(std::ifstream &stream);
    ~LiftEvent();
};
