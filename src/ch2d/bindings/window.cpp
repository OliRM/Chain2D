// ch2d
#include <ch2d/LuaInterface.hpp>

namespace ch2d
{
    void LuaInterface::window_setView(unsigned int id)
    {
        std::shared_ptr<sf::View> view = mViewHandler.get(id);

        mRenderWindow.setView(*view);
    }
}
