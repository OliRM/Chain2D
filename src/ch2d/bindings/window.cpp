// ch2d
#include <ch2d/System.hpp>

namespace ch2d
{
    void System::window_setView(unsigned int id)
    {
        auto view = mViewHandler.get(id);

        mRenderWindow.setView(*view);
    }
}
