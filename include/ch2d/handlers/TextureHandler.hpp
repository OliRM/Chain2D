#ifndef CH2D_TEXTUREHANDLER_H
#define CH2D_TEXTUREHANDLER_H

// Standard
#include <memory>

// ch2d
#include <ch2d/common/Handler.hpp>

// SFML
#include <SFML/Graphics.hpp>

namespace ch2d
{
    class TextureHandler : public Handler<sf::Texture>
    {
    public:
        unsigned int load(const std::string&);
    };
}

#endif
