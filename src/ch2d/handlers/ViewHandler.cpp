// ch2d
#include <ch2d/handlers/ViewHandler.hpp>

namespace ch2d
{
    unsigned int ViewHandler::create(void)
    {
        unsigned int id = 0;

        std::shared_ptr<sf::View> view = std::make_shared<sf::View>();

        id = mPointerStorage.add(view);

        return id;
    }
}
