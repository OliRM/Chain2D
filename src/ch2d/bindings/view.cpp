// ch2d
#include <ch2d/System.hpp>

namespace ch2d
{
    unsigned int System::view_create(void)
    {
        return mViewHandler.create();
    }

    bool System::view_remove(unsigned int id)
    {
        return mViewHandler.remove(id);
    }

    bool System::view_setCenter(unsigned int id, LUA_NUMBER x, LUA_NUMBER y)
    {
        auto view = mViewHandler.get(id);

        if(nullptr == view)
        {
            return false;
        }

        view->setCenter(x, y);

        return true;
    }

    bool System::view_setSize(unsigned int id, LUA_NUMBER width, LUA_NUMBER height)
    {
        auto view = mViewHandler.get(id);

        if(nullptr == view)
        {
            return false;
        }

        view->setSize(width, height);

        return true;
    }

    bool System::view_setRotation(unsigned int id, LUA_NUMBER degrees)
    {
        auto view = mViewHandler.get(id);

        if(nullptr == view)
        {
            return false;
        }

        view->setRotation(degrees);

        return true;
    }

    bool System::view_setViewport(unsigned int id, LUA_NUMBER top, LUA_NUMBER left, LUA_NUMBER width, LUA_NUMBER height)
    {
        auto view = mViewHandler.get(id);

        if(nullptr == view)
        {
            return false;
        }

        view->setViewport(sf::FloatRect(top, top, width, height));

        return true;
    }

    std::tuple<LUA_NUMBER, LUA_NUMBER> System::view_getCenter(unsigned int id)
    {
        std::tuple<LUA_NUMBER, LUA_NUMBER> data {0.f, 0.f};

        auto view = mViewHandler.get(id);

        if(nullptr == view)
        {
            return  data;
        }

        auto center = view->getCenter();

        data = std::make_tuple(center.x, center.y);

        return data;
    }

    std::tuple<LUA_NUMBER, LUA_NUMBER> System::view_getSize(unsigned int id)
    {
        std::tuple<LUA_NUMBER, LUA_NUMBER> data {0.f, 0.f};

        auto view = mViewHandler.get(id);

        if(nullptr == view)
        {
            return data;
        }

        auto size = view->getSize();

        data = std::make_tuple(size.x, size.y);

        return data;
    }

    LUA_NUMBER System::view_getRotation(unsigned int id)
    {
        LUA_NUMBER data {0.f};

        auto view = mViewHandler.get(id);

        if(nullptr == view)
        {
            return data;
        }

        auto rotation = view->getRotation();

        data = rotation;

        return data;
    }

    std::tuple<LUA_NUMBER, LUA_NUMBER, LUA_NUMBER, LUA_NUMBER> System::view_getViewport(unsigned int id)
    {
        std::tuple<LUA_NUMBER, LUA_NUMBER, LUA_NUMBER, LUA_NUMBER> data {0.f, 0.f, 0.f, 0.f};

        auto view = mViewHandler.get(id);

        if(nullptr == view)
        {
            return data;
        }

        auto viewport = view->getViewport();

        data = std::make_tuple(viewport.left, viewport.top, viewport.width, viewport.height);

        return data;
    }
}
