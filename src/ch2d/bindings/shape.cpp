// ch2d
#include <ch2d/System.hpp>

namespace ch2d
{
    bool System::shape_setTexture(unsigned int shapeId, unsigned int textureId)
    {
        auto shape = mShapeHandler.get(shapeId);

        auto texture = mTextureHandler.get(textureId);

        if(nullptr == shape || nullptr == texture)
        {
            return false;
        }

        shape->setTexture(texture.get());

        return true;
    }

    bool System::shape_setTextureRect(unsigned int id, LUA_NUMBER top, LUA_NUMBER left, LUA_NUMBER width, LUA_NUMBER height)
    {
        auto shape = mShapeHandler.get(id);

        if(nullptr == shape)
        {
            return false;
        }

        shape->setTextureRect(sf::IntRect(top, left, width, height));

        return true;
    }

    bool System::shape_setFillColor(unsigned int id, LUA_NUMBER r, LUA_NUMBER g, LUA_NUMBER b, LUA_NUMBER a)
    {
        auto shape = mShapeHandler.get(id);

        if(nullptr == shape)
        {
            return false;
        }

        shape->setFillColor(sf::Color(r, g, b, a));

        return true;
    }

    bool System::shape_setOutlineColor(unsigned int id, LUA_NUMBER r, LUA_NUMBER g , LUA_NUMBER b, LUA_NUMBER a)
    {
        auto shape = mShapeHandler.get(id);

        if(nullptr == shape)
        {
            return false;
        }

        shape->setOutlineColor(sf::Color(r, g, b, a));

        return true;
    }

    bool System::shape_setOutlineThickness(unsigned int id, LUA_NUMBER thickness)
    {
        auto shape = mShapeHandler.get(id);

        if(nullptr == shape)
        {
            return false;
        }

        shape->setOutlineThickness(thickness);

        return true;
    }

    bool System::shape_setPosition(unsigned int id, LUA_NUMBER x, LUA_NUMBER y)
    {
        auto shape = mShapeHandler.get(id);

        if(nullptr == shape)
        {
            return false;
        }

        shape->setPosition(sf::Vector2f(std::floor(x), std::floor(y)));

        return true;
    }

    bool System::shape_setOrigin(unsigned int id, LUA_NUMBER x, LUA_NUMBER y)
    {
        auto shape = mShapeHandler.get(id);

        if(nullptr == shape)
        {
            return false;
        }

        shape->setOrigin(std::floor(x), std::floor(y));

        return true;
    }
    bool System::shape_setRotation(unsigned int id, LUA_NUMBER rotation)
    {
        auto shape = mShapeHandler.get(id);

        if(nullptr == shape)
        {
            return false;
        }

        shape->setRotation(rotation);

        return true;
    }

    bool System::shape_setScale(unsigned int id, LUA_NUMBER x, LUA_NUMBER y)
    {
        auto shape = mShapeHandler.get(id);

        if(nullptr == shape)
        {
            return false;
        }

        shape->setScale(x, y);

        return true;
    }

    std::tuple<LUA_NUMBER, LUA_NUMBER, LUA_NUMBER, LUA_NUMBER> System::shape_getTextureRect(unsigned int id)
    {
        std::tuple<LUA_NUMBER, LUA_NUMBER, LUA_NUMBER, LUA_NUMBER> data {0.f, 0.f, 0.f, 0.f};

        auto shape = mShapeHandler.get(id);

        if(nullptr == shape)
        {
            return data;
        }

        auto textureRect = shape->getTextureRect();

        data = std::make_tuple(textureRect.left, textureRect.top, textureRect.width, textureRect.height);

        return data;
    }

    std::tuple<LUA_NUMBER, LUA_NUMBER, LUA_NUMBER, LUA_NUMBER> System::shape_getFillColor(unsigned int id)
    {
        std::tuple<LUA_NUMBER, LUA_NUMBER, LUA_NUMBER, LUA_NUMBER> data {0.f, 0.f, 0.f, 0.f};

        auto shape = mShapeHandler.get(id);

        if(nullptr == shape)
        {
            return data;
        }

        auto fillColor = shape->getFillColor();

        data = std::make_tuple(fillColor.r, fillColor.g, fillColor.b, fillColor.a);

        return data;
    }

    std::tuple<LUA_NUMBER, LUA_NUMBER, LUA_NUMBER, LUA_NUMBER> System::shape_getOutlineColor(unsigned int id)
    {
        std::tuple<LUA_NUMBER, LUA_NUMBER, LUA_NUMBER, LUA_NUMBER> data {0.f, 0.f, 0.f, 0.f};

        auto shape = mShapeHandler.get(id);

        if(nullptr == shape)
        {
            return data;
        }

        auto outlineColor = shape->getOutlineColor();

        data = std::make_tuple(outlineColor.r, outlineColor.g, outlineColor.b, outlineColor.a);

        return data;
    }

    LUA_NUMBER System::shape_getOutlineThickness(unsigned int id)
    {
        auto shape = mShapeHandler.get(id);

        if(nullptr == shape)
        {
            return 0.f;
        }

        return shape->getOutlineThickness();
    }

    std::tuple<LUA_NUMBER, LUA_NUMBER> System::shape_getPosition(unsigned int id)
    {
        std::tuple<LUA_NUMBER, LUA_NUMBER> data {0.f, 0.f};

        auto shape = mShapeHandler.get(id);

        if(nullptr == shape)
        {
            return data;
        }

        auto position = shape->getPosition();

        data = std::make_tuple(position.x, position.y);

        return data;
    }

    std::tuple<LUA_NUMBER, LUA_NUMBER> System::shape_getOrigin(unsigned int id)
    {
        std::tuple<LUA_NUMBER, LUA_NUMBER> data {0.f, 0.f};

        auto shape = mShapeHandler.get(id);

        if(nullptr == shape)
        {
            return data;
        }

        auto origin = shape->getPosition();

        data = std::make_tuple(origin.x, origin.y);

        return data;
    }

    LUA_NUMBER System::shape_getRotation(unsigned int id)
    {
        auto shape = mShapeHandler.get(id);

        if(nullptr == shape)
        {
            return 0.f;
        }

        return shape->getRotation();
    }

    std::tuple<LUA_NUMBER, LUA_NUMBER> System::shape_getScale(unsigned int id)
    {
        std::tuple<LUA_NUMBER, LUA_NUMBER> data {0.f, 0.f};

        auto shape = mShapeHandler.get(id);

        if(nullptr == shape)
        {
            return data;
        }

        auto scale =  shape->getScale();

        return std::make_tuple(scale.x, scale.y);
    }
}
