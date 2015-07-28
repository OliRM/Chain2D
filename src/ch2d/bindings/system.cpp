// ch2d
#include <ch2d/LuaInterface.hpp>

namespace ch2d
{
    void LuaInterface::system_quit(void)
    {
        mRunning = {false};
    }
}
