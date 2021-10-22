#pragma once

#include "Activity.h"

#include <fstream>
#include <iostream>
#include <linux/input.h>

struct InputEvent {
    struct timeval time;
    uint16_t type;
    uint16_t code;
    uint32_t value;
} __attribute__((packed));

class Event
{
  public:
    InputEvent input;

    virtual ~Event()
    {
    }

    virtual void UpdateActivity(Activity &activity) const = 0;
};