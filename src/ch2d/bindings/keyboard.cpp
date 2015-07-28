// ch2d
#include <ch2d/System.hpp>

namespace ch2d
{
    bool System::keyboard_isDown(unsigned int key)
    {
        return mEventHandler.keyboard_isDown(key);
    }
}
