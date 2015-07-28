// ch2d
#include <ch2d/System.hpp>

namespace ch2d
{
    unsigned int System::viewport_create(LUA_NUMBER x, LUA_NUMBER y, LUA_NUMBER width, LUA_NUMBER height)
    {
        return mViewportHandler.create(x, y, width, height);
    }

    bool System::viewport_remove(unsigned int id)
    {
        return mViewportHandler.remove(id);
    }
}
