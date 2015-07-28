// ch2d
#include <ch2d/LuaInterface.hpp>

namespace ch2d
{
    LUA_NUMBER LuaInterface::mouse_x(void)
    {
        return mEventHandler.mouse_x();
    }

    LUA_NUMBER LuaInterface::mouse_y(void)
    {
        return mEventHandler.mouse_y();
    }

    bool LuaInterface::mouse_isDown(unsigned int key)
    {
        return mEventHandler.mouse_isDown(key);
    }
}
