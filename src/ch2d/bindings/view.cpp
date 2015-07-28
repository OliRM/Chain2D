// ch2d
#include <ch2d/LuaInterface.hpp>

namespace ch2d
{
    unsigned int LuaInterface::view_create(LUA_NUMBER x, LUA_NUMBER y, LUA_NUMBER width, LUA_NUMBER height)
    {
        return mViewHandler.create(x, y, width, height);
    }

    bool LuaInterface::view_remove(unsigned int id)
    {
        return mViewHandler.remove(id);
    }

    void LuaInterface::view_setCenter(unsigned int id, LUA_NUMBER x, LUA_NUMBER y)
    {
        std::shared_ptr<sf::View> view = mViewHandler.get(id);

        view->setCenter(std::floor(x), std::floor(y));
    }
}
