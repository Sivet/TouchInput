#pragma once

#include <iostream>

struct InputEvent {
    struct timeval time;
    uint16_t type;
    uint16_t code;
    uint32_t value;
} __attribute__((packed));

class Event
{
  public:
    Event();
};