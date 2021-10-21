#pragma once

#include "Event.h"
//#include <fstream>
//#include <iostream>

class PressEvent : public Event
{
  public:
    uint32_t x;
    uint32_t y;

    PressEvent();
    PressEvent(std::ifstream &stream);
    void Read(std::ifstream &stream);
};
