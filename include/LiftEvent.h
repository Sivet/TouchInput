#pragma once

#include "Event.h"
//#include <fstream>
//#include <iostream>

class LiftEvent : public Event
{
  public:
    LiftEvent(std::ifstream &stream);
    void Read(std::ifstream &stream);
};
