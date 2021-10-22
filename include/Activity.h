#pragma once
#include <array>
#include <iostream>

class Event;

class Activity
{
  private:
    std::array<uint32_t, 2> coords;
    bool pressed;

  public:
    void Handle(const Event &event);
    void SetCoords(uint32_t x, uint32_t y);
    std::array<uint32_t, 2> GetCoords();
    void setPressed(bool isPressed);
    bool IsPressed();
};
