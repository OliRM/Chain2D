// ch2d
#include <ch2d/handlers/TextureHandler.hpp>

namespace ch2d
{
    unsigned int TextureHandler::create(void)
    {
        unsigned int id = 0;

        std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();

        id = mPointerStorage.add(texture);

        return id;
    }
}
