#include <LiftEvent.h>

LiftEvent::LiftEvent(std::ifstream &stream)
{
    stream.read(reinterpret_cast<char *>(&input), sizeof(input));
    while (input.type != 0 || input.value != 0) {
        stream.read(reinterpret_cast<char *>(&input), sizeof(input));
    }
}
void LiftEvent::UpdateActivity(Activity &activity) const
{
    activity.setPressed(false);
}