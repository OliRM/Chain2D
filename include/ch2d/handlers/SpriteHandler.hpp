#ifndef CH2D_SPRITEHANDLER_H
#define CH2D_SPRITEHANDLER_H

// Standard
#include <memory>

// ch2d
#include <ch2d/common/Handler.hpp>

// SFML
#include <SFML/Graphics.hpp>

namespace ch2d
{
    class SpriteHandler : public Handler<sf::Sprite>
    {
    public:
        size_t create(void);
    };
}

#endif
