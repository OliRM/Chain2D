// ch2d
#include <ch2d/handlers/SpriteHandler.hpp>

namespace ch2d
{
    size_t SpriteHandler::create(void)
    {
        size_t id = 0;

        std::shared_ptr<sf::Sprite> sprite = std::make_shared<sf::Sprite>();

        id = mPointerStorage.add(sprite);

        return id;
    }
}
