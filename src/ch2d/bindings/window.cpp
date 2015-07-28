// ch2d
#include <ch2d/System.hpp>

namespace ch2d
{
    void System::window_setView(unsigned int id)
    {
        std::shared_ptr<sf::View> view = mViewHandler.get(id);

        mRenderWindow.setView(*view);
    }
}
