// ch2d
#include <ch2d/System.hpp>

namespace ch2d
{
    LUA_NUMBER System::mouse_x(void)
    {
        return mEventHandler.mouse_x();
    }

    LUA_NUMBER System::mouse_y(void)
    {
        return mEventHandler.mouse_y();
    }

    bool System::mouse_isDown(unsigned int key)
    {
        return mEventHandler.mouse_isDown(key);
    }
}
