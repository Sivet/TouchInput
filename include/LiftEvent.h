#pragma once

#include "Event.h"

class LiftEvent : public Event
{
  public:
    LiftEvent(std::ifstream &stream);
    void UpdateActivity(Activity &activity) const;
};
