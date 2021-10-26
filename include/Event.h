#pragma once

#include <iostream>
#include <linux/input.h>

struct EventInput {
    struct timeval time;
    uint16_t type;
    uint16_t code;
    uint32_t value;
} __attribute__((packed));

enum class eventType {
    Press,
    Drag,
    Lift
};

class Event
{
  public:
    eventType type;
    uint32_t x;
    uint32_t y;

    Event()
    {
    }
    ~Event()
    {
    }
};