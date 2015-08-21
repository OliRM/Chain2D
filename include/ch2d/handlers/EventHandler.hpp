#ifndef CH2D_EVENTHANDLER_H
#define CH2D_EVENTHANDLER_H

// Standard
#include <memory>

// SFML
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// Lua
extern "C"
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

namespace ch2d
{
    struct Mouse
    {
        LUA_NUMBER x;
        LUA_NUMBER y;
        bool buttons[sf::Mouse::Button::ButtonCount];
    };

    class EventHandler
    {
    public:
        // Constructor
        EventHandler(sf::RenderWindow&);

        // update
        void update(void);

        // Keyboard methods
        bool keyboard_isDown(size_t);

        // Mouse methods
        LUA_NUMBER mouse_x(void);
        LUA_NUMBER mouse_y(void);
        bool mouse_isDown(size_t);

    private:
        // Window reference
        sf::RenderWindow& mRenderWindow;
        bool mKeys[sf::Keyboard::KeyCount];
        Mouse mMouse;
    };
}

#endif
