// ch2d
#include <ch2d/System.hpp>

namespace ch2d
{
    unsigned int System::view_create(LUA_NUMBER x, LUA_NUMBER y, LUA_NUMBER width, LUA_NUMBER height)
    {
        return mViewHandler.create(x, y, width, height);
    }

    bool System::view_remove(unsigned int id)
    {
        return mViewHandler.remove(id);
    }

    void System::view_setCenter(unsigned int id, LUA_NUMBER x, LUA_NUMBER y)
    {
        std::shared_ptr<sf::View> view = mViewHandler.get(id);

        view->setCenter(std::floor(x), std::floor(y));
    }
}
