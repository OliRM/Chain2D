// ch2d
#include <ch2d/handlers/ViewHandler.hpp>

namespace ch2d
{
    size_t ViewHandler::create(void)
    {
        size_t id = 0;

        std::shared_ptr<sf::View> view = std::make_shared<sf::View>();

        id = mPointerStorage.add(view);

        return id;
    }
}
