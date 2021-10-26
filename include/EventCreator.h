#include "Event.h"
#include <fstream>
#include <iostream>

class EventCreator
{
  private:
    std::ifstream touchDriver;
    EventInput eventInput;

    void ReadType(Event &event);
    void ReadBody(Event &event);

  public:
    EventCreator();
    ~EventCreator();

    bool HasNewEvents();
    Event GetEvent();
};
