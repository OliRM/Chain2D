// ch2d
#include <ch2d/handlers/TextureHandler.hpp>

namespace ch2d
{
    size_t TextureHandler::create(void)
    {
        size_t id = 0;

        std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();

        id = mPointerStorage.add(texture);

        return id;
    }
}
