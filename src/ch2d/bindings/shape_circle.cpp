// ch2d
#include <ch2d/System.hpp>

namespace ch2d
{
    unsigned int System::shape_circle_create(void)
    {
        unsigned int id = 0;

        auto circle = std::make_shared<sf::CircleShape>();

        id = mDrawableHandler.add(circle);

        return id;
    }

    bool System::shape_circle_setRadius(unsigned int id, LUA_NUMBER radius)
    {
        auto circle = static_cast<sf::CircleShape*>((mDrawableHandler.get(id)).get());

        if(nullptr == circle)
        {
            return false;
        }

        circle->setRadius(radius);

        return true;
    }

    LUA_NUMBER System::shape_circle_getRadius(unsigned int id)
    {
        auto circle = static_cast<sf::CircleShape*>((mDrawableHandler.get(id)).get());

        if(nullptr == circle)
        {
            return 0;
        }

        auto radius = circle->getRadius();

        return radius;
    }
}
