#include <PressEvent.h>

PressEvent::PressEvent(std::ifstream &stream)
{
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
}
void PressEvent::UpdateActivity(Activity &activity) const
{
    activity.setPressed(true);
    activity.SetCoords(x, y);
}