#pragma once

#include <iostream>
#include <vector>

struct InputEvent {
    struct timeval time;
    uint16_t type;
    uint16_t code;
    uint32_t value;
} __attribute__((packed));

class Event
{
  public:
    std::vector<InputEvent> inputs;

    Event();
    ~Event();
};