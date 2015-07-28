// ch2d
#include <ch2d/handlers/SpriteHandler.hpp>

namespace ch2d
{
    unsigned int SpriteHandler::create(void)
    {
        unsigned int id = 0;

        std::shared_ptr<sf::Sprite> sprite = std::make_shared<sf::Sprite>();

        id = mPointerStorage.add(sprite);

        return id;
    }
}
