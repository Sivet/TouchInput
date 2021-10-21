#include <PressEvent.h>

PressEvent::PressEvent()
{
    std::cout << "Fuck" << std::endl;
}
PressEvent::PressEvent(std::ifstream &stream)
{
    std::cout << "Press" << std::endl;
    stream.read(reinterpret_cast<char *>(&input), sizeof(input));
    while (input.type != 0 || input.value != 0) {
        if (input.type == EV_ABS && input.code == ABS_X) {
            x = input.value;
        }
        if (input.type == EV_ABS && input.code == ABS_Y) {
            y = input.value;
        }
        stream.read(reinterpret_cast<char *>(&input), sizeof(input));
    }
    std::cout << "X: " << x << " Y:" << y << std::endl;
}
void PressEvent::Read(std::ifstream &stream)
{
}