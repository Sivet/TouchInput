#include <LiftEvent.h>

LiftEvent::LiftEvent(std::ifstream &stream)
{
    std::cout << "Lift" << std::endl;
    while (input.type != 0 && input.value != 0) {
        stream.read(reinterpret_cast<char *>(&input), sizeof(input));
    }
}
void LiftEvent::Read(std::ifstream &stream)
{
}