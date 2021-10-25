#pragma once
#include <array>
#include <fstream>
#include <iostream>

class Event;

class Activity
{
  private:
    std::ifstream touchDriver;
    std::array<uint32_t, 2> coords;
    bool pressed;

  public:
    Activity(std::string path);
    ~Activity();

    void Handle(const Event &event);
    void SetCoords(uint32_t x, uint32_t y);
    std::array<uint32_t, 2> GetCoords();
    void setPressed(bool isPressed);
    bool IsPressed();
};
