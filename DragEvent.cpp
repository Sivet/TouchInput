#include <DragEvent.h>

DragEvent::DragEvent(std::ifstream &stream)
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
    //std::cout << "X: " << x << " Y:" << y << std::endl;
}
void DragEvent::UpdateActivity(Activity &activity) const
{
    if (x == 0) {
        activity.SetCoords(activity.GetCoords()[0], y);
    } else if (y == 0) {
        activity.SetCoords(x, activity.GetCoords()[1]);
    } else {
        activity.SetCoords(x, y);
    }
}