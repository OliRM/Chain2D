// ch2d
#include <ch2d/System.hpp>

namespace ch2d
{
    unsigned int System::shape_rectangle_create(void)
    {
        unsigned int id = 0;

        auto rectangle = std::make_shared<sf::RectangleShape>();

        id = mDrawableHandler.add(rectangle);

        return id;
    }

    bool System::shape_rectangle_setSize(unsigned int id, LUA_NUMBER width, LUA_NUMBER height)
    {
        auto rectangle = static_cast<sf::RectangleShape*>((mDrawableHandler.get(id)).get());

        if(nullptr == rectangle)
        {
            return false;
        }

        rectangle->setSize(sf::Vector2f(width, height));

        return true;
    }

    std::tuple<LUA_NUMBER, LUA_NUMBER> System::shape_rectangle_getSize(unsigned int id)
    {
        std::tuple<LUA_NUMBER, LUA_NUMBER> data {0.f, 0.f};

        auto rectangle = static_cast<sf::RectangleShape*>((mDrawableHandler.get(id)).get());

        if(nullptr == rectangle)
        {
            return data;
        }

        sf::Vector2f dimensions = rectangle->getSize();

        data = std::make_tuple(dimensions.x, dimensions.y);

        return data;
    }
}
